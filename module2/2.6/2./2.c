#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
	FILE *in, *out;
	char ch;
	char a[3]={'1', '0', '1'};
	int i=0;
	if (argc !=2) {
	    printf("File: %s\n", argv[0]);
    }
    if ((in=fopen(argv[1], "rb"))==NULL) {
	    printf("Ошибка при открытии файла\n");
	    exit(1);
    }
    if ((out=fopen("output.txt", "wb"))==NULL) {
	    printf("Ошибка при открытии файла\n");
	    exit(1);
    } 
    while(!feof(in)) {
    	fread(&ch, 1, 1, in);
        if(ch!='\n') {
            if(i==3) {
                i=0;
            }
    		ch^=a[i];
            i++;
        }
        fwrite(&ch, 1, 1, out);
    }	
    fclose(in);
    fclose(out);
    return 0;
}
