#include <stdio.h>
#include <string.h>
#include "type.h"

bool arg_is(const char *argv, const char *long_form, const char *short_form)
{
    return (long_form && strcmp(argv, long_form) == 0) || (short_form && strcmp(argv, short_form) == 0);
}

int arguments(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        if (arg_is(argv[i], "--version", "-v")) {
            printf("0.0.1\n");
            return 0;
        } else if (arg_is(argv[i], "--help", "-h")) {
            printf("taima <time>\n");
            printf("--verions|-v:   prints version number\n");
            return 0;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    arguments(argc, argv);
    return 0;
}
