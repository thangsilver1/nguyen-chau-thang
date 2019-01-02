#include<stdio.h>
#include<conio.h>
#include<dos.h>
int input()
{
int x;
// Ð?u tiên ta khai báo cái này .
union REGS regs;
// Gán AH = 1 t?c là báo v?i nó là ta s? d?ng hàm 1 trong ng?t 21h
regs.h.ah =1;
// Sau dó g?i hàm ng?t
int86(0x21,&regs,&regs) ;
//Hàm trên mà th?c thi thì xu?t hi?n d?u nh?c cho ta nh?p 1 ký t?
//---> T?ng giá tr? mình nh?p AL -> L?y ra
x = regs.h.al ;//T?ng giá tr? mình nh?p vào AL
x = x - 0x30;//L?y ra (:-)$
return x;
}
