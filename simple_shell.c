#include "shell.h"

int main(int ac, char **argv, char **env)
{
    char *line = NULL;
    char **cmd = NULL;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        line = read_line();

        if (line == NULL)
            return (0);

        cmd = _tokenizer(line);
        if (cmd == NULL)
            continue;
        // for (i = 0; cmd[i]; i++)
        // {
        //     printf("%s\n", cmd[i]);
        // }
        // freearray(cmd);

        execute_cmd(cmd, argv, env);
    }
}
