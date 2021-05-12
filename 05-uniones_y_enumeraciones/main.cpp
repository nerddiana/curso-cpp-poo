#include <iostream>

using namespace std;

int main() {
	union numero_letra {
		int numero;
		char letra;
	};

	numero_letra x = {'A'};

	cout << "x como numero: " << x.numero << endl;
	cout << "x como letra: " << x.letra << endl;

	// enum dias_semana { lunes, martes, miercoles, jueves, viernes }; // 0, 1, 2, 3, 4
	enum dias_semana { lunes = 'l', martes = 'm', miercoles = 'x', jueves = 'j', viernes = 'v' };

	dias_semana dia = jueves;

	cout << "dia: " << (char)dia << endl;

	return 0;
}