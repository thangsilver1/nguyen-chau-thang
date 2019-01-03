#include <iostream>

using namespace std;

struct AVL{
	int gt;
	int cb;
	AVL *tr;
	AVL *ph;
};

// --- tao goc cho cay AVL ---
AVL *goc;
void Tao(AVL *&goc){
	goc = NULL;
}

// --- ham xac dinh yeu to can bang cua 1 nut ---
int NutCanBang(AVL *goc){
	if(goc->tr == NULL && goc->ph == NULL)
		return 0;
	else
		if(goc->tr != NULL && goc->ph == NULL)
			return 1 + NutCanBang(goc->tr);
		else
			if(goc->tr == NULL && goc->ph != NULL)
				return 1 + NutCanBang(goc->ph);
			else
				if(goc->tr != NULL && goc->ph != NULL)
					return (1 + NutCanBang(goc->tr)) - (1 + NutCanBang(goc->ph));
}

// --- moc 1 nut vao cay ---
void Moc(AVL *&goc, int x){
	if(goc == NULL){
		goc = new AVL;
		goc->gt = x;
		goc->ph = NULL;
		goc->tr = NULL;
	}
	else
		if(x >= goc->gt)
			Moc(goc->ph, x);
		else
			Moc(goc->tr, x);
}

// --- nhap cay ---
void NhapCay(AVL *&goc){
	int x;
	do{
		cout << "nhap gia tri / nhap 0 de ket thuc nhap: ";
		cin >> x;
		if(x != 0)
			Moc(goc, x);
	}while(x != 0);
}

// --- xuat cay ---
void XuatCay(AVL *goc){
	if(goc != NULL){
		XuatCay(goc->ph);
		cout << goc->gt << "\t";
		XuatCay(goc->tr);
	}
}

// --- dem so la cua cay ---
int DemLa(AVL *goc){
	if(goc == NULL)
		return 0;
	else
		if(goc->ph == NULL && goc->tr == NULL)
			return 1;
		else
			return DemLa(goc->tr) + DemLa(goc->ph);
}

// --- tim vi tri cua nut mang gia tri x ---
int TimVT(AVL *goc, int x){
	if(goc != NULL)
		if(x == goc->gt)
			return 1;
		else
			if(x < goc->gt)
				return TimVT(goc->tr, x)*2;
			else
				return TimVT(goc->ph, x)*2 + 1;
}

// --- in chieu cao cay ---
int ChieuCao(AVL *goc){
	if(goc == NULL)
		return 0;
	else
		return 1 + max(ChieuCao(goc->tr), ChieuCao(goc->ph));
}

// --- dem so nut cua cay ---
int DemNut(AVL *goc){
	if(goc == NULL)
		return 0;
	else
		return 1 + DemNut(goc->tr) + DemNut(goc->ph);
}

// --- in cac gia tri tai muc i ---
void InMuc(AVL *goc, int i){
	if(goc != NULL)
		if(i == 1)
			cout << "\t" << goc->gt;
		else{
			i = i - 1;
			InMuc(goc->tr, i);
			InMuc(goc->ph, i);
		}
}

// --- tong cac nut o muc i ---
int TongMuc(AVL *goc, int i){
	if(goc == NULL)
		return 0;
	else
		if(i == 1)
			return goc->gt;
		else{
			i = i - 1;
			return TongMuc(goc->tr, i) + TongMuc(goc->ph, i);
		}
}


int main(){

	Tao(goc);
	NhapCay(goc);
	XuatCay(goc);
	
	cout << endl << NutCanBang(goc);
//	cout << endl << "so la cua cay: " << DemLa(goc);
//	cout << endl << "vi tri nut mang gia tri x: " << TimVT(goc, 6);
//	cout << endl << "chieu cao cay: " << ChieuCao(goc);
//	cout << endl << "so nut cua cay: " << DemNut(goc);
//	cout << endl << "cac gia tri tai muc i: ";
//	InMuc(goc, 3);
//	cout << endl << "tong cac gia tri tai muc i: " << TongMuc(goc, 3);
}
