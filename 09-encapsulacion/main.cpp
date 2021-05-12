#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
	string nombre;
	int edad;
public:
	Persona(string n, int e = 18) : nombre(n), edad(e) {}
	void saludar() {
		cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << endl;
	}
	void actualizarEdad(int e);
	int obtenerEdad();
	/*void actualizarEdad(int e) {
		edad = e;
	}
	int obtenerEdad() {
		return edad;
	}*/
};

void Persona::actualizarEdad(int e) {
	edad = e;
}

int Persona::obtenerEdad() {
	return edad;
}

int main() {

	Persona p = Persona("Diana");

	// Esto ya no es posible
	// cout << "nombre: " << p.nombre << endl;

	p.saludar();
	p.actualizarEdad(26);
	cout << "nueva edad: " << p.obtenerEdad() << endl;

	return 0;
}