#include <iostream>
#include "APPSETTING.h"
using namespace std;

APPSETTING::APPSETTING()
{

}

APPSETTING* APPSETTING::s_instance = NULL;

APPSETTING* APPSETTING::getInstance()
{
    if (s_instance == NULL)
    {
        s_instance = new APPSETTING();
    }
    return s_instance;
}