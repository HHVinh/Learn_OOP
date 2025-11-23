#ifndef NHAVIEN_H
#define NHAVIEN_H

#include <string>
using namespace std;

class NHANVIEN
{
private:
    string HoTen;
    string DiaChi;
    
public:
    // Hàm tạo không đối số
    NHANVIEN();
    // Hàm tạo một đối số
    NHANVIEN(int t);
    // Hàm tạo sao chép
    NHANVIEN(const NHANVIEN& b);
    //  Toán tử gán =
    void operator=(const NHANVIEN& b);
    // Hàm ảo
    virtual void HamAo();

    void NhapNV();
    ~NHANVIEN();
};

#endif