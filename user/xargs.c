#include "kernel/types.h"
#include "user/user.h"
<<<<<<< Updated upstream

int main(int argc, char *argv[]){
    int i;
    int j = 0;
    int k;
    int l,m = 0;
    char block[32];
    char buf[32];
    char *p = buf;
    char *lineSplit[32];
    for(i = 1; i < argc; i++){
        lineSplit[j++] = argv[i];
    }
    while( (k = read(0, block, sizeof(block))) > 0){
        for(l = 0; l < k; l++){
            if(block[l] == '\n'){
                buf[m] = 0;
                m = 0;
                lineSplit[j++] = p;
                p = buf;
                lineSplit[j] = 0;
                j = argc - 1;
                if(fork() == 0){
                    exec(argv[1], lineSplit);
                }                
                wait(0);
            }else if(block[l] == ' ') {
                buf[m++] = 0;
                lineSplit[j++] = p;
                p = &buf[m];
            }else {
                buf[m++] = block[l];
=======
#include "kernel/param.h"

int main(int argc, char *argv[])
{
    int k;
    char block[32];
    char buf[32];
    char *temp = buf;

    int top = 0;
    char *final_input[MAXARG];

    for (int i = 1; i < argc; i++)
    {
        final_input[top++] = argv[i];
    }

    int bufTop = 0;
    while ((k = read(0, block, sizeof(block))) > 0)
    {
        for (int i = 0; i < k; i++)
        {
            if (block[i] == '\n')
            {
                buf[bufTop] = 0;
                bufTop = 0;
                final_input[top++] = temp;
                temp = buf;
                final_input[top] = 0;
                top = argc - 1;
                if (fork() == 0)
                {
                    exec(argv[1], final_input);
                }
                wait(0);
            }
            else if (block[i] == ' ')
            {
                buf[bufTop++] = 0;
                final_input[top++] = temp;
                temp = &buf[bufTop];
            }
            else
            {
                buf[bufTop++] = block[i];
>>>>>>> Stashed changes
            }
        }
    }
    exit(0);
}
