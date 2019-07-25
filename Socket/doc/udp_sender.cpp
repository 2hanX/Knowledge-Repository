#include<stdio.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET SendingSocket;
	SOCKADDR_IN ReceiverAddr;
	int Port = 8888;
	char SendBuf[1024];
	int BufLength = 1024;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SendingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	ReceiverAddr.sin_family = AF_INET;
	ReceiverAddr.sin_port = htons(Port);
//	ReceiverAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.100");
	ReceiverAddr.sin_addr.S_un.S_addr = inet_pton(AF_INET, "192.168.1.100", (void *)&ReceiverAddr.sin_addr.S_un.S_addr);
	sendto(SendingSocket, SendBuf, BufLength, 0, (SOCKADDR *)&ReceiverAddr, sizeof(ReceiverAddr));

	closesocket(SendingSocket);

	WSACleanup();

	system("pause");
	return 0;
}