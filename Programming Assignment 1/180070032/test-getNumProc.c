#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    for (int i = 0; i < 2; i++)
    {
        int ret = fork();
        if (ret == 0)
        {
            getNumProc();
        }
        else
        {
            getNumProc();
            wait();
        }
    }
    exit();
}