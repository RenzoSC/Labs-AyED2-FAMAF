#include "strfuncs.h"


size_t string_length(const char *str){
    return (*str) ? 1 + string_length(str + 1) : 0;
}

char *string_filter(const char *str, char c){
    size_t len = string_length(str);
    size_t new_len = 0;
    char *new_str;

    // Count the number of characters in the original string that are not 'c'
    for (size_t i = 0; i < len; i++) {
        if (str[i] != c) {
            new_len++;
        }
    }

    // Allocate memory for the new string
    new_str = (char *) malloc((new_len + 1) * sizeof(char));

    // Copy characters from the original string that are not 'c' to the new string
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (str[i] != c) {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';

    return new_str;
}