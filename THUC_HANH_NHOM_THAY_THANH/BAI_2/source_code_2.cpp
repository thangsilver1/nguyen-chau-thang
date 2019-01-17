#include <iostream>
#include <fstream>
#define max 20

using namespace std;

fstream f;

void NhapMaTran(int a[max][max], int &n, int &m);// --- tao ma tran ---
void LuuMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb);// --- luu ma tran vao file ---
void LuuKetQua(int a[max][max], int n, int m);// --- luu ket qua vao file ---
void CongMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb, int c[max][max]);
void TruMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb, int c[max][max]);
void NhanMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb, int c[max][max]);

// --- chuong trinh chinh ---
int main(){
	int x;
	int mt1[max][max];
	int n1, m1;
	int mt2[max][max];
	int mt3[max][max];
	int n2, m2;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	cout << "nhap ma tran NxM thu nhat: " << endl;
	NhapMaTran(mt1, n1, m1);
	cout << "nhap ma tran NxM thu hai: " << endl;
	NhapMaTran(mt2, n2, m2);
	LuuMaTran(mt1, n1, m1, mt2, n2, m2);
	
	f.open("DU_LIEU/output2.txt", ios::out);
	f << "";
	f.close();
	
	do{
		cout << "1. cong 2 ma tran" << endl;
		cout << "2. tru 2 ma tran" << endl;
		cout << "3. nhan 2 ma tran" << endl;
		cout << "0. de thoat" << endl;
		cout << "chon: ";
		cin >> x;
		cout << endl;
		switch(x){
			case 1:
				if(flag1 == 0){
					CongMaTran(mt1, n1, m1, mt2, n2, m2, mt3);
					if(n1 == n2 && m1 == m2){
						f.open("DU_LIEU/output2.txt", ios::out | ios::app);
						f << "ket qua cong 2 ma tran:\n";
						f.close();
						LuuKetQua(mt3, n1, m1);
						flag1 = 1;
					}
				}
				else{
					CongMaTran(mt1, n1, m1, mt2, n2, m2, mt3);
				}
				break;
			case 2:
				if(flag2 == 0){
					TruMaTran(mt1, n1, m1, mt2, n2, m2, mt3);
					if(n1 == n2 && m1 == m2){
						f.open("DU_LIEU/output2.txt", ios::out | ios::app);
						f << "ket qua tru 2 ma tran:\n";
						f.close();
						LuuKetQua(mt3, n1, m1);
						flag2 = 1;
					}
				}
				else{
					TruMaTran(mt1, n1, m1, mt2, n2, m2, mt3);
				}
				break;
			case 3:
				if(flag3 == 0){
					NhanMaTran(mt1, n1, m1, mt2, n2, m2, mt3);
					if(m1 == n2){
						f.open("DU_LIEU/output2.txt", ios::out | ios::app);
						f << "ket qua nhan 2 ma tran:\n";
						f.close();
						LuuKetQua(mt3, n1, m2);
						flag3 = 1;
					}
				}
				else{
					NhanMaTran(mt1, n1, m1, mt2, n2, m2, mt3);
				}
				break;
		}
	}while(x != 0);
}
// --- ket thuc chuong trinh chinh ---


void NhapMaTran(int a[max][max], int &n, int &m){
	
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << "nhap phan tu [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
	
	cout << endl;
	
}

void LuuMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb){
	f.open("DU_LIEU/input2.txt", ios::out);
	f << "ma tran thu nhat:\n";
	for(int i = 0; i < na; i++){
		for(int j = 0; j < ma; j++){
			f << a[i][j] << " ";
		}
		f << "\n";
	}
	f << "ma tran thu 2:\n";
	for(int i = 0; i < nb; i++){
		for(int j = 0; j < mb; j++){
			f << b[i][j] << " ";
		}
		f << "\n";
	}
	f.close();
}

void LuuKetQua(int a[max][max], int n, int m){
	f.open("DU_LIEU/output2.txt", ios::out | ios::app);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			f << a[i][j] << " ";
		}
		f << "\n";
	}
	f.close();
}

void CongMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb,int c[max][max]){
	
	if(na == nb && ma == mb){
		for(int i = 0; i < na; i++){
			for(int j = 0; j < ma; j++){
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		cout << "ket qua cong 2 ma tran la:" << endl;
		for(int i = 0; i < na; i++){
			for(int j = 0; j < ma; j++){
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
		cout << "khong the cong 2 ma tran nay !!!" << endl;
}

void TruMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb, int c[max][max]){
	
	if(na == nb && ma == mb){
		for(int i = 0; i < na; i++){
			for(int j = 0; j < ma; j++){
				c[i][j] = a[i][j] - b[i][j];
			}
		}
		cout << "ket qua tru 2 ma tran la:" << endl;
		for(int i = 0; i < na; i++){
			for(int j = 0; j < ma; j++){
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
		cout << "khong the tru 2 ma tran nay !!!" << endl;
}

void NhanMaTran(int a[max][max], int na, int ma, int b[max][max], int nb, int mb, int c[max][max]){
	if(ma == nb){
		for(int i = 0; i < na; i++){
			for(int j = 0; j < mb; j++){
				c[i][j] = 0;
				for(int k = 0; k < ma; k ++){
					c[i][j] += a[i][k]*b[k][j];
				}
			}
		}
		cout << "ket qua nhan 2 ma tran la:" << endl;
		for(int i = 0; i < na; i++){
			for(int j = 0; j < mb; j++){
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
		cout << "khong the nhan 2 ma tran nay !!!" << endl;
}
