#ifndef LOPMANG_H
#define LOPMANG_H

class LOPMANG
{
private:
    int* m_arr;
    int m_size;

public:
    LOPMANG();
    LOPMANG(const LOPMANG &b);

    void Add(int value);
    int GetSize();
    int& operator[](int index);
    void operator=(const LOPMANG &b);
    void XuatMang();
    void InsertAt();

    ~LOPMANG();

};
#endif