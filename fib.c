#include <stdio.h>
#include <stdlib.h>

int get_fib(int n)
{
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}
    return get_fib(n - 1) + get_fib(n - 2);
}

int main(int argc, char *argv[]){
   int result = get_fib(atoi(argv[1]) + 2);
   printf("%d\n", result);
   return 0;
}
