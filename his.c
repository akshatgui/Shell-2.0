#include "his.h"

void his(char** sep,int i,HISTORY_STATE *myhist,HIST_ENTRY **mylist){
   
   if(!strcmp(sep[0],"history")){

           HISTORY_STATE *myhist = history_get_history_state ();
           HIST_ENTRY **mylist = history_list ();

       if(i==1){
           
           int k=myhist->length;
           k--;
         //  int l=myhist->length;
           if(myhist->length>=10){
               int j=0;
            while (j<10){
                printf (" %s\n", mylist[k]->line);
                j++;
                k--;
            }
           }
           else{
               while(k>0){
                    printf (" %s\n", mylist[k]->line);
                    k--;
               }
           }

       }

       else if(i==2){
           //printf("HAHA\n");
           long int v = strtol(sep[1],NULL,10);
           //printf("%ld\n",v);
           int k=myhist->length;
           k--;
         //  int l=myhist->length;
           if(myhist->length>=v){
               if(v>20)
                v=20;
               int j=0;
            while (j<v){
                printf (" %s\n", mylist[k]->line);
                j++;
                k--;
            }
           }
           else{
               int u=k;
               if (k>20)
                u=20;
               while(u>0){
                    printf (" %s\n", mylist[k]->line);
                    k--;
                    u--;
               }
           }

       }
   }

    }