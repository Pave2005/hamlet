#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "output.h"
#include "compare.h"

void PrintfData (char** pointer, size_t n_lines)
{
    for (size_t i = 0; i < n_lines; i++)
    {
        printf ("%s\n", pointer[i]);
    }
    printf ("\n");
}
void PrintfOriginal (char** pointer, size_t n_lines)
{
    PrintfData (pointer, n_lines);
}

void PrintfSorted (char** pointer, size_t n_lines)
{
    qsort (pointer, n_lines, sizeof (char*), Compare);
    PrintfData (pointer, n_lines);
}

void PrintfRevertSorted (char** pointer, size_t n_lines)
{
    qsort (pointer, n_lines, sizeof (char*), ReverseCompare);
    PrintfData (pointer, n_lines);
}
