#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <iostream>
#include <string>
using namespace std;

class FileSystem
{
    private:
        string m_name;
    public:
        FileSystem();
        virtual ~FileSystem();
        virtual int getSize() = 0;

};

#endif