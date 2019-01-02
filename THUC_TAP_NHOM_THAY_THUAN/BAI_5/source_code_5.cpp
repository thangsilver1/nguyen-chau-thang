#include <iostream>
#include <fstream>
#define max 20
using namespace std;

struct PhanSo{
	int t;
	int m;
};

// --- doc du lieu bai toan tu file va2 gan gia tri cho cac bien ---
void DocFile(int &n, int &p, int &q){
	fstream f;
	f.open("DU_LIEU/FRACTIONS.INP.txt", ios::in);
	f >> n;
	f >> p;
	f >> q;
	f.close();
}

// --- sap xep day so ket qua va luu vao file ---
void LuuKetQua(PhanSo ps[max], int n){
	
	// --- sap xep day so ket qua ---
	for(int i = 0; i < n-1; i++){
		for(int j = i; j < n; j++){
			if((float)ps[i].t/ps[i].m > (float)ps[j].t/ps[j].m){
				swap(ps[i], ps[j]);
			}
		}
	}
	
	// --- luu day so ket qua vao file ---
	fstream f;
	f.open("DU_LIEU/FRACTIONS.OUT.txt", ios::out);
	for(int i = 0; i < n; i++){
		f << ps[i].t << "/" << ps[i].m << "\n";
	}
	f.close();
}

// --- ham kiem tra theo dieu kien bai toan ---
void KiemTra(int n, int p, int q){
	PhanSo ps[(n/2)-1];
	int vt = 0;
	for(float i = n/2; i < n; i++){
		for(float j = 1; j < n/2; j++){
			if(j/i > (float)1/p && j/i < (float)1/q){
				ps[vt].t = j;
				ps[vt].m = i;
				vt++;
			}
		}
	}
	LuuKetQua(ps, (n/2)-1);
	cout << "da hoan thanh !!! mo file de xem ket qua !!!";
}

int main(){
	
	int n, p, q;
	
	DocFile(n, p, q);
//	cout << n << " " << p << " " << q << endl;
	
	KiemTra(n, p, q);
}
