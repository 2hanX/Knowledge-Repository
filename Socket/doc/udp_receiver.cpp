#include<stdio.h>
#include<WinSock2.h>
#pragma comment (lib,"ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET ReceivingSocket;
	SOCKADDR_IN ReceiverAddr;
	SOCKADDR_IN SenderAddr;
	int Port = 8888;
	char ReceiveBuf[1024];
	int BufLength = 1024;
	int SenderAddrSize = sizeof(SenderAddr);

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	ReceivingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	ReceiverAddr.sin_family = AF_INET;
	ReceiverAddr.sin_port = htons(Port);
	ReceiverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	bind(ReceivingSocket, (SOCKADDR *)&SenderAddr, sizeof(SenderAddr));

	recvfrom(ReceivingSocket, ReceiveBuf, BufLength, 0, (SOCKADDR *)&SenderAddr, &SenderAddrSize);

	closesocket(ReceivingSocket);
	
	WSACleanup();

	system("pause");
	return 0;
}