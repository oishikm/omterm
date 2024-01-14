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

#define BIG_LINE 256
#define SMALL_LINE 64

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

void promptline(char* scanline)
{
    char cwd[BIG_LINE], dirname[SMALL_LINE], username[SMALL_LINE];
    
    getcwd(cwd, sizeof(cwd)); // from unistd.h
    getcwd_dirname(cwd, dirname);
    getlogin_r(username, sizeof(username)); // from unistd.h
    
    // You can edit next line to customize the prompt line, or comment it to get no prompt text (like WozMon)
    printf("[%s %s]$ ", username, dirname);

    scanf(" %[^\n]s", scanline);
}

int main()
{
    char scanline[BIG_LINE];

    while(1) // Main Loop
    {            
        promptline(scanline);
        if(strcmp(scanline, "exit") == 0)
            goto _exit;
        else
            system(scanline);        
    }

    _exit:
        printf("[EXIT]\n");
        return 0;
}