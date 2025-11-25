#include "FileInfo.h"

FileInfo::FileInfo()
{
    m_size = 0;
}

FileInfo::~FileInfo()
{
    cout << "\nHàm hủy của FileInfo";
}

FileInfo::FileInfo(int size)
{
    m_size = size;
}

int FileInfo::getSize()
{
    return m_size;
}