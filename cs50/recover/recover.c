#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef uint8_t BYTE;
BYTE buffer[512];
int check_jpeg(BYTE *memory);




int main(int argc, char **argv)
{
    bool validFile = false;
    bool firstFile = true;
    char * filename = (char * ) malloc(8 * sizeof(char));
    FILE*img=NULL;
    if(argc !=2){
        printf("Usage: ./recover FILE \n");
        return 1;
    }
    FILE *card = fopen(argv[1],"r");
    int counter =1;

   

    while(fread(buffer,512,1,card)==1)
    {
        // 
        if(check_jpeg(buffer)){
            if(firstFile){
                firstFile = false;
                validFile= true;
            }
            else{
                fclose(img);


        

            }

        sprintf(filename,"%03i.jpg",counter);
        img=fopen(filename,"w");
        counter++;





        }

        

            if(validFile){
                fwrite(buffer,512,1,img);
            }


          
  

        }
    fclose(img);
    fclose(card);
    free(filename);
    return 0;

    }

    




 


int check_jpeg(BYTE *memory){
    if(*memory!=0xFF){
        return 0;
    }
    if(*(memory+1) !=0xd8 ){
        return 0;
    }
    if((*(memory+2)!=0xff)){
        return 0;
    }
    if((*(memory+3)&0xff)!=0xe0){
        return 0;
    }

    return 1;

}