#include <stdio.h>
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET ListeningSocket;
	SOCKET NewConnection;
	SOCKADDR_IN  ServerAddr;
	SOCKADDR_IN ClientAddr;
	int Port = 8888;

	// 初始化 Winsock版本 2.2
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// 创建一个新的套接字来监听客户机连接
	ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(Port);
	ServerAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	// 使用bind函数将地址信息和套接字关联起来
	bind(ListeningSocket, (SOCKADDR *)&ServerAddr,sizeof(ServerAddr));

	// 监听客户机连接
	listen(ListeningSocket, 10);

	// 连接到达时，接受一个新连接
	int nSize = sizeof(SOCKADDR);
	NewConnection = accept(ListeningSocket, (SOCKADDR *)&ClientAddr, &nSize);

	//关闭套接字
	closesocket(NewConnection);
	closesocket(ListeningSocket);

	//终止 DLL 的使用
	WSACleanup();

	system("pause");
	return 0;
}