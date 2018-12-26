// --- code bai 1 ---
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

fstream f;
fstream g;

struct ThongTin{
	string ten;
	int GioiTinh;
	string SoDienThoai;
	string Email;
	string DiaChi;
};

// --- them 1 danh ba vao danh sach ---
void Them(){
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
	f.close();
	g.close();
}

// --- liet ke danh sach ---
void LietKe(){
	
}

int main(){
	
	Them();

}
