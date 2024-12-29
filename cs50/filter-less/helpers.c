#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Row
    for(int i =0;i<height;i++){
        for(int j=0;j<width;j++){
            BYTE blue = image[i][j].rgbtBlue;
            BYTE green = image[i][j].rgbtGreen;
            BYTE red = image[i][j].rgbtRed;
            BYTE grayscale = (BYTE)round((float)(blue+green+red)/3);
            image[i][j].rgbtBlue = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtRed= grayscale;

            


        }

    }

    
}

// Convert image to sepia
int less(int num1, int num2){
    return (num1<num2) ? num1: num2;
}
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i =0; i<height;i++){
        for(int j=0;j<width;j++){
        BYTE originalRed = image[i][j].rgbtRed;
        BYTE originalGreen = image[i][j].rgbtGreen;
        BYTE originalBlue = image[i][j].rgbtBlue;
        BYTE sepiaRed = less((.393 * originalRed + .769 * originalGreen + .189 * originalBlue),255);
        BYTE sepiaGreen = less((.349 * originalRed + .686 * originalGreen + .168 * originalBlue),255);
        BYTE sepiaBlue = less((.272 * originalRed + .534 * originalGreen + .131 * originalBlue),255);
        image[i][j].rgbtRed = sepiaRed;
        image[i][j].rgbtBlue = sepiaBlue;
        image[i][j].rgbtGreen = sepiaGreen;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int halfWidth = width /2;
    for(int i =0; i<height;i++){
        RGBTRIPLE *row = image[i];
        for(int j=0;j<halfWidth;j++){
            RGBTRIPLE temp;
            temp = row[j];
            row[j] = row[width-1-j];
            row[width-j] = temp;
        } 

    }
    
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE newimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newimage[i][j] = image[i][j];
        }
    }
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        
        { int red=0;
    int green=0;
    int blue=0;
    int counter=0;
            if(i>=0 &&j>=0){
                red+=newimage[i][j].rgbtRed;
                 green+=newimage[i][j].rgbtGreen;
                  blue+=newimage[i][j].rgbtBlue;
                  counter++;
                
                
                
            }
            if(i-1>=0){
                
                 red+=newimage[i-1][j].rgbtRed;
                 green+=newimage[i-1][j].rgbtGreen;
                  blue+=newimage[i-1][j].rgbtBlue;
                  counter++;
                
                
                
                
                
            }
            if(i+1<height){
                red+=newimage[i+1][j].rgbtRed;
                 green+=newimage[i+1][j].rgbtGreen;
                  blue+=newimage[i+1][j].rgbtBlue;
                  counter++;
                
                
                
                
                
            }
            if(j+1<width){
                red+=newimage[i][j+1].rgbtRed;
                 green+=newimage[i][j+1].rgbtGreen;
                  blue+=newimage[i][j+1].rgbtBlue;
                  counter++;
                
                
                
                
                
                
            }
       
        if(j-1>=0){
                red+=newimage[i][j-1].rgbtRed;
                 green+=newimage[i][j-1].rgbtGreen;
                  blue+=newimage[i][j-1].rgbtBlue;
                  counter++;
                
                
                
                
                
                
            }
            if(i+1<height&&j+1<width){
                
                red+=newimage[i+1][j+1].rgbtRed;
                 green+=newimage[i+1][j+1].rgbtGreen;
                  blue+=newimage[i+1][j+1].rgbtBlue;
                  counter++;
                
                
                
            }
            if(i+1<height&&j-1>=0){
                
                red+=newimage[i+1][j-1].rgbtRed;
                 green+=newimage[i+1][j-1].rgbtGreen;
                  blue+=newimage[i+1][j-1].rgbtBlue;
                  counter++;
                
                
                
            }
       
       if(i-1>=0&&j-1>=0){
                
                red+=newimage[i-1][j-1].rgbtRed;
                 green+=newimage[i-1][j-1].rgbtGreen;
                  blue+=newimage[i-1][j-1].rgbtBlue;
                  counter++;
                
                
                
            }
       
         if(i-1>=0&&j+1<width){
                
                red+=newimage[i-1][j+1].rgbtRed;
                 green+=newimage[i-1][j+1].rgbtGreen;
                  blue+=newimage[i-1][j+1].rgbtBlue;
                  counter++;
                
                
                
            }
       
       image[i][j].rgbtRed=round(red/(counter*1.0));
       image[i][j].rgbtBlue=round(blue/(counter*1.0));
       image[i][j].rgbtGreen=round(green/(counter*1.0));
       
    }
      
     }
     
    return;
}
