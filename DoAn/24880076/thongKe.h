#ifndef THONGKE_H
#define THONGKE_H

#include <iostream>
#include "Observer.h"
#include "quanLyMatHang.h"
using namespace std;

class ThongKe 
{
private:

public:
	ThongKe();
	virtual ~ThongKe();
	virtual void Update() = 0;
	virtual void XuatThongKe() = 0;

};

#endif