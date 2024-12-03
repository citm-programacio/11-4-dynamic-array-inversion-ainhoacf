// dynamicArrayInversion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class DynamicArray {
private:
	int size = 0;
	int capacity;
	string* array;

public:
	DynamicArray() {
		capacity = 10;
		array = new string[capacity];
	}

	DynamicArray(int _c) {
		capacity = _c;
		array = new string[capacity];
	}

	bool insert(string newElement, int position) {
		if (position < 0 || position > size) {
			cout << "Invalid position" << endl;
			return false;
		}
		if (size == capacity) {
			capacity *= 2;
			string* newArray = new string[capacity];
			for (int i = 0; i < size; i++) {
				newArray[i] = array[i];
			}
			delete[] array;
			array = newArray;
		}
		for (int i = size; i > position; i--) {
			array[i] = array[i - 1];
		}
		array[position] = newElement;
		size++;
		return true;
	}

	void invert() {
		int i = 0, j = size - 1;
		while (i < j) {
			string temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << ", ";
		}
		cout << endl;
	}

	~DynamicArray() {
		delete[] array;
	}
};

int main() {
	DynamicArray a(10);

	a.insert("one", 0);
	a.insert("two", 1);
	a.insert("three", 2);
	a.insert("four", 3);

	cout << "Array before inversion: ";
	a.print();

	a.invert();

	cout << "Array after inversion: ";
	a.print();

	return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
