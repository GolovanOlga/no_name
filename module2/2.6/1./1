#include <stdio.h>
#include <stdlib.h>
int main () {
FILE *fp;
struct text {
char line[100];
};
struct text text_info[1000];
if ((fp=fopen("read.txt", "r"))==NULL) {
	printf("Ошибка при открытии файла\n");
	exit(1);
}
int i=0, k,n, m=1, t=0, T;
while (fscanf(fp, "%s", text_info[i].line)!=EOF) {
	i++;
}
fclose(fp);
k=i;
int B[k];
i=0;
while(i<k) {
	n=i+1;
	while(n<k) {
		T=0;
		while(t<100) {
			if(text_info[i].line[t]==text_info[n].line[t]) {
				T++;
				t++;
			}
			else {t++;}
		}
		t=0;
		if(T==100) {
			m++;
			n++;
		}
		else {n++;}
	}
	B[i]=m;
	m=1;
	i++;
}
i=0;
while(i<k) {
	n=i+1;
	while(n<k) {
		T=0;
		while(t<100) {
			if(text_info[i].line[t]==text_info[n].line[t]) {
				T++;
				t++;
			}
			else {t++;}
		}
		t=0;
		if(T==100) {
			B[n]=0;
			n++;
		}
		else {n++;}
	}
	i++;
}
i=0;
n=k;
if((fp=fopen("results.txt", "w"))==NULL) {
	printf("Ошибка при открытии файла\n");
	exit(1);
}
while(k>0) {
	while(i<n) {
		if(B[i]==k) {
			fprintf(fp, "%s\n", text_info[i].line);
			i++;
		}
		else {i++;}
	}
	i=0;
	k--;
}
fclose(fp);
return 0;
}
