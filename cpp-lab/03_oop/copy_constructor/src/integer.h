#pragma once
class Integer{
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    int GetValue() const;
    void SetValue(int value);
};