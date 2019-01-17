#include <iostream>
#include <fstream>
#include <stdlib.h>

#define max 20

using namespace std;

struct BienLuu{
	int ten;// --- ghi lai vi tri da di qua truoc do ---
	int tong;// --- tong do dai doan duong di duoc ---
	int co;// --- 0: chua xet / 1: da xet ---
};

// --- nhap ma tran nxn / tao moi do thi / luu do thi ---
void NhapMaTran(int &n, int a[max][max]){
	fstream f;
	
	cout << "nhap cap ma tran nxn: n = ";
	cin >> n;
	
	// --- nhap ma tran ---
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}	
	
	// --- luu ma tran vao file ---
	f.open("DU_LIEU/MA_TRAN.txt", ios::out);
	
	f << n << "\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			f << a[i][j] << " ";
		}
		f << "\n";
	}
	
	f.close();
			
}

// --- doc ma tran trong file ra mang 2 chieu ---
void MoDoThi(int &n, int a[max][max]){
	
	fstream f;
	string s;
	
	f.open("DU_LIEU/MA_TRAN.txt", ios::in);
	
	getline(f, s);// --- dong dau tien ---
	n = atoi(s.c_str());// --- cap ma tran vuong nxn ---
	for(int i = 0; i < n; i++)// --- cac dong tiep theo ---
		for(int j = 0; j < n; j++)
			f >> a[i][j];// ---gan cac gia tri tuong ung trong ma tran ---
	
	f.close();
	
}

// --- test du lieu mang 2 chieu / xuat mang 2 chieu ---
void XuatMaTran(int n, int a[max][max]){
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
			
}

// --- ham dieu kien de gan gia tri bien phu cho bien chinh ---
void SoSanh(BienLuu &bc, BienLuu &bp){
	
	if(bc.co != 1){//--- chi thuc hien khi gia tri co = 0 ---
		if(bc.tong == 0){// --- bien chinh co gia tri tong = 0 ---
			bc.ten = bp.ten;
			bc.tong = bp.tong;
		}
		else{// --- khi bien chinh co tong khac 0 ---
			if(bp.tong != 0 && bc.tong > bp.tong){// bien phu phai khac 0 va bien phu co tong < tong bien chinh ---
				bc.ten = bp.ten;
				bc.tong = bp.tong;
			}
		}
	}
	
}

// --- chon diem co tong duong di nho nhat va bat co = 1 / danh dau vi tri da di qua ---
void Duyet(int n, BienLuu bc[max], int &vt){
	
	int ln = 1000;// --- bien dung de so sanh ---
	
	for(int i = 0; i < n; i++){
		
		if(bc[i].co != 1 && bc[i].tong != 0){// --- xet cac vi tri chua di qua co tong khac 0 ---
		
			if(bc[i].tong < ln){
				vt = i;// --- luu vi tri co duong di ngan nhat ---
				ln = bc[i].tong;// --- thay doi gia tri ln de kiem tra toi uu hon ---
			}
		
		}

	}
	
	bc[vt].co = 1; // --- tra ve vi tri hang cho lan duyet ma tran tiep theo ---

}

// --- xuat ra lo trinh duong di ngan nhat tu mang bien chinh ---
void LoTrinh(int n, BienLuu a[max], int x, int y){
	
	cout << endl << "do dai duong di ngan nhat: " << a[y].tong << endl;
	cout << "lo trinh:  " << y;
	while(y != x){
		y = a[y].ten;
		cout << " <-- " << y;
	}
	
}

// --- luu ket qua vao file ---
void LuuKQ(int n, BienLuu bc[max], int x, int y){
	
	fstream f;
	
	f.open("DU_LIEU/LUU_KET_QUA.txt", ios::out);
	
	f << "diem bat dau: " << x << "\n";
	f << "diem ket thuc: " << y << "\n";
	f << "do dai duong di ngan nhat la: " << bc[y].tong << "\n";
	f << "lo trinh:  " << "\t" << y;
	while(y != x){
		y = bc[y].ten;
		f << " <-- " << y;
	}
	
	f.close();
}

// --- ham tim duong di ngan nhat ---
void TimDuong(int n, int a[max][max]){
	
	BienLuu BC[6];// --- bien chinh ---
	BienLuu BP;// --- bien phu ---
	
	BP.co = 0;
	
	// --- khoi tao hang dau tien ---
	for(int i = 0; i < n; i++){
		BC[i].ten = 0;
		BC[i].tong = 0;
		BC[i].co = 0;
	}
	
	int bd;
	int kt;
	
	// --- nhap diem bat dau ---
	do{
		cout << "nhap diem bat dau: ";
		cin >> bd;
		if(bd < 0 || bd > n-1)
			cout << "khong tim thay diem bat dau !!! nhap lai !!!" << endl;
	}while(bd < 0 || bd > n-1);
	cout <<  endl;
	
	// --- nhap diem ket thuc ---
	do{
		cout << "nhap diem ket thuc: ";
		cin >> kt;
		if(kt < 0 || kt > n-1)
			cout << "khong tim thay diem ket thuc !!! nhap lai !!!" << endl;
	}while(kt < 0 || kt > n-1);	
	cout << endl;
	
	int x = bd;// --- vi tri bat dau ---
	int y = kt;// --- vi tri ket thuc ---
	int i = x;// --- bat dau doc ma tran tu hang x / vi tri bat dau tim duong ---
	
	// --- danh dau vi tri bat dau ---
	BC[x].co = 1;
	
	cout << endl << "---------------------------------------------" << endl;
	cout << "qua trinh tim duong di ngan nhat:" << endl << endl;
	
	
	// --- vi tri cac diem / lam cho dep ---
	for(int l = 0; l < n; l++){
		cout << l << "\t";
	}
	cout << endl << "---------------------------------------------" << endl;
	
	// --- bat dau xu ly tim duong di ngan nhat ---
	do{
		
		for(int j = 0; j < n; j++){
			
			// --- gan cho bien phu cac gia tri ten va gia tri tong ---
			if(a[i][j] != 0){// --- xu ly khi gia tri ma tran tai hang i cot j khac 0 ---
				BP.ten = x;
				BP.tong = a[i][j] + BC[x].tong;
			}
			else{// --- xu ly khi gia tri ma tran tai hang i cot j bang 0 ---
				BP.ten = 0;
				BP.tong = 0;
			}
			
			SoSanh(BC[j], BP);
		
		}
		
		// --- xuat ra qua trinh thay doi gia tri cua mang BC[] theo dong ---
		for(int c = 0; c < n; c++)
			cout << BC[c].ten << "," << BC[c].tong << "\t";
		cout << endl;
		
		Duyet(n ,BC, x);// --- danh dau vinh tri da di qua ---
		i = x;// --- dua i den hang tiep theo de doc ma tran ---
		
	}while(x != y);
	// --- ket thuc xu ly tim duong ngan nhat ---
	
	LoTrinh(n, BC, bd, kt);// --- xuat ra lo trinh duong di ---
	LuuKQ(n, BC, bd, kt);// --- luu cac thong tin ket qua ---
	
}

int main(){
	
	int n;
	int a[max][max];
	
//	NhapMaTran(n, a);// --- tao moi 1 do thi ---
	
	MoDoThi(n, a);// --- doc do thi tu file ---
	
	XuatMaTran(n ,a);// --- test ma tran doc dung chua ---
	
	cout << endl;
	
	TimDuong(n, a);// --- xu ly ---
	
}
