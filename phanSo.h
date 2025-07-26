#include <stdio.h>

typedef struct phanSo
{
    int TuSo;
    int MauSo;
} phanSo;

void nhapPhanSo(phanSo &a);
phanSo congHaiPhanSo(phanSo &a, phanSo &b);
void inPhanSo(phanSo a);