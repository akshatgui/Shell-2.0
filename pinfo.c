#include "pinfo.h"


void pinfo(char** a, int x){
   if(!strcmp(a[0],"pinfo")){ 

        int pid = (int)getpid();
    			if(x == 2)
    				pid = atoi(a[1]);

    			char buf[500], path[100];

    			sprintf(path, "/proc/%d/stat", pid);
    			FILE *fp = fopen(path, "r");
    			if(fp == NULL)
    			{
    				printf("Some error occured while running the command");
    
    			}
    			else
    			{
                    char A[50][50];

                    int k=0;
                    while(k<23){
                        fscanf(fp,"%s",A[k]);
                        k++;
                    }
    				printf("PID: %d\nFilename: %s\nProcess status: %s\nMemory: %s\n", pid, A[1], A[2], A[22]);
    				fclose(fp);
    			}

    			sprintf(path, "/proc/%d/exe", pid);
    			readlink(path, buf, 500);
    			printf("Executable path: %s\n", buf);

    }

}