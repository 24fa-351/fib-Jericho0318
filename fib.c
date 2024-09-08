#include <stdio.h>
#include <stdlib.h>

unsigned int get_fib(unsigned int n)
{
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}
    return get_fib(n - 1) + get_fib(n - 2);
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
   fprintf(file, "hello");
   fclose(file);
   }
   char line[atoi(argv[1])];
   unsigned int num;
   if (fscanf(file, "%u", &num) == 1)
   {
   	printf("%u\n", get_fib(atoi(argv[1]) + 2));
   }
   fclose(file);
   return 0;
}
