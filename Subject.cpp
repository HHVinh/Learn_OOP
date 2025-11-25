#include "Subject.h"

Subject::Subject()
{
    m_soLuong = 0;
}

Subject::~Subject()
{

}

void Subject::Attach(Observer* observer)
{
    // m_soLuong;
    // m_danhSach[m_soLuong - 1] = observer;

    if (m_soLuong < 100) {
        m_danhSach[m_soLuong] = observer;
        m_soLuong++;  // ✅ Tăng số lượng sau khi gán
    }

}

void Subject::Detach(Observer* observer)
{
    // Tìm và xóa observer khỏi danh sách
    for (int i = 0; i < m_soLuong; i++) {
        if (m_danhSach[i] == observer) {
            // Dịch chuyển các phần tử phía sau lên
            for (int j = i; j < m_soLuong - 1; j++) {
                m_danhSach[j] = m_danhSach[j + 1];
            }
            m_soLuong--;
            break;
        }
    }

}

void Subject::Notify()
{
    for (int i = 0; i < m_soLuong; i++)
    {
        m_danhSach[i]->Update();
    }

}