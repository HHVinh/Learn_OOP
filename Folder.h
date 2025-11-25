#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include <string>
#include "FileSystem.h"
using namespace std;

class Folder : public FileSystem
{
    private:
        int m_numberOfChild;
        FileSystem* m_childList[100];

    public:
        Folder();
        ~Folder() override;
        void add(FileSystem* child);
        int getSize() override;

};

#endif