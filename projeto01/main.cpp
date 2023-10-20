#include "stack.h"
#include "stack.cpp"
#include "queue.h"
#include "queue.cpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <utility>

using namespace structures;

struct Cenario {
    std::string nome;
    std::pair<int, int> dim;
    std::pair<int, int> start;
    std::vector<std::vector<char>> matriz;
};

// Função para converter uma string em um vetor bidimensional de caracteres
std::vector<std::vector<char>> stringToMatrix(const std::string& str, int numRows, int numCols) {
    std::vector<std::vector<char>> matrix(numRows, std::vector<char>(numCols));
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = str[index];
            index++;
        }
    }
    return matrix;
}

// Função para retornar o valor de uma tag em um determinado cenário
std::string getTag(std::string& cenarios, int& index, std::string tag) {
    for (int i = index; i < cenarios.length(); i++) {
        if (cenarios[i] == '<' && cenarios[i+1] != '/') {
            int k = i+1;
            std::string name_selector;
            while (cenarios[k] != '>') {
                name_selector += cenarios[k];
                k++;
            }
            if (name_selector == tag) {
                int j = k+1;
                std::string name;
                while (cenarios[j] != '<') {
                    name += cenarios[j];
                    j++;
                }
                return name;
            }
        }
    }
    return "";
}

// Função para determinar a área do componente conexo
int determineArea(const Cenario& cenario) {

     // Define as direções possíveis (vizinhança-4).
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
     
    // Inicializa a matriz R com '0'.
    std::vector<std::vector<char>> R(cenario.dim.first, std::vector<char>(cenario.dim.second, '0'));
    // Inicializa a Queue (Fila)
    structures::ArrayQueue<std::pair<int, int>> queue(1000);
    queue.enqueue(cenario.start);

    // Marcar ponto inicial como visitado
    if (cenario.matriz[cenario.start.first][cenario.start.second] == '1') {
        R[cenario.start.first][cenario.start.second] = '1';
    } else {
        return 0;
    }

    while (!queue.empty()) {
        std::pair<int, int> current = queue.dequeue();
        
        for (int i = 0; i < 4; i++) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            // Verificar se a nova posição está dentro dos limites do cenário
            if (newX >= 0 && newX < cenario.dim.first && newY >= 0 && newY < cenario.dim.second) {
                if (cenario.matriz[newX][newY] == '1') {
                    if (R[newX][newY] == '0') {
                        // Marcar a nova posição como visitada e adicioná-la à fila
                        R[newX][newY] = '1';
                        queue.enqueue(std::make_pair(newX, newY));
                    }
                }
            }
        }
    }
    // Calcular a área do componente conexo
    int area = 0;
    for (int i = 0; i < cenario.dim.first; i++) {
        for (int j = 0; j < cenario.dim.second; j++) {
            if (R[i][j] == '1') {
                area++;
            }
    }
}
    return area;
}

// Função para analisar os cenarios de limpeza do robô
void robot_cleaner(std::string cenarios) {
    for (int i = 0; i < cenarios.length(); i++) {
        if (cenarios[i] == '<' && cenarios[i+1 != '/']) {
                int j = i+1;
                std::string main_selector;
                while (cenarios[j] != '>') {
                    main_selector += cenarios[j];
                    j++;
                }
                if (main_selector == "cenario") {
                    // Definindo a estrutura do cenario
                    Cenario cenario;
                    cenario.nome = getTag(cenarios, j, "nome");
                    cenario.dim = std::make_pair(std::stoi(getTag(cenarios, j, "altura")), std::stoi(getTag(cenarios, j, "largura")));
                    cenario.start = std::make_pair(std::stoi(getTag(cenarios, j, "x")), std::stoi(getTag(cenarios, j, "y")));
                    std::string matriz = getTag(cenarios, j, "matriz");
                    cenario.matriz = stringToMatrix(matriz, cenario.dim.first, cenario.dim.second);

                    // Resolvendo a área de limpeza do robo
                    int area_matriz = determineArea(cenario);
                    std::cout << cenario.nome << " " << area_matriz << std::endl;
                }
            }
        }
}

// Função para validar as tags xml
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

    // Open and read file to std::string cenario
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
        //  Verificar a área de limpeza do robô
        robot_cleaner(cenario);
    }
    return 0;
}

