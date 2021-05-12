#include <iostream>
#include <string>

using namespace std;

void pasoPorReferencia(string *puntero) {
	cout << "Paso por referencia de un string" << endl
		<< "dirección del argumento str: " << &puntero << endl
		<< "dirección de referencia: " << puntero << endl
		<< "valor pasado por referencia: " << *puntero << endl;
}

int main() {

	char letra = 'A';
	char *puntero = &letra;

	cout << "direccion de letra: " << (int *) &letra << endl;
	cout << "valor de letra: " << letra << endl;
	cout << "direccion de puntero: " << &puntero << endl;
	cout << "valor de puntero: " << (int *) puntero << endl;
	cout << "valor almacenado en la memoria que guarda el puntero: " << *puntero << endl;

	char letra2 = 'B';
	puntero = &letra2;

	cout << "direccion de puntero: " << &puntero << endl;
	cout << "valor de puntero: " << (int *) puntero << endl;
	cout << "valor almacenado en la memoria que guarda el puntero: " << *puntero << endl;

	string texto = "Hola mundo";

	pasoPorReferencia(&texto);

	return 0;
}
