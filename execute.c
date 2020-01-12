#include "execute.h"

void execute(char** a, int x){
	 fgpoint=0;
    x=x-1;
	int bg=0;
    
	if(a[x][0]=='&'){
		 bg=1;
		 jcount++;
		//printf("1\n");
	}
//Background Process
	// for (int i=0;i<=x;i++)
		// printf("%s\n",a[i]);
    if(strcmp(a[0],"ls") && strcmp(a[0],"cd") && strcmp(a[0],"pwd") && strcmp(a[0],"echo") && strcmp(a[0],"pinfo") && strcmp(a[0],"history") && strcmp(a[0],"nightswatch") && strcmp(a[0],"setenv") && strcmp(a[0],"unsetenv") && strcmp(a[0],"jobs")&& strcmp(a[0],"overkill")&& strcmp(a[0],"kjob")&& strcmp(a[0],"bg")&& strcmp(a[0],"fg"))
		{
			//printf(" world");
            pid_t pid_child = fork();
			if (pid_child < 0)
			{
				printf("Not able to fork properly\n");
				return;
			}
			else if (pid_child == 0)
			{   
				setpgid(0,0);
                int error=execvp(a[0],a);
					printf("Error in executing command\n");
					_exit(1);
			}
			else
			{
				if(bg==1){
					char pc[5];
					sprintf(pc, "%d", pid_child); 
					strcpy(job[jcount-1],pc);
					strcpy(job[jcount],a[0]);
					jcount++;
				}
				int status;
                if (!bg){
					fgpoint=pid_child;
					waitpid(pid_child, &status, WUNTRACED);
					if(WIFSTOPPED(status)){
						jcount++;
						char cp[5];
					    sprintf(cp, "%d", pid_child); 
						strcpy(job[jcount-1],cp);
						strcpy(job[jcount],a[0]);
						jcount++;
					}
					else
					printf("\nCommand %s with pid %d exited normally\n", a[0], (int)getpid());

					fgpoint=0;
				}
                //printf("%d\n",status);
				//if (!bg && status != 0)			
					//printf("\nCommand %s with pid %d did not exited normally\n", a[0], (int)getpid());
				
			}
		
		}




}
