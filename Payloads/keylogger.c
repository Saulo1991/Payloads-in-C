#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>

int main() {
    int fd = open("/dev/input/event0", O_RDONLY);
    struct input_event ie;

    while (read(fd, &ie, sizeof(struct input_event))) {
        if (ie.type == EV_KEY) {
            printf("Key: %i\n", ie.code);
            fflush(stdout);
        }
    }
    close(fd);
    return 0;
}
