#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
	string nombre;
	int edad;
	string nacionalidad;
public:
	Persona(string n, int e = 18, string x = "mexicana") : nombre(n), edad(e), nacionalidad(x) {};
	void saludar() {
		cout << "Hola, mi nombre es " << nombre << ", tengo " << edad << " años y soy " << nacionalidad << "." << endl;
	}
	Persona &cambiarNombre(string nombre) {
		// Aquí this resuelve la ambiguedad
		this->nombre = nombre;
		return *this; // Aquí el objeto retorna una referencia a si mismo
	}
	Persona &cambiarEdad(int edad) {
		this->edad = edad;
		return *this;
	}
	Persona &cambiarNacionalidad(string nacionalidad) {
		this->nacionalidad = nacionalidad;
		return *this;
	}
	Persona *clonar() { // Otro caso de uso para this es la posibilidad clonar un objeto completo.
		return new Persona(*this);
	}
};

int main() {

	Persona persona = Persona("Diana");
	// persona.saludar();

	persona
		.cambiarNombre("Diana Martínez")
		.cambiarEdad(26)
		.cambiarNacionalidad("colombiana")
		.saludar();

	Persona *persona2 = persona.clonar();

	persona2->cambiarNombre("Diana Copia").saludar();

	return 0;
}
