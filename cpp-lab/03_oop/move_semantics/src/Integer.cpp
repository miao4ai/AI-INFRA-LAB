#include "Integer.h"
#include <iostream>

Integer::Integer(){
    std::cout << "Integer()" << std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value){
    std::cout << "Integer(int)" << std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer &obj){
    std::cout << "Integer(Integer &obj)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj){
    std::cout << "Integer(Interger && obj)" <<std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer& Integer::operator=(const Integer& obj){
    if (this == &obj) {            // 1) 自赋值保护：a = a 时直接返回
        return *this;
    }
    delete m_pInt;                 // 2) 释放自己原来的内存，避免泄漏
    m_pInt = new int(*obj.m_pInt); // 3) 深拷贝 obj 的值
    return *this;                  // 4) 返回自己，支持链式赋值
}

Integer::~Integer(){
    std::cout<<"~integer()"<<std::endl;
    delete m_pInt;
}
int Integer::GetValue() const{
    return *m_pInt;
}

void Integer::SetValue(int value){
    *m_pInt = value;
}
