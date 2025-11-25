#ifndef FILEINFO_H
#define FILEINFO_H
#include <iostream>
#include <string>
#include "FileSystem.h"
using namespace std;

class FileInfo : public FileSystem
{
    private:
        int m_size;

    public:
        FileInfo();
        ~FileInfo() override;
        FileInfo(int size);
        int getSize() override;

};

#endif