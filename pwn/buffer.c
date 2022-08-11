#include <stdio.h>
#include <stdlib.h>

void lovely_func() {
    char buffer[128];
    char *p = buffer;
    printf("Your lovely stack lives at %p\n", p);
    gets(buffer);
    printf("Your input was: %s\n", buffer);
}

int main(int argc, char **argv) {
    printf("Whoo hoo\nEnter your lovely string!\n");
    lovely_func();
}
