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

extern int fgpoint;
extern int jcount;
extern char job[100][100];

void execute(char**,int);