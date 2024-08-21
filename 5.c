#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>

int main(){
    int fd[5];
    char filename[20];
    const char *loop_program = "#include <stdio.h>\n"
                               "int main() {\n"
                               "    while (1) {\n"
                               "        // Infinite loop\n"
                               "    }\n"
                               "    return 0;\n"
                               "}\n";

    for(int i=0;i<5;i++){
        sprintf(filename, "file%d.c",i);
        fd[i]=creat(filename,0644);
        if(fd[i]==-1){
            perror("failed");
            return 1;
        }
        write(fd[i],loop_program,strlen(loop_program));

        close(fd[i]);
        sleep(1);

    }
}