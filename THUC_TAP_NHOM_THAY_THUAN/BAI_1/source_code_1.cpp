#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define max 20

using namespace std;

// --- tao san ma tran / cong viec ---
//int a[5][5] = {0, 1, 0, 1, 0,
//			   0, 0, 1, 1, 1,
//			   0, 0, 0, 0, 1,
//			   0, 0, 0, 0, 0,
//			   0, 0, 0, 0, 0};

// --- su dung cho nhap ma tran bang tay / su dung file ---
int a[max][max];


// --- nhap ma tran / cong viec bang tay ---
void NhapMT(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << "nhap a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

// --- nhap ma tran / cong viec tu file ---
void NhapFile(int &n){
	fstream f;
	string s;
	f.open("DU_LIEU/INP.txt", ios::in);
	getline(f, s);
	n = atoi(s.c_str());
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			f >> a[i][j];
		}
	}
	f.close();
}

// --- kiem tra xem cot d co bang 0 (khong co cung den) hay khong ---
int KiemTra(int n, int d){
	int flag = 0;
	for(int i = 0; i < n; i++){
		if(a[i][d] != 0)
			flag = 1;
	}
	return flag;
}

// --- xoa hang d (gan gia tri hang d = 0) sau khi tim ra cot d bang 0 (khong co cung den) ---
void XoaHang(int n, int d){
	for(int i = 0; i< n; i++){
		a[d][i] = 0;
	}
}

// --- danh dau cot d da xet roi (gan gia tri cot d = -1) ---
void Block(int n, int d){
	for(int i = 0; i < n; i++){
		a[i][d] = -1;
	}
}

// --- kiem tra mang xem sau khi sap xep Topo có thay doi trong mang hay khong ---
int ThongBao(int n){
	int flag = 0;
	for(int i = 0; i < n; i++){
		if(a[i][i] != -1)
			flag = 1;
	}
	return flag;
}
void Topo(int n){
	int i = 0;
	int flag = 0;
	do{
		for(int j = 0; j < n; j++)
			if(KiemTra(n, j) == 0){
				cout << j << "\t";
				XoaHang(n, j);
				Block(n, j);
//				a[j][j] = -1;
			}
		i++;
	}while(i < n);
	if(ThongBao(n) == 1){
		cout << "khong co thu tu viec lam nao het!!!";
	}
}

int main(){
	int n;
	NhapFile(n);
	
//	NhapMT(n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	Topo(n);
	
}
