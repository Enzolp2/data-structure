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
    // Implementação do método push
}

template<typename T>
T structures::ArrayStack<T>::pop() {
    // Implementação do método pop
}

template<typename T>
T& structures::ArrayStack<T>::top() {
    // Implementação do método top
}

template<typename T>
void structures::ArrayStack<T>::clear() {
    // Implementação do método top
}

template<typename T>
std::size_t structures::ArrayStack<T>::size() {
    // Implementação do método size
}

template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
    // Implementação do método max_size
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    // Implementação do método empty
}

template<typename T>
bool structures::ArrayStack<T>::full() {
    // Implementação do método top
}