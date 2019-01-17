#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

fstream f, g, h;

void NhapFile(int &n);// --- ghi n so tu nhien vao file ---
void XuatFile(int n);// --- xuat file chinh ra mang hinh ---

int KiemTra(int n);// --- kiem tra chuoi trong file chinh tang chua ---
void XepVaoFile(int s1, int s2);// --- xep 2 file phu vao file chinh ---

void Natural(int n);// --- tach gia tri tang dan trong chuoi file chinh ra luan phien 2 file phu ---

void NaturalSort(int n);// --- thuc hien thao tac tron straight mergesort ---


int main(){
	
	int n;
	
	srand(time(NULL));
	
	NhapFile(n);
	
	cout << "chuoi file goc: ";
	XuatFile(n);
	
	NaturalSort(n);

}

void NhapFile(int &n){
	f.open("DU_LIEU/FILE_0.txt", ios::out);
	cout << "nhap so phan tu muon tao: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		f << rand() % 50 + 1 << " ";
	}
	f.close();
}

void XuatFile(int n){
	int a;
	f.open("DU_LIEU/FILE_0.txt", ios::in);
	cout << endl << "gia tri chuoi:" << endl;
	for(int i = 1; i <= n; i++){
		f >> a;
		cout << a << " ";
	}
	f.close();
}

int KiemTra(int n){
	int a, b;
	int flag = 1;
	
	f.open("DU_LIEU/FILE_0.txt", ios::in);
	
	f >> a;
	for(int i = 2; i <= n; i++){
		f >> b;
		if(a > b)
			flag = 0;
		a = b;
	}
	f.close();
	return flag;
}

void XepVaoFile(int s1, int s2){
	
	f.open("DU_LIEU/FILE_0.txt", ios::out);
	g.open("DU_LIEU/FILE_1.txt", ios::in);
	h.open("DU_LIEU/FILE_2.txt", ios::in);
	
	int tam1;
	int tam2;
	
	int i = 1;
	int j = 1;
	
	g >> tam1;
	h >> tam2;
	
	while(i <= s1 && j <= s2){
		if(tam1 <= tam2){
			f << tam1 << " ";
			g >> tam1;
			i++;
		}
		else{
			f << tam2 << " ";
			h >> tam2;
			j++;
		}
	}
	if(i <= s1){
		for(i; i <= s1; i++){
			f << tam1 << " ";
			g >> tam1;
		}
	}
	if(j <= s2){
		for(j; j <= s2; j++){
			f << tam2 << " ";
			h >> tam2;
		}
	}
	
	f.close();
	g.close();
	h.close();

}

void Natural(int n){
	
	f.open("DU_LIEU/FILE_0.txt", ios::in);
	g.open("DU_LIEU/FILE_1.txt", ios::out);
	h.open("DU_LIEU/FILE_2.txt", ios::out);
	
	int tam, luu;
	int i = 1;
	int co = 1;
	int dem1 = 0;
	int dem2 = 0;
	
	f >> tam;
	i++;
	g << tam << " ";
	dem1++;
	luu = tam;
	
	do{
		
		while(i <= n && co == 1){
			f >> tam;
			i++;
			if(luu <= tam){
				g << tam << " ";
				dem1++;
				luu = tam;
			}
			else{
				h << tam << " ";
				dem2++;
				luu = tam;
				co = 0;
			}
				
		}
		
		while(i <= n && co == 0){
			f >> tam;
			i++;
			if(luu <= tam){
				h << tam << " ";
				dem2++;
				luu = tam;
			}
			else{
				g << tam << " ";
				dem1++;
				luu = tam;
				co = 1;
			}
		}
	}while(i <= n);
	
	f.close();
	g.close();
	h.close();
	
	XepVaoFile(dem1, dem2);
	cout << endl;
	XuatFile(n);
}

void NaturalSort(int n){
	while(KiemTra(n) == 0){	// --- kiem tra thay cuoi chua tang ---
		Natural(n);
	}
}
