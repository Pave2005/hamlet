#ifndef INIT_STRINGS
#define INIT_STRINGS

long FileSize (FILE *file);
char* ReadText (FILE* file, long file_size);
size_t CountLines (char* buf, long file_size);
char** InitStrings (char** pointer, char* buf, long file_size);

#endif
