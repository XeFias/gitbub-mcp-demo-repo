#include <stdio.h>

#include "hello.h"

int main(int argc, char *argv[])
{
    puts(greeting_from_args(argc, argv));
    return 0;
}
