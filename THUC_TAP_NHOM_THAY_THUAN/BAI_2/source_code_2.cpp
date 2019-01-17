#include <iostream>
#include <string.h>

using namespace std;

// --- tao cau truc cua van ba ---
struct VB {
	char nd[100];// --- noi dung van ban ---
	VB *sau;// --- phan dau ---
	VB *truoc;// --- phan duoi ---
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
	
		if(strcmp(tam, "\0") != 0){// --- noi dung khac enter ---
			
			p = new VB;
			p->sau = NULL;
			p->truoc = NULL;
			strcpy(p->nd, tam);
	
			if(dau == NULL)// --- dong dau tien ---
				dau = p;
			else// --- cac dong sau ---
				q->sau = p;
	
			p->truoc = q;
			q = p;
		}	
	}while(strcmp(tam, "\0") != 0);// --- khi noi dung bang enter thi ket thuc ---
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

// --- kiem tra co dong i -> j co xuat hien trong van ban khong ---
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

// --- hien thi van ban tu dong i den dong j ---
void HThiIJ(VB *dau, int i, int j){
	
	dau = Dong(i);
	cout << endl << "noi dung dong thu " << i << " den dong thu " << j << " la:" << endl;
	
	if(KTIJ(dau, i, j) == 1){// --- kiem tra xem co dong i den dong j khong ---

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
	gets(tam);// --- tao noi dung cho dong can chen ---
	
	while(dau != NULL){// --- chay den cuoi van ban ---
		p = dau;
		dau = dau->sau;
	}
	
	// --- moc dong can chen vao cuoi van ban ---
	q = new VB;
	strcpy(q->nd, tam);
	p->sau = q;
	q->truoc = p;
	q->sau = NULL;

}

// --- xoa dong thu i den dong thi j ---
void XoaIJ(VB *&dau, int i, int j){

	VB *p, *q, *s;

	if(KTIJ(dau, i, j) == 1){// --- kiem tra dong i den j co xuat hien trong van ban khong ---
		
		while(i <= j){
			
			// --- xoa tu tren xuong neu i la dong dau tien cua van ban ---
			if(i == 1){// --- vi tri i nam dau van ban ---
				p = dau;
				dau = dau->sau;
				dau->truoc = NULL;
				delete p;
			}
			
			else{
				
				p = Dong(i);// --- di den dong thu i ---
				
				// --- xoa tu duoi len neu j la dong cuoi cung cua van ban ---
				if(p->sau == NULL){// --- vi tri j nam cuoi van ban ---
					q = p->truoc;
					q->sau = NULL;
					delete p;
				}
				
				// --- xoa tu tren xuong neu dong i va j nam giua van ban ---
				else{// --- vi tri can xoa nam giua van ban ---
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

// --- chep noi dung dong I(p) vao sau dong K(q) ---
void ChepIK(VB *dau, VB *p, VB *q){
	
	VB *s, *c;
	
	s = q->sau; // --- dong s: dong sau dong k(q) ---
	c = new VB; // --- tao moi 1 bien VB de sao chep ---
	strcpy(c->nd, p->nd); // --- sao chep noi dung dong I(p) vao c ---
	q->sau = c;// --- moc dong c vao sau dong K(q) ---
	c->truoc = q;// --- moc K(q) vao truoc dong dong c ---
	c->sau = s;// --- moc dong s vao sau dong c ---
	s->truoc = c;// ---  moc dong c vao truoc dong s ---
}

// --- chep noi dung dong i den j vao sau dong k ---
void ChepIJK(VB *dau, int i, int j, int k){
	
	VB *p, *sp;
	VB *dd[j-i+1];// --- mang chua dia chi dong i den dong j
	
	if(KTIJ(dau, i, j) == 1){// --- kiem tra xem dong i den j co xuat hien trong van ban khong ---
		
		int dem = i;
		
		// --- dua dia chi cua dong i den dong j vao mang dd[] ---
		for(int a = 0; a <= j-i; a++){
			dd[a] = Dong(dem);// --- gan dia chi co phan tu cua mang ---
			dem++;
		}
		
		// --- bat dau chep noi dung dong i den j vao sau dong k ---
		for(int a = 0; a <= j-i; a++){
			p = Dong(k);// --- chay den dong k ---
			ChepIK(dau, dd[a], p); // --- chep noi dung dong i vao sau dong k ---
			k++;// --- xac dinh vi tri tiep theo de chep noi dung ---
		}
	}
}


int main() {
	
	TaoVB(dau);
	int i;
	int j;
	int k;

// --- nhap va hien thi van ban vua nhap ---
	NhapVB(dau);
	cout << endl << "---------------------------------------------------------";
	cout << endl << "noi dung van ban vua tao la:" << endl << endl;
	HThi(dau);
	
// --- hien thi van ban tu dong i den dong j ---
	i =  2;
	j = 4;
	cout << endl << "---------------------------------------------------------";
	HThiIJ(dau, i, j);

// --- chen va hien thi noi dung van ban ---	
	cout << endl << "---------------------------------------------------------";
	ChenCuoi(dau);
	cout << endl << "noi dung van ban sau khi chen la:" << endl << endl;
	HThi(dau);
	
// --- xoa va hien thi noi dung van ban	---
	i = 3;
	j = 5;
	XoaIJ(dau, i, j);
	cout << endl << "---------------------------------------------------------";
	cout << endl << "noi dung van ban sau khi xoa tu dong thu " << i << " den dong thu " << j << " la:" << endl << endl;
	HThi(dau);
	
// --- chep noi dung i den j vao sau k va hien thi noi dung ---
	i = 2;
	j = 4;
	k = 2;
	ChepIJK(dau, i, j, k);
	cout << endl << "---------------------------------------------------------";
	cout << endl << "noi dung van ban sau khi chen dong thu " << i << " den dong thu " << j << " vao sau dong " << k << " la:" << endl << endl;
	HThi(dau);
	
}
