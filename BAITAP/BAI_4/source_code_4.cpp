// code bai 4
#include <iostream>
#include <fstream>

using namespace std;

struct BienLuu{
	int ten;
	int tong;
	int co;
};
// --- doc ma tran trong file ra mang 2 chieu ---
void MoDoThi(int a[6][6]){
	fstream f;
	f.open("DU_LIEU/MA_TRAN.txt", ios::in);
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			f >> a[i][j];
	f.close();
}

// --- test du lieu mang 2 chieu ---
void XuatMaTran(int a[6][6]){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}		
}

// --- ham so sanh 2 BienLuu ---
void SoSanh(BienLuu &bc, BienLuu &bp){
	if(bc.co != 1){
		if(bc.tong == 0){
			bc.ten = bp.ten;
			bc.tong = bp.tong;
		}
		else{
			if(bc.tong > bp.tong){
				bc.ten = bp.ten;
				bc.tong = bp.tong;
			}
		}
	}
}

// --- chon diem co tong nho nhat va bat co = 1 ---
void Duyet(BienLuu bc[6], int &vt){
	int ln = 1000;
	for(int i = 0; i < 6; i++){
		cout << bc[i].co << "\t";
		if(bc[i].co != 1 && bc[i].tong != 0){
			if(bc[i].tong < ln){
				vt = i;
				ln = bc[i].tong;
			}
		}
	}
	bc[vt].co = 1;
	cout << vt << endl;
}

// --- ham tim duong di ngan nhat ---
void TimDuong(int a[6][6]){
	
	BienLuu BC[6];
	BienLuu BP;
	
	BP.co = 0;
	
	// --- khoi tao hang dau tien ---
	for(int i = 0; i < 6; i++){
		BC[i].ten = 0;
		BC[i].tong = 0;
		BC[i].co = 0;
	}
	
	int x = 0;	// --- bi tri bat dau ---
	int y = 5;	// --- vi tri ket thuc ---
	int i = 0;	// --- bat dau doc ma tran tu hang 1 ---
	
	// --- danh dau vi tri bat dau ---
	BC[x].co = 1;
	
	do{
		
		for(int j = 0; j < 6; j++){
			// --- cho bien phu ten va gia tri tong ---
			BP.ten = x;
			BP.tong = a[i][j] + BC[x].tong;
			
			SoSanh(BC[j], BP);
		}
	
		for(int c = 0; c < 6; c++)
			cout << BC[c].ten << "," << BC[c].tong << "\t";
		cout << endl;
	
		Duyet(BC, x);
		i = x;
	}while(x != y);
}


int main(){
	int a[6][6];
	
	MoDoThi(a);
	
	XuatMaTran(a);
	
	cout << endl;
	
	TimDuong(a);
}
