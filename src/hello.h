#ifndef HELLO_H
#define HELLO_H

/* Returns the default greeting printed by the application. */
const char *hello_message(void);

/* Returns the first command-line argument, or hello_message() if it is
 * missing or empty. */
const char *greeting_from_args(int argc, char *argv[]);

#endif /* HELLO_H */
