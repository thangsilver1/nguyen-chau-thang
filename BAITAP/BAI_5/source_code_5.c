#include<stdio.h>
#include<conio.h>
#include<dos.h>
int input()
{
int x;
// �?u ti�n ta khai b�o c�i n�y .
union REGS regs;
// G�n AH = 1 t?c l� b�o v?i n� l� ta s? d?ng h�m 1 trong ng?t 21h
regs.h.ah =1;
// Sau d� g?i h�m ng?t
int86(0x21,&regs,&regs) ;
//H�m tr�n m� th?c thi th� xu?t hi?n d?u nh?c cho ta nh?p 1 k� t?
//---> T?ng gi� tr? m�nh nh?p AL -> L?y ra
x = regs.h.al ;//T?ng gi� tr? m�nh nh?p v�o AL
x = x - 0x30;//L?y ra (:-)$
return x;
}
