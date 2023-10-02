#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "output.h"
#include "compare.h"
#include "init_strings.h"

void PrintfData (String* pointer, size_t n_lines)
{
    for (size_t i = 0; i < n_lines; i++)
    {
        printf ("%s\n", pointer[i].str);
    }
    printf ("\n");
}

void PrintfOriginal (String* pointer, size_t n_lines)
{
    PrintfData (pointer, n_lines);
}

void PrintfSorted (String* pointer, size_t n_lines)
{
    qsort (pointer->str, n_lines, sizeof (char*), Compare);
    PrintfData (pointer, n_lines);
}

void PrintfRevertSorted (String* pointer, size_t n_lines)
{
    //qsort (pointer->str, n_lines, sizeof (char*), ReverseCompare);
    PrintfData (pointer, n_lines);
}
