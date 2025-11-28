#include "HinhChuNhat.h"

HinhChuNhat::HinhChuNhat(/* args */)
{
}

HinhChuNhat::~HinhChuNhat()
{
}

void HinhChuNhat::nhapHinh()
{
    cout << "\nNhap toa do dinh A: ";
    m_A.NhapToaDo();
    cout << "\nNhap toa do dinh B: ";
    m_B.NhapToaDo();
    cout << "\nNhap toa do dinh C: ";
    m_C.NhapToaDo();
    cout << "\nNhap toa do dinh D: ";
    m_D.NhapToaDo();
}

bool HinhChuNhat::hinhYeuCau()
{   
    if (m_A.DiemToaDo()) return true;
    if (m_B.DiemToaDo()) return true;
    if (m_C.DiemToaDo()) return true;
    if (m_D.DiemToaDo()) return true;

    int trucXTrai = 0, trucXPhai = 0, trucYTren = 0, trucYDuoi = 0;

    if (m_A.DiemTrucXTrai()) trucXTrai++;
    if (m_A.DiemTrucXPhai()) trucXPhai++;
    if (m_A.DiemTrucYTren()) trucYTren++;
    if (m_A.DiemTrucYDuoi()) trucYDuoi++;

    if (m_B.DiemTrucXTrai()) trucXTrai++;
    if (m_B.DiemTrucXPhai()) trucXPhai++;
    if (m_B.DiemTrucYTren()) trucYTren++;
    if (m_B.DiemTrucYDuoi()) trucYDuoi++;

    if (m_C.DiemTrucXTrai()) trucXTrai++;
    if (m_C.DiemTrucXPhai()) trucXPhai++;
    if (m_C.DiemTrucYTren()) trucYTren++;
    if (m_C.DiemTrucYDuoi()) trucYDuoi++;

    if (m_D.DiemTrucXTrai()) trucXTrai++;
    if (m_D.DiemTrucXPhai()) trucXPhai++;
    if (m_D.DiemTrucYTren()) trucYTren++;
    if (m_D.DiemTrucYDuoi()) trucYDuoi++;

    if (trucXTrai && trucXPhai || trucYTren & trucYDuoi) return true;

    int trenTrai = 0, duoiTrai = 0, trenPhai = 0, duoiPhai = 0;
    
    if (m_A.DiemTrenTrai()) trenTrai++;
    if (m_A.DiemTrenPhai()) trenPhai++;
    if (m_A.DiemDuoiTrai()) duoiTrai++;
    if (m_A.DiemDuoiPhai()) duoiPhai++;

    if (m_B.DiemTrenTrai()) trenTrai++;
    if (m_B.DiemTrenPhai()) trenPhai++;
    if (m_B.DiemDuoiTrai()) duoiTrai++;
    if (m_B.DiemDuoiPhai()) duoiPhai++;

    if (m_C.DiemTrenTrai()) trenTrai++;
    if (m_C.DiemTrenPhai()) trenPhai++;
    if (m_C.DiemDuoiTrai()) duoiTrai++;
    if (m_C.DiemDuoiPhai()) duoiPhai++;

    if (m_D.DiemTrenTrai()) trenTrai++;
    if (m_D.DiemTrenPhai()) trenPhai++;
    if (m_D.DiemDuoiTrai()) duoiTrai++;
    if (m_D.DiemDuoiPhai()) duoiPhai++;

    if (trenTrai != 1 || trenPhai != 1 || duoiTrai != 1 || duoiPhai != 1)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
