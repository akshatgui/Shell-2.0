#include "unset.h"


void unset(char** a, int i){
  if(!strcmp(a[0],"unsetenv")){
    if(i==1){
        printf("error");
    }

    int q=unsetenv(a[1]);
    if(q==1)
        printf("Error");
  }
}