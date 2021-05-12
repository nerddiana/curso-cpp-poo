#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
	string nombre;
	int edad;
	Persona(string n, int e = 18) : nombre(n), edad(e) {}
	void saludar() {
		cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << endl;
	}
	~Persona() {
		cout << "Este código se ejecuta cuando se destruye el objeto" << endl;
	}
};

int main() {

	Persona p = Persona("Diana");

	cout << "nombre: " << p.nombre << endl;

	p.saludar();


	// Memoria dinámica, se requiere limpiar la memoria manualmente
	Persona *p2 = new Persona("Diana 2");

	cout << "nombre: " << p2->nombre << endl;

	p2->saludar();

	// Invoca el destructor y limpia la memoria
	delete p2;
	cout << "después de eliminar p2" << endl;

	return 0;
}