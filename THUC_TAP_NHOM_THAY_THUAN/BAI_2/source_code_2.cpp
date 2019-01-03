#include <iostream>
#include <string.h>

using namespace std;

// --- tao cau truc cua van ba ---
struct VB {
	char nd[100];
	VB *sau;
	VB *truoc;
};

// --- khoi tao 1 van ban ---
VB *dau;
void TaoVB(VB *&dau) {
	dau == NULL;
}

// --- nhap noi dung cua van ban ---
void NhapVB(VB *&dau) {
	char tam[100];
	VB *p, *q;
	do {
		cout << endl << "nhap noi dung cua van ban / ket thuc bang enter: " << endl;
		fflush(stdin);
		gets(tam);
		if(strcmp(tam, "\0") != 0){
			p = new VB;
			p->sau = NULL;
			p->truoc = NULL;
			strcpy(p->nd, tam);
			if(dau == NULL)
				dau = p;
			else
				q->sau = p;
			p->truoc = q;
			q = p;
		}
	} while(strcmp(tam, "\0") != 0);
}

// --- hien thi van ban ---
void HThi(VB *dau) {
	if(dau != NULL){
		cout << dau->nd << endl;
		HThi(dau->sau);
	}
}

// --- tra ve dia chi dong i ---
VB *Dong(int i){
	VB *p = dau;
	int dem = 1;
	while(p != NULL && dem != i){
		p = p->sau;
		dem++;
	}
	return p;
}

// --- kiem tra co dong i -> j khong ---
int KTIJ(VB *dau, int i, int j){
	VB *p, *q;
	p = Dong(i);
	q = Dong(j);
	if(p != NULL && q != NULL){
		return 1;
	}
	else{
		return 0;
	}
}

// --- hien thi dong i den dong j ---
void HThiIJ(VB *dau, int i, int j){
	dau = Dong(i);
	cout << endl << "noi dung dong i den dong j la:" << endl;
	if(KTIJ(dau, i, j) == 1){
		while(i <= j){
			cout << dau->nd << endl ;
			i++;
			dau = dau->sau;
		}
	}
}

// --- chen 1 dong vao cuoi van ban ---
void ChenCuoi(VB *dau){
	char tam[100];
	VB *p, *q;
	fflush(stdin);
	cout << endl << "nhap doan van ban can chen: " << endl;
	gets(tam);
	while(dau != NULL){
		p = dau;
		dau = dau->sau;
	}
	q = new VB;
	strcpy(q->nd, tam);
	p->sau = q;
	q->truoc = p;
	q->sau = NULL;
}

// --- xoa dong thu i den dong thi j ---
void XoaIJ(VB *&dau, int i, int j){
	VB *p, *q, *s;
	if(KTIJ(dau, i, j) == 1){
		while(i <= j){
			if(i == 1){
				p = dau;
				dau = dau->sau;
				dau->truoc = NULL;
				delete p;
			}
			else{
				p = Dong(i);
				if(p->sau == NULL){
					q = p->truoc;
					q->sau = NULL;
					delete p;
				}
				else{
					q = p->truoc;
					s = p->sau;
					q->sau = s;
					s->truoc = q;
					delete p;
				}
			}
			j--;
		}
	}
}

// --- chep noi dung dong p vao sau dong q ---
void ChepIK(VB *dau, VB *p, VB *q){
	VB *s, *c;
	
	s = q->sau; // --- dong sau dong q ---
	c = new VB; // --- tao moi 1 bien VB de sao chep ---
	strcpy(c->nd, p->nd); // --- sao chep noi dung p vao noi dung c ---
	q->sau = c;
	c->truoc = q;
	c->sau = s;
	s->truoc = c;
}

// --- chep noi dung dong i den j vao sau dong k ---
void ChepIJK(VB *dau, int i, int j, int k){
	VB *p, *sp;
	VB *dd[j-i+1];
	
	if(KTIJ(dau, i, j) == 1){
		int dem = i;
		
		// --- dua vi tri cua dong i den dong j vao mang dd[] ---
		for(int a = 0; a <= j-i; a++){
			dd[a] = Dong(dem);
			dem++;
		}
		
		// --- lay vi tri dong i den j trong mang dd [] va chep vao vi tri sau k ---
		for(int a = 0; a <= j-i; a++){
			p = Dong(k);
			ChepIK(dau, dd[a], p); // --- chep dd[] vao sau k ---
			k++;
		}
	}
}
int main() {
	
	TaoVB(dau);

// --- nhap va hien thi van ban vua nhap ---
	NhapVB(dau);
	cout << endl << "noi dung van ban vua tao:" << endl;
	HThi(dau);
	
// --- hien thi van ban tu dong i den dong j ---
	HThiIJ(dau, 2, 4);

// --- chen va hien thi noi dung van ban ---	
	ChenCuoi(dau);
	cout << endl << "noi dung van ban sau khi chen:" << endl;
	HThi(dau);
	
// --- xoa va hien thi noi dung van ban	---
	XoaIJ(dau, 3, 5);
	cout << endl << "noi dung van ban sau khi xoa:" << endl;
	HThi(dau);
	
// --- 
	ChepIJK(dau, 2, 4, 2);
	cout << endl << "noi dung van ban sau khi chen i den j vao sau k:" << endl;
	HThi(dau);
}
