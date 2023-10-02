#ifndef INIT_STRINGS
#define INIT_STRINGS

struct String
{
    char* str;
    int len;
};

long FileSize (FILE *file);
char* ReadText (FILE* file, long file_size);
size_t CountLines (char* buf, long file_size);
String* InitStrings (String* pointer, char* buf, long file_size);

#endif
