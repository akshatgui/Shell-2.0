#include "commands.h"


void commands(char** a,char c[],int n){

    
   // printf("%s\n",a[0]);
//pwd 
    if(!strcmp(a[0],"pwd")){
        //printf("%s",)
        char pwd[1000000];
        getcwd(pwd, sizeof(pwd));
        printf("%s\n",pwd);
    }


//echo
    if(!strcmp(a[0],"echo")){
        int b=1;
        while(a[b]){
            printf("%s ",a[b]);
            b++;
        }
        printf("\n");
    }

//cd
    if(!strcmp(a[0],"cd")){
        if(n==1){
            chdir(c);
        }
        else{
            if(a[1][0]=='~'){
                char* string;
                string=(char*)malloc(1024*sizeof(char));

                int i=0;
                while(c[i]){
                    string[i]=c[i];
                    i++;
                }
                int j=1;
                while(a[1][j]){
                    string[i]=a[1][j];
                    i++;
                    j++;
                }
                string[i]='\0';
                chdir(string);
            }
            else
                chdir(a[1]);
        }    
    }

}