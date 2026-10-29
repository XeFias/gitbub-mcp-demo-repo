#ifndef HELLO_H
#define HELLO_H

/* Returns the greeting printed by the application. */
const char *hello_message(void);

/* Returns the first command-line argument, or hello_message() if none. */
const char *greeting_from_args(int argc, char *argv[]);

#endif /* HELLO_H */
