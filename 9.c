// Write a program to print the following information about a given file.
// a. inode
// b. number of hard links
// c. uid
// d. gid
// e. size
// f. block size
// g. number of blocks
// h. time of last access
// i. time of last modification
// j. time of last change

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int argv,char *argc[]){
    struct stat s;
    stat(argc[1],&s);
    printf("inode=%ld\n",s.st_ino);
    printf("number of hardlinks=%ld\n",s.st_nlink);
    printf("uid=%d\n",s.st_uid);
    printf("gid=%d\n",s.st_gid);
    printf("size=%ld\n",s.st_size);
    printf("block size=%ld\n",s.st_blksize);
    printf("number of block=%ld\n",s.st_blocks);
    printf("Last access time=%s",ctime(&s.st_atime));
    printf("Time of last modification: %s", ctime(&s.st_mtime));
    printf("Time of last change: %s", ctime(&s.st_ctime));


    return 0;
}