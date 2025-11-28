#include "LopHoc.h"
LopHoc::LopHoc()
{
}

LopHoc::~LopHoc()
{
}

void LopHoc::nhapThongTin()
{
    int n;
    cout << "\nNhập số lượng sinh viên: ";
    cin >> n;

    for (int i = 0; i < n; i ++)
    {   
        cout << "\nNhập thông tin sinh viên thứ "<< i + 1 << ": ";
        SinhVien sv;
        sv.nhapThongTin();
        m_DanhSachSV.push_back(sv);
    }
}

void LopHoc::xuatThongTin()
{
    cout << "\n=== DANH SÁCH SINH VIÊN ===";
    for (int i = 0; i < m_DanhSachSV.size(); i++)
    {
        cout << "\nSinh viên thứ "<< i + 1 << ": ";
        m_DanhSachSV[i].xuatThongTin();
    }
}

void LopHoc::xuatSVGioi()
{
    double tb;
    bool coSV = false;
    cout << "\nNhập điểm trung bình thấp nhất mong muốn: ";
    cin >> tb;

    cout << "\n === DANH SÁCH SINH VIÊN THEO YÊU CẦU ==";
    for (int i = 0; i < m_DanhSachSV.size(); i++)
    {
        if (m_DanhSachSV[i].getDiemTrungBinh() > tb)
        {
            cout << "\nSinh viên thứ "<< i + 1 << ":";
            m_DanhSachSV[i].xuatThongTin();
            coSV = true;
        }
    }

    if (!coSV)
    {
        cout << "\nKhông có sinh viên nào đạt yêu cầu.";
    }
}