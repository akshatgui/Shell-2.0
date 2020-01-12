#include "cronjob.h"

void cronjob(char** a){

int space=2;
        int quant=0;
                 //printf("%d\n",strcmp(a[space],"-t"));
    char** right;
    right=(char**)malloc(1024*sizeof(char*));
    right[0]=(char*)malloc(1024*sizeof(char));
    int qw=0;

    while(qw<100){
            qw++;
            right[qw]=(char*)malloc(1024*sizeof(char));

    }

     while(strcmp(a[space],"-t")){
         
         //right[space-1]=a[space];
         //printf("HI\n");
        strcpy(right[space-2],a[space]);
         space++;
     }

    // printf("Hi\n");

     int tim=atoi(a[space+1]);
     int period=atoi(a[space+3]);

    // printf("%d\n",tim);
    //  printf("%d\n",space);
     //printf("%s\n",right[0]);
        // printf("%s\n",right[1]);


     while(1){
         sleep(tim);
         quant=quant+tim;
         commands(right,cwd,space-2);

        ls(right,space-2,current);
    
        pinfo(right,space-2);
    
        execute(right,space-2);
        HISTORY_STATE *myhist;
        HIST_ENTRY **mylist;
    
        his(right,i,myhist,mylist);

        if(quant>period)
            break;
    
     }

}