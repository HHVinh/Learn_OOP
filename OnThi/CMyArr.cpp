#include "CMyArr.h"

CMyArr::CMyArr()
{
}

CMyArr::~CMyArr()
{

}

void CMyArr::Add(int t)
{
    m_danhSach.push_back(t);
}

int CMyArr::Min()
{   
    if (m_danhSach.empty())
    {
        return -1;
    }

    int minValue = m_danhSach[0], minIndex = 0;
    for (int i = 0; i < m_danhSach.size(); i++)
    {
        if (m_danhSach[i] < minValue)
        {
            minValue = m_danhSach[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int CMyArr::operator[](int index)
{
    if (m_danhSach.empty())
    {
        return -1;
    }
    return m_danhSach[index];
}