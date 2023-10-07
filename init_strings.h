#ifndef INIT_STRINGS
#define INIT_STRINGS

struct String
{
    char* str;
    int len;
};

struct OneginFile
{
    FILE* file;
    long file_size;
    int n_lines;
    char* buf;
};

long FileSize (OneginFile info);
char* ReadText (OneginFile info);
size_t CountLines (OneginFile info);
String* InitStrings (String* pointer, OneginFile info);
String* OneginFileCtor (OneginFile* info);

#endif
