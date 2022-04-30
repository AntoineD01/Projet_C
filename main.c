#include <stdio.h>
#include "Takuzu.h"

int main()
{
    menu();
    if (size()==4)
    {
        matrix_four();
    }
    else
    {
        matrix_eight();
    }
}
