// code bai 5
#include <stdio.h>
#include <dos.h>
#include <conio.h>
int ltime = 0, ttime = 0, times[5];
void interrupt(*dos_interrupt)();
void interrupt lock_interrupt(){
	ltime++;
	ttime++;
	(*dos_interrupt)();
}
int main(){
	char line[80];
	int i, total, n = 5;
	dos_interrupt = getvect(8);
	disable();
}
