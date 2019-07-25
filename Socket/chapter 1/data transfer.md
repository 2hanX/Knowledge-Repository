### 数据传输[^1]

#### 发送数据

```c
int	send(
	SOCKET s, //已建立连接、将用于发送数据的套接字
	const char FAR * buf, //字符缓冲区指针，用于包含即将发送的数据
	int len, //缓冲区内字符数
	int flags // 取值： 0 、 MSG_DONTROUTE 或 MSG_OOB
); // 成功返回发送的字节数，失败返回 SOCKET_ERROR
```

```c
int	WSASend(
	SOCKET s,
	LPWSABUF lpBuffers, //指向一个或多个 WSABUF 结构的指针
	DWORD dwBufferCount, //指明传递的 WSABUF 结构的数量
	LPDWORD lpNumberOfBytesSent, //指向 DWORD(WSASend调用返回) 的指针，包含已发送的字节总数
	DWORD dwFlags,
	LPWSAOVERLAPPED lpOverlapped, //用于重叠 I/O
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
); //成功返回 0，失败返回 SOCKET_ERROR
```

#### 接受数据

```c
int	recv(
	SOCKET s, //准备用来接收数据的套接字
	char FAR * buf, //用于接受数据的字符缓冲区
	int len, // buf 缓冲区的长度
	int flags // 取值：0、MSG_PEEK 或 MSG_OOB
);
```

```c
int	WSARecv(
	SOCKET s,
	LPWSABUF lpBuffers,
	DWORD dwBufferCount,
	LPDWORD lpNumberOfBytesRecvd, //指向这个函数调用收到的字节数
	LPDWORD lpFlags, //取值：MSG_PEEK、MSG_OOB 或 MSG_PARTIAL
	LPWSAOVERLAPPED lpOverlapped,
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);
```

### 流协议 [^2]

```c
char sendbuff[2048] = { 0 };
int nBytes = 2048;
// int nBytes = strlen(sendbuff);
int ret = send(s, sendbuff, nBytes, 0);
```

```c
char sendbuff[2048];
int nBytes = 2048, nLeft, idx;
nLeft = nBytes;
idx = 0;
while(nLeft > 0)
{
    int ret = send(s, &sendbuff[idx], nLeft, 0);
    if(ret == SOCKET_ERROR)
    {
        //出错
    }
    nLeft -= ret;
    idx += ret;
}
```

### 中断连接[^3]

```c
int	shutdown(
	SOCKET s,
	int how // 取值：SD_RECEIVE、SD_SEND 或 SD_BOTH
);
```

### 无连接通信[^4]

#### 接收数据[^5]

```c
int	recvfrom(
	SOCKET s, //前 4 个参数与 recv() 一致
	char FAR * buf,
	int len,
	int flags, // 取值：MSG_OOB 或 MSG_PEEK（慎用）
	struct sockaddr FAR * from, // 指向发送数据端的地址
	int FAR * fromlen
);
```

```c
int	WSARecvFrom(
	SOCKET s,
	LPWSABUF lpBuffers,
	DWORD dwBufferCount,
	LPDWORD lpNumberOfBytesRecvd,
	LPDWORD lpFlags, //取值：0、MSG_PEEK、MSG_OOB 或 MSG_PARTIAL
	struct sockaddr FAR * lpFrom, //指向发送端地址
	LPINT lpFromlen,
	LPWSAOVERLAPPED lpOverlapped,
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);
```

[udp_receiver](../doc/udp_receiver.cpp)

#### 发送数据

```c
int	sendto(
	SOCKET s,
	const char FAR * buf,
	int len,
	int flags,
	const struct sockaddr FAR * to, // sockaddr结构指针，指向接收数据的目标地址
	int tolen
);
```

```c
int	WSASendTo(
	SOCKET s,
	LPWSABUF lpBuffers,
	DWORD dwBufferCount,
	LPDWORD lpNumberOfBytesSent,
	DWORD dwFlags,
	const struct sockaddr FAR * lpTo,
	int iTolen,
	LPWSAOVERLAPPED lpOverlapped,
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);
```

[udp_sender](../doc/udp_sender.cpp)



---

[^1]: 在已建立连接的套接字上发送数据，可调用 `send()` 或`WSASend()`；接受数据可调用 `recv()` 或`WSARecv()`
[^2]: 即面向连接的协议，采用 `SOCK_STREAM`
[^3]: 直接调用`closesocket()`可能会丢失数据，因此在此之前需要调用`shutdown()`来终止连接；此外并非所有的面向连接的协议都支持从容关闭，对于不支持从容关闭连接的协议（如 ATM）来说可以直接调用`closesocket()`来结束进程
[^4]: 通过 UDP 协议通信，不能确保可靠的数据传输，但能将数据发送到多个目标，即使不知对方是否准备接收这些数据
[^5]: 不必调用` listen()`和`accept()`，只需调用`bind() `和接收函数