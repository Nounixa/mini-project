#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int i;
    time_t t;
    srand((unsigned) time(&t));
    for ( i = 0; i < 4; i++)
    {
              printf("%d\n", rand() % 5);
             sleep(1);
    }
    

};