#include <stdio.h>
#include "LOPPHANSO2.h"
#include "LOPDIEM3.h"
#include "LOPTAMGIAC3.h"
#include "LOPDAGIAC3.h"
#include "LOPMANG.h"

// int main()
// {   
    // // LẬP TRÌNH HƯỚNG THỦ TỤC
    // // Khai báo 2 phân số
    // PhanSo a, b;

    // // Nhập hai phân số
    // NhapPhanSo(a);
    // NhapPhanSo(b);

    // // Cộng hai phân số
    // PhanSo ketQua;
    // ketQua = CongHaiPhanSo(a, b);
    
    // // Xuất kết quả:
    // printf("Kết quả là: ");
    // XuatPhanSo(ketQua);


    // LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG (Đối tượng bao gồm HÀNH ĐỘNG + DỮ LIỆU)
    // Các đối tượng thực hiện hành động
    // LOPPHANSO a, b;

    // // Yêu cầu đối tượng a thực hiện hành động nhập
    // a.NhapPhanSo();
    // b.NhapPhanSo();

    // // Yêu cầu đối tượng a + b
    // LOPPHANSO ketQua;
    // ketQua = a.Cong(b);
    
    // // Yêu cầu đối tượng ketQua xuat ra kết quả
    // printf("Kết quả là: ");
    // ketQua.XuatPhanSo();

    // LOPDIEM a, b;

    // // Yêu cầu nhập đối tượng a, b
    // a.NhapDiem();
    // b.NhapDiem();

    // // Yêu cầu đối tượng a tính khoảng cách với b
    // double ketQua;
    // ketQua = a.TinhKhoangCach(b);

    // // Yêu cầu đối tượng ketQua xuất kết quả
    // printf("Kết quả điểm A(%d, %d) + điểm B(%d, %d) = %0.2lf", a.x, a.y, b.x, b.y, ketQua);

    // LOPTAMGIAC tg;

    // // Yêu cầu nhập đối tượng A, B, C
    // tg.Nhap();

    // // Yêu cầu tg tính chu vi
    // double chuVi = tg.TinhChuVi();
    // printf("Kết quả là: %0.2lf", chuVi);

    // LOPDAGIAC dg;

    // //  Yêu cầu nhập đa giác
    // dg.nhapDG();

    // // Yêu cầu tính chu vi đa giác
    // double chuVi =  dg.TinhChuViDG();
    // printf("Kết quả chu vi đa giác %d đỉnh là: %0.2lf", dg.SoLuongDinh, chuVi);

    // LOPPHANSO p1;
    // p1.GanTuSo(1);
    // p1.GanMauSo(2);

    // LOPPHANSO ::DocThanhPhanTinh();

    // LOPPHANSO p1;
    // LOPPHANSO p2(2,3);
    // LOPPHANSO p3;
    
    // LOPPHANSO cong, tru, nhan, chia;
    // cong = p1 + p2;
    // cong.XuatPhanSo();

    // tru = p1 - p2;
    // tru.XuatPhanSo();

    // nhan = p1 * p2;
    // nhan.XuatPhanSo();

    // chia = p1 / p2;
    // chia.XuatPhanSo();

    // if (p3 > p2)
    // {    
    //     printf("\nPhân số p3 lớn hơn p2");
    // }
    // else if (p3 < p2)
    // {    
    //     printf("\nPhân số p3 nhỏ hơn p2");
    // }
    // else if (p3 == p2)
    // {    
    //     printf("\nHai phân số bằng nhau");
    // }
    // else
    // {
    //     printf("\nHai phân số khác nhau");
    // }

    // p3 = p2;
    // p3.XuatPhanSo();

    // LOPMANG arr, arr2;

    // arr.Add(1);
    // arr.Add(2);
    // arr.Add(3);

    // arr.XuatMang();

    // arr2 = arr;
    // arr2.XuatMang();    

//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// template <typename T>
//     class Box {
//     public:
//         T value;
//         Box(T v) {
//         value = v;
//         }
//         void show() {
//         cout << "Value: " << value << "\n";
//         }
//     };

// int main()
// {
    // string s1("abcdefgh");
    // string s2("Abcdefgh");

    // if (s1 == s2)
    // {
    //     cout << "Bằng" << endl;
    // } else
    // {
    //     cout << "Không bằng" << endl;
    // }

    // s2 = s1.substr(4,4);
    // cout << s2 << endl;

    // string s3 = s1 + s2;
    // cout << s3 << endl;

    // string s;
    // s.append(s1 + s2 + s3);

    // cout << s << endl;

    // vector<int>arr;

    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);

    // cout << "Danh sách mảng: ";
    // for (int i = 0; i < arr.size(); i ++)
    // {
    //     cout << arr[i] << " ";
    // }


    // Box<int> intBox(50);
    // Box<string> strBox("Hellox");

    // intBox.show();
    // strBox.show();

    // return 0;
// }


// #include <iostream>
// #include <string>
// #include "NHANVIEN.h"
// #include "CONGTY.h"
// using namespace std;

// int main()
// {
    // NHANVIEN* p;
    // NHANVIENSX* pNVSX;
    // NHANVIENVP* pNVVP;

    // p = new NHANVIEN();
    // p->NhapNV();
    // p->HamAo();

    // pNVSX = new NHANVIENSX();
    // pNVSX->NhapNV();
    // pNVSX->HamAo();

    // p = pNVSX;
    // p->NhapNV();
    // p->HamAo();

    // pNVVP = new NHANVIENVP();
    // pNVVP->NhapNV();
    // pNVVP->HamAo();

    // p = pNVVP;
    // p->NhapNV();
    // p->HamAo();

    // CONGTY a;
    // a.Nhap();
    // double ketQua = a.TongLuong();
    // cout << "Tổng lương là: " << ketQua;

//     return 0;
// }

#include <iostream>
#include <string>
#include "LOPDIEM3.h"
#include "HINH.h"
#include "HINHCHUNHAT.h"
#include "HINHTRON.h"
#include "MATPHANG.h"
#include "APPSETTING.h"
#include "FileInfo.h"
#include "FileSystem.h"
#include "Folder.h"
using namespace std;

int main()
{
    // MATPHANG a;

    // a.nhap();
    // double ketQua = a.tongChuVi();
    // cout << "Kết quả tổng chu vi là: " << ketQua;

    // APPSETTING* p1 = APPSETTING::getInstance();

    FileInfo* log1 = new FileInfo(100);
    FileInfo* log2 = new FileInfo(200);
    FileInfo* log3 = new FileInfo(300);
    FileInfo* log4 = new FileInfo(400);

    Folder* HoChiMinh = new Folder();
    Folder* south = new Folder();
    Folder* north = new Folder();
    Folder* HaNoi = new Folder();
    Folder* VietNam = new Folder();

    VietNam->add(south);
    VietNam->add(north);
    VietNam->add(log4);

    south->add(HoChiMinh);
    HoChiMinh->add(log1);
    HoChiMinh->add(log2);

    north->add(HaNoi);
    HaNoi->add(log3);

    int totalSize = VietNam->getSize();
    cout << "Tổng kích thước là: " << totalSize;

    delete VietNam;

    return 0;
}