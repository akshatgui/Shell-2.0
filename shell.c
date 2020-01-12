#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include <errno.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "getinput.c"
#include "commands.h"
#include "ls.h"
#include "pinfo.h"
#include "execute.h"
#include "his.h"
#include "set.h"
#include "unset.h"
#include <signal.h> 
  
void sigintHandler(int sig_num) 
{ 
    if(fgpoint)
        kill(fgpoint,sig_num);
} 




char job[100][100];
int fgpoint;
int jcount=0;
char** sep;
char** pip;
char** sep1;

int dhupchik,lul,sad,happy;



int main(){
signal(SIGINT, sigintHandler);
signal(SIGTSTP, sigintHandler);
signal(SIGQUIT, sigintHandler);




char *x = getlogin();
char *y=malloc(1000000*sizeof(char));
gethostname(y, 1000000);
char cwd[1000000];
getcwd(cwd, sizeof(cwd));
int j=0;


while(1){

    char current[1000000];
    getcwd(current, sizeof(current));


//printing name if deeper than ~
    if(strstr(current,cwd)){
       int s=strlen(cwd);
         //printf("\033[1;31m");

       printf("\033[1;36m<%s\033[1;32m@\033[1;36m%s:\033[1;32m~%s/\033[1;36m>\033[0m",x,y,&current[s]);
    }
//printing name otherwise    
    else
    {
        //  printf("\033[1;31m");

        printf("\033[1;36m<%s\033[1;32m@\033[1;36m%s:\033[1;32m%s/\033[1;36m>\033[0m",x,y,&current[0]);
    }



    char** prompt;
    prompt=(char**)malloc(1024*sizeof(char));
    char** prp;
    prp=(char**)malloc(1024*sizeof(char));
    int z=getin(prompt,prp);
    int r=0;
    if(prompt[0]!= NULL){
    if(!strcmp(prompt[0],"quit")){
      //  printf("123\n");
        break;
    }
    }
    
    while(z>0){
        // printf("%d\n",z);
        add_history(prompt[r]);
        getcwd(current, sizeof(current));

    int pp=0;
    pip=(char**)malloc(1024*sizeof(char*));
    pip[0]=(char*)malloc(1024*sizeof(char));        

   // printf("%s\n",prp[0]);


    while( (pip[pp] = strsep(&prp[r],"|")) != NULL ){
        if(strlen(pip[pp]) == 0)
            continue;
        pp++;
        pip[pp]=(char*)malloc(1024*sizeof(char));
    }

    //printf("%d\n",pp);

    if(pp>1){
    int fd3 = open(",", O_WRONLY | O_CREAT| O_TRUNC ,0677);
	if (fd3 == -1) 
	{
		write(1,"Error in creating new file\n",27);
	}
    int i=0;
    sep=(char**)malloc(1024*sizeof(char*));
    sep[0]=(char*)malloc(1024*sizeof(char));
    int k=0;
    
   
    while( (sep[i] = strsep(&pip[0]," ")) != NULL ){
        if(strlen(sep[i]) == 0)
            continue;
        i++;
        sep[i]=(char*)malloc(1024*sizeof(char));
    }


//All Parts

    if (sep[0] == NULL){
        // printf("exiting\n");
        break;    printf("%s\n",prp[0]);
    }

    int save1= dup(1);
    dup2(fd3,1);

     lul=0;
     sad=0;
     happy=0;

    while(lul<i-1){
        if(strcmp(sep[lul],"<"))
            lul++;
        else{
             sad=3;
            break;
        }
                    
    }

    if(sad==3){
  //  printf("%d\n",lul);
    lul++;

    while(lul<i){
//        printf("BLAH\n");
        sep[lul-1]=sep[lul];
        lul++;
    }

    sep[i-1]=NULL;
    

        i--;

    }

    
        commands(sep,cwd,i);

    ls(sep,i,current);

    pinfo(sep,i);

    execute(sep,i);
    set(sep,i);
    unset(sep,i);
    HISTORY_STATE *myhist;
    HIST_ENTRY **mylist;
    close(fd3);
    his(sep,i,myhist,mylist);
    dup2(save1,1);
    
    sep1=(char**)malloc(1024*sizeof(char*));
    sep1[0]=(char*)malloc(1024*sizeof(char));
    i=0;
    while( (sep1[i] = strsep(&pip[1]," ")) != NULL ){
        if(strlen(sep1[i]) == 0)
            continue;
        i++;
        sep1[i]=(char*)malloc(1024*sizeof(char));
    }


    lul=0;
    

    while(lul<i-1){
        if(strcmp(sep1[lul],">"))
            lul++;
        else{
            //printf("%d\n",lul);
             happy=3;
            break;
        }
                    
    }

    if(happy==3){
    char** arrow;
    arrow=(char**)malloc(1024*sizeof(char*));
    arrow[0]=(char*)malloc(1024*sizeof(char));
    arrow[0]=sep1[lul+1];
    sep1[lul+1]=NULL;
    sep1[lul]==NULL;
    i--;
    i--;
    sep1[i]=NULL;
    //printf("%s\n",sep[i]);
    int fd4 = open(arrow[0], O_WRONLY | O_CREAT | O_RDONLY | O_TRUNC ,0677);
	if (fd4 == -1) 
	{
		write(1,"Error in creating new file\n",27);
	}
    fd3=open(",", O_RDONLY);
    if(fd3<0)
        printf("Erorr in o[pening file\n");
     int save2=dup(0);
     dup2(fd3,0);

    dhupchik= dup(1);
    dup2(fd4,1);

    commands(sep1,cwd,i);

    ls(sep1,i,current);

    pinfo(sep1,i);

    execute(sep1,i);
//    printf("lulli\n");
   

    his(sep1,i,myhist,mylist); 
    set(sep1,i);
    unset(sep1,i);
    dup2(save2,0);
    dup2(dhupchik,1);


    }
    else{
    i++;
    
   sep1[i-1]=",";

     commands(sep1,cwd,i);

    ls(sep1,i,current);

    pinfo(sep1,i);

    execute(sep1,i);
//    printf("lulli\n");
   

    his(sep1,i,myhist,mylist); 
    }


    }

//tokenizing the string 
    else{
    int i=0;
    sep=(char**)malloc(1024*sizeof(char*));
    sep[0]=(char*)malloc(1024*sizeof(char));
    int k=0;
    
   
    while( (sep[i] = strsep(&prompt[r]," ")) != NULL ){
        if(strlen(sep[i]) == 0)
            continue;
        i++;
        sep[i]=(char*)malloc(1024*sizeof(char));
    }


//All Parts

    if (sep[0] == NULL){
        // printf("exiting\n");
        break;    printf("%s\n",prp[0]);
    }
    // printf("dsadas\n");









     lul=0;
     sad=0;
     happy=0;
    int chill=0;
    while(lul<i-1){
        if(strcmp(sep[lul],"<"))
            lul++;
        else{
             sad=3;
            break;
        }
                    
    }

    if(sad==3){
  //  printf("%d\n",lul);
    lul++;

    while(lul<i){
//        printf("BLAH\n");
        sep[lul-1]=sep[lul];
        lul++;
    }

    sep[i-1]=NULL;
    

        i--;

    }

    lul=0;

    while(lul<i-1){
        if(strcmp(sep[lul],">>"))
            lul++;
        else{
             chill=3;
            break;
        }
                    
    }

    if(chill==3){
    char** arrow;
    arrow=(char**)malloc(1024*sizeof(char*));
    arrow[0]=(char*)malloc(1024*sizeof(char));
    arrow[0]=sep[lul+1];
    sep[lul+1]=NULL;
    sep[lul]==NULL;
    i--;
    i--;
    sep[i]=NULL;
    //printf("%s\n",sep[i]);
    int fd2 = open(arrow[0], O_WRONLY | O_CREAT | O_RDONLY | O_APPEND ,0677);
	if (fd2 == -1) 
	{
		write(1,"Error in creating new file\n",27);
	}

     dhupchik= dup(1);
    dup2(fd2,1);

    //Cronjob
     if(!strcmp(sep[0],"cronjob")){
         
         int space=2;
        int quant=0;
                 //printf("%d\n",strcmp(sep[space],"-t"));
    char** right;
    right=(char**)malloc(1024*sizeof(char*));
    right[0]=(char*)malloc(1024*sizeof(char));
    int qw=0;

    while(qw<100){
            qw++;
            right[qw]=(char*)malloc(1024*sizeof(char));

    }

     while(strcmp(sep[space],"-t")){
         
         //right[space-1]=sep[space];
         //printf("HI\n");
        strcpy(right[space-2],sep[space]);
         space++;
     }

    // printf("Hi\n");

     int tim=atoi(sep[space+1]);
     int period=atoi(sep[space+3]);

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
        set(right,space-2);
        unset(right,space-2);

        if(quant>period)
            break;
    
     }
 }






    else{
    commands(sep,cwd,i);

    ls(sep,i,current);

    pinfo(sep,i);

    execute(sep,i);
    HISTORY_STATE *myhist;
    HIST_ENTRY **mylist;

    his(sep,i,myhist,mylist);
    set(sep,i);
    unset(sep,i);

    }


    dup2(dhupchik,1);
    continue;

    }



 lul=0;

    while(lul<i-1){
        if(strcmp(sep[lul],">"))
            lul++;
        else{
             happy=3;
            break;
        }
                    
    }

    if(happy==3){
    char** arrow;
    arrow=(char**)malloc(1024*sizeof(char*));
    arrow[0]=(char*)malloc(1024*sizeof(char));
    arrow[0]=sep[lul+1];
    sep[lul+1]=NULL;
    sep[lul]==NULL;
    i--;
    i--;
    sep[i]=NULL;
    //printf("%s\n",sep[i]);
    int fd2 = open(arrow[0], O_WRONLY | O_CREAT | O_RDONLY | O_TRUNC ,0677);
	if (fd2 == -1) 
	{
		write(1,"Error in creating new file\n",27);
	}

     dhupchik= dup(1);
    dup2(fd2,1);

    //Cronjob
     if(!strcmp(sep[0],"cronjob")){
         
         int space=2;
        int quant=0;
                 //printf("%d\n",strcmp(sep[space],"-t"));
    char** right;
    right=(char**)malloc(1024*sizeof(char*));
    right[0]=(char*)malloc(1024*sizeof(char));
    int qw=0;

    while(qw<100){
            qw++;
            right[qw]=(char*)malloc(1024*sizeof(char));

    }

     while(strcmp(sep[space],"-t")){
         
         //right[space-1]=sep[space];
         //printf("HI\n");
        strcpy(right[space-2],sep[space]);
         space++;
     }

    // printf("Hi\n");

     int tim=atoi(sep[space+1]);
     int period=atoi(sep[space+3]);

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
        set(right,space-2);
        unset(right,space-2);
        execute(right,space-2);
        HISTORY_STATE *myhist;
        HIST_ENTRY **mylist;
    
        his(right,i,myhist,mylist);

        if(quant>period)
            break;
    
     }
 }






    else{
    commands(sep,cwd,i);

    ls(sep,i,current);

    pinfo(sep,i);
    set(sep,i);
    unset(sep,i);
    execute(sep,i);
    HISTORY_STATE *myhist;
    HIST_ENTRY **mylist;

    his(sep,i,myhist,mylist);

    }


    dup2(dhupchik,1);
    continue;

    }



    














//Cronjob
     if(!strcmp(sep[0],"cronjob")){
         
         int space=2;
       
                 //printf("%d\n",strcmp(sep[space],"-t"));
    char** right;
    right=(char**)malloc(1024*sizeof(char*));
    right[0]=(char*)malloc(1024*sizeof(char));
    int qw=0;

    while(qw<100){
            qw++;
            right[qw]=(char*)malloc(1024*sizeof(char));

    }

     while(strcmp(sep[space],"-t")){
         
         //right[space-1]=sep[space];
         //printf("HI\n");
        strcpy(right[space-2],sep[space]);
         space++;
     }

   
    // printf("Hi\n");

     int tim=atoi(sep[space+1]);
     int period=atoi(sep[space+3]);
      int quant=tim;

    // printf("%d\n",tim);
    //  printf("%d\n",space);
     //printf("%s\n",right[0]);
        // printf("%s\n",right[1]);
        //space++;
        //right[space-2]="&";
        //printf("%d\n",space);
    pid_t pic=fork();
    if(strcmp(right[0],"ls") && strcmp(right[0],"cd") && strcmp(right[0],"pwd") && strcmp(right[0],"echo") && strcmp(right[0],"pinfo") && strcmp(right[0],"history") && strcmp(right[0],"nightswatch") && strcmp(right[0],"setenv") && strcmp(right[0],"unsetenv")){
        space++;
        strcpy(right[space-3],"&");
    }
    if(pic==0){
     while(1){
         sleep(tim);
         quant=quant+tim;
         commands(right,cwd,space-2);

        ls(right,space-2,current);

        if(!strcmp(right[0],"jobs")){
            int jobcnt=0;
            //printf("1\n");
           //int ex=0;
           char dest[1000];
           //sprintf(dest,)           
        for(int hg=0;hg<jcount;){
            sprintf(dest,"/proc/%s/stat",job[hg]);

            FILE *fd=fopen(dest,"r");
            if (fd!=NULL){
                char A[50][50];

                    int ka=0;
                    while(ka<23){
                        fscanf(fd,"%s",A[ka]);
                        ka++;
                    }
                if(strcmp(A[2],"Z")){
                    if(!strcmp(A[2],"R") || !strcmp(A[2],"S")){
                        jobcnt++;    
                        printf("[%d] Running %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                    if(!strcmp(A[2],"T")){
                        jobcnt++;
                        printf("[%d] Stopped %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                }


            }
            hg=hg+2;

        }
    }
    
        pinfo(right,space-2);
        set(right,space-2);
        unset(right,space-2);
        execute(right,space-2);
        HISTORY_STATE *myhist;
        HIST_ENTRY **mylist;
    
        his(right,i,myhist,mylist);

        if(quant>period)
            break;
     }
     exit(0);
     }
 }






    else{
        //printf("2\n");
        if(!strcmp(sep[0],"jobs")){
            int jobcnt=0;
            //printf("1\n");
           //int ex=0;
           char dest[1000];
           //sprintf(dest,)           
        for(int hg=0;hg<jcount;){
            sprintf(dest,"/proc/%s/stat",job[hg]);

            FILE *fd=fopen(dest,"r");
            if (fd!=NULL){
                char A[50][50];

                    int ka=0;
                    while(ka<23){
                        fscanf(fd,"%s",A[ka]);
                        ka++;
                    }
                if(strcmp(A[2],"Z")){
                    if(!strcmp(A[2],"R") || !strcmp(A[2],"S")){
                        jobcnt++;    
                        printf("[%d] Running %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                    if(!strcmp(A[2],"T")){
                        jobcnt++;
                        printf("[%d] Stopped %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                }


            }
            hg=hg+2;

        }
    }
    if(!strcmp(sep[0],"overkill")){
        for(int hg=0;hg<jcount;){
           int kj=atoi(job[hg]);
            kill(kj,9);
            hg=hg+2;
        }

    }

    if(!strcmp(sep[0],"kjob")){
        if(i<=2){
            printf("Error\n");
        }
        else
        {
             int jobcnt=0;
             int pkj=0;
            //printf("1\n");
           //int ex=0;
           char dest[1000];
           //sprintf(dest,)           
        for(int hg=0;hg<jcount;){
            sprintf(dest,"/proc/%s/stat",job[hg]);

            FILE *fd=fopen(dest,"r");
            if (fd!=NULL){
                char A[50][50];

                    int ka=0;
                    while(ka<23){
                        fscanf(fd,"%s",A[ka]);
                        ka++;
                    }
                if(strcmp(A[2],"Z")){
                    if(!strcmp(A[2],"R") || !strcmp(A[2],"S")){
                        pkj=atoi(job[hg]);
                        jobcnt++;  
                          
                      //  printf("[%d] Running %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                    if(!strcmp(A[2],"T")){
                        pkj=atoi(job[hg]);
                        jobcnt++;
                       // printf("[%d] Stopped %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                }


            }
            int totalcount=atoi(sep[1]);
            if(jobcnt==totalcount){
                int sig=atoi(sep[1]);
                kill(pkj,sig);
                break;
            }
            hg=hg+2;

        }
        }
        
    }

    if(!strcmp(sep[0],"bg")){
        if(i==1){
            printf("Error\n");
        }
        else
        {
            int jobcnt=0;
             int pkj=0;
            //printf("1\n");
           //int ex=0;
           char dest[1000];
           //sprintf(dest,)           
        for(int hg=0;hg<jcount;){
            sprintf(dest,"/proc/%s/stat",job[hg]);

            FILE *fd=fopen(dest,"r");
            if (fd!=NULL){
                char A[50][50];

                    int ka=0;
                    while(ka<23){
                        fscanf(fd,"%s",A[ka]);
                        ka++;
                    }
                if(strcmp(A[2],"Z")){
                    if(!strcmp(A[2],"R") || !strcmp(A[2],"S")){
                        pkj=atoi(job[hg]);
                        jobcnt++;  
                          
                      //  printf("[%d] Running %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                    if(!strcmp(A[2],"T")){
                        pkj=atoi(job[hg]);
                        jobcnt++;
                       // printf("[%d] Stopped %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                }


            }
            int totalcount=atoi(sep[1]);
            if(jobcnt==totalcount){
                //int sig=atoi(sep[1]);
                kill(pkj,SIGCONT);
                break;
            }
            hg=hg+2;

        }
            
        }
        

    }


    if(!strcmp(sep[0],"fg")){
        if(i==1){
            printf("Error\n");
        }
        else
        {
            int jobcnt=0;
             int pkj=0;
            //printf("1\n");
           //int ex=0;
           char dest[1000];
           //sprintf(dest,)           
        for(int hg=0;hg<jcount;){
            sprintf(dest,"/proc/%s/stat",job[hg]);

            FILE *fd=fopen(dest,"r");
            if (fd!=NULL){
                char A[50][50];

                    int ka=0;
                    while(ka<23){
                        fscanf(fd,"%s",A[ka]);
                        ka++;
                    }
                if(strcmp(A[2],"Z")){
                    if(!strcmp(A[2],"R") || !strcmp(A[2],"S")){
                        pkj=atoi(job[hg]);
                        jobcnt++;  
                          
                      //  printf("[%d] Running %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                    if(!strcmp(A[2],"T")){
                        pkj=atoi(job[hg]);
                        jobcnt++;
                       // printf("[%d] Stopped %s [%s]\n",jobcnt,job[hg+1],job[hg]);
                    }
                }


            }
            int totalcount=atoi(sep[1]);
            if(jobcnt==totalcount){
                //int sig=atoi(sep[1]);
                kill(pkj,SIGCONT);
                int status,wpid;
                fgpoint=pkj;
                    wpid=waitpid(pkj,&status,WUNTRACED);
                // while(!WIFEXITED(status) && ! WIFSIGNALED(status)){
                // }
                break;
            }
            hg=hg+2;

        }
            
        }
        

    }


    commands(sep,cwd,i);

    ls(sep,i,current);

    pinfo(sep,i);
    set(sep,i);
    unset(sep,i);
    execute(sep,i);
    HISTORY_STATE *myhist;
    HIST_ENTRY **mylist;

    his(sep,i,myhist,mylist);

    

    }



    }



   r++;
   z--;
}
}

return 0;

}