#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"
#include "compare.h"
#include "init_strings.h"

int main ()
{
    // struct OneginFile
    // { FILE* file;
    //   int file_size;
    //   int n_lines;
    //   ;

    // OneginFileCtor(&onegin_file, "str.txt")
    //                               file_name
    // FILE* file = fopen(file_name

    FILE* file = fopen ("str.txt", "r");
    long file_size = FileSize (file);

    char* buf = ReadText (file, file_size);
    size_t n_lines = CountLines (buf, file_size);

    // printSorted
    // printRevertSorted
    // printText
    // String* pointer = (String*)calloc( n_lines, sizeof(char*));
    char** pointer = (char**)calloc (n_lines, sizeof (char*));
    InitStrings (pointer, buf, file_size);

    PrintfOriginal (pointer, n_lines);

    PrintfSorted (pointer, n_lines);

    PrintfRevertSorted (pointer, n_lines);

    free (pointer);
}
