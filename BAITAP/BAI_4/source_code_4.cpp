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
void SoSanh(BienLuu &bc, BienLuu bp){
	if(bc.tong > bp.tong){
		bc.ten = bp.ten;
		bc.tong = bp.tong;
	}
}

// --- chon diem co tong nho nhat va bat co = 1 ---
void Duyet(BienLuu bc[6], int &vt){
	int ln = 1000;
	for(int i = 0; i < 6; i++){
		if(bc[i].co == 0 && bc[i].tong != 0){
			if(bc[i].tong < ln){
				vt = i;
				ln = bc[i].tong;
			}
		}
	}
	bc[vt].co = 1;
}

// --- ham tim duong di ngan nhat ---
void TimDuong(int a[6][6]){
	
	BienLuu BC[6];
	BienLuu BP;
	
	BP.co = 0;
	
	// --- khoi tao hang dau tien ---
	for(int l = 0; l < 6; l++){
		BC[l].ten = 0;
		BC[l].tong = 0;
		BC[l].co = 0;
	}
	
	int x = 0;	// --- bi tri bat dau ---
	int y = 5;	// --- vi tri ket thuc ---
	int i = 0;	// --- doc theo hang ---
	// --- danh dau vi tri bat dau ---
	BC[x].co = 1;
	
	while(i < 6){
		for(int j = 0; j < 6; j++){
			// --- cho bien phu ten va gia tri tong ---
			BP.ten = x;
			BP.tong = a[i][j] + BC[x].tong;
			
			if(BC[j].co == 0){
				if(BC[j].tong == 0){
					BC[j].ten = BP.ten;
					BC[j].tong = BP.tong;
				}
				else{
					SoSanh(BC[j], BP);
				}
			}
		}
		Duyet(BC, x);
		i = x;
		cout << x << endl;
	}
	for(int c = 0; c < 6; c++)
		cout << BC[c].ten << "," << BC[c].tong << "\t";
}
int main(){
	int a[6][6];
	
	MoDoThi(a);
	
	XuatMaTran(a);
	
	cout << endl;
	
	TimDuong(a);
}
