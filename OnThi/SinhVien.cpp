#include "SinhVien.h"

SinhVien::SinhVien()
{
}

SinhVien::~SinhVien()
{
}

void SinhVien::nhapThongTin()
{
    cout << "\nNhap MSSV: ";
    cin >> m_MSSV;
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, m_hoVaTen);
    cout <<"Nhap diem trung binh: ";
    cin >> m_diemTrungBinh;
}

double SinhVien::getDiemTrungBinh() const
{
    return m_diemTrungBinh;
}

void SinhVien::xuatThongTin() const
{
    cout << "\nMSSV: " << m_MSSV << " - Ho va ten: " << m_hoVaTen << " - Diem trung binh: " << m_diemTrungBinh;
}
