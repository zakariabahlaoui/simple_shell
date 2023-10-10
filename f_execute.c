#include "shell.h"

void execute_cmd(char **cmd, char **argv, char **env)
{
    if (execve(cmd[0], cmd, env) == -1)
    {
        perror(argv[0]);
    }
}