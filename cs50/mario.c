#include <stdio.h>



int main(){

    int height;

    printf("Height: ");
    scanf("%d", &height);
    // This is the line
    int line =1;
    while(line<=height){
        
        
            for(int j=height-line;j>0;j--){
                printf(" ");
        
        }
        for(int i=0; i<line;i++){
            printf("#");
        }
        printf("\n");
        line+=1;

    }

    return 0;




}