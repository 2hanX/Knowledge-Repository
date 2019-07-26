### Winsock中的IPv4寻址

```c
typedef struct sockaddr_in {
    short sin_family; 
    USHORT sin_port; //16位的端口号
    STRUCT in_addr	sin_addr; //32位IP地址
    CHAR sin_zero[8]; //不使用，一般用0填充
};
```

#### 端口号

- `0~1023`：由[IANA](https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml)控制，为已知服务保留
- `1024~49151`：由IANA列出的已注册端口，由普通用户执行的普通用户进程或程序可以使用这些端口
- `49152~65535`：动态和（或）专用端口

### Winsock中的IPv6寻址

```c
struct sockaddr_in6 {
	USHORT sin6_family; // AF_INET6.
	USHORT sin6_port;   // Transport level port number.
	ULONG  sin6_flowinfo; // IPv6 flow information.
	IN6_ADDR sin6_addr;  // IPv6 address.
	ULONG sin6_scope_id;  // Set of interfaces for a scope.
} // 28 Bytes
```

### 地址及名称解析[^1]

#### 名称解析例程

| 旧（WSPiApi.h)(IPv4) | 新(WS2tcpip.h)(IPv4,IPv6) |
| -------------------- | ------------------------- |
| `gethostbyname()`    | `getnameinfo()`           |
| `inet_addr()`        | `getaddrinfo()`           |

```c
int	WspiapiGetAddrInfo( //函数原型
	const char	*nodename, //指定以空字符结束的主机名或文字地址
	const char	*servname, //包含端口号或服务名的以空字符结束的字符串
	const struct addrinfo	*hints,
	struct addrinfo	**res //返回addrinfo结构的一个链表，包含由字符串名称解析来的地址
);//成功返回 0，失败返回 Winsock 错误信息
```

```c
struct addrinfo
{
	int	ai_flags;       // 取值：AI_PASSIVE、AI_CANONNAME 或 AI_NUMERICHOST
    int	ai_family;      // 取值：AF_INET、AF_INET6或AF_UNSPEC
    int	ai_socktype;    // 套接字类型；取值：SOCK_DGRAM或SOCK_STREAM
    int	ai_protocol;    // 0 or IPPROTO_xxx for IPv4 and IPv6
    size_t	ai_addrlen;     // Length of ai_addr
    char *	ai_canonname;   // Canonical name for nodename
	struct sockaddr *	ai_addr;        // Binary address
    struct addrinfo *   ai_next;        // Next structure in linked list
}; //函数解析名称成功，返回结果为 ai_next 字段形成的链表；解析的地址存放在链表；长度为 ai_addrlen；可以将这两个字段传递给 bind connect sendto 等函数
```

[getaddrinfo](../doc/getaddrinfo.cpp)

```c
/*
	接受已初始化的套接字结构，返回与地址和端口信息对应的主机和服务名
*/
int	WspiapiGetNameInfo (
	const struct sockaddr	*sa,
	socklen_t	salen,
	char	*host,
	size_t	hostlen,
	char	*serv,
	size_t	servlen,
	int	flags //取值：NI_NOFQDN、NI_NUMERICHOST、NI_NAMEREQD、NI_NUMERICESRV 或 NI_DGRAM
);
```

[resolver](../doc/resolver.cpp)

`resolver.exe -n localhost -s 445 -p tcp -b`

#### 简单地址转换[^2]

```c
int WSAStringToAddress(
	LPWSTR	AddressString, //需要转换的字符串
	INT	AddressFamily, //地址簇；取值：AF_INET、AF_INET6或AF_IPX
	LPWSAPROTOCOL_INFO lpProtocolInfo,
	LPSOCKADDR lpAddress, //将字符串地址转换为该地址结构
	LPINT	lpAddressLength
);
```

```c
INT	WSAAddressToString( // 将二进制地址格式化为一个字符串
	LPSOCKADDR lpsaAddress,
	DWORD	dwAddressLength,
	LPWSAPROTOCOL_INFO lpProtocolInfo,
	LPWSTR lpszAddressString,
	LPDWORD	lpdwAddressStringLength
);
```

#### 传统名称解析例程[^3]

```c
// 将一个点分十进制表示的IPv4地址转换为一个32位无符号长整数（网络字节顺序）
unsigned long inet_addr( 
	const char FAR * cp
);
```

```c
// 与 inet_addr 相对；将 IPv4网络地址转换成一个字符串
char FAR * inet_ntoa(
	struct in_addr in
);
```



---

[^1]: 分配两种IP的文字串地址，以及将两种IP的名称解析为地址专用结构；名称解析`API：getaddrinfo`和`getnameinfo`;文字地址和套接字地址结构之间转换的`API：WSAAddressToString`和`WSAStringToAddress`
[^2]: 只是在字符串文字地址和套接字地址结构之间进行转换，可使用`API：WSAStringToAddress`和`WSAAddressToString`
[^3]: 新API：`getaddrinfo`和`getnameinfo`