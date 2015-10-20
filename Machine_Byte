/*
  在不用sizeof情况下，判断机器字长

*/
#include <stdio.h>
int main ()
{
    int x1 = 0x7fffffff;//0111 1111 1111 1111 1111 1111 1111 1111
    int x2 = 0x80000000;//1000 0000 0000 0000 0000 0000 0000 0000
    int x3 = 0x7fff; //0111 1111 1111 1111
    int x4 = 0x8000;//1000 0000 0000 0000
    if(x1+1 == x2)
        printf("int=32");
    else if(x3+1==x4)
        printf("int=16");
}
