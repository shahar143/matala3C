//
// Created by shahar on 12/22/22.
//

#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30

int get_line(char* s){
    int counter = 0;
    while(counter < LINE){
        int temp = getchar();
        if(temp == '\n' || temp == '\r'){
            break;
        }
        s[counter] = temp;
        counter++;
        if(temp <= 0){
            s[counter - 1] = '\0';
            return -1;
        }
    }
    s[counter] = '\0';
    return counter;
}

int get_word(char* word){
    int counter = 0;
    while(counter < WORD){
        int temp = getchar();
        if(temp == '\n' || temp == ' ' || temp == '\t' || temp == '\r'){
            break;
        }
        word[counter] = temp;
        counter++;

        if(temp == EOF){
            word[counter - 1] = '\0';
            return -1;
        }
    }

    word[counter] = '\0';
    return counter;
}


int sub_string(char *str1, char* str2){
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    if(str2_len == 0 && str1_len == 0) return 1;
    if(str2_len == 0) return 1;
    if(str1_len == 0) return 0;

    for(int i = 0; i <= (str1_len - str2_len); i++){
        int j = i;
        int k = 0;
        int ans = 1;
        while(j < i + str2_len && k < str2_len){
            if(*(str2 + k) != *(str1 +j)){
                ans = 0;
                break;
            }
            j++;
            k++;
        }
        if(ans == 1) return 1;
    }
    return 0;
}


int similar(char* s, char* t){
    if(!(strcmp(s,t))) return 1;
    if(strlen(s)- strlen(t) > 1) return 0;
    for(int i = 0; i < strlen(s); i++){
        char* stprt = (char *)calloc(strlen(t)-i, sizeof(char));
        if(stprt == NULL){
            printf("place wasn't allocated!");
            exit(1);
        }
        char* merged_string = (char *)calloc(strlen(t), sizeof(char));
        if(merged_string == NULL){
            printf("place wasn't allocated!");
            exit(1);
        }
        strncpy(merged_string, s, i);
        strncpy(stprt, s + i + 1, strlen(s) -i);
        strcat(merged_string, stprt);
        if(!(strcmp(t, merged_string))) return 1;
        free(stprt);
        free(merged_string);
    }
    return 0;
}

void print_lines(char* str){
    char line[LINE];
    int hasNext = 1;
    while(hasNext) {
        if (get_line(line) <= 0) {
            hasNext = 0;
        }
        if(sub_string(line, str) == 1){
            printf("%s\n", line);
        }
    }
}

void print_words(char* str){
    char word[WORD];
    while(get_word(word) > 0){
        if(similar(word, str) == 1){
            printf("%s\n", word);
        }
    }
}

int main(){
    char string[WORD];
    char option;
    char blank_space;
    loop:
    scanf("%s %c%c", string, &option, &blank_space);
    if(option == 'a'){
        getchar();
        print_lines(string);
    }
    else if(option == 'b'){
        getchar();
        print_words(string);
    }
    else{
        printf("choose a or b\n");
        goto loop;
    }
}