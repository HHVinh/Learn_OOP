#include <iostream>
#include <string>
using namespace std;

// 2024 - 2025 - HK2 - Câu 1
// #include "CMyArr.h"

// int main()
// {
//     CMyArr arr; // Khởi tạo một đối tượng CMyArr
//     arr.Add(5);
//     arr.Add(4);
//     arr.Add(9);
//     arr.Add(6);

//     // Tìm chỉ số của phần tử nhỏ nhất
//     int minIndex = arr.Min();

//     // Kiểm tra xem mảng có rỗng không trước khi in
//     if (minIndex != -1)
//     {
//         // In ra giá trị của phần tủe nhỏ nhất sửa dụng toán tử []
//         cout << arr[minIndex] << endl;
//     }
//     else
//     {
//         cout << "Mang rong." << endl;
//     }

//     return 0;
// }


// 2024 - 2025 - HK2 - Câu 2

// #include "ThongTinChung.h"
// #include "ManHinh.h"
// #include "MayChieu.h"
// #include "Tivi.h"

// int main()
// {
//     // Trong hàm main hoặc nơi sử dụng
//     ManHinh manHinh;
//     manHinh.setTenThietBi("Man hinh LCD");
//     manHinh.setMaThietBi("MH001");
//     manHinh.setTrangThai("Dang bat");
//     manHinh.disPlayContent("Man hinh do phan giai 4K");

//     MayChieu mayChieu;
//     mayChieu.setTenThietBi("May chieu phong hop");
//     mayChieu.disPlayContent("Slide PowerPoint ve du an XYZ");
//     // Output: Màn hình 'May chieu phong hop' đang hiển thị: 'Slide PowerPoint ve du an XYZ'

//     Tivi tv;
//     tv.setTenThietBi("Samsung 4K");
//     tv.disPlayContent("Phim 'Avengers: Endgame'");
//     // Output: Màn hình 'Samsung 4K' đang hiển thị: 'Phim Avengers: Endgame'

//     manHinh.displayInfo();
//     mayChieu.displayInfo();
//     tv.displayInfo();


//     ThongTinChung* devices[] = {new MayChieu(), new Tivi(), new ManHinh()};

//     for (auto device : devices) {
//         device->turnOn();           // Hành vi chung
//         device->disPlayContent("Hello");  // Hành vi chung  
//         device->displayInfo();      // Hành vi riêng - ĐA HÌNH
//     }

//     return 0;
// }



// 2024 - 2025 - HK1
// #include "SinhVien.h"
// #include "LopHoc.h"
// #include "MatPhang.h"
// #include "HTron.h"
// #include "HVuong.h"
// #include "HChuNhat.h"
// #include "QuanLyHinh.h"

// int main()
// {   
    // Câu 1
    // LopHoc lop;

    // lop.nhapThongTin();
    // lop.xuatThongTin();
    // lop.xuatSVGioi();


    // Câu 2 Không dùng QuanLyHinh
    // MatPhang* mp;
    
    // mp = new HTron();
    // mp->themHinh();
    // mp->tinhChuVi();
    // mp->tinhDienTich();
    // mp->xuatHinh();

    // mp = new HVuong();
    // mp->themHinh();
    // mp->tinhChuVi();
    // mp->tinhDienTich();
    // mp->xuatHinh();

    // mp = new HChuNhat();
    // mp->themHinh();
    // mp->tinhChuVi();
    // mp->tinhDienTich();
    // mp->xuatHinh();


    // Câu 2 Có dùng QuanLyHinh
//     QuanLyHinh quanLy;

//     quanLy.themHinh();
//     quanLy.xuatHinh();
    
//     return 0;
// }



// Học kì 2 - 2023 - 2024 Câu 1
// #include "PhanSoThi.h"
// #include "MangPhanSo.h"

// int main()
// {
//     MangPhanSo* arr = new MangPhanSo();
//     PhanSoThi p1;
//     PhanSoThi p2;
//     PhanSoThi p3;

//     p1.NhapPhanSo();
//     p2.NhapPhanSo();
//     p3.NhapPhanSo();

//     arr->themPhanSo(p1);
//     arr->themPhanSo(p2);
//     arr->themPhanSo(p3);

//     arr->inMangPhanSo();

//     arr->tinhTrungBinh();

//     p1.soSanh(0);

//     return 0;
// }


// Học kì 2 - 2023 - 2024 Câu 2
#include "ToaDo.h"
#include "HinhTron.h"
#include "HinhChuNhat.h"
#include "HinhHoc.h"
#include "DanhSachHinh.h"

int main()
{
    DanhSachHinh dsHinh;

    dsHinh.themHinh();
    cout << "\n\n === DANH SACH HINH ===";
    int soLuong = dsHinh.demSoLuong();
    cout << "\n\nSo luong hinh yeu cau: " << soLuong;
    

    return 0;
}
