#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // ---- TEST 1 ----
    printf("\n=== TEST 1: archivo con multiples líneas ===\n");
    fd = open("test1.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);

    // ---- TEST 2 ----
    printf("\n=== TEST 2: archivo con una sola línea ===\n");
    fd = open("test2.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);

    // ---- TEST 3 ----
    printf("\n=== TEST 3: archivo vacío ===\n");
    fd = open("test3.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);

    // ---- TEST 4 ----
    printf("\n=== TEST 4: archivo sin salto de línea final ===\n");
    fd = open("test4.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);

    // ---- TEST 5 ----
    printf("\n=== TEST 5: BUFFER_SIZE pequeño (prueba manual) ===\n");
    fd = open("test5.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);
    return 0;
}

