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
#include<time.h>
#include "getinput.c"
#include "commands.h"
#include "ls.h"
#include "pinfo.h"
#include "execute.h"
#include "his.h"

void cronjob(char**);