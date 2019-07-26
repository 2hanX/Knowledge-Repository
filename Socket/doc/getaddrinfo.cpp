/*
	1. 该示例中应用程序试图解析主机名“hostname”，并希望在5001端口与某项
	服务建立一个TCP连接
	2. 给定 AF_UNSPEC，则返回地址可能是 IPv4 或 IPv6
	3. 给定 AI_CANONNAME，
	4. 给定 AI_NUMERICHOST，则可以输入一个文字字符串地址（如：“192.168.1.100”）
*/


#include<stdio.h>
#include<WS2tcpip.h>
#include<winsock2.h>
#pragma comment (lib,"ws2_32.lib")

int main()
{
	SOCKET s;
	struct addrinfo hints, *result;
	int rc;
	memset(&hints, 0, sizeof(hints));

	hints.ai_flags = AI_CANONNAME;
	//hints.ai_flags = AI_NUMERICHOST;

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	rc = getaddrinfo("hostname", "5001", &hints, &result);
	//rc = getaddrinfo("192.168.1.100", "5001", &hints, &result);
	if (rc != 0)
	{
		// 无法解析名称
	}

	s = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (s == INVALID_SOCKET)
	{
		//套接字API失败
	}

	rc = connect(s, result->ai_addr, result->ai_addrlen);
	if (rc == SOCKET_ERROR)
	{
		//连接API失败
	}
	freeaddrinfo(result);
	return 0;
}