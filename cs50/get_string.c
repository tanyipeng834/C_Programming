#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char * get_string(){
    int capacity =10;
    char * s = malloc(capacity*sizeof(int));

    if(s==NULL){
        printf("Memory allocation has failed");
        exit(1);
    }
    int length =0;
    char c;

    while((c= getchar())!='\n' && c!= EOF ){
        s[length++] = c;
        if(length == capacity){
            s = realloc(s,capacity*2*sizeof(int));
            if(s ==NULL){
                printf("Memory allocaiton has failed");
                exit(1);
            }
        }
    }
    s[length]='\0';
    return s;


}

int main(){
    printf("Enter your string");
    char * user_input = get_string();
    printf("Your input is %s",user_input);
    free(user_input);

}

