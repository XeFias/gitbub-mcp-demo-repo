#include <stdio.h>
#include <string.h>

#include "hello.h"

static int failures = 0;

static void expect_str(const char *test, const char *expected, const char *actual)
{
    if (actual == NULL || strcmp(actual, expected) != 0) {
        fprintf(stderr, "FAIL: %s: expected \"%s\", got \"%s\"\n",
                test, expected, actual ? actual : "(null)");
        failures++;
        return;
    }
    printf("PASS: %s\n", test);
}

static void test_hello_message_returns_greeting(void)
{
    expect_str("test_hello_message_returns_greeting",
               "Hello, World!", hello_message());
}

static void test_greeting_from_args_uses_argument(void)
{
    char *argv[] = {"hello", "Good morning", NULL};

    expect_str("test_greeting_from_args_uses_argument",
               "Good morning", greeting_from_args(2, argv));
}

static void test_greeting_from_args_uses_first_argument_only(void)
{
    char *argv[] = {"hello", "Hi", "there", NULL};

    expect_str("test_greeting_from_args_uses_first_argument_only",
               "Hi", greeting_from_args(3, argv));
}

static void test_greeting_from_args_defaults_without_argument(void)
{
    char *argv[] = {"hello", NULL};

    expect_str("test_greeting_from_args_defaults_without_argument",
               "Hello, World!", greeting_from_args(1, argv));
}

static void test_greeting_from_args_defaults_on_empty_argument(void)
{
    char *argv[] = {"hello", "", NULL};

    expect_str("test_greeting_from_args_defaults_on_empty_argument",
               "Hello, World!", greeting_from_args(2, argv));
}

int main(void)
{
    test_hello_message_returns_greeting();
    test_greeting_from_args_uses_argument();
    test_greeting_from_args_uses_first_argument_only();
    test_greeting_from_args_defaults_without_argument();
    test_greeting_from_args_defaults_on_empty_argument();

    if (failures > 0) {
        fprintf(stderr, "%d test(s) failed\n", failures);
        return 1;
    }
    puts("All tests passed");
    return 0;
}
