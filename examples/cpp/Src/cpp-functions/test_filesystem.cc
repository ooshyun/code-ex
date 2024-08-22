#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void test_filesystem(void) {
    // int fd = memfd_create("kilgore", MFD_ALLOW_SEALING);
    // if (fd == -1)
    //     error("memfd_create()");

    // if (ftruncate(fd, MAX_SIZE) == -1)
    //     error("ftruncate()");

    // if (fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_GROW) == -1)
    //     error("fcntl(F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_GROW)");

    char *str1 = "One likes to believe in the freedom of music,\n";
    if (write(fd, str1, strlen(str1)) == -1) {
        error("write()");
    } else {
        printf("write() success\n");
    }

    char *str2 = "but glittering prizes and endless compromises shatter the illusion of integrity.";
    if (write(fd, str2, strlen(str2)) == -1) {
        error("write()");
    } else {
        printf("write() success\n");
    }

    // This part will raise error
    // if (fcntl(fd, F_ADD_SEALS, F_SEAL_WRITE) == -1)
    //     error("fcntl(F_ADD_SEALS, F_SEAL_WRITE)");

    // if (write(fd, "This will fail!", 15) == -1) {
    //     error("write()");
    // } else {
    //     printf("write() success\n");
    // }

    // off_t r = lseek(fd, 0, 0);
    // if (r == -1)
    //     error("lseek()");

    // char buf[MAX_SIZE];
    // if (read(fd, buf, sizeof buf) == -1)
    //     error("read()");

    // printf("%s\n", buf);

    // sleep(30);
}