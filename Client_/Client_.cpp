// это КЛИЕНТ
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>

using namespace std;
#pragma warning(disable: 4996)

int main() {
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	setlocale(LC_ALL, "Russian");
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1112);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to proxy-server.\n";
		return 1;
	}
	std::cout << "Connected!\n";
	char msg[256];
	while (recv(Connection, msg, sizeof(msg), NULL))
	{
		std::string message(msg);
		cout << message << endl;
	}
	return 0;
}