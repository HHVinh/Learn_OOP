#ifndef THONGTINCHUNG_H
#define THONGTINCHUNG_H

#include <iostream>
#include <string>
using namespace std;

class ThongTinChung
{
    private:
        string m_tenThietBi;
        string m_maThietBi;
        string m_trangThai;

    public:
        ThongTinChung();
        virtual ~ThongTinChung();

        
        virtual int turnOn();
        virtual int turnOff();
        virtual void disPlayContent(const string& content);
        
        virtual void getDeviceType() = 0;
        virtual void displayInfo() = 0;

        void xuatThongTin();

        void setTenThietBi(const string& ten);
        void setMaThietBi(const string& ma);
        void setTrangThai(const string& trangThai);

        string getTenThietBi() const;
        string getMaThietBi() const;
        string getTrangThai() const;
};

#endif