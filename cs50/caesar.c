#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdio.h>

char rotate(char c, int key);
int main(int argc, char* argv[]){

   
    if(argc!=2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for(int i =0;i <strlen(argv[1]);i++){
        if(!isdigit(argv[1][i])){
            printf("Usage: ./caesar key\n");
            return 1;

        }

        
    }
    int key  = atoi(argv[1]);
    char *text = (char *)malloc(1000 * sizeof(char));
    printf("PlainText: ");
   fgets(text, 1000, stdin);
   char * outputText = (char *)malloc(1000 * sizeof(char));
   int len = strlen(text);

   for(int i =0;i<len;i++){
    outputText[i] = rotate(text[i],key);
   }
    outputText[len] = '\0';

   printf("Ciphertext: %s", outputText);
   free(text);
   free(outputText);



    





}

char rotate(char c , int key)
{
    
    if(isalpha(c)){
        if(islower(c)){
            int result = ((c-97) +key)%26 +97  ;
            return (char)result;

        }
        else if(isupper(c)){
            int result = ((c-65) +key)%26 +65 ;
            return (char)result;


        }
    }
    else{
        return c;
    }

    

}