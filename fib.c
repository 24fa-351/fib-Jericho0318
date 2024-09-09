#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int recur_fib(unsigned long long int n)
{
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}
    return recur_fib(n - 1) + recur_fib(n - 2);
}

unsigned long long int iter_fib(unsigned long long int n)
{
    unsigned long long int first = 0, second = 1, sum = 0;
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}
    for (int i = 2; i <= n; ++i)
    {
    	sum    = first + second;
    	first  = second;
    	second = sum;
    }
    return sum;
}

int main(int argc, char *argv[]){
   const char *filename = argv[3];
   FILE *file = fopen(filename, "r");
   if (filename == NULL)
   {
   	file = fopen(filename, "w");
   	if (file == NULL) 
   	{
   		printf("File not found\n");
   		return 0;
   	}
   }
   char line[atoi(argv[1])];
   unsigned long long int get_num = atoi(fgets(line, sizeof(line), file));
   if (!strcmp(argv[2], "i"))
   {
   	printf("%llu\n", iter_fib(get_num + 3));
   }
   else if (!strcmp(argv[2], "r"))
   {
   	printf("%llu\n", recur_fib(get_num + 4));
   }
   fclose(file);
   return 0;
}
