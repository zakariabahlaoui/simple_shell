#include "shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t l = 0;
    size_t i;

    i = getline(&line, &, stdin);

    if (i == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}