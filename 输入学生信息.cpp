#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
struct student{
	char sno[30];
	char name[50];
	char sex[5];
	int age;
}stu[MAX];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s%s%d", stu[i].sno, stu[i].name, stu[i].sex,&stu[i].age);
		printf("%s\n", stu[i].sno);
	}
	int m;
	scanf("%d", &m);
	while (m) {
		char a[3];
		scanf("%s",a);
		int i;
		for (i = 0; i < n; i++) {
			if (strcmp(a, stu[i].sno)==0) {
				printf("%s %s %s %d\n", stu[i].sno, stu[i].name, stu[i].sex, stu[i].age); break;
			}
		}
		if(i==n) printf("No Answer!\n");
		m--;
	}
	//system("pause");
	return 0;
}
