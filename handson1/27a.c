/*
Name: 27a.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// write a program to execute ls -Rl by the following system calls
// a. execl


#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL);
    return 0;
}

// output 
// ./a.out 
// .:
// total 272
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   845 Aug 31 00:16 10.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1996 Aug 31 00:20 11.c
// -rwx--S--- 1 bhagyashah05 bhagyashah05   302 Aug 31 00:19 11.txt
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   604 Aug 31 00:21 12.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   827 Aug 31 00:23 13.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1136 Aug 31 00:23 14.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   524 Aug 31 00:30 15.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   611 Aug 31 17:21 16a.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   611 Aug 31 17:22 16b.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   849 Aug 31 17:22 17a.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   747 Aug 31 17:23 17b.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1018 Aug 31 17:24 18a.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1027 Aug 31 17:24 18b.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1423 Aug 31 17:25 18c.c
// -rwx------ 1 bhagyashah05 bhagyashah05    34 Aug 31 17:24 18record.txt
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   594 Aug 31 17:25 19.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   518 Aug 30 23:49 1a.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   487 Aug 30 23:51 1b.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   749 Aug 30 23:52 1c.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   713 Aug 31 17:25 20.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   407 Aug 31 17:26 21.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   903 Aug 31 17:27 22.c
// -rwx------ 1 bhagyashah05 bhagyashah05    47 Aug 31 17:26 22.txt
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   654 Aug 31 17:27 23.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   638 Aug 31 17:28 24.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1241 Aug 31 17:29 25.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   342 Aug 31 17:29 26a.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05    67 Aug 30 14:09 26ademo.c
// -rwxrwxr-x 1 bhagyashah05 bhagyashah05 15968 Aug 30 14:08 26ademo.out
// -rwxrwxr-x 1 bhagyashah05 bhagyashah05 15960 Aug 30 14:27 26a.out
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   391 Aug 31 17:31 26b.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   303 Aug 30 17:10 27a.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   300 Aug 30 17:10 27b.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   353 Aug 30 17:10 27c.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05     0 Aug 30 14:33 27cdemo
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   328 Aug 30 17:10 27d.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   327 Aug 30 17:11 27e.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   737 Aug 30 17:11 28.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1940 Aug 30 22:08 29.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   396 Aug 30 23:53 2.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   982 Aug 30 23:47 30.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   534 Aug 30 23:53 3.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   524 Aug 30 23:54 4.c
// -rw---x--T 1 bhagyashah05 bhagyashah05    32 Aug 10 10:07 4.txt
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1051 Aug 30 16:16 5.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   754 Aug 30 23:56 6.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   557 Aug 31 00:13 7.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1283 Aug 31 00:14 8.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05  1288 Aug 31 00:15 9.c
// -rwxrwxr-x 1 bhagyashah05 bhagyashah05 15960 Aug 31 17:31 a.out
// -rw------- 1 bhagyashah05 bhagyashah05     0 Aug 30 23:53 blankfile
// -rw-r--r-- 1 bhagyashah05 bhagyashah05    95 Aug 30 23:54 file0.c
// -rw-r--r-- 1 bhagyashah05 bhagyashah05    95 Aug 30 23:55 file1.c
// -rw-r--r-- 1 bhagyashah05 bhagyashah05    95 Aug 30 23:55 file2.c
// -rw-r--r-- 1 bhagyashah05 bhagyashah05    95 Aug 30 23:55 file3.c
// -rw-r--r-- 1 bhagyashah05 bhagyashah05    95 Aug 30 23:55 file4.c
// -rw-rw-r-- 2 bhagyashah05 bhagyashah05    30 Aug 31 00:15 linkfile.txt
// -rwxr----x 1 bhagyashah05 bhagyashah05    28 Aug 10 11:58 myfile
// -rw-rw-r-- 2 bhagyashah05 bhagyashah05    30 Aug 31 00:15 myFile
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05     0 Aug 21 19:02 README.md
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05   373 Aug 29 18:13 temp.c
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05     2 Aug 31 17:22 tickets.txt