#include <iostream>
#include <string>

using namespace std;

struct Persona {
	char* nombre;
	int edad;
};

void procesarPersona(Persona p) {
	cout << "Pasando struct como argumento" << endl;
	cout << "  nombre: " << p.nombre << endl;
}

int main() {

	/*Persona P = {
		nombre: (char *)"Diana",
		edad: 24
	};

	cout << "P.nombre: " << P.nombre << endl;*/

	// Memoria dinámica / punteros
	Persona *P = new Persona;

	P->nombre = (char *)"Diana";
	P->edad = 26;

	// Estructura en memoria
	cout << "P: " << P << endl;
	cout << "&P->nombre: " << &P->nombre << endl;
	cout << "&P->edad: " << &P->edad << endl;
	cout << "sizeof P: " << sizeof(P) << " bytes" << endl;
	cout << "sizeof &P->nombre: " << sizeof(&P->nombre) << " bytes" << endl;
	cout << "sizeof &P->edad: " << sizeof(&P->edad) << " bytes" << endl;
	cout << "sizeof Persona: " << sizeof(Persona) << " bytes" << endl;

	procesarPersona(*P);

	// Otros ejemplos de estructuras útiles

	struct Punto {
		int x, y;
	};

	Punto p = { x: 10, y: 20 };

	cout << "Punto: " << endl;
	cout << "  p.x: " << p.x << ", p.y: " << p.y << endl;

	struct Fecha {
		int d, m, a; // Dia, Mes y Año
	};

	Fecha fecha = {
		d: 1,
		m: 12,
		a: 2021
	};

	cout << "Fecha:" << endl;
	cout << "  Dia: " << fecha.d << ", mes: " << fecha.m << ", año: " << fecha.a << endl;

	struct Lugar {
		string ciudad, estado, pais;
	};

	Lugar l = {
		ciudad: "Los Angeles",
		estado: "California",
		pais: "México"
	};


	cout << "Lugar: " << endl;
	cout << "  ciudad: " << l.ciudad << ", estado: " << l.estado << ", pais: " << l.pais << endl;

	return 0;
}