#include <iostream>
#include "integer.h"

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

Integer Integer::operator+(const Integer & a) const{
    Integer temp;
    *temp.m_pInt = *m_pInt + *a.m_pInt;
    return temp;
}
