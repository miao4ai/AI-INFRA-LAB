#include "integer.h"

Integer::Integer(){
    m_pInt = new int(0);
}

Integer::Integer(int value){
    m_pInt = new int(value);
}

Integer::Integer(Integer &obj){
    m_pInt = new int(*obj.m_pInt);
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
    delete m_pInt;
}
int Integer::GetValue() const{
    return *m_pInt;
}

void Integer::SetValue(int value){
    *m_pInt = value;
}
