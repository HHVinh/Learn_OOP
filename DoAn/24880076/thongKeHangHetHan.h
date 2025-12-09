#ifndef THONGKEHANGHETHAN_H
#define THONGKEHANGHETHAN_H

#include <string>
#include "thongKe.h"
#include "quanLyMatHang.h"
using namespace std;

class ThongKeHangHetHan : public ThongKe 
{
private:

public:
	void Update() override;
	void XuatThongKe() override;
};

#endif