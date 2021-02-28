#define _GNU_SOURCE
#define _XOPEN_SOURCE 600  
#include <ftw.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int dirTraversal(const char *pathname, const struct stat *sbuf, int type, struct FTW *ftwb){
    //print the type   
    if (type != FTW_SL && type != FTW_SLN){
    switch (type){
    case FTW_D:
        printf("D ");
        break;
    
    case FTW_DNR:
        printf("DNR ");
        break;
    
    case FTW_DP:
        printf("DP ");
        break;

    case FTW_F:
        printf("F ");
        break;

    case FTW_NS:
        printf("NS ");
        break;
    
    default:
        printf(" ");
        break;
    }
    //print inode number
    printf("%7ld ", (long) sbuf->st_ino);
    //print the name of the file/dir
    printf("%s\n",  &pathname[ftwb->base]); 
    //tell nftw() to continue
    }
    return 0;
}

int main(int argc, char **argv){
    int flag;
    flag |= FTW_PHYS;

    //path, function, descriptors, flag
    if (nftw((argc < 2) ? "." : argv[1], dirTraversal, 10, flag) == -1) {
        perror("nftw");
        exit(1);
    }
    exit(0);
}