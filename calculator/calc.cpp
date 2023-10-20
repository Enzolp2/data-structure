#include <iostream>
using namespace std;

float mult(float n1, float n2) {
	return n1 * n2;
}

float div(float n1, float n2) {
	return n1/n2;
}

float subt(float n1, float n2) {
	return n1 - n2;
}

float add(float n1, float n2) {
	return n1 + n2;
}

int main() {
	float n1;
	float n2;
	
	cout << "Number 1: ";
	cin >> n1;
	
	cout << "Number 2: ";
	cin >> n2;
	
	cout << "---------------" << endl;
	cout << "Soma: " << add(n1, n2) << endl;
	cout << "Subtração: " << subt(n1, n2) << endl;
	cout << "Multiplicação: " << mult(n1, n2) << endl;
	cout << "Divisão: " << div(n1, n2) << endl;
	return 0;
	 	
}
