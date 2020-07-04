#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	printf("1 - login your account\n");
	printf("2 - register your account\n");
	printf("* chose number\n");
	
	int x;
 	scanf("%d", &x);
 	
 	if(x == 1){
 		
 		
	 	printf("enter name\n");
	 	char acc_name[20];
	 	scanf("%s", &acc_name);
 		
 		// read account 
	 	FILE *f =fopen(acc_name,"r" );
	 	
	 	if(f == NULL){
	 		printf("the file is not found\n");
	 		exit(1);
	 	}
	 	
	 	fseek(f,0, SEEK_END);
	 	int sz = ftell(f);
	 	fseek(f,0, SEEK_SET);
	 	
	 	char *data = (char *)malloc(sz);
	 	fread(data, sizeof(char),sz , f );
	 	printf("you ara paasword is : %s\n\n", data);
	 	
	 	fclose(f);
	 	
	 }else if(x ==2){
		 // write account 
		 
		 
	 	printf("enter new name \n");
 		char acc_name[20];
	 	scanf("%s", &acc_name);
 		
 		
	 	printf("enter new oassword\n");
 		char Pass_Acc[20];
	 	scanf("%s", &Pass_Acc);
	 	
	 	FILE *f =fopen(acc_name,"w");
	 	
 		char *space = " _ ";
	 	
	 	fwrite(acc_name, sizeof(char),strlen(acc_name) , f );
	 	fwrite(space, sizeof(char),strlen(space) , f );
	 	fwrite(Pass_Acc, sizeof(char),strlen(Pass_Acc) , f );
	 	
	 	
	 	fclose(f);
 	}else{
	 	printf("the input not found !!");
	 }
 	
	return 0;
}
