#include <iostream>

using namespace std;

class Poligono {
protected:
	int ancho, alto;
public:
	Poligono(int b = 0, int a = 0) : ancho(b), alto(a) {}
	int obtenerAncho() {
		return ancho;
	}
	int obtenerAlto() {
		return alto;
	}
	int obtenerArea() {
		cout << "Calcular el area para un poligono" << endl;
		return 0;
	};
};

class Rectangulo : public Poligono {
public:
	Rectangulo(int b = 0, int a = 0) : Poligono(b, a) {}

	int obtenerArea() {
		cout << "Calcular el area para un rectangulo" << endl;
		return (ancho * alto);
	}
};

class Triangulo : public Poligono {
public:
	Triangulo(int b = 0, int a = 0) : Poligono(b, a) {}

	int obtenerArea() {
		cout << "Calcular el area para un triangulo" << endl;
		return (ancho * alto) / 2;
	}
};

class Cuadrado : public Rectangulo {
public:
	Cuadrado(int lado = 0) : Rectangulo(lado, lado) {}
};

int main() {
	Poligono p = Poligono();
	cout << "poligono ancho: " << p.obtenerAncho() << ", alto: " << p.obtenerAlto() << ", area: " << p.obtenerArea() << endl;

	Rectangulo r = Rectangulo(15, 20);
	cout << "rectangulo ancho: " << r.obtenerAncho() << ", alto: " << r.obtenerAlto() << ", area: " << r.obtenerArea() << endl;

	Triangulo t = Triangulo(19, 24);
	cout << "triangulo ancho: " << t.obtenerAncho() << ", alto: " << t.obtenerAlto() << ", area: " << t.obtenerArea() << endl;

	Cuadrado c = Cuadrado(60);
	cout << "cuadrado ancho: " << c.obtenerAncho() << ", alto: " << c.obtenerAlto() << ", area: " << c.obtenerArea() << endl;

	return 0;
}