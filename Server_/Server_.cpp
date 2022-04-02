// это СЕРВЕР. программа 1
#include "socket_functions.h"

using namespace std;

int main()
{
	Socket task_socket;
	string packet;
    while (!cin.eof())
    {
		string packet_part;
		getline(cin, packet_part);
		task_socket.SendPacketToClient(packet_part);
	}
	return 0; // в деструкторе сокет закроется сам
}