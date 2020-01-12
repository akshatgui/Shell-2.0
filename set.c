#include "set.h"


void set(char** a, int i){
  if(!strcmp(a[0],"setenv")){
    if(i==1 || i>3){
        printf("error");
    }

    int q=setenv(a[1],a[2],1);
    if(q==1)
        printf("Error");
  }
}