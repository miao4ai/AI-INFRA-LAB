#include "integer.h"
#include <iostream>

using namespace std;
int main(){
    Integer i(5);
    Integer i2(i);          // 拷贝构造：i2 是新对象，用 i 初始化
    cout << i2.GetValue() << endl;   // 5

    Integer i3(100);        // i3 先有自己的值 100
    i3 = i;                 // 拷贝赋值：i3 已存在，把 i 的值搬进来（走 operator=）
    cout << i3.GetValue() << endl;   // 5
}