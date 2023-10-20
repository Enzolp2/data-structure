#include "stack.h"
#include "stack.cpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace structures;

bool xml_validation(std::string& cenario, ArrayStack<std::string>& stack) {

    for (std::size_t i = 0 ; i < cenario.length(); i++) {
        if (cenario[i] == '<') {
            if (cenario[i+1] == '/') {
                // Tag de Fechamento
                if (stack.empty()) {
                    // Verifica se a Stack está vazia
                    return 0;
                }
                int k = i + 2;
                std::string selector_close;
                while (cenario[k] != '>') {
                    // Recupera o valor do seletor de fechamento
                    selector_close += cenario[k];
                    k++;
                }
                if (stack.pop() != selector_close){
                    return 0;
                }

            } else {
                // Tag de Abertura
                int j = i+1;
                std::string selector_open;
                while (cenario[j] != '>') {
                    // Recupera o valor do seletor de abertura
                    selector_open += cenario[j];
                    j++;
                }
                stack.push(selector_open);
            }
        }
    }

    return (!stack.size());
}

int main() {
    
    char xmlfilename[100];
    std::cout << "Cenario Filename (cenarios1.xml): ";
    std::cin >> xmlfilename;  // entrada

    std::string file_path;
    std::ifstream file;
    std::string cenario;

    file_path = "cenarios/" + std::string(xmlfilename);

    // Open and read file
    file.open(file_path);
    if (!file.is_open()) {
        throw std::invalid_argument("File not found");
    }
    std::string line;
    while (std::getline(file, line)) {
        cenario += line;
    }

    //  Instancia a pilha de gerenciamento de tags XML
    ArrayStack<std::string> stack(1000000);

    //  Verificar abertura e fechamento de tag xml
    if (!xml_validation(cenario, stack)) {
        std::cout << "erro" << std::endl;
    } else {
        std::cout << "xml valido" << std::endl;
    }

    //  Verificar a área de limpeza do robô

    return 0;
}

