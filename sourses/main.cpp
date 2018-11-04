// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#include "stack.hpp"
int main(){
    stack1<std::pair<int, std::string>> st;
    st.push_emplace(4, "hello");
    std::pair<int, std::string> pair1 = st.get_value(0);
    std::pair<int, std::string> result{4, "hello"};
    std::cout << pair1.first <<std::endl;
}
