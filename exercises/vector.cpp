#include <iostream>
using namespace std;



int main() {
	char *c;
	c = new char[26];  // retirar e alocar (com new)
	for (int i = 0; i < 26; i++) {
		c[i] = 'A';
	}
	int asciiValue = (int)c[0];
	cout << asciiValue << endl;	
	
	for (int j = 0 ; j < 26 ; j++) {
		cout << j + asciiValue << ", ";
	}

}

