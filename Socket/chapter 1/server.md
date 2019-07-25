### Winsock初始化[^1]

```c++
int WSAStartup(
	WORD wVersionRequested,
    LPWSADATA lpWSAData
);
//wVersionRequested 参数用于指定准备加载的 Winsock 库的版本，低位字节是主版本，高位字节是次版本；使用宏 MAKEWORD(x,y)（其中x 高字节）来获得正确值 
```

```c
typedef struct WSAData {
	WORD wVersion; //ws2_32.dll 建议我们使用的版本号
	WORD wHighVersion; //ws2_32.dll 支持的最高版本号
	char szDescription[WSADESCRIPTION_LEN+1]; //一个以 null 结尾的字符串，用来说明 ws2_32.dll 的实现以及厂商信息
	char szSystemStatus[WSASYS_STATUS_LEN+1];  //一个以 null 结尾的字符串，用来说明 ws2_32.dll 的状态以及配置信息
	unsigned short iMaxSockets; //2.0以后不再使用
	unsigned short iMaxUdpDg; //2.0以后不再使用
	char FAR * lpVendorInfo; //2.0以后不再使用
} WSADATA, FAR * LPWSADATA;
```

### Winsock 释放资源

`int WSACleanup(void);`

### IPv4寻址 [^2]

```c
typedef struct sockaddr_in {
    short sin_family; //地址族（Address Family）; 地址类型:AF_INET/PF_INET(IPv4)
    USHORT sin_port; //16位的端口号
    STRUCT in_addr	sin_addr; //32位IP地址
    CHAR sin_zero[8]; //不使用，一般用0填充
} SOCKADDR_IN, *PSOCKADDR_IN;
```

```c
unsigned long inet_addr(	//将点分十进制的IP地址转换成32位IP地址
	const char FAR * cp
);
// 在 VS2013 以后的版本中可用 inet_pton() 代替；添加头文件 <ws2tcpip.h>
int inet_pton(
	INT Family,
	PCSTR pszAddrString,
	PVOID pAddrBuf
);
```

```c
sockaddr_in sockAddr;
memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
sockAddr.sin_family = AF_INET; // 使用IPv4 地址
//sockAddr.sin_addr.s_addr = inet_addr("192.168.1.100");
sockAddr.sin_addr.S_un.S_addr = inet_pton(AF_INET, "192.168.1.100", (void *)&sockAddr.sin_addr.S_un.S_addr);  //具体的IP地址
sockAddr.sin_port=htons(8888); //8888 端口
```

### 创建套接字[^3]

```c
SOCKET	socket(
	int af, // 协议的地址簇；AF_INET/PF_INET
	int type, // 协议的套接字类型；TCP：SOCK_STREAM；UDP：SOCK_DGRAM
	int protocol // TCP：IPPROTO_TCP；UDP：IPPROTO_UDP
);
```

### 面向连接的通信

- 服务端：`socket()/WSASocket()`→`绑定 bind()`→`监听 listen()`→`Accept()/WSAAccept()`
- 客户端：`socket()/WSASocket()`→地址解析→`Connect()/WSAConnect()`

#### 绑定 [^4]

```c
int	bind(
	SOCKET s, // 参数s代表用来等待客户机连接的那个套接字
	const struct sockaddr FAR * name,
	int namelen
);
```

```c
//创建套接字
SOCKET servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//绑定套接字
sockaddr_in sockAddr;
memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
sockAddr.sin_family = AF_INET;  //使用IPv4地址
//sockAddr.sin_addr.s_addr = inet_addr("192.168.1.100");
//sockAddr.sin_addr.S_un.S_addr = inet_pton(AF_INET, "192.168.1.100", (void *)&sockAddr.sin_addr.S_un.S_addr);  //具体的IP地址
sockAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //INADDR_ANY 允许将套接字绑定到系统中所有可用的接口，以便将来传到任意接口上的客户机连接（必须在正确的端口上）都可以被监听和接受
sockAddr.sin_port = htons(1234);  //端口
bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
```

#### 监听[^5]

```c
int	listen(
	SOCKET s, // 被绑定的套接字
	int	backlog // 指定被搁置的连接的最大队列长度
);
```

#### 接受连接 [^6]

```c
SOCKET	accept(
	SOCKET s, // 被绑定的套接字，处于监听模式
	struct sockaddr FAR * addr, // 有效的 `SOCKADDR_IN` 结构的地址；`addr` 为`SOCKADDR_IN`结构的长度;使用`sockaddr`结构来替换`SOCKADDR_IN`
	int FAR * addrlen // addr 结构的长度
);
```

### 部分示例

[tcp_server](../doc/tcp_server.cpp)



---

[^1]: 调用 Winsock 函数之前需要加载 Winsock 库，通过调用 `WSAStartup `函数实现
[^2]: 在 Winsock 中，应用程序通过 `SOCKADDR_IN `结构来指定IP地址和服务端口信息
[^3]: 两个函数可以创建套接字：`socket()`和`WSASocket()`
[^4]: 服务器端调用 `bind()` 函数将套接字与特定的 IP 地址和端口绑定起来，只有这样，流经该 IP 地址和端口的数据才能交给套接字处理
[^5]: 将套接字置于监听模式，指示套接字等待连接传入
[^6]: `Accept() `、`WSAAccept()` 、`AccdptEX()`