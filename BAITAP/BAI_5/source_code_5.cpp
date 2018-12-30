#include<stdio.h>
#include<conio.h>
#include<dos.h>
int nhap();
void main()
{
int x;
printf ("\n Moi ban nhap mot so tu 0->9:");
x=nhap();
printf("\n So ban vua nhap la: %d",x);
getch();
}
int nhap()
{
union REGS regs;
int x;
regs.h.ah=1;
int86(0x21,&regs,&regs);
x=regs.h.al;
x = x - 0x30;
return x;
}
