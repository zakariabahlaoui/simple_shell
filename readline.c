#include "shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    size_t n;

    n = getline(&line, &len, stdin);

    if (n == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}