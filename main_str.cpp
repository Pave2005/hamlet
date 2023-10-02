#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"
#include "compare.h"
#include "init_strings.h"

int main ()
{
    OneginFile info = {};
    info.file = fopen ("str.txt", "r");
    info.file_size = FileSize (info);

    info.buf = ReadText (info);
    info.n_lines = CountLines (info);
    String* pointer = (String*)calloc (info.n_lines, sizeof(String*));
    InitStrings (pointer, info);

    PrintfOriginal (pointer, info);
    PrintfSorted (pointer, info);

    PrintfRevertSorted (pointer, info);

    free (pointer);
}

//OneginFileCtor (OneginFile* info, String pointer)
//{

//}
                              //file_name
//FILE* file = fopen(file_name
//OneginFileCtor (&onegin_file, "str.txt")
