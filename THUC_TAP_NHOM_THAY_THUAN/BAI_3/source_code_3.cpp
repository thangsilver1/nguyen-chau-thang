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
void KiemTraCB(AVL *&goc);
void XoayTrTr(AVL *&nut);   // --- hieu chinh trai trai---
void XoayTrPh(AVL *&nut);   // --- hieu chinh trai phai ---
void XoayPhPh(AVL *&nut);   // --- hieu chinh phai phai ---
void XoayPhTr(AVL *&nut);   // --- hieu chinh phai trai ---
void XuLyXoay(AVL *&nut);   // --- ham xu ly cac hieu chinh xoay ---


int main(){

	Tao(goc);
	
	NhapNut(goc);
	
//	NutCanBang(goc);
	
	XuatCay(goc);
	
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

