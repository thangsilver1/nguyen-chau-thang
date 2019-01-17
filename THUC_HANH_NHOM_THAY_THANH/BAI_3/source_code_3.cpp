#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#define max 20

using namespace std;

fstream f;

struct NgayThang{
	int ngay;
	int thang;
	int nam;
};

void NhapNT(NgayThang &NT){
	cout << "ngay: ";
	cin >> NT.ngay;
	cout << "thang: ";
	cin >> NT.thang;
	cout << "nam: ";
	cin >> NT.nam;
}

class NhanVien{
	
	string HT;// --- gioi tinh ---
	int GT;// --- gioi tinh (1 nam / 0 nu)---
	NgayThang NVL;// --- ngay vao lam --- sua lai string dd/mm/yyyy
	float HSL;// --- he so luong ---
	int SC;// --- so con ---
	static long LCB;// --- luong co ban ---
	
	public:
		void Nhap(){
			string s;
			cout << "nhap ho ten: ";
			fflush(stdin);
			getline(cin, HT);
			f << HT << "\n";
			cout << "nhap gioi tinh: ";
			fflush(stdin);
			getline(cin, s);
			f << s << "\n";
			if(s.compare("nam") == 0)
				GT = 1;// --- nam 1 ---
			else
				GT = 0;// --- nu 0 ---
			cout << "nhap ngay vao lam:" < endl;;
			fflush(stdin);
			NhapNT(NVL);
			f << NVL.ngay << "/" << NVL.thang << "/" << NVL.nam << "\n";
			cout << "nhap he so luong: ";
			fflush(stdin);
			cin >> HSL;
			f << HSL << "\n";
			cout << "nhap so con: ";
			fflush(stdin);
			cin >> SC;
			f << SC << "\n";
		}
		
		void NhapFile(){
			string s;
			getline(f, s);
			HT = s;
			getline(f, s);
			if(s.compare("nam") == 0)
				GT = 1;// --- nam 1 ---
			else
				GT = 0;// --- nu 0 ---
			getline(f, s);
			NVL.ngay = atoi((s.substr(0,2)).c_str());
			NVL.thang = atoi((s.substr(3,2)).c_str());
			NVL.nam = atoi((s.substr(6,4)).c_str());
			getline(f, s);
			HSL = atof(s.c_str());
			getline(f, s);
			SC = atoi(s.c_str());
		}
		
		long TinhLuong(){
			return LCB*HSL;
		}
		
		float TinhTroCap(){
			if(GT == 0)
				return SC*1.5;
			else
				return SC;
		}
		
		int TinhTienThuong(){
			int tgl = 2019 - NVL.nam;
			return  tgl * 1000000;
		}
		
		int con(){
			return SC;
		}
		
		void Xuat(){
			cout << "ten: " << HT << endl;
		}	
		
};
long NhanVien::LCB = 1000000;

class NhanVienVanPhong:public NhanVien{
	
	int SNV;// --- so ngay van ---
	static int DMV;// --- dinh muc vang ---
	static int DGP;// --- don gia phat ---
	
	public:
		
		void NhapNVVP(){
			NhanVien::Nhap();
			cout << "nhap so ngay van: ";
			fflush(stdin);
			cin >> SNV;
			f << SNV << "\n";
		}
		
		void NhapFileNVVP(){
			NhanVien::NhapFile();
			string s;
			getline(f, s);
			SNV = atoi(s.c_str());
		}
		
		int TinhTienPhatNVVP(){
			if(SNV > DMV)
				return SNV*DGP;
			else
				return 0;
		}
		
		float TinhTroCapNVVP(){
			return 200000*NhanVien::TinhTroCap();
		}
		
		long TinhLuongNVVP(){
			return NhanVien::TinhLuong() - TinhTienPhatNVVP();
		}
		
		void XuatNVVP(){
			NhanVien::Xuat();
			cout << "tien luong: "<< TinhLuongNVVP() << endl;
			cout << "tien thuong lam viec: " << NhanVien::TinhTienThuong() << endl;
			cout << "tien phat: " << TinhTienPhatNVVP() << endl;
			cout << "tien tro cap: " << TinhTroCapNVVP() << endl;
		}
		
};

int NhanVienVanPhong::DMV = 3;
int NhanVienVanPhong::DGP = 100000;

class NhanVienSanXuat:public NhanVien{
	
	int SSP;// --- so san pham ---
	static int DMSP;// --- dinh muc san pham ---
	static int DGSP;// --- don gia san pham ---
	
	public:
		
		void NhaPNVSX(){
			NhanVien::Nhap();
			cout << "nhap so san pham: ";
			fflush(stdin);
			cin >> SSP;
			f << SSP << "\n";
		}
		
		void NhapFileNVSX(){
			NhanVien::NhapFile();
			string s;
			getline(f, s);
			SSP = atoi(s.c_str());
		}
		
		float TinhTienThuongNVSX(){
			if(SSP > DMSP)
				return (SSP - DMSP)*DGSP*0.03;
		}
		
		int TinhTroCapNVSX(){
			return 120000*NhanVien::con();
		}
		long TinhLuongNVSX(){
			return (SSP*DGSP) + TinhTienThuong();
		}
		
		void XuatNVSX(){
			NhanVien::Xuat();
			cout << "tien luong: "<< TinhLuongNVSX() << endl;
			cout << "tien thuong lam viec: " << NhanVien::TinhTienThuong() << endl;
			cout << "tien thuong san pham: " << TinhTienThuongNVSX() << endl;
			cout << "tien tro cap: " << TinhTroCapNVSX() << endl;
		}
		
};
int NhanVienSanXuat::DMSP = 30;
int NhanVienSanXuat::DGSP = 20000;


// --- chuong trinh chinh ---
int main(){
	
	NhanVienVanPhong nv1;
	NhanVienSanXuat nv2;
	NhanVienVanPhong nv3[max];
	NhanVienSanXuat nv4[max];
	string s;
	int n;
	int x;
	int m;
	long ltb = 0;
	
	do{
		cout << endl << "----------------------------------------------------------" << endl;
		cout << "1. nhap nhan vien van phong" << endl;
		cout << "2. nhap nhan vien san xuat" << endl;
		cout << "3. nhap nhieu nhan vien van phong tu tep" << endl;
		cout << "4. nhap nhieu vien san xuat tu tep" << endl;
		cout << "0. thoat" << endl;
		cout << "chon: ";
		
		cin >> x;
		switch(x){
			case 1:
				f.open("DU_LIEU/NHAN_VIEN_VAN_PHONG_LUU.txt", ios::out | ios::app);
				cout << endl << "----------------------------------------------------------" << endl;
				nv1.NhapNVVP();
				cout << endl << "----------------------------------------------------------" << endl;
				nv1.XuatNVVP();
				f.close();
				
				break;
			case 2:
				f.open("DU_LIEU/NHAN_VIEN_SAN_XUAT_LUU.txt", ios::out | ios::app);
				cout << endl << "----------------------------------------------------------" << endl;
				nv2.NhaPNVSX();
				cout << endl << "----------------------------------------------------------" << endl;
				nv2.XuatNVSX();
				f.close();
				
				break;
			case 3:
				f.open("DU_LIEU/NHAN_VIEN_VAN_PHONG.txt", ios::in);
				getline(f, s);
				n = atoi(s.c_str());
				for(int i = 0; i < n; i++)
					nv3[i].NhapFileNVVP();
				f.close();
				for(int i = 0; i < n; i++){
					cout << endl << "----------------------------------------------------------" << endl;
					cout << "nhan vien " << i+1 << ":" << endl;
					nv3[i].XuatNVVP();
				}
				cout << endl << "----------------------------------------------------------" << endl;
				cout << "nhan 1 de xem tien luong trung binh cua nhan vien van phong (0 de thoat): ";
				cin >> m;
				if(m == 1){
					for(int i = 0; i < n; i++){
						ltb += nv3[i].TinhLuongNVVP();
					}
					cout << "luong trung binh la: " << ltb/n << endl;
				}
				
				break;
			case 4:
				f.open("DU_LIEU/NHAN_VIEN_SAN_XUAT.txt", ios::in);
				getline(f, s);
				n = atoi(s.c_str());
				for(int i = 0; i < n; i++)
					nv4[i].NhapFileNVSX();
				f.close();
				for(int i = 0; i < n; i++){
					cout << endl << "----------------------------------------------------------" << endl;
					cout << "nhan vien " << i+1 << ":" << endl;
					nv4[i].XuatNVSX();
				}
				
				break;
			case 0:
				break;
		}
	}while(x != 0);
}
// --- ket thuc chuong trinh chinh ---
