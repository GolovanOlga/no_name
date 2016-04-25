#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
	FILE *in, *out;
	char ch;
	char a[3]={'1', '0', '1'};
	int i=0, c=0;
	if (argc !=2) {
	    printf("File: %s\n", argv[0]);
    }
    if ((in=fopen(argv[1], "r"))==NULL) {
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
    		if(i==3) 
    			i=0;
    		ch^=a[i];
    		i++;
    		putc(ch, out);
    	}
    }	
    fclose(in);
    fclose(out);
    return 0;
}

