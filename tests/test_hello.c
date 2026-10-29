#include <stdio.h>
#include <string.h>

#include "hello.h"

static int failures = 0;

static void test_hello_message_returns_greeting(void)
{
    const char *msg = hello_message();

    if (msg == NULL || strcmp(msg, "Hello, World!") != 0) {
        fprintf(stderr, "FAIL: expected \"Hello, World!\", got \"%s\"\n",
                msg ? msg : "(null)");
        failures++;
        return;
    }
    puts("PASS: test_hello_message_returns_greeting");
}

int main(void)
{
    test_hello_message_returns_greeting();

    if (failures > 0) {
        fprintf(stderr, "%d test(s) failed\n", failures);
        return 1;
    }
    puts("All tests passed");
    return 0;
}
