#ifndef CMYARR_H
#define CMYARR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CMyArr
{
    private: 
        vector<int> m_danhSach;

    public:
        CMyArr();
        ~CMyArr();
        void Add(int t);
        int Min();
        int operator[](int index);
};

#endif