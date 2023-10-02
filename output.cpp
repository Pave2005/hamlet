#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "output.h"
#include "compare.h"
#include "init_strings.h"

void PrintfData (String* pointer, OneginFile info)
{
    for (size_t i = 0; i < info.n_lines; i++)
    {
        printf ("%s\n", pointer[i].str);
    }
    printf ("\n");
}

void PrintfOriginal (String* pointer, OneginFile info)
{
    PrintfData (pointer, info);
}

void PrintfSorted (String* pointer, OneginFile info)
{
    qsort (pointer, info.n_lines, sizeof (String), Compare);
    PrintfData (pointer, info);
}

void PrintfRevertSorted (String* pointer, OneginFile info)
{
    qsort (pointer, info.n_lines, sizeof (String), ReverseCompare);
    PrintfData (pointer, info);
}
