#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t recur_fib(uint64_t num) {
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return recur_fib(num - 1) + recur_fib(num - 2);
}

uint64_t iter_fib(uint64_t num) {
    uint64_t first = 0, second = 1, sum = 0;
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    for (int ix = 0; ix < num; ++ix) {
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        perror(
            "Provide 4 arguments: ./<filename> <num> <i/r> <filename.txt>\n");
        exit(1);
    }

    const char *filename = argv[3];
    FILE *file = fopen(filename, "r");
    if (filename == NULL) {
        perror("File not found\n");
        exit(1);
    }

    uint64_t file_num;
    char line[1024];
    uint64_t get_num = atoi(argv[1]);

    fscanf(file, "%ld", &file_num);
    uint64_t sum = get_num + file_num;

    if (!strcmp(argv[2], "i")) {
        printf("%lu\n", iter_fib(sum - 2));
    } else if (!strcmp(argv[2], "r")) {
        printf("%lu\n", recur_fib(sum - 1));
    } else {
        perror("Choose between i or r in argv[2]\n");
        exit(1);
    }
    fclose(file);
    return 0;
}
