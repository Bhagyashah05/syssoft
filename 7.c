#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    FILE *fo,*fw;

    fo=fopen("myfile","r");
    if(fo==NULL){
        return 1;
    }

    fw=fopen("myFile","w");

    if(fw==NULL){
        return 1;
    }
    int c;
    while((c=fgetc(fo))!=EOF){
        fputc(c,fw);
    }

    printf("donee");

    fclose(fo);
    fclose(fw);
    return 0;

}