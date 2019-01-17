#include <iostream>
#include <fstream>

#define max 20
using namespace std;

fstream f;
fstream g;

struct SuaXe{
	int stt;
	int t;
	int d;
};


void DocFile(SuaXe xe[max], int &n);// --- doc danh sach xe can sua ---
void SapXep(SuaXe xe[max], int n);// --- sap xep theo chieu tang thoi han giao xe (d) ---
void XuLy(SuaXe xe[max], int n);// --- bat dau sua xe / xuat ra mang hinh / luu vao file ---


// --- chuong trinh chinh ---
int main(){
	
	SuaXe XE[max];
	int n;
	
	DocFile(XE, n);
	
	// --- thu tu ban dau ---
	cout << "thu tu xe ban dau:" << endl;
	for(int i = 1; i <= n; i++)
		cout << XE[i].stt << "\t";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << XE[i].t << "\t";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << XE[i].d << "\t";
	cout << endl;
	
	SapXep(XE, n);
	
	// --- thu tu sau khi sap xep ---
	cout << endl << "thu tu xe sau khi sap xep:" << endl;
	for(int i = 1; i <= n; i++)
		cout << XE[i].stt << "\t";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << XE[i].t << "\t";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << XE[i].d << "\t";
	cout << endl;
	
	XuLy(XE, n);
	
}
// --- ket thuc chuong trinh chinh ---


void DocFile(SuaXe xe[max], int &n){
	
	int i = 1;
	int j = 1;
	
	f.open("DU_LIEU/INP.txt", ios::in);
	
	// --- doc so xe ---
	f >> n;
	
	// --- doc thoi gian sua xe ---
	while(i <= n){
		xe[i].stt = i;
		f >> xe[i].t;
		i++;
	}
	
	// --- doc thoi gian giao xe ---
	while(j <= n){
		f >> xe[j].d;
		j++;
	}
	f.close();
	
}

void SapXep(SuaXe xe[max], int n){

	for(int i = 1; i <= n-1; i++)
		for(int  j = i; j <= n; j++)
			if(xe[j].d < xe[i].d)
				swap(xe[j], xe[i]);
	
}
void XuLy(SuaXe xe[max], int n){
	
	f.open("DU_LIEU/OUTP.txt", ios::out);
	
	// --- xu ly cac xe can sua chua ---
	int tgs = 0;
	int kt = 0;
	cout << endl << "thu tu cac xe can sua la: " << endl;
	f << "thu tu cac xe can sua la:" << "\n";
	for(int i = 1; i <= n; i++){
		tgs += xe[i].t;
		if(tgs <= xe[i].d){
			cout << "xe " << xe[i].stt << endl;
			f << "xe " << xe[i].stt << "\n";
		}
		else{
			tgs -= xe[i].t;
		}	
	}
	
	
	// --- xu ly cac xe khong sua chua ---
	tgs = 0;
	cout << endl << "thu tu cac xe khong sua la: " << endl;
	f << "\n" << "thu tu cac xe khong sua la:" << "\n";
	for(int i = 1; i <= n; i++){
		tgs += xe[i].t;
		if(tgs > xe[i].d){
			tgs -= xe[i].t;
			cout << "xe " << xe[i].stt << endl;
			f << "xe " << xe[i].stt << "\n";
		}
		else{
			kt++;
		}
	}
	
	// --- kiem tra neu khong co xe nao sua thi in ra khong co ---
	if(kt == 5){
		cout << "khong co" << endl;
		f << "khong co" << "\n";
	}
	
	f.close();
}

