#include <graphics.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

fstream f;

void VeKhung(){
	setbkcolor(BLUE);// --- tao mau nen ---
	setcolor(WHITE);// --- tao mau ky tu ---
	rectangle(14, 20, 950, 71);
	rectangle(13, 19, 951, 72);
	setfillstyle(1, BLUE);
	bar(15, 21, 950, 71);
}

void InConTro(int x, int y, int mau){
	settextstyle(3, HORIZ_DIR, 2);
//	setcolor(BLUE);
//	outtextxy(x, y, "|");
//	delay(500);
	setcolor(mau);
	outtextxy(x, y, "_");
//	delay(500);
}

void InKyTu(int &x, int y, char a[80], int mau){
	settextstyle(3, HORIZ_DIR, 2);
	setcolor(mau);
	outtextxy(x, y, a);
	x += textwidth(a);
}

int main(){
	
    initwindow(1000, 150, "thang kuro");//mo cua so do hoa
	VeKhung();
	char chuoi[80];
	char tam[2];
	string s;
	int a = 15;
	int i = 0;
	int x = 15;
	int y = 21;
	int xl = x;
	int xr = x;
	int dem = 80;
	// --- doc tu file va ghi len dong editer ---
	f.open("DU_LIEU/INP.txt", ios::in);
	getline(f, s);
	f.close();
	strcpy(chuoi, s.c_str());
	setcolor(BLACK);
	InKyTu(x, y, chuoi, BLACK);
	InConTro(x, 46, WHITE);
	
	do{
		tam[0] = getch();

		if(tam[0] == 13){
			break;
		}
		else{
			if(tam[0] == 71){
				// --- key home ---
				InConTro(x, 46, BLUE);
				InConTro(15, 46, WHITE);
				dem++;
			}
			else{
				if(tam[0] == 79){
					// --- key end ---
					InConTro(15, 46, BLUE);
					InConTro(x, 46, WHITE);
					dem++;
				}
				else{
					if(tam[0] == 75){
						// --- key left ---
						cout << "key left" << endl;
						dem++;
					}
					else{
						if(tam[0] == 77){
							// --- key right ---
							cout << "key right" << endl;
							dem++;
						}
						else{
							if(tam[0] == 83){
								// --- delete ky tu ---
								cout << "xoa" << endl;
								dem++;
							}
							else{
								// --- nhan ky tu in ra mang hinh ---
								InConTro(15, 46, BLUE);
								InConTro(x, 46, BLUE);
								InKyTu(x, y, tam, BLACK);
								InConTro(x, 46, WHITE);
								chuoi[i] = tam[0];
								dem--;
								i++;
								cout << dem << endl;
							}
						}
					}
				}
			}
		}
	}while(dem > 0);
	
	closegraph();//dong cua so do hoa
} 
