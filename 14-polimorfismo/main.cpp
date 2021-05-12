#include <iostream>
#include <string>

using namespace std;

class Mascota {
protected:
	static int cantidad_mascotas;
	string nombre;
	string sonido;
public:
	Mascota(string nombre);
	~Mascota();
	static int obtenerCantidadMascotas();
	string obtenerNombre() {
		return nombre;
	};
	string obtenerSonido() {
		return sonido;
	};
};

int Mascota::cantidad_mascotas = 0;

Mascota::Mascota(string nombre) {
	this->nombre = nombre;
	cantidad_mascotas += 1;
}

Mascota::~Mascota() {
	cantidad_mascotas -= 1;
}

int Mascota::obtenerCantidadMascotas() {
	return cantidad_mascotas;
}

class Perro : public Mascota {
public:
	Perro(string n) : Mascota(n) {
		this->sonido = "guau!";
	}
};

class Gato : public Mascota {
public:
	Gato(string n) : Mascota(n) {
		this->sonido = "miau!";
	}
};


class Humano {
public:
	static void presentarMascota(Mascota *m) {
		cout
			<< "Mi mascota se llama " << m->obtenerNombre()
			<< " y hace " << m->obtenerSonido()
			<< endl;
	}
};

int main() {
	Perro *doge = new Perro("Doge");
	Gato *michi = new Gato("Michi");

	Mascota *mascota;

	for (int cuenta = 0; cuenta < Mascota::obtenerCantidadMascotas(); cuenta++) {
		if (cuenta == 0) {
			mascota = doge;
		} else if (cuenta == 1) {
			mascota = michi;
		}
		Humano::presentarMascota(mascota);
	}

	return 0;
}