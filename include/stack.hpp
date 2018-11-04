// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <iostream>
#include <cstddef>
#include <stack>

template <typename T>
class stack {
  std::size_t capacity;
  T* array;
public:
  stack();
  void push(T&& value);
  void push(const T& value);
  void pop();
  std::size_t get_capacity();
  const T& head() const;
  const T& get_element(unsigned index) const;
  ~stack();
};

template <typename T>
stack<T>::stack(){
    capacity = 0;
    array = nullptr;
}

template <typename T>
std::size_t stack<T>::get_capacity(){
    return capacity;
}

template <typename T>
void stack<T>::push(T&& value){
    if (array == nullptr){
        capacity++;
        array = new T[capacity];
        array[0] = std::move(value);
    } else {
        T* help_array = new T[capacity];
        for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        delete[] array;
        capacity++;
        array = new T[capacity];
        for (unsigned i = 0; i < capacity-1; ++i){
            array[i] = help_array[i];
        }
        delete[] help_array;
        array[capacity-1] = std::move(value);
    }
}

template <typename T>
void stack<T>::push(const T& value){
if (array == nullptr){
        capacity++;
        array = new T[capacity];
        array[0] = value;
    } else {
        T* help_array = new T[capacity];
        for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        delete[] array;
        capacity++;
        array = new T[capacity];
        for (unsigned i = 0; i < capacity-1; ++i){
            array[i] = help_array[i];
        }
        delete[] help_array;
        array[capacity-1] = value;
    }
    }

template <typename T>
void stack<T>::pop(){
    if (array == nullptr) return;
    T* help_array = new T[capacity];
    for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        delete[] array;
    capacity--;
    if (capacity == 0){
        array = nullptr;
        return;
    }
    array = new T[capacity];
    for (unsigned i = 0; i < capacity; ++i){
            array[i] = help_array[i];
        }
    delete[] help_array;
}


template <typename T>
const T& stack<T>::head() const{
    return array[0];
}

template <typename T>
const T& stack<T>::get_element(unsigned index) const{
    return array[index];
}

template <typename T>
stack<T>::~stack(){
    if (array != nullptr)
    delete[] array;
}

template<typename T>
class stack1
{
  std::size_t capacity;
  T* array;
public:
template <typename... Args>
  void push_emplace(Args&&... args);
  stack1();
  void push(T&& value);
  const T& head() const;
  void pop();
  const T& get_value(unsigned index) const;
  std::size_t get_capacity();
  ~stack1();
};

template <typename T>
stack1<T>::stack1(){
    capacity = 0;
    array = nullptr;
}

template <typename T>
template <typename ... Args>
void stack1<T>::push_emplace(Args&&... args){
if (array == nullptr){
        capacity++;
        array = new T[capacity];
        array[0] = T(std::forward<Args>(args)...);
    } else {
        T* help_array = new T[capacity];
        for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        delete[] array;
        capacity++;
        array = new T[capacity];
        for (unsigned i = 0; i < capacity-1; ++i){
            array[i] = help_array[i];
        }
        delete[] help_array;
        array[capacity-1] = T(std::forward<Args>(args)...);
    }
}

template <typename T>
const T& stack1<T>::get_value(unsigned index) const{
    return array[index];
}

template <typename T>
void stack1<T>::push(T&& value){
    if (array == nullptr){
        capacity++;
        array = new T[capacity];
        array[0] = std::move(value);
    } else {
        T* help_array = new T[capacity];
        for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        delete[] array;
        capacity++;
        array = new T[capacity];
        for (unsigned i = 0; i < capacity-1; ++i){
            array[i] = help_array[i];
        }
        delete[] help_array;
        array[capacity-1] = std::move(value);
    }
}

template <typename T>
const T& stack1<T>::head() const{
    return array[0];
}

template <typename T>
void stack1<T>::pop(){
if (array == nullptr){
    return;
}
    T* help_array = new T[capacity];
    for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        delete[] array;
    capacity--;
    if (capacity == 0){
        array = nullptr;
        return;
    }
    array = new T[capacity];
    for (unsigned i = 0; i < capacity; ++i){
            array[i] = help_array[i];
        }
    delete[] help_array;
}

template <typename T>
std::size_t stack1<T>::get_capacity(){
    return capacity;
}

template <typename T>
stack1<T>::~stack1(){
if (array != nullptr)
    delete[] array;
}

#endif // INCLUDE_STACK_HPP_
