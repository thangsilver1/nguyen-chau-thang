#include <iostream>
#include <stdlib.h>
#include <ctime>
#define max 7

using namespace std;

// --- cac ham chuong trinh ---
bool KiemTra(int a[max-1], int b, int c);/* --- kiem tra so "c" co trung voi
												cac so trong mang a[] co "b" phan tu khong --- */

void ChonSo(int cs[max-1]);// --- nguoi choi chon 6 so ---

void XoSo(int xs[max]);// --- vietlot xo so 6 so---



void KetQuaXS(int cs[max-1], int xs[max]);// ---kiem tra va xuat ket qua giai thuong ---


// --- chuong trinh chinh ---
int main(){
	
	int CS[max-1];
	int XS[max];
	
	srand(time(NULL));
	
	XoSo(XS);
	
	ChonSo(CS);
	
	KetQuaXS(CS, XS);
	
}
// --- ket thuc chuong trinh chinh ---


void ChonSo(int cs[max-1]){
	
	int x;
	int i = 0;
	
	cout << "chon 6 so khac nhau: " << endl;
	
	// --- nhap so muon chon ---
	do{
		cout << "chon so thu " << i+1 << ": ";
		cin >> x;
		if(x <= 55 && x >= 1){
			if(KiemTra(cs, i, x) == true){
				cs[i] = x;
				i++;
			}
			else
				cout << "so trung!!!" << endl;
		}
		else
			cout << "so vua nhap vuot qua gioi han!!!" << endl;
	}while(i < max-1);
	
	// --- xuat cac so vua chon va so dac biet o cuoi cung ---
	cout << endl << "day so ban vua chon la: ";
	for(int i = 0; i < max-1; i++)
		if(cs[i] >= 1 && cs[i] < 10)	
			cout << "0" << cs[i] << " ";
		else
			cout << cs[i] << " ";
	cout << endl;
}

bool KiemTra(int a[max-1], int b, int c){
	
	for(int i = 0; i < b; i++){
		if(c == a[i])
			return false;
	}
	return true;
	
}

void XoSo(int xs[max]){
	
	int x;
	int i = 0;
	
	// --- tao ket qua xo so ---
	xs[i] = rand() % 55 + 1;
	i++;
	while(i < max){
		x = rand() % 55 + 1;
		if(KiemTra(xs, i, x) == true){
			xs[i] = x;
			i++;
		}
	}
	
	// --- sap xep ket qua xo so ---
	for(int a = 0; a < max-2; a++)
		for(int b = a; b < max-1; b++)
			if(xs[a] > xs[b])
				swap(xs[a], xs[b]);
	
	// --- xuat ket qua xo so ---
	cout << "ket qua xo so la: ";
	for(i = 0; i < max-1; i++)
		if(xs[i] > 0 && xs[i] < 10)	
			cout << "0" << xs[i] << " ";
		else
			cout << xs[i] << " ";
	cout << "- " << xs[6];
	cout << endl;
}

void KetQuaXS(int cs[max-1], int xs[max]){
	
	int kq = 0;
	
	// --- kiem tra xem nguoi choi trung bao nhieu so ---
	for(int i = 0; i < max-1; i++){
		for(int j = 0; j < max-1; j++)
			if(cs[i] == xs[j])
				kq++;
	}
	
	// --- kiem tra xem nguoi choi trung giai nao ---
	switch(kq){
		case 6:
			cout << endl << "Ban da trung: Giai Jackpot 1 !!!" << endl;
			break;
		case 5:
			for(int i = 0; i < max-1; i++)
				if(xs[6] == cs[i])
					kq++;
			if(kq == 6)
				cout << endl << "Ban da trung: Giai Jackpot 2 !!!" << endl;
			else
				cout << endl << "Ban da trung: Giai Nhat !!!" << endl;
			break;
		case 4:
			cout << endl << "Ban fa trung: Giai nhi !!!" << endl;
			break;
		case 3:
			cout << endl << "Ban da trung: Giai ba !!!" << endl;
			break;
	}
	if(kq < 3)
		cout << endl << "Ban da mat tien ngu !!!" << endl;
	
}
