#include <stdio.h>
#include "lopPhanSo.h"

void lopPhanSo::nhapPhanSo()
{
    printf("Nhập tử số: ");
    scanf("%d", &tuSo);
    printf("Nhập mẫu số: ");
    scanf("%d", &mauSo);
}

lopPhanSo lopPhanSo::cong(lopPhanSo b)
{
    lopPhanSo kq;

    kq.tuSo = tuSo * b.mauSo + mauSo*b.tuSo;
    kq.mauSo = mauSo * b.mauSo;

    return kq;
}

void lopPhanSo::inPhanSo()
{
    printf("%d/%d", tuSo, mauSo);
}

void lopPhanSo::ganTuSo(int t)
{
    tuSo = t;
}

int lopPhanSo::inTuSo()
{
    return tuSo;
}

void lopPhanSo::ganMauSo(int m)
{
    if(m != 0) mauSo = m;
}

int lopPhanSo::inMauSo()
{
    return mauSo;
}

lopPhanSo::lopPhanSo()
{
    tuSo = 0;
    mauSo = 1;
}

lopPhanSo::lopPhanSo(int t, int m)
{
    tuSo = t;
    if (m != 0)
    {
        mauSo = m;
    }
    else
    {
        mauSo = 1;
    }
}

lopPhanSo::lopPhanSo(lopPhanSo &p)
{
    tuSo = p.tuSo;
    mauSo = p.mauSo;
}