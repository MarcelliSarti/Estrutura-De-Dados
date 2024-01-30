#include <stdlib.h>
#include <stdio.h>

int c = 1;

void function_a ()
{
    int d=1;
    c++;
    printf("c = %d\n",c);
    function_a ();
}



main( )
{
  function_a();
}
