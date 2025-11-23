#include <stdio.h>
#include "LOPPHANSO2.h"

int LOPPHANSO::ThanhPhanTinh = 0;

void LOPPHANSO ::NhapPhanSo()
{
    printf("Nhập tử số: ");
    scanf("%d", &tuSo);
    do
    {
        printf("Nhập mẫu số: ");
        scanf("%d", &mauSo); 
    } while (mauSo == 0);
      
}

LOPPHANSO LOPPHANSO ::operator+(const LOPPHANSO &b)
{
    LOPPHANSO ketqua;
    ketqua.tuSo = tuSo * b.mauSo + b.tuSo * mauSo;
    ketqua.mauSo = mauSo * b.mauSo;
    return ketqua;
}

LOPPHANSO LOPPHANSO ::operator-(const LOPPHANSO &b)
{
    LOPPHANSO ketqua;
    ketqua.tuSo = tuSo * b.mauSo - b.tuSo * mauSo;
    ketqua.mauSo = mauSo * b.mauSo;
    return ketqua;
}

LOPPHANSO LOPPHANSO ::operator*(const LOPPHANSO &b)
{
    LOPPHANSO ketqua;
    ketqua.tuSo = tuSo * b.tuSo;
    ketqua.mauSo = mauSo * b.mauSo;
    return ketqua;
}

LOPPHANSO LOPPHANSO ::operator/(const LOPPHANSO &b)
{
    LOPPHANSO ketqua;
    ketqua.tuSo = tuSo * b.mauSo;
    ketqua.mauSo = mauSo * b.tuSo;
    return ketqua;
}

bool LOPPHANSO ::operator>(const LOPPHANSO &b)
{
    int t1, t2;
    t1 = tuSo * b.mauSo;
    t2 = mauSo * b.tuSo;
    return t1 > t2; 
}

bool LOPPHANSO ::operator<(const LOPPHANSO &b)
{
    int t1, t2;
    t1 = tuSo * b.mauSo;
    t2 = mauSo * b.tuSo;
    return t1 < t2; 
}

bool LOPPHANSO ::operator==(const LOPPHANSO &b)
{
    int t1, t2;
    t1 = tuSo * b.mauSo;
    t2 = mauSo * b.tuSo;
    return t1 == t2; 
}

bool LOPPHANSO ::operator!=(const LOPPHANSO &b)
{
    int t1, t2;
    t1 = tuSo * b.mauSo;
    t2 = mauSo * b.tuSo;
    return t1 != t2; 
}

void LOPPHANSO ::operator=(const LOPPHANSO &b)
{   
    // This là con trỏ, trỏ tới đối tượng gọi hàm
    if (this != &b) // Chỉ thực hiện khi 2 đối tượng khác nhau
    {
        tuSo = b.tuSo;
        mauSo = b.mauSo;
    }
}

void LOPPHANSO ::XuatPhanSo()
{
    printf("\n%d/%d", tuSo, mauSo);
}

void LOPPHANSO ::GanTuSo(int t)
{
    tuSo = t;
}

int LOPPHANSO ::DocTuSo()
{
    return tuSo;
}

void LOPPHANSO ::GanMauSo(int m)
{
    if (m != 0)
    {
        mauSo = m;
        if (mauSo < 0)
        {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }
}

int LOPPHANSO ::DocMauSO() 
{
    return mauSo;
}

LOPPHANSO ::LOPPHANSO()
{
    tuSo = 0;
    mauSo = 1;
}

LOPPHANSO ::LOPPHANSO(int t, int m)
{
    tuSo = t;
    if (mauSo != 0)
    {
        mauSo = m;
        if (mauSo < 0)
        {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }
    else
    {
        mauSo = 1;
    }
}

LOPPHANSO ::LOPPHANSO(const LOPPHANSO &p)
{
    tuSo = p.tuSo;
    mauSo = p.mauSo;
}

LOPPHANSO ::~LOPPHANSO()
{
    // printf("\nHủy đối tượng!");
}

int LOPPHANSO ::DocThanhPhanTinh()
{
    return ThanhPhanTinh;
}
