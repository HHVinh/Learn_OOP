#include "Folder.h"

Folder::Folder()
{
    m_numberOfChild = 0;
}

Folder::~Folder()
{
    cout << "\nHàm hủy của Folder";
    for (int i = 0; i < m_numberOfChild; i++)
    {
        delete m_childList[i];
    }
}

void Folder::add(FileSystem* child)
{
    m_numberOfChild++;
    m_childList[m_numberOfChild - 1] = child;
}

int Folder::getSize()
{
    int totalSize = 0;
    for (int i = 0; i < m_numberOfChild; i++)
    {
        totalSize += m_childList[i]->getSize();
    }
    return totalSize;
}