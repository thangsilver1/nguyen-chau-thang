// code bai 4
#include <iostream>
#include <fstream>

using namespace std;

struct BienLuu{
	int ten;
	int tong;
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

void TimDuong(int a[6][6]){
	BienLuu LD[6];
	int i = 0;
	int n = 0;
	for(int l = 0; l < 6; l++){
		LD[l].ten = l;
		LD[l].tong = 0;
	}
	while(n <= 5){
		n++;
		for(int j = 0; j < 6; j++)
			if(a[i][j] != 0){
				LD[j].ten = j;
				LD[j].tong = LD[j].tong + a[i][j];
			}
		i++;
	}
	for(int x = 0; x < 6; x++)
		cout << LD[x].ten << "\t" << LD[x].tong << endl;
}
int main(){
	int a[6][6];
	
	MoDoThi(a);
	
	XuatMaTran(a);
	
	cout << endl;
	
	TimDuong(a);
}
