#pragma once
class Integer{
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(Integer &obj);
    Integer& operator=(const Integer& obj);   // 拷贝赋值：你来实现
    ~Integer();
    int GetValue() const;
    void SetValue(int value);
};