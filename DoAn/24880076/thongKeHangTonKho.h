#ifndef THONGKEHANGTONKHO_H
#define THONGKEHANGTONKHO_H

#include "thongKe.h"
#include "quanLyMatHang.h"

class ThongKeHangTonKho : public ThongKe 
{
private:

public:
    void Update() override;
    void XuatThongKe() override;
};

#endif