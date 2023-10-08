#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"
#include "compare.h"
#include "init_strings.h"

int main ()
{
    OneginFile info = {};
    String* pointer = OneginFileCtor (&info, "str.txt");

    PrintfOriginal (pointer, info);
    PrintfSorted (pointer, info);
    PrintfRevertSorted (pointer, info);

    free (pointer);
}
