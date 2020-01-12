#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include "getinput.c"
#include "commands.h"
#include "ls.h"
#include "pinfo.h"
#include "execute.h"
#include "his.h"
 
int space=2;
int quant=0;

char right[100000][100000];

 if(sep[0]=="cronjob"){
     while(sep[space]!="-t"){
         //right[space-2]=sep[space];
         strcpy(right[space-2],sep[space]);
         space++;
     }

     int tim=sep[space+1];
     int period=sep[space+3];

     while(1){
         sleep(tim);
         quant=quant+tim;
         commands(right,cwd,i);

        ls(right,i,current);
    
        pinfo(right,i);
    
        execute(right,i);
        HISTORY_STATE *myhist;
        HIST_ENTRY **mylist;
    
        his(right,i,myhist,mylist);

        if(quant>period)
            break;
    
     }
 }