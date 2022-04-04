// это ПРОКСИ-СЕРВЕР
#include "socket_functions.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
#pragma warning(disable: 4996)

int main() {
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	setlocale(LC_ALL, "Russian");
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Ошибка" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Ошибка подключения к серверу\n";
		return 1;
	}
	cout << "Подключение выполнено!\n";
	char msg[256];
	ofstream log("log.txt");
	recv(Connection, msg, sizeof(msg), NULL);
	Socket client_socket(msg);
	while (recv(Connection, msg, sizeof(msg), NULL))
	{
		string packet(msg);
		log << packet << endl;
		client_socket.SendPacketToClient(packet);
	}
	log.close();
	return 0;
}
