#include "myword.h"
void set_stopword(char *filename, char *stopwords[])                    
{
    FILE *fp = fopen(filename, "r");                                   
    char line[1000];
    char delimiters[] = ".,\n\t\r";
    char *token;
    int i;
    
    while (fgets(line, 1000, fp) != NULL)                               
    {
        token = (char*) strtok(line, delimiters);
        
        while (token != NULL)
        {
            i = (int) (*token - 'a');
            strcat(stopwords[i], token);
            strcat(stopwords[i], ",");
            token = (char*) strtok(NULL, delimiters);
        }
    }
    
    fclose(fp);
}


 
int contain_word(char *stopwords[], char *word) {
    if (word == NULL || *word == '\0' ) return 0;
    else {
        return str_contain_word(stopwords[*word - 'a'], word); // stopwords index = starting letter - 'a'
    }
}
int str_contain_word(char *str, char *word)
{
  if (str == NULL || word == NULL) return 0;  
  char temp[20] = {0};
  strcat(temp, ",");
  strcat(temp, word);
  strcat(temp, ","); 
  if (strstr(str, temp))
      return 1;
  else
      return 0;
    
  return 0;
}
int process_word(char *filename, WORDSUMMARY *words, char *stopwords[]) {
    FILE *fp = NULL; 
    char line[MAX_LINE_LEN]; 
    const char delimiters[] = " .,;:!()&?-\n\t\r\"\'"; 
    char *token; 
    int i = 0;
    int compare;
    fp = fopen(filename, "r");
    while (fgets(line, MAX_LINE_LEN, fp)) { 
        words->line_count++; 
        trim(line); 
        lower_case(line); 
        token = strtok(line, delimiters);
        while (token) {
            words->word_count++;
            if (contain_word(stopwords, token) == 0) { 
                while (i < words->keyword_count && strcmp(token, words->word_array[i].word)) {
                    i++;
                }         
                if (i < words->keyword_count) {
                    words->word_array[i].frequency++;
                }               
                else {
                    strcpy(words->word_array[i].word, token); 
                    words->word_array[i].frequency = 1;
                    words->keyword_count++; 
                }
                i = 0;

            }

            token = strtok(NULL, delimiters); 

        }

    }

    fclose(fp);
  
}



int save_to_file(char *filename, WORDSUMMARY *words) {
    FILE *fp = NULL;
    int i;
	fp = fopen(filename, "w");
    fprintf(fp, "%-20s  %8d\n", "Line count", words->line_count);
    fprintf(fp, "%-20s  %8d\n", "Word count", words->word_count);
    fprintf(fp, "%-20s  %8d\n", "Keyword count", words->keyword_count);
    fprintf(fp, "%-18s  %10s\n", "Keyword", "frequency");

    for (i = 0; i < words->keyword_count; i++) {
        fprintf(fp, "%-18s  %10d\n", words->word_array[i].word, words->word_array[i].frequency);
    }
	fprintf(fp, "\n");
    fclose(fp);
    return 1;

}

