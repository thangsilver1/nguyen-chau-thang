#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

fstream f;
fstream g;

struct DE{
	string CH;
	string DAA;
	string DAB;
	string DAC;
	string DA;
};

// --- ham kiem tra dap an dung va dap an nguoi thi ---
bool KiemTraDA(string a, string b){
	if(a.substr(0, 1).compare(b) == 0)
		return true;
	else
		return false;
}

// --- ham yeu cau luu diem ---
void LuuDiem(int diem){
	int a;
	do{
		cout << "chon 1 de luu diem / chon 2 de khong luu diem!!!" << endl;
		cin >> a;
		if(a < 0 || a > 2)
			cout << "chon lai!!!" << endl;
	}while(a < 0 || a > 2);
	if(a == 1){
		string s;
		cout << endl << "nhap ten de luu diem: ";
		fflush(stdin);
		getline(cin, s);
		g.open("DIEM/LUU_DIEM.txt", ios::out | ios::app);
		g << s << "\t\t" << diem << "\n";
		g.close();
		cout << "luu diem thanh cong" << endl << endl;
	}
}

// --- ham mo de thi trong thu muc BO_DE ---
void MoDe(){
	string s;
	string x;
	int diem = 0;
	
	getline(f, s);
	cout << s << endl;
	getline(f, s);
	for(int i = atoi(s.c_str()); i > 0; i--){
		getline(f, s);		// --- dong 1 / cau hoi ---
		cout << s << endl;
		getline(f, s);		// --- dong 2 / dap an A ---
		cout << s << endl;
		getline(f, s);		// --- dong 3 / dap an B ---
		cout << s << endl;
		getline(f, s);		// --- dong 4 / dap an C ---
		cout << s << endl;
		getline(f, s);		// --- dong 5 / dap an dung ---
		cout << "cau tra loi cua ban la: ";
		fflush(stdin);
		getline(cin, x);	// --- dap an nguoi thi ---
		cout << endl;
		// --- kiem tra dap an dung voi dap an nguoi thi va cong diem ---
		if(KiemTraDA(s, x) == true)
			diem += 2;
	}
	cout << "da hoan thanh bai kiem tra!!!" << endl << endl;
	LuuDiem(diem);
	
}

// --- xem diem da luu trong LUU_DIEM.txt

void ChonDe(){
	int a;
	
	do{
		cout << "nhap so 1, 2 hoac 3 chon bo de tuong ung!!!" << endl;
		cout << "1. de 1" << endl << "2. de 2" << endl << "3. de 3" << endl;
		cin >> a;
		if(a < 1 || a > 3)
			cout << "chon sai!!! vui long chon lai!!!";
	}while(a < 1 || a > 3);
	
	if(a == 1){
		f.open("BO_DE/DE_1.txt", ios::in);
		MoDe();
		f.close();
	}
	else
		if(a == 2){
			f.open("BO_DE/DE_2.txt", ios::in);
			MoDe();
			f.close();
		}
		else{
			f.open("BO_DE/DE_3.txt", ios::in);
			MoDe();
			f.close();
		}
}

int main(){
	
	ChonDe();
	
	
}
