#include <iostream>
using namespace std;

// função para somar dois inteiros
int soma(int a, int b) {  // passagem de parametros por valor (cópia)
  int c;
  c = a + b;
  return c;
}

int soma2(int *pa, int *pb) {  // passagem de parametros por ponteiro (sem cópia do parâmetro) 
  int c;
  c = *pa + *pb;
  return c;
}

int soma3(int &a, int &b) {  // passagem de parametros por referência (sem cópia do parâmetro) 
  int c;
  c = a + b;
  return c;
}

float *temperaturas() {
  float *vet = new float[10];
  for (int i = 0; i < 10; i++) {
    vet[i] = 3.14 * i;
  }
  // return vet;
   return &vet[0];
}

int main() {
  
  cout << "For Loop" << endl;
  for (int i = 0; i < 10; i++) {
    cout << i << " ";
  }
  
  // PONTEIROS EM C++
  int x;
  x = 77;
  
  int *p; // ponteiro para uma variável do tipo int
  p = &x; // inicializando ponteiro com o endereço de x
  
  cout << endl << x << endl;   // 
  cout << *p << endl;                 // representa o conteúdo do ponteiro p
  
  cout << *p << endl; 
  
  int **q; // 'ponteiro do ponteiro' indireção múltipla
  q = &p;
  cout << q << endl;
  cout << **q << endl;    // repesenta o conteúdo do ponteiro q
  
  // CHAMANDO FUNÇÕES
  int m, n, s1, s2, s3;
  m = 2;
  n = 8;
  s1 = soma(m, n);
  s2 = soma2(&m, &n);
  s3 = soma3(m, n);
  
  cout << "Soma1: " << s1 << endl;
  cout << "Soma2: " << s2 << endl;
  cout << "Soma3: " << s3 << endl;
  
  // DECLARAÇÃO DE VETORES
  
      // declaração estática de vetor
  float temp[10] = {2, 4, 18, 1, 24, 16, 29, 43, 15, 40};  // alocados de forma contínua na memória
  float *aux;
  
  temp[9] = 10;
  *temp = 55;           // *temp representa um ponteiro cujo endereço é a primeira posição do vetor
  *(temp + 1) = 8;
  
  aux = temp + 3;
  *aux = 36;
  
    // percorrendo vetor
  for (int i=0; i<10; i++) {
    cout << temp[i] << endl;
  }
  
    // declaração dinâmica de vetor
  if (1) {
    cout << "Delcaração Dinâmica!" << endl;
    float *vet;
    vet = temperaturas();
    
    for (int i = 0; i < 10; i++) {
      cout << vet[i] << endl;
    }
    
    
    
    
    delete [] vet;
  }
  
  return 0;
}
