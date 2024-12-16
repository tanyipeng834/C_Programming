#include <stdio.h>


int main()

{
    int change;

    do{
        printf("Change Owed:" );
        scanf("%d", &change);
        }
    
    while(change<=0);
    int coinCount=0;
    while(change>0){
        if(change>=25){
            change-=25;
            coinCount+=1;
        }
        else if(change>=10){
            change-=10;
            coinCount+=1;
        }
        else if (change>=5){
            change-=5;
            coinCount+=1;

        }
        else if(change>=1){
            change-=1;
            coinCount+=1;
        }


    }
    printf("%d\n",coinCount);
    return coinCount;
    



}