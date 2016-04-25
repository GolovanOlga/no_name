#include <stdio.h>
#include <stdlib.h>
int main () {
	FILE *in, *out;
	char ch, a='A';
	int c=0;
	if ((in=fopen("input.txt", "r"))==NULL) {
	    printf("Ошибка при открытии файла\n");
	    exit(1);
    } 
    if ((out=fopen("output.txt", "w"))==NULL) {
	    printf("Ошибка при открытии файла\n");
	    exit(1);
    } 
    while(!feof(in)) {
    	ch=getc(in);
    	if(!feof(in)) {
    		ch^=a;
    		putc(ch, out);
    		c++;
    	}
    }	
    fclose(in);
    fclose(out);
    if ((in=fopen("output.txt", "r"))==NULL) {
	    printf("Ошибка при открытии файла\n");
	    exit(1);
    } 
    if ((out=fopen("output2.txt", "w"))==NULL) {
	    printf("Ошибка при открытии файла\n");
	    exit(1);
    } 
    while(!feof(in) && c>0) {
    	ch=getc(in);
    	if(!feof(in)) {
    		ch^=a;
    		putc(ch, out);
    		c--;
    	} 
    }
    return 0;
}
