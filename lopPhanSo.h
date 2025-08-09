#ifndef LOPPHANSO_H
#define LOPPHANSO_H

// Định nghĩa lớp phân số
class lopPhanSo
{
private:
    int tuSo;    // tử số
    int mauSo;   // mẫu số

public:
    lopPhanSo();
    lopPhanSo(int t, int m);
    lopPhanSo(lopPhanSo &p);    

    void nhapPhanSo();              // Hàm nhập phân số
    lopPhanSo cong(lopPhanSo b);    // Hàm cộng hai phân số
    void inPhanSo();                // Hàm in phân số

    void ganTuSo(int t);
    int inTuSo();
    void ganMauSo(int m);
    int inMauSo();
};

#endif
