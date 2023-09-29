#include <stdio.h>
#include <stdlib.h>
#include "init_strings.h"

char* ReadText (FILE* file, long file_size)
{
    char* buf = (char*)calloc (file_size + 1, sizeof (char));
    fread (buf, sizeof (char), file_size, file);
    return buf;
}

size_t CountLines (char* buf, long file_size)
{
    size_t n_lines = 0;
    for (size_t i = 0; i < file_size; i++)
    {
        if (buf[i] == '\n' && buf[i + 1] != EOF)
        {
            n_lines++;
            buf[i] = '\0';
        }
    }
    return n_lines;
}

char** InitStrings (char** pointer, char* buf, long file_size)
{
    pointer[0] = buf;
    size_t n = 1;
    for (size_t i = 0; i < file_size; i++)
    {
        if (buf[i] == '\0')
        {
            // pointer[n].str = ...
            pointer[n] = buf + i + 1;
            // pointer[n].len = j;
            n++;
        }
    }
    return pointer;
}

long FileSize (FILE *file)
{
    fseek (file, 0, SEEK_END);
    long size = ftell (file);
    fseek (file, 0, SEEK_SET);
    return size;
}
