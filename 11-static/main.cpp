#include <iostream>
#include <string>

using namespace std;

class Mensaje {
public:
	static int numero_mensajes; // No se puede inicializar ni utilizar en el código de declaración de clase
	string texto;
	Mensaje(string msg);
	// static void bajarCuenta();
	~Mensaje();
};

// Solo se puede acceder en las definiciones externas a la clase
int Mensaje::numero_mensajes = 0;

Mensaje::Mensaje(string msg) {
	texto = msg;
	numero_mensajes += 1;
}

// Esto no se puede hacer, los miembros estáticos no pueden leer this
/*void Mensaje::bajarCuenta() {
	this->numero_mensajes -= 1;
}*/

Mensaje::~Mensaje() {
	numero_mensajes -= 1;
}

int main() {

	Mensaje *m1 = new Mensaje("un mensaje");
	Mensaje *m2 = new Mensaje("otro mensaje");

	cout << "Mensaje 1: " << m1->texto << endl;
	cout << "Mensaje 2: " << m2->texto << endl;

	// m2->bajarCuenta();

	cout << "Numero de instancias de mensaje: " << m2->numero_mensajes << endl;

	delete m2;
	cout << "Numero actualizado de instancias de mensaje: " << m2->numero_mensajes << endl;

	cout << "Acceder desde la clase: " << Mensaje::numero_mensajes << endl;

	return 0;
}