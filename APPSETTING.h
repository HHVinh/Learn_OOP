#ifndef APPSETTING_H
#define APPSETTING_H

class APPSETTING
{
    private:
        static APPSETTING* s_instance;
        // Hàm tạo không đối số đưa vào private
        APPSETTING();

    public:
        // static là biến tĩnh
        static APPSETTING* getInstance();
};

#endif