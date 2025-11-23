#include <stdio.h>
#include "LOPMANG.h"

LOPMANG ::LOPMANG()
{
    m_arr = NULL;
    m_size = 0;
}

// BẮT BUỘC PHẢI CÓ KHI THÀNH PHẦN LÀ CON TRỎ CẤP PHÁT ĐỘNG
LOPMANG ::LOPMANG(const LOPMANG &b)
{
    m_size = b.m_size;

    if (m_size > 0)
    {
        m_arr = new int[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_arr[i] = b.m_arr[i];
        }
    }
    else
    {
        m_arr = nullptr;
    }
}

// BẮT BUỘC PHẢI CÓ KHI THÀNH PHẦN LÀ CON TRỎ CẤP PHÁT ĐỘNG
void LOPMANG::operator=(const LOPMANG &b)
{
    if(this == &b)
    {
        return;
    }

    delete [] m_arr; // Xóa vùng nhớ cũ nếu có

    m_size = b.m_size;

    if (m_size > 0)
    {
        m_arr = new int[m_size];
        for(int i = 0; i < m_size; i++)
        {
            m_arr[i] = b.m_arr[i];
        }
    }
    else
    {
        m_arr = nullptr;
    }
}

// BẮT BUỘC PHẢI CÓ KHI THÀNH PHẦN LÀ CON TRỎ CẤP PHÁT ĐỘNG
LOPMANG ::~LOPMANG()
{
    delete [] m_arr;
}

void LOPMANG ::Add(int value)
{   
    int* newArr = new int[m_size + 1];
    if (m_size > 0)
    {
        for (int i = 0; i < m_size; i++)
        {
            newArr[i] = m_arr[i];
        }
    }
    newArr[m_size] = value;
    delete [] m_arr;
    m_arr = newArr;
    m_size ++;
}

int LOPMANG ::GetSize()
{
    return m_size;
}

int& LOPMANG::operator[](int index)
{
    if (index < 0 || index >= m_size)
        throw "out of index";
    return m_arr[index];
}

void LOPMANG ::XuatMang()
{
    printf("\nDanh sách mảng: \n");
    for (int i = 0; i < m_size; i++)
    {
        printf("%d ", m_arr[i]);
    }
}

void LOPMANG ::InsertAt()
{
    int k, value;
    printf("\n\nNhap so can chen: ");
    scanf("%d", &value);
    do
    {
        printf("Nhap vi tri can chen (tu 0 den %d): ", m_size);
        scanf("%d", &k);
    } while (k < 0 || k > m_size);

    int* newArr = new int[m_size + 1];

    for(int i = 0; i < k; i ++)
    {
        newArr[i] = m_arr[i];
    }
    
    newArr[k] = value;
    
    for(int i = k + 1; i <= m_size; i ++)
    {
        newArr[i] = m_arr[i-1];
    }

    delete [] m_arr;
    m_arr = newArr;
    m_size ++;
}
