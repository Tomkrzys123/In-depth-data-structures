// add your program signature 
// add descriptions to function declarations

#include "string.h"
#include "mystring.h"

#define MAX_WORD 30
#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

typedef struct word {
    char word[MAX_WORD];
    int frequency;
} WORD;

typedef struct words {
    WORD word_array[MAX_WORDS];
    int line_count;
    int word_count;
    int keyword_count;
} WORDSUMMARY;

void set_stopword(char *filename, char *stopwordsp[]);
int contain_word(char *stopwords[], char *word);
int str_contain_word(char *str, char *word);
int process_word(char *filename, WORDSUMMARY *words, char *stopwords[]);
int save_to_file(char *filename, WORDSUMMARY *words);