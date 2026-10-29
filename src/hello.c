#include "hello.h"

const char *hello_message(void)
{
    return "Hello, World!";
}

const char *greeting_from_args(int argc, char *argv[])
{
    if (argc > 1 && argv[1][0] != '\0') {
        return argv[1];
    }
    return hello_message();
}
