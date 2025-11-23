#include <stdio.h>
#include "LOPTAMGIAC3.h"

void LOPTAMGIAC ::Nhap()
{   
    do
    {
        printf("Nhập đỉnh A: \n");
        // Yêu cầu A thực hiện hành động
        A.NhapDiem();
        
        printf("Nhập đỉnh B: \n");
        // Yêu cầu B thực hiện hành động
        B.NhapDiem();
        
        printf("Nhập đỉnh C: \n");
        // Yêu cầu C thực hiện hành động
        C.NhapDiem();
    } while (KiemTraHopLe(A, B, C) == false);
    
}

bool LOPTAMGIAC ::KiemTraHopLe(LOPDIEM a, LOPDIEM b, LOPDIEM c)
{   
    double ab, ac, bc;
    ab = a.TinhKhoangCach(b);
    ac = a.TinhKhoangCach(c);
    bc = b.TinhKhoangCach(c);
    return ab + ac > bc 
        && ab + bc > ac 
        && bc + ac > ab;
}

double LOPTAMGIAC ::TinhChuVi()
{
    double a, b, c;
    a = B.TinhKhoangCach(C);
    b = A.TinhKhoangCach(C);
    c = A.TinhKhoangCach(B);
    return a + b + c;
}