#ifndef NHAVIENVP_H
#define NHAVIENVP_H

#include <string>
#include "NHANVIEN.h"
using namespace std;

class NHANVIENVP : public NHANVIEN
{
private:
    double HeSoLuong;
    double PhuCap;
    
public:
    // Hàm tạo không đối số
    NHANVIENVP();
    // Hàm tạo 1 đối số
    NHANVIENVP(int t);
    // Hàm tạo sao chép
    NHANVIENVP(const NHANVIENVP& b);
    // Toán tử gán =
    void operator=(const NHANVIENVP& b);
    // Hàm ảo
    void HamAo();

    void NhapNV();
    double TinhLuongNVVP();
    ~NHANVIENVP();

};
#endif