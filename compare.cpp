#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct String
// {
//   char* str;
//   int len;
// }

int Compare (const void* str1, const void* str2)
{
    // String*
    // strcmp(((String*)str1)->str, ...)
    return strcmp (*(const char**)str1, *(const char**)str2);
}

int ReverseCompare (const void* str1, const void* str2)
{
    // String* str_1 = ...
    const char* str_1 = *(const char**)str1;
    const char* str_2 = *(const char**)str2;
    // str1_len = str_1->len;
    int str1_len = strlen (str_1) - 1;
    int str2_len = strlen (str_2) - 1;

    while (str1_len >= 0 && str2_len >= 0)
    {
        if (str_1[str1_len] != str_2[str2_len])
        {
            return str_1[str1_len] - str_2[str2_len];
        }
        str1_len--;
        str2_len--;
    }
    return 0;
}
