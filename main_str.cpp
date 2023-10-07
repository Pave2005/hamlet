#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"
#include "compare.h"
#include "init_strings.h"

int main ()
{
    OneginFile info = {};
    String* pointer = OneginFileCtor (&info);

    PrintfOriginal (pointer, info);
    PrintfSorted (pointer, info);

    PrintfRevertSorted (pointer, info);

    free (pointer);
}




                              //file_name
//FILE* file = fopen(file_name
//OneginFileCtor (&onegin_file, "str.txt")

