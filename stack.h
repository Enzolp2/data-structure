#ifndef STACK_H
#define STACK_H

#include <cstddef>

namespace structures 
{
   template<typename T>
   class ArrayStack {
   public:
      // Construtores e Destrutores
      ArrayStack();
      explicit ArrayStack(std::size_t max);
      ~ArrayStack();

      void push(const T& data); // empilha
      T pop(); // desempilha
      T& top(); // retorna o topo
      void clear(); // limpa a pilha
      std::size_t size(); // retorna o tamanho
      std::size_t max_size(); // retorna o tamanho maximo
      bool empty(); // verifica se esta vazia
      bool full(); // verifica se esta cheia
   private:
      T* contents;
      int top_;
      std::size_t max_size_;
      static const auto DEFAULT_SIZE = 10u;
   };
}

#endif // STACK_H
