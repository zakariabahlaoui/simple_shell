#include "shell.h"

int main(int ac, char **argv, char **env)
{
    char *line = NULL;
    char **cmd = NULL;
    int index = 0;
    int stat = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        line = read_line();

        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (stat);
        }
        index++;

        cmd = _tokenizer(line);
        if (cmd == NULL)
            continue;
        // for (i = 0; cmd[i]; i++)
        // {
        //     printf("%s\n", cmd[i]);
        // }
        // freearray(cmd);

        stat = execute_cmd(cmd, argv, env, index);
    }
}
