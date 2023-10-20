#include "queue.h"
#include <stdexcept>

using namespace structures;

template<typename T>
ArrayQueue<T>::ArrayQueue() {
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
    begin_ = 0;
    end_ = -1;
    size_ = 0;
}

template<typename T>
ArrayQueue<T>::ArrayQueue(std::size_t max) {
    max_size_ = max;
    contents = new T[max_size_];
    begin_ = 0;
    end_ = -1;
    size_ = 0;
}

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete [] contents;
}

template<typename T>
void ArrayQueue<T>::enqueue(const T& data) {
    if (full()) {
        throw std::out_of_range("Fila cheia!");
    } else {
        end_ = (end_ + 1) % max_size_;
        contents[end_] = data;
        size_++;
    }
}

template<typename T>
T ArrayQueue<T>::dequeue() {
    T data;
    if (empty()) {
        throw std::out_of_range("Fila vazia!");
    } else {
        data = contents[begin_];
        begin_ = (begin_ + 1) % max_size_;
        size_--;
        return data;
    }
}

template<typename T>
T& ArrayQueue<T>::back() {
    if (empty()) {
        throw std::out_of_range("Fila vazia!");
    } else {
        return contents[end_];
    }
}

template<typename T>
void ArrayQueue<T>::clear() {
    begin_ = 0;
    end_ = -1;
    size_ = 0;
}

template<typename T>
std::size_t ArrayQueue<T>::size() {
    return size_;
}

template<typename T>
std::size_t ArrayQueue<T>::max_size() {
    return max_size_;
}

template<typename T>
bool ArrayQueue<T>::empty() {
    return (size_ == 0);
}

template<typename T>
bool ArrayQueue<T>::full() {
    return (size_ == max_size_);
}
