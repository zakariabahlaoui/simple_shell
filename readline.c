#include "shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t length = 0;
    size_t i;

    i = getline(&line, &length, stdin);

    if (i == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}