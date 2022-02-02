#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
   int ret = fork();

   if (ret == 0)
   {
       showAncestry();
       helloYou("calling from child");
   }
   else
   {
       helloYou("calling from parent");
       wait();
       showAncestry();
   }
   exit();
}