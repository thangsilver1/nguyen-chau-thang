// code bai 4
#include <iostream>
#include <fstream>

using namespace std;

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

int main(){
	int a[6][6];
	
	MoDoThi(a);
	
	XuatMaTran(a);
}
