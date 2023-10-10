#include "shell.h"

void execute_cmd(char **cmd, char **env)
{
    if (execve(cmd[0], cmd, env) == -1)
    {
        perror("Error:");
    }
}