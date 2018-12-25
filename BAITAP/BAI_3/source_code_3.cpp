#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

fstream f;

struct DE{
	string CH;
	string DAA;
	string DAB;
	string DAC;
	string DA;
};

int MoDe(){
	string s;
	getline(f1)
	for(int )
}

void ChonDe(){
	int a;
	
	do{
		cout << "nhap so 1, 2 hoac 3 chon bo de tuong ung!!!" << endl;
		cout << "1. de 1" << endl << "2. de 2" << endl << "3. de 3" << endl;
		cin >> a;
		if(a < 1 || a > 3)
			cout << "chon sai!!! vui long chon lai!!!"
	}while(a < 1 || a > 3);
	
	if(a == 1){
		f.open("BO_DE/DE_1.txt", ios::out);
	}
	else
		if(a == 2){
			f.open("BO_DE/DE_2.txt", ios::out);
		}
		else{
			f.open("BO_DE/DE_3.txt", ios::out);
		}
	
}

bool KiemTraDA()
