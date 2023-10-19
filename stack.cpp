#include "stack.h"

template<typename T>
structures::ArrayStack<T>::ArrayStack() {
   ArrayStack(DEFAULT_SIZE);
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
    // Implementação do construtor com parâmetro
    max_size_ = max;
    contents = new T[max_size_];
    top_ = -1;
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
   // Implementação do destrutor
   delete [] contents;
}

template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    // Empilha o data na stack caso não esteja cheia
    if (full()) {
        throw std::out_of_range("Stack is Full");
    }
    top_++;
    contents[top_] = data;
}

template<typename T>
T structures::ArrayStack<T>::pop() {
    // Desempilha um elemento caso a stack não esteja vazia
    if (empty()) {
        throw std::out_of_range("Empty Stack");
    }
    T aux = contents[top_];
    top_--;
    return aux;
}

template<typename T>
T& structures::ArrayStack<T>::top() {
    // Retorna o dado do topo da stack
    if (empty()) {
        throw std::out_of_range("Empty Stack");
    }
    return contents[top_];
}

template<typename T>
void structures::ArrayStack<T>::clear() {
    // Limpa a stack
    top_ = -1;
}

template<typename T>
std::size_t structures::ArrayStack<T>::size() {
    // Retorna o o tamanho atual da stack
    return (top_ + 1);
}

template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
    // Retorna o o tamanho maximo da stack
    return max_size_;
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    // Verifica se a stack está vazia
    return (top_ == -1);
}

template<typename T>
bool structures::ArrayStack<T>::full() {
    // Verifica se a stack está cheia
    return (top_ == max_size() - 1);
}