// --- code bai 1 ---
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct ThongTin{
	string Ten;
	string GioiTinh;
	string SoDienThoai;
	string Email;
	string DiaChi;
};

// --- them 1 danh ba vao danh sach ---
void Them(){
	fstream f;
	fstream g;
	string s;
	f.open("DU_LIEU/DANH_BA.txt", ios::out | ios::app);
	g.open("DU_LIEU/THEM.txt", ios::in);
	fflush(stdin);
	getline(g, s);
	do{
		f << s << "\n";
		fflush(stdin);
		getline(g, s);
	}while(s.compare("") != 0);
	cout << "da them xong!!!" << endl;
	f.close();
	g.close();
}

// --- liet ke danh sach ---
void LietKe(){
	fstream f;
	string s;
	ThongTin tt;
	f.open("DU_LIEU/DANH_BA.txt", ios::in);
	getline(f, s);
	do{
		tt.Ten = s;
		getline(f, tt.GioiTinh);
		getline(f, tt.SoDienThoai);
		getline(f, tt.Email);
		getline(f, tt.DiaChi);
		cout << tt.Ten << "\t" << tt.GioiTinh << "\t" << tt.SoDienThoai << "\t" << tt.Email << "\t" << tt.DiaChi << endl;
		getline(f, s);
	}while(s.compare("") != 0);
	f.close();
}

// --- chinh sua bang ghi ---
void ChinhSua(){
	
}

// --- tin kiem theo ten ---
void TimKiem(){
	ThongTin tt;
	string x;
	string s;
	fstream f;
	f.open("DU_LIEU/DANH_BA.txt", ios::in);
	cout << "nhap ten muon tim trong danh ba: ";
	getline(cin, x);
	fflush(stdin);
	getline(f, s);
	do{
		tt.Ten = s;
		getline(f, tt.GioiTinh);
		getline(f, tt.SoDienThoai);
		getline(f, tt.Email);
		getline(f, tt.DiaChi);
		if(x.compare(tt.Ten) == 0)
			cout << tt.Ten << "\t" << tt.GioiTinh << "\t" << tt.SoDienThoai << "\t" << tt.Email << "\t" << tt.DiaChi << endl;
		getline(f, s);
	}while(s.compare("") != 0);
	f.close();
	
}
int main(){
	
//	Them();

//	LietKe();

	TimKiem();
}
