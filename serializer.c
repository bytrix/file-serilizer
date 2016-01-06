#include <stdio.h>
#include <windows.h>
int rt_num(FILE *fp){
	int count_rt=0;
	char ch;
	while(ch!=EOF){
		ch=fgetc(fp);
		if(ch=='\n'){
			count_rt++;
		}
	}
	fclose(fp);
	return count_rt;
}
int main(){
	FILE *fp;
	FILE *bat;
	char ch;
	char f[100];
	char ext[10];
	char cmd[100];
	char buffer[100];
	int i=1;
	int file_num;
	//转换文件列表（TXT文档）
	printf("Enter the TXT file name which lists the file set you want to rename:\n  :");
	scanf("%s", f);

	//最终文件的扩展名
	printf("The file extension of your final file\n  :");
	scanf("%s", ext);

	sprintf(cmd,"dir *.%s/b>%s",ext,f);
	system(cmd);

	fp=fopen(f,"r");
	//读取文件个数(即行数)
	file_num=rt_num(fp);
	fp=fopen(f,"r");
	bat=fopen("serializer.bat","w");
	printf("========== BATCH COMMAND ==========\n");
	printf("ren ");
	fputs("@echo off\nren ",bat);
	while(ch!=EOF && ch!=0xFF){
		ch=fgetc(fp);
		if(ch=='\n'){
			printf(" %d.%s",i,ext);
			sprintf(buffer," %d.%s",i,ext);
			fputs(buffer,bat);
			ch=' ';
			if(i!=file_num){
				printf("\nren");
				fputs("\nren",bat);
			}else{
				printf("\n");
				fputs("\n",bat);
			}
			i++;
		}
		printf("%c",ch);
		sprintf(buffer,"%c",ch);
		fputs(buffer,bat);
	}
	return 0;
}