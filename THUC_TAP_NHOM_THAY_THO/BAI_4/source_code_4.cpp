// code bai 4
#include <iostream>
#include <fstream>
#include <stdlib.h>
#define max 20
using namespace std;

struct BienLuu{
	int ten;
	int tong;
	int co;
};
// --- doc ma tran trong file ra mang 2 chieu ---
void MoDoThi(int &n, int a[max][max]){
	fstream f;
	string s;
	f.open("DU_LIEU/MA_TRAN.txt", ios::in);
	getline(f, s);
	n = atoi(s.c_str());
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			f >> a[i][j];
	f.close();
}

// --- test du lieu mang 2 chieu ---
void XuatMaTran(int n, int a[max][max]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}		
}

// --- ham dieu kien gan gia tri bien phu cho bien chinh ---
void SoSanh(BienLuu &bc, BienLuu &bp){
	if(bc.co != 1){
		if(bc.tong == 0){
			bc.ten = bp.ten;
			bc.tong = bp.tong;
		}
		else{
			if(bp.tong != 0 && bc.tong > bp.tong){
				bc.ten = bp.ten;
				bc.tong = bp.tong;
			}
		}
	}
}

// --- chon diem co tong nho nhat va bat co = 1 ---
void Duyet(int n, BienLuu bc[max], int &vt){
	int ln = 1000;
	for(int i = 0; i < n; i++){
		if(bc[i].co != 1 && bc[i].tong != 0){
			if(bc[i].tong < ln){
				vt = i;
				ln = bc[i].tong;
			}
		}
	}
	bc[vt].co = 1; // --- tra ve vi tri hang cho lan duyet ma tran tiep theo ---
}

// --- xuat ra lo trinh duong di ngan nhat tu mang BienLuu ---
void LoTrinh(int n, BienLuu a[max], int x, int y){
	cout << endl << "do dai duong di ngan nhat: " << a[y].tong << endl;
	cout << "lo trinh:  " << y;
	while(y != x){
		y = a[y].ten;
		cout << " <-- " << y;
	}
}
// --- luu ket qua vao file ---
void LuuKQ(int n, BienLuu bc[max], int x, int y){
	fstream f;
	f.open("DU_LIEU/LUU_KET_QUA.txt", ios::out);
	f << "diem bat dau: " << x << "\n";
	f << "diem ket thuc: " << y << "\n";
	f << "do dai duong di ngan nhat la: " << bc[y].tong << "\n";
	f << "lo trinh:  " << "\t" << y;
	while(y != x){
		y = bc[y].ten;
		f << " <-- " << y;
	}
	f.close();
}

// --- ham tim duong di ngan nhat ---
void TimDuong(int n, int a[max][max]){
	
	BienLuu BC[6];
	BienLuu BP;
	
	BP.co = 0;
	
	// --- khoi tao hang dau tien ---
	for(int i = 0; i < n; i++){
		BC[i].ten = 0;
		BC[i].tong = 0;
		BC[i].co = 0;
	}
	int bd, kt;
	cout << "nhap diem bat dau: ";
	cin >> bd;
	cout << "nhap diem ket thuc ";
	cin >> kt;
	cout << endl;
	
	int x = bd;	// --- bi tri bat dau ---
	int y = kt;	// --- vi tri ket thuc ---
	int i = x;	// --- bat dau doc ma tran tu hang x / vi tri bat dau tim duong ---
	
	// --- danh dau vi tri bat dau ---
	BC[x].co = 1;
	
	do{
		
		for(int j = 0; j < n; j++){
			
			// --- gan cho bien phu ten va gia tri tong ---
			if(a[i][j] != 0){
				BP.ten = x;
				BP.tong = a[i][j] + BC[x].tong;
			}
			// --- xu ly khi gia tri ma tran tai hang i cot j bang 0 ---
			else{
				BP.ten = 0;
				BP.tong = 0;
			}
			SoSanh(BC[j], BP);
		}
		
		// --- xuat ra qua trinh thay doi gia tri cua mang BC[] theo dong ---
		for(int c = 0; c < n; c++)
			cout << BC[c].ten << "," << BC[c].tong << "\t";
		cout << endl;
		
		Duyet(n ,BC, x);	// --- danh dau vinh tri da di qua ---
		i = x;	// --- dua i den hang tiep theo de doc ma tran ---
	}while(x != y);
	
	LoTrinh(n, BC, bd, kt);
	LuuKQ(n, BC, bd, kt);
}

int main(){
	int n;
	int a[max][max];
	
	MoDoThi(n, a);
	
	XuatMaTran(n ,a);
	
	cout << endl;
	
	TimDuong(n, a);
}
