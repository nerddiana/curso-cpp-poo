#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
	static int numero_animales;
	string alimento;
public:
	Animal();
	~Animal();
	static int obtenerNumeroAnimales();
	string obtenerAlimento() {
		return alimento;
	};
	void comer() {
		cout << "Este animal está comiendo " << alimento << "... ñom ñom" << endl;
	};
};

int Animal::numero_animales = 0;

Animal::Animal() {
	cout << "Creando nuevo animal..." << endl;
	numero_animales += 1;
}

Animal::~Animal() {
	cout << "Borrando animal..." << endl;
	numero_animales -= 1;
}

int Animal::obtenerNumeroAnimales() {
	return numero_animales;
}

class Herviboro : public Animal {
public:
	Herviboro() : Animal() {
		this->alimento = "plantas";
	}
	void pastar() {
		cout << "Este animal está pastando..." << endl;
	}
};

class Carnivoro : public Animal {
public:
	Carnivoro() : Animal() {
		this->alimento = "carne";
	}
	void cazar() {
		cout << "Este animal está cazando..." << endl;
	}
};

class Omnivoro : public Herviboro, public Carnivoro {
public:
	Omnivoro() : Herviboro(), Carnivoro() {}
	void comer() {
		cout << "Este animal está comiendo todo tipo de alimentos..." << endl;
	}
};

int main() {
	Carnivoro *leon = new Carnivoro();
	Herviboro *cebra = new Herviboro();

	cout << "Numero de animales: " << Animal::obtenerNumeroAnimales() << endl;

	cout << "Leon: " << endl;
	leon->cazar();
	leon->comer();

	cout << "Cebra: " << endl;
	// Esto no es posible
	// cebra->cazar();
	cebra->pastar();
	cebra->comer();

	Omnivoro *humano = new Omnivoro();

	cout << "Humano: " << endl;

	humano->cazar();
	humano->Carnivoro::comer();

	humano->pastar();
	humano->Herviboro::comer();

	humano->comer();

	cout << "Numero de animales: " << Animal::obtenerNumeroAnimales() << endl;

	return 0;
}