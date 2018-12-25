// code bai 2
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;

// --- kieu du lieu ngay thang ---
struct NgayThang{
	int D;
	int M;
	int Y;
};

// --- kiem tra nhap dd/MM/yyyy ---
bool KT(int &d, int &m, int &y){
	
	if(y < 1 || m > 12 || m < 1 || d < 1 || d > 31)
		return false;
	else
		if(m != 2)
			if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				return true;
			else
				if(d >= 1 && d <= 30)
					return true;
				else
					return false;
		else
			if((y%400 == 0) || ((y%4 == 0) && (y%100 != 0)))
				if(d >= 1 && d <= 29)
					return true;
				else
					return false;
			else
				if(d >= 1 && d <= 28)
					return true;
				else
					return false;
					
}

// --- tao bien NgayThang bang chuoi dd/MM/yyyy ---
void ChuyenDoi(string &s, NgayThang &a){
	
	// --- chuyen doi chuoi vua nhap ---
	a.D = atoi((s.substr(0,2)).c_str());
//	cout << a.D << endl;
	a.M = atoi((s.substr(3,2)).c_str());
//	cout << a.M << endl;
	a.Y = atoi((s.substr(6,4)).c_str());
//	cout << a.Y << endl;

}

// --- nhap chuoi dd/MM/yyyy và kiem tra ---
void Nhap(NgayThang &a){
	
	string s;
	bool flag = false;
	
	do{
		fflush(stdin);
		cout << "nhap ngay theo dinh dang dd//MM/yyyy: ";
		getline(cin, s);
		
		// --- kiem tra du lieu vua nhap ---
		if(s.length() == 10 && s.find('/') == 2 && s.find('/', 3) == 5 && s.rfind('/') == 5){
			ChuyenDoi(s, a);
			if(KT(a.D, a.M, a.Y) == true)
				flag = true;
		}	
	}while(flag == false);
	
}

// --- kiem tra nam nhuan ---
bool NamNhuan(int a){
	
	if((a%400 == 0) || ((a%4 == 0) && (a%100 != 0)))
//		cout << "nam " << a.Y << " la nam nhuan!" << endl;
		return true;
	else
//		cout << "nam " << a.Y << " khong phai la nam nhuan!" << endl;
		return false;

}

// --- so ngay trong trong thang ---
int TinhNgay(int m, int y){
	int songay;
	switch(m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: 
			songay = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11: 
			songay = 30;
			break;
		case 2:
			if(NamNhuan(y) == true)
				songay = 29;
			else
				songay = 28;
			break;
	}
	return songay;
}

// --- so thu tu ngay trong nam ---
int SoThuTu(NgayThang &a){
	
	int stt = a.D;
	for(int i = 1; i <= a.M - 1; i++)
		stt = stt + TinhNgay(i, a.Y);
	return stt;

}

// --- so thu tu chuyen sang ngay ---
void SoSangNgay(NgayThang &b, int &n){
	for(int i = n; n > 0; n -= TinhNgay(b.M, b.Y))
		if(n > TinhNgay(b.M, b.Y)){
			b.M++;
		}
		else
			if(n == TinhNgay(b.M, b.Y)){
				b.M++;
				b.D = 1;
				n = 0;
			}
			else{
				b.D = n;
				n = 0;
			}
	cout << "ngay sau khi cong la: " << b.D << "/" << b.M << "/" << b.Y << endl;	
}

// --- cong du lieu NgayThang voi so nguyen duong ---
void Cong(NgayThang a, int &x){
	
	cout << "nhap so tu nhien duong: ";
	cin >> x;
	
	int n = SoThuTu(a) + x;
	
	NgayThang b;
	b.Y = a.Y;
	b.M = 1;
	b.D = 0;
	
	while(n > 365)
		for(n; n >= 366; n-=366){
			if(NamNhuan(b.Y) == false)
				n++;
			b.Y++; // xong nam
		}
	if(n == 365){
		b.Y++; // xong nam
		b.D = 1; // xong ngay
		b.M = 1; // xong thang
	}
	else
		if(n < 365)
			SoSangNgay(b, n); // xong ngay va thang
}

// --- tru du lieu NgayThang voi so nguyen duong ---
void Tru(NgayThang a, int &x){
	
	cout << "nhap so tu nhien duong: ";
	cin >> x;
	
	NgayThang b;
	b.Y = a.Y;
	b.M = a.M;
	b.D = a.D;
	
	while(x >= 365){
		if(NamNhuan(b.Y) == false){
			b.Y--;
			x -= 365;
		}
		else{
			b.Y--;
			x -= 366;
		}
	}
	
	int stt = SoThuTu(b);
	
	b.M = 1;
	b.D = 0;
	
	if(stt > x){
		stt -= x;
		SoSangNgay(b, stt);
	}
	else{
		b.Y--;
		if(NamNhuan(b.Y) == true)
			stt += 366;
		else
			stt += 365;
		stt -= x;
		SoSangNgay(b, stt);
	}
}

int main(){
	
	NgayThang DMY;
	
	Nhap(DMY);
	if(NamNhuan(DMY.Y))
		cout << "nam " << DMY.Y << " la nam nhuan!" << endl;
	else
		cout << "nam " << DMY.Y << " khong la nam nhuan!" << endl;
		
	cout << "ngay: " << DMY.D << endl;
	cout << "thang: " << DMY.M << endl;
	cout << "nam: " << DMY.Y << endl;
	
	cout << "so thu tu cua ngay " << DMY.D << "/" << DMY.M << "/" << DMY.Y << " la: " << SoThuTu(DMY) << endl;
	
	int y;
	
	Cong(DMY, y);
	
	int z;
	
	Tru(DMY, z);

}
