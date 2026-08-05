#include "integer.h"

Integer::Integer(){
    m_pInt = new int(0);
}

Integer::Integer(int value){
    m_pInt = new int(value);
}

int Integer::GetValue() const{
    return *m_pInt;
}

void Integer::SetValue(int value){
    *m_pInt = value;
}
