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
    buf[file_size] = '\0';
    for (size_t i = 0; i < file_size; i++)
    {
        if (buf[i] == '\n')
        {
            n_lines++;
            buf[i] = '\0';
        }
    }
    return n_lines;
}

String* InitStrings (String* pointer, char* buf, long file_size)
{
    pointer[0].str = buf;
    size_t n = 1;
    size_t tmp = 0;
    for (size_t i = 0; i < file_size; i++)
    {
        if (buf[i] == '\0')
        {
            //printf ("%lu\n", i);
            pointer[n].str = buf + i + 1;
            pointer[n - 1].len = i - tmp;
            tmp = i + 1;
            n++;
        }
    }
    //printf ("%lu\n", sizeof (&(pointer->str[])));
    //printf ("%lu\n", sizeof (char*));
    return pointer;
}

long FileSize (FILE *file)
{
    fseek (file, 0, SEEK_END);
    long size = ftell (file);
    fseek (file, 0, SEEK_SET);
    return size;
}
