### getpeername[^1]

```c
int	getpeername(
	SOCKET s,
	struct sockaddr FAR * name, //指向下层协议类型的 SOCKADDR 的结构
	int FAR * namelen
);
```

### getsockname[^2]

```c
int	getsockname(
	SOCKET s,
	struct sockaddr FAR * name,
	int FAR * namelen
);
```

### WSADuplicateSocket[^3]

```c
int	WSADuplicateSocket(
	SOCKET s, //准备复制的套接字句柄
	DWORD dwProcessId, //打算复制的套接字的进程ID
	LPWSAPROTOCOL_INFO lpProtocolInfo
);
```



---

[^1]: 用于获取通信方的套接字地址信息
[^2]: 返回给定套接字的本地接口的地址信息
[^3]: 建立 `WSAPROTOCOL_INFO` 结构，实现进程间对资源的操作，而同一个进程中的线程可自由传递套接字描述符