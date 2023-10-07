#include <stdio.h>
#include <stdlib.h>
#include "init_strings.h"


char* ReadText (OneginFile info)
{
    char* buf = (char*)calloc (info.file_size + 1, sizeof (char));
    fread (buf, sizeof (char), info.file_size, info.file);
    return buf;
}

size_t CountLines (OneginFile info)
{
    size_t n_lines = 0;
    info.buf[info.file_size] = '\0';
    for (size_t i = 0; i < info.file_size; i++)
    {
        if (info.buf[i] == '\n')
        {
            n_lines++;
            info.buf[i] = '\0';
        }
    }
    return n_lines;
}

String* InitStrings (String* pointer, OneginFile info)
{
    pointer[0].str = info.buf;
    size_t n = 1;
    size_t tmp = 0;
    for (size_t i = 0; i < info.file_size; i++)
    {
        if (info.buf[i] == '\0')
        {
            pointer[n].str = info.buf + i + 1;
            pointer[n - 1].len = i - tmp;
            tmp = i + 1;
            n++;
        }
    }
    return pointer;
}

String* OneginFileCtor (OneginFile* info, const char* file_name)
{
    info->file = fopen (file_name, "r");
    info->file_size = FileSize (*info);
    info->buf = ReadText (*info);
    info->n_lines = CountLines (*info);
    String* pointer = (String*)calloc (info->n_lines, sizeof(String*));
    InitStrings (pointer, *info);
    return pointer;
}

long FileSize (OneginFile info)
{
    fseek (info.file, 0, SEEK_END);
    long size = ftell (info.file);
    fseek (info.file, 0, SEEK_SET);
    return size;
}
