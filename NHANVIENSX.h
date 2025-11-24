#ifndef NHAVIENSX_H
#define NHAVIENSX_H

#include <string>
#include "NHANVIEN.h"
using namespace std;

class NHANVIENSX : public NHANVIEN
{
private:
    int SoLuong;
    
public:
    // Hàm tạo không đối số
    NHANVIENSX();
    // Hàm tạo một đối số
    NHANVIENSX(int t);
    // Hàm tạo sao chép
    NHANVIENSX(const NHANVIENSX& b);
    // Toán tử gán =
    void operator=(const NHANVIENSX& b);
    // Hàm ảo
    void HamAo() override;
    double TinhLuong() override;


    void NhapNV() override;
    ~NHANVIENSX();
};

#endif