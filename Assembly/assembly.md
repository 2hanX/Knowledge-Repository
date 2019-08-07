### MASM 平台

| 命令 | 说明                                | 举例                 | 含义                                     |
| ---- | ----------------------------------- | -------------------- | ---------------------------------------- |
| R    | 查看或修改寄存器内容                | `-r ds`<br />`:1000` | 修改`ds`寄存器，赋值为`1000`             |
| D    | 列出从SA:偏移地址开始的内存中的数据 | `-d ds:10 18`        | 查看`ds:10`~`ds:18`内存中的内容          |
| E    | 写数据                              | `-e ds:0 11 22 33`   | 从`ds:0`开始的内存区间写入数据`11 22 33` |
| A    | 以汇编指令的形式写数据              | `-a ds:50`           | 从`ds:50`开始的内存区间写数据            |
| U    | 以汇编指令的形式读数据              | `-u ds:100`          | 从`ds:100`处开始读数据，汇编语言格式显示 |
| P    | 循环语句一次执行完，直到`cx=0`      |                      |                                          |
| T    | 单步代码执行                        |                      |                                          |
| G    | 执行到某行                          | `-g cs:100`          | 执行到`cs:100`                           |
| Q    | 退出                                |                      |                                          |

### 流程

1. `masm.exe target.asm;`
2. `link.exe target.obj;`
3. `debug.exe target.exe`

### 标志寄存器

| 符号 | 说明                               | 含义                                                         |
| ---- | ---------------------------------- | ------------------------------------------------------------ |
| OF   | Overflow Flag；溢出标志位          | ==有符号运算==结果超过计算机表示的范围，置为1                |
| DF   | Direction Flag；方向标志位         | 串处理中控制`si`，`di`的增减；1：同时递减；<br />`cld`指令：置DF为0；<br />`std`指令：置DF为1 |
| IF   | Interrupt Flag；中断标志位         |                                                              |
| TF   | Trace Flag；跟踪标志位             |                                                              |
| SF   | Sign Flag；符号标志位              | 结果为负，置为1                                              |
| ZF   | Zero Flag；零标志位                | 结果为0，置为1                                               |
| AF   | Auxiliary Carry Flag；辅助进位标志 |                                                              |
| PF   | Parity Flag；奇偶标志位            | 比特位1的个数为偶数，置为1                                   |
| CF   | Carry Flag；进位标志位             | ==无符号运算==结果存在进位，置为1                            |

### Debug标志位表示

| 标志位 | ==1==                        | ==0==                            |
| ------ | ---------------------------- | -------------------------------- |
| OF     | OV（Overflow，溢出）         | NV（Not Overflow，未溢出）       |
| DF     | DN（Down，减少）             | UP（增加）                       |
| IF     | EI（Enable Interrupt，允许） | DI（Disable Interrupt，禁止）    |
| SF     | NG（Negative，负）           | PL（Positive，正）               |
| ZF     | ZR（Zero，等于零）           | NZ（Not Zero，不等于零）         |
| AF     | AC（Auxiliary Carry，进位）  | NA（No Auxiliary Carry，无进位） |
| CF     | CY（Carry，进位）            | NC（No Carry，无进位）           |
| PF     | PE（Parity Even，偶）        | PO（Parity Odd，奇）             |

