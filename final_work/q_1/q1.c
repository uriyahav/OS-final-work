#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. uninitialized data segment */
int primes[] = { 2, 3, 5, 7 };  /* 2. initialized data segment */

static int
square(int x)                   /* 3. allocated in frame for square() */
{
    int result;                 /* 4. allocated in frame for square() */

    result = x * x;
    return result;              /* 5.return value is passed via register */
}

static void
doCalc(int val)                 /* 6. allocated in frame for doCalc() */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. allocated in frame for doCalc() */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* allocated in frame for main() */
{
    static int key = 9973;      /* initialized data segment */
    static char mbuf[10240000]; /* uninitialized data segment */
    char* p;                    /* allcoated in frame for main() */


    doCalc(key);

    exit(EXIT_SUCCESS);
}