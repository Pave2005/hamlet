#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init_strings.h"

int Compare (const void* str1, const void* str2)
{
    return strcmp (((const String*)str1)->str, ((const String*)str2)->str);
}

int ReverseCompare (const void* str1, const void* str2)
{
    const String* str_1 = (const String*)str1;
    const String* str_2 = (const String*)str2;
    int str1_len = str_1->len - 1;
    int str2_len = str_2->len - 1;

    while (str1_len >= 0 && str2_len >= 0)
    {
        if (str_1->str[str1_len] != str_2->str[str2_len])
        {
            return str_1->str[str1_len] - str_2->str[str2_len];
        }
        str1_len--;
        str2_len--;
    }
    return 0;
}
