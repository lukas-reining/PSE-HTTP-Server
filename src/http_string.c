#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/http_string.h"
#include "../include/http_error.h"


string *new_string(size_t len) {
    string *str = calloc(sizeof(string), 1);
    if (str == NULL) {
        exit(2);
    }
    str->str = calloc(len, sizeof(char));
    if (str->str == NULL) {
        exit(3);
    }
    str->len = len;
    return str;
}


void free_str(string *str) {
    if (str == NULL) return;
    free(str->str);
    free(str);
    str = NULL;
}


void print_string(string *str) {
    for (int i = 0; i < str->len; i++) {
        putchar(str->str[i]);
    }
}


string *cpy_str(const char *src) {
    size_t newLength = strlen(src);
    string *dest = new_string(newLength);
    memcpy(dest->str, src, newLength);
    return dest;
}


string *cat_str(string *dest, const char *src) {
    size_t size1 = dest->len;
    size_t size2 = strlen(src);
    size_t newSize = size1 + size2;

    if (newSize != NULL){

        string *newString = new_string(newSize);
        memcpy(newString->str, dest->str, size1);
        memcpy(newString->str + size1, src, size2);

        return newString;

    } else{

        error("cat_str: Strings are empty");
    }

}


string * sub_str(string *str, size_t start, size_t len) {
    if (start + len > str->len) return NULL;

    string *substring = new_string(len);
    for (int i = 0; i < len; i++) {
        substring->str[i] = str->str[start + i];
    }

    return substring;
}



char equals_str(string *str1, string *str2) {
    if (str1->pos != str2->pos) return 0;
    for (int i = 0; i < str1->pos; ++i) {
        if (str1->str[i] != str2->str[i]) return 0;
    }
    return 1;
}


char chars_equal_str(string *str, char *chars) {
    if (strlen(chars) != str->pos) return 0;
    for (int i = 0; i < str->pos; ++i) {
        if (str->str[i] != chars[i]) return 0;
    }
    return 1;
}


int find_str(string *str1, string *str2) {
    int len1 = str1->pos;
    int len2 = str2->pos;

    for (int i = 0; i <= len1 - len2; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j < len2; j++) {
            if (str1->str[i + j] != str2->str[j]) break;
        }

        if (j == len2) return i;
    }

    return -1;
}


int find_chars(string *str1, char *chars) {
    int len1 = str1->pos;
    int len2 = strlen(chars);

    for (int i = 0; i <= len1 - len2; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j < len2; j++) {
            if (str1->str[i + j] != chars[j]) break;
        }

        if (j == len2) return i;
    }

    return -1;
}
