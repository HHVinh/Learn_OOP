class LOPPHANSO
{
private:
    // Thành phần dữ liệu
    int tuSo;
    int mauSo;

    // Thành phần tĩnh
    static int ThanhPhanTinh;

public:
    // Hàm tạo
    LOPPHANSO();
    LOPPHANSO(int t, int m);
    
    // Hàm tạo sao chép
    LOPPHANSO(const LOPPHANSO &p);
    
    // Thành phần xử lý
    void NhapPhanSo();
    void XuatPhanSo(); 
    void GanTuSo(int t);
    int DocTuSo();
    void GanMauSo(int m);
    int DocMauSO(); 
    static int DocThanhPhanTinh();
    ~LOPPHANSO();

    // Cách viết 1
    // LOPPHANSO Cong(LOPPHANSO b);

    // Cách viết 2
    LOPPHANSO operator+(const LOPPHANSO &b);
    LOPPHANSO operator-(const LOPPHANSO &b);
    LOPPHANSO operator*(const LOPPHANSO &b);
    LOPPHANSO operator/(const LOPPHANSO &b);

    bool operator>(const LOPPHANSO &b);
    bool operator<(const LOPPHANSO &b);
    bool operator==(const LOPPHANSO &b);
    bool operator!=(const LOPPHANSO &b);

    // Toán tử gán bằng
    void operator=(const LOPPHANSO &b);
};

