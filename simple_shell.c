#include "shell.h"

int main(int ac, char **argv, char **env)
{
    char *line = NULL;
    char **cmd = NULL;

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);

        line = read_line();

        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (0);
        }

        cmd = tokenizer(line);
        if (cmd == NULL)
            continue;

        execute_cmd(cmd, argv, env);
    }
}