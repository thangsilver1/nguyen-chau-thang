#include <iostream>

using namespace std;

struct AVL{
	int gt;
	int cb;   // --- yeu to can bang: (-1 ,0 ,1) can bang / 2 lech trai / -2 lech phai ---
	AVL *tr;
	AVL *ph;
};

AVL *goc;

void Tao(AVL *&goc);   // --- tao goc cho cay AVL ---
void TaoCay(AVL *&goc, AVL *nut);   // --- tao dinh cua cay ---
void NhapNut(AVL *&goc);   // --- nhap cay ---
void XuatCay(AVL *goc);   // --- xuat cay ---
int ChieuCao(AVL *nut);   // --- chieu cao cay tai 1 nut ---
void NutCanBang(AVL *goc);   // --- ham xac dinh yeu to can bang cua 1 nut / gan cho nut luon ---
void KiemTraCB(AVL *&goc);   // --- kiem tra va hieu chinh cay sao cho can bang ---

void XoayTrTr(AVL *&nut);   // --- hieu chinh trai trai---
void XoayTrPh(AVL *&nut);   // --- hieu chinh trai phai ---
void XoayPhPh(AVL *&nut);   // --- hieu chinh phai phai ---
void XoayPhTr(AVL *&nut);   // --- hieu chinh phai trai ---
void XuLyXoay(AVL *&nut);   // --- ham xu ly cac hieu chinh xoay ---

void XoaDinh(AVL *&goc);   // --- xoa dinh cua cay ---
void XoaNut(AVL *&goc, int x);   // --- xoa 1 nut co gia tri la x ---

void AVLChua(AVL *goc, int &co);   // --- kiem tra 1 cay co phai la cay AVL ---

// --- chuong trinh chinh ---
int main(){

	Tao(goc);
	
	NhapNut(goc);
	
	cout << endl;
	XuatCay(goc);
	
	cout << endl;
	int co = 0;
	AVLChua(goc, co);
	if(co == 1)
		cout << endl << "cay nay chua phai la cay AVL !!!";
	else
		cout << endl << "cay nay la cay AVL !!!";
	
	cout << endl;
	int i;
	cout << endl << "nhap gia tri can xoa: ";
	cin >> i;
	XoaNut(goc, i);
	
	cout << endl << "cay sau khi xoa la: " << endl;
	NutCanBang(goc);
	XuatCay(goc);
	co = 0;
	AVLChua(goc, co);
	if(co == 1)
		cout << endl << "cay nay chua phai la cay AVL !!!";
	else
		cout << endl << "cay nay la cay AVL !!!";
}

// --- cac ham xu ly ---

void Tao(AVL *&goc){
	goc = NULL;
}

void TaoCay(AVL *&goc, AVL *nut){
	if(goc == NULL){
		nut->tr = NULL;
		nut->ph = NULL;
		goc = nut;
	}
	else{
		if(nut->gt <= goc->gt)
			TaoCay(goc->tr, nut);
		else
			TaoCay(goc->ph, nut);
	}
}

void NhapNut(AVL *&goc){
	AVL *nut;
	do{
		nut = new AVL;
		cout << "nhap gia tri / nhap 0 de ket thuc nhap: ";
		cin >> nut->gt;
		if(nut->gt != 0){
			TaoCay(goc, nut);
			NutCanBang(goc);
			KiemTraCB(goc);
			NutCanBang(goc);
		}
	}while(nut->gt != 0);
}

void XuatCay(AVL *goc){
	if(goc != NULL){
		XuatCay(goc->tr);
		cout << goc->gt << "," << goc->cb << "\t";
		XuatCay(goc->ph);
	}
}

int ChieuCao(AVL *nut){
	if(nut == NULL)
		return 0;
	else
		return 1 + max(ChieuCao(nut->tr), ChieuCao(nut->ph));
}

void KiemTraCB(AVL *&goc){
	AVL *x;
	if(goc->cb == 2){
		x = goc->tr;
		if(x->cb == 2)
			KiemTraCB(goc->tr);
		else{
			x = goc;
			XuLyXoay(x);
			goc = x;
		}
	}
	else{
		if(goc->cb == -2){
			x = goc->ph;
			if(x->cb == -2)
				KiemTraCB(goc->ph);
			else{
				x = goc;
				XuLyXoay(x);
				goc = x;
			}
		}
	}
}

void NutCanBang(AVL *goc){
	if(goc != NULL){
		goc->cb = ChieuCao(goc->tr) - ChieuCao(goc->ph);
		NutCanBang(goc->tr);
		NutCanBang(goc->ph);
	}
}

void XoayTrTr(AVL *&nut){
	AVL *a, *b, *du;
	a = nut;
	b = nut->tr;
	du = b->ph;
	b->ph = a;
	a->tr = du;
	nut = b;
}

void XoayTrPh(AVL *&nut){
	AVL *a, *b, *c ,*ct, *cp;
	a = nut;
	b = nut->tr;
	c = b->ph;
	ct = c->tr;
	cp = c->ph;
	b->ph = ct;
	c->tr = b;
//	a->tr = c;
	a->tr = cp;
	c->ph = a;
	nut = c;
}

void XoayPhPh(AVL *&nut){
	AVL *a, *b, *du;
	a = nut;
	b = nut->ph;
	du = b->tr;
	b->tr = a;
	a->ph = du;
	nut = b;
}

void XoayPhTr(AVL *&nut){
	AVL *a, *b, *c ,*ct, *cp;
	a = nut;
	b = nut->ph;
	c = b->tr;
	ct = c->tr;
	cp = c->ph;
	b->tr = cp;
	c->ph = b;
//	a->ph = c;
	a->ph = ct;
	c->tr = a;
	nut = c;
}

void XuLyXoay(AVL *&nut){
	AVL *kt;
	if(nut != NULL){
		if(nut->cb == 2){
			kt = nut->tr;
			if(kt->tr != NULL)
				XoayTrTr(nut);
			else
				XoayTrPh(nut);
		}
		if(nut->cb == -2){
			kt = nut->ph;
			if(kt->tr != NULL)
				XoayPhTr(nut);
			else
				XoayPhPh(nut);
		}
	}
}

void XoaDinh(AVL *&goc){
	AVL *a, *b, *c, *d;
	a = goc;
	b = goc->tr;
	c = goc->ph;
	if(b->ph == NULL){
		b->ph = c;
		goc = b;
		delete a;
	}
	else{
		d = b;
		b = b->ph;
		while(b->ph != NULL){
			d = b;
			b = b->ph;
		}
		if(b->tr == NULL){
			b->ph = c;
			b->tr = goc->tr;
			d->ph = NULL;
			goc = b;
			delete a;
		}
		else{
			d->ph = b->tr;
			b->ph = c;
			b->tr = goc->tr;
			goc = b;
			delete a;
		}
	}
}

void XoaNut(AVL *&goc, int x){
	if(goc != NULL)
		if(goc->gt == x){
			if(goc->tr == NULL && goc->ph == NULL)
				goc = NULL;
			else
				XoaDinh(goc);	
		}
		else
			if(goc->gt >= x)
				XoaNut(goc->tr, x);
			else
				XoaNut(goc->ph, x);
}

void AVLChua(AVL *goc, int &co){
	if(goc != NULL){
		if(goc->cb == 2 || goc->cb == -2)
			co = 1;
		else{
			AVLChua(goc->tr, co);
			AVLChua(goc->ph, co);
		}
	}
}
