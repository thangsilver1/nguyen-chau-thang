// code bai 1
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

fstream f;

struct ThongTin{
	char ten[10];
	bool GioiTinh;
	char SoDienThoai[10];
	char Email[50];
	char DiaChi[100];
};

void Them(ThongTin tt){
	f.open("DU_LIEU/DANH_BA.txt", ios::out);
	f << "abc\n";
	f << "xyz\n";
	f.close();
}

int main(){
	ThongTin tt;
	Them(tt);
}
