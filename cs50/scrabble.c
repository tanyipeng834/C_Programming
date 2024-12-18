#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h> 

int calculate_point(char* string);
int POINTS[] ={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int main(){
    char * inputOne = (char*) malloc(100* sizeof(char));
     char * inputTwo = (char*) malloc(100* sizeof(char));

    
    printf("Player 1 : ");
    scanf("%99s",inputOne);
    printf("Player 2 : ");
    scanf("%99s",inputTwo);

    int pointOne =calculate_point(inputOne);
    int pointTwo =calculate_point(inputTwo);
    
   

    if (pointOne>pointTwo){
        printf("Player 1 Wins!\n");
    }
    else if(pointTwo>pointOne){
        printf("Player 2  Wins!\n");
    }
    else{
        printf("Tie!\n");
    }
    
    




}

int calculate_point(char* string)
{
    int points =0;
    for (int i=0;i<strlen(string);i++)
    {
        int index = toupper(string[i])-65;
        points += POINTS[index];


    }
    return points;
    

}