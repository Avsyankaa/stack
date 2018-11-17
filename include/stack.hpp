// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <cstddef>
#include <iostream>
#include <memory>
#include <stack>

template <typename T>
class stack {
public:
  stack();
  void push(T&& value);
  void push(const T& value);
  template <typename... Args>
  void push_emplace(Args&&... args);
  void pop();
  std::size_t get_capacity();
  const T& head() const;
  const T& get_element(unsigned index) const;

private:
  std::size_t capacity;
  std::unique_ptr<T[]> array;
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
        array = make_unique<T[]> (capacity);
        array[0] = std::move(value);
    } else {
        std::unique_ptr<T[]> help_array = make_unique<T[]> (capacity);
        for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        capacity++;
        array = make_unique<T[]> (capacity);
        for (unsigned i = 0; i < capacity-1; ++i){
            array[i] = help_array[i];
        }
        array[capacity-1] = std::move(value);
    }
}

template <typename T>
void stack<T>::push(const T& value){
if (array == nullptr){
        capacity++;
        array = make_unique<T[]> (capacity);
        array[0] = value;
    } else {
        std::unique_ptr<T[]> help_array = make_unique<T[]> (capacity);
        for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        capacity++;
        array = make_unique<T[]> (capacity);
        for (unsigned i = 0; i < capacity-1; ++i){
            array[i] = help_array[i];
        }
        array[capacity-1] = value;
    }
    }

template <typename T>
template <typename ... Args>
void stack<T>::push_emplace(Args&&... args){
if (array == nullptr){
        capacity++;
        array = make_unique<T[]> (capacity);
        array[0] = T(std::forward<Args>(args)...);
    } else {
        std::unique_ptr<T[]> help_array = make_unique<T[]> (capacity);
        for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
        capacity++;
        array = make_unique<T[]> (capacity);
        for (unsigned i = 0; i < capacity-1; ++i){
            array[i] = help_array[i];
        }
        array[capacity-1] = T(std::forward<Args>(args)...);
    }
}

template <typename T>
void stack<T>::pop(){
    if (array == nullptr) return;
    std::unique_ptr<T[]> help_array = make_unique<T[]> (capacity);;
    for (unsigned i = 0; i < capacity; ++i){
            help_array[i] = array[i];
        }
    capacity--;
    if (capacity == 0){
        array = nullptr;
        return;
    }
    array = make_unique<T[]> (capacity);
    for (unsigned i = 0; i < capacity; ++i){
            array[i] = help_array[i];
        }
}


template <typename T>
const T& stack<T>::head() const{
    if (array == nullptr)
       throw std::runtime_error{"Stack is empty"};
    return array[0];
}

template <typename T>
const T& stack<T>::get_element(unsigned index) const{
    if (array == nullptr)
       throw std::runtime_error{"Stack is empty"};
    return array[index];
}

#endif // INCLUDE_STACK_HPP_
