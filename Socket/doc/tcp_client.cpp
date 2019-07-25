#include<stdio.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET s;
	SOCKADDR_IN servAddr;
	int Port = 8888;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 建立一个 SOCKADDR_IN 结构，用它来连接到 8888 端口的服务器
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(Port);
	//servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.100");
	servAddr.sin_addr.S_un.S_addr = inet_pton(AF_INET, "192.168.1.100", (void *)&servAddr.sin_addr.S_un.S_addr);

	connect(s, (SOCKADDR *)&servAddr, sizeof(servAddr));

	closesocket(s);

	WSACleanup();

	system("pause");
	return 0;
}