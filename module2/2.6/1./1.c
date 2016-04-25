#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]) {
FILE *fp;
struct text {
char line[30];
};
int u, N;
u=sizeof(struct text);
scanf ("%d", &N); //N - число слов в тексте
N=N*u;
struct text text_info[N];
if (argc !=2) {
	printf("File: %s\n", argv[0]);
}
if ((fp=fopen(argv[1], "r"))==NULL) {
	printf("Ошибка при открытии файла\n");
	exit(1);
}
int i=0, k,n, m=1, t=0, T;
// while делит текст на слова, для каждого слова создаётся массив
while (fscanf(fp, "%s", text_info[i].line)!=EOF) { 
	i++;
}
fclose(fp);
k=i;
int B[k];
/*B[k] - массив, элементами которого являются значения
соответствующие кол-ву встречаемости слов в тексте*/
i=0;
/*while удаляет знаки препинания из строки*/
while(i<k) {
	while(text_info[i].line[t]!='\0') {
		if (text_info[i].line[t]==33 || text_info[i].line[t]==34 || text_info[i].line[t]== 39 || text_info[i].line[t]==44 || text_info[i].line[t]==45 || text_info[i].line[t]==46 || text_info[i].line[t]==58 || text_info[i].line[t]==59 || text_info[i].line[t]==63) {
			T=t;
			while (text_info[i].line[t]!='\0') {
				text_info[i].line[t]=text_info[i].line[t+1];
				t++;
			}
			t=T+1;
		}
		else {t++;}
	}
	t=0;
	i++;
}
i=0;
/*while сравнивает слова и записывает в массив B сколько 
раз слово встретится в тексте*/
while(i<k) {
	n=i+1;
	while(n<k) {
		if (strcmp(text_info[i].line, text_info[n].line)==0) {
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
/*если слово уже встречалось в тексте, то while зануляет
соответствующее значение в массиве B */
while(i<k) {
	n=i+1;
	while(n<k) {
		if (strcmp(text_info[i].line, text_info[n].line)==0) {
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
/*вывод в файл слов и их количества в тексте*/
while(k>0) {
	while(i<n) {
		if(B[i]==k) {
			if(text_info[i].line[0]!='\0'){
			fprintf(fp, "%s  %d\n", text_info[i].line, B[i]);}
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
fclose(fp);
return 0;
}
