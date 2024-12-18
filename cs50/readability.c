#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h> 
#include <math.h>
int computeScore(int letters, int words, int sentences);

int main(){
     char *text = (char *)malloc(1000 * sizeof(char));
     
    printf("What is your paragraph? \n");
   fgets(text, 1000, stdin);
    int words =1;
    int sentences =0;
    int letters =0;
    for(int i =0; i< strlen(text);i++){
        if(text[i]==' '){
            words+=1;
        }
        else if(text[i]== '.' || text[i]=='?' || text[i]=='!'){
            sentences+=1;

        }
        else if(isalpha(text[i])){
            letters++;
        }


    }
    int score = computeScore(letters,words,sentences);
    if(score<=1){
        printf("Before Grade 1\n");
    }
    else if(score>16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %d\n",score);
    }
}
int computeScore(int letters, int words, int sentences) {
    // Convert integers to floats to avoid integer division
    float lettersPer100Words = ((float)letters / words) * 100;
    float sentencesPer100Words = ((float)sentences / words) * 100;

    // Compute the readability score using the correct formula
    float score = (0.0588 * lettersPer100Words) - (0.296 * sentencesPer100Words) - 15.8;

    // Return the rounded score
    return (int)round(score);
}