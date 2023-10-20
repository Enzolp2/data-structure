#include "verify-code.h"
#include "pilha.h"
#include <iostream>

using namespace std;

bool verificaChaves(std::string trecho_programa) {
    bool resposta = true;
    int  tamanho  = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);

    for (int i = 0; i < tamanho; i++) {
        // condições de parada dor 'for' podem ser adicionadas...
        if (trecho_programa[i] == '{') {
            pilha.push(trecho_programa[i]);
        } else if (trecho_programa[i] == '}') {
            if (pilha.empty()) return false;
            pilha.pop();
        }
    }
    if (!(pilha.empty())) return false;
    return resposta;
}

bool verificaParenteses(std::string trecho_programa) {
    bool resposta = true;
    int  tamanho  = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);

    for (int i = 0; i < tamanho; i++) {
        // condições de parada dor 'for' podem ser adicionadas...
        if (trecho_programa[i] == '(') {
            pilha.push(trecho_programa[i]);
        } else if (trecho_programa[i] == ')') {
            if (pilha.empty()) return false;
            pilha.pop();
        }
    }
    if (!(pilha.empty())) return false;
    return resposta;
}

bool verificaColchetes(std::string trecho_programa) {
    bool resposta = true;
    int  tamanho  = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);

    for (int i = 0; i < tamanho; i++) {
        // condições de parada dor 'for' podem ser adicionadas...
        if (trecho_programa[i] == '[') {
            pilha.push(trecho_programa[i]);
        } else if (trecho_programa[i] == ']') {
            if (pilha.empty()) return false;
            pilha.pop();
        }
    }
    if (!(pilha.empty())) return false;
    return resposta;
}
int main(void) {
	
	std::string trecho;
	trecho = "int main() {\n    std::string trecho_programa = \"{UFSC}\";\n    bool ok = verificaChaves(trecho_programa);\n    if (ok) {\n        std::cout << \"Tudo certo\" << std::endl;\n    } else {\n        std::cout << \"Há problema\" << std::endl;\n    }\n    return 0;\n}\n";
	
	cout << "verificaParenteses" << verificaParenteses(trecho) << endl;
	cout << "verificaColchetes" << verificaColchetes(trecho) << endl;
	cout << "verificaChaves" << verificaChaves(trecho) << endl;
	
	return 0;
}

