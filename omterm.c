/*
 * omterm - Oishik M Terminal
 *
 * A simple wrapper around bash (or any other similar and/or compatible POSIX shell)
 * to bring a simple terminal experience to the user.
 *
 * Simplicity inspired by Steve Wozniak's WozMon. 
 * omterm however, of course, does not perform any machine code execution like WozMon.
 * It is simply a wrapper around POSIX shells.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void getcwd_dirname(char* cwd, char* dirname)
{
    int i;
    int slash_location = 0;
    int len = strlen(cwd);
    for(i=0; cwd[i] != '\0'; i++)
    {
        if(cwd[i] == '/')
        {
            slash_location = i;
        }
    }
    // printf("%d", slash_location);
    strncpy(dirname, cwd + slash_location + 1, len - slash_location);
}

void promptline()
{
    char cwd[256], dirname[64], username[64];
    getcwd(cwd, sizeof(cwd));
    getcwd_dirname(cwd, dirname);
    getlogin_r(username, sizeof(username));
    // You can edit next line to customize the prompt line.
    printf("[%s %s]", username, dirname);
}

int main()
{
    promptline();
    printf("\n");
    return 0;
}