#include "shell.h"

void execute_cmd(char **cmd, char **argv, char **env)
{
    pid_t id;
    int status;

    id = fork();

    if (id == 0)
    {
        if (execve(cmd[0], cmd, env) == -1)
        {
            perror(argv[0]);
            freearray(cmd);
        }
    }
    else
    {
        waitpid(id, &status, 0);
        freearray(cmd);
    }
}