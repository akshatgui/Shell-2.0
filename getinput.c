#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<pwd.h>
#include<grp.h>
#include <sys/wait.h>

int getin(char** a,char** b){
    int k=0;
    int j=0;
    a[0]=(char*)malloc(1024*sizeof(char));
    b[0]=(char*)malloc(1024*sizeof(char));

    char* buff = readline("");
    //strcpy(a, buf);
    while( (a[k] = strsep(&buff,";")) != NULL ){
        k++;
        a[k]=(char*)malloc(1024*sizeof(char));
        b[k]=(char*)malloc(1024*sizeof(char));
        strcpy(b[k-1],a[k-1]);
    
    }

    // while( (b[j] = strsep(&buff,";")) != NULL ){
    //     j++;
    //     b[j]=(char*)malloc(1024*sizeof(char));
    // }
    return k;
}
