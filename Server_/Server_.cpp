// это СЕРВЕР. программа 1
#include "Socket_functions.h"

using namespace std;

int main()
{
	Socket task_socket; // создаем сокет (ср. "Socket_functions.h")
	string ip;
	setlocale(LC_ALL, "Russian");
	cout << "Введите IP клиента: "; // после того как запустили прокси-сервер, 
									// запрашиваем айпи клиента
	cin >> ip;
	task_socket.SendPacketToProxy(ip);
    while (!cin.eof()) // пока ввод не закончен
    {
		string packet_part;
		getline(cin, packet_part); // считываем пакет
		task_socket.SendPacketToProxy(packet_part); // отправляем в прокси-сервер
	}
	return 0; 
}