#ifndef LOPPHANSO_H
#define LOPPHANSO_H

// Định nghĩa lớp phân số
class lopPhanSo
{
public:
    int tuSo;    // tử số
    int mauSo;   // mẫu số

    void nhapPhanSo();              // Hàm nhập phân số
    lopPhanSo cong(lopPhanSo b);    // Hàm cộng hai phân số
    void inPhanSo();                // Hàm in phân số
};

#endif
