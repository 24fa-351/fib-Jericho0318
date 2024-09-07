#include <stdio.h>
#include <stdlib.h>

int get_fib(unsigned int n)
{
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}
    return get_fib(n - 1) + get_fib(n - 2);
}

int main(int argc, char *argv[]){
   unsigned int num;
   sscanf(argv[1], "%u", &num);
   printf("%u\n", get_fib(num + 2));
   return 0;
}
