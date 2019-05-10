/*  program: bmpconverter
/*
* Auteur 1: Claes Ferre
* Auteur 2: Grispen Bart
* Link naar github repository: https://github.com/Nightwolve/C-Programming/tree/master/Grispen_Claes_BMP_Inverter
*  sources used:
*  https://stackoverflow.com/questions/4346598/gets-function-in-c -->fgets for filename
*
*
*/

#include <stdio.h>
#include <stdlib.h> //dynamic mem
#include <string.h>

#define HEADERSIZE 54

int main()
{
    //pointers to files
    FILE *source, *target;

    //heap mem
    unsigned char *dynamBMPHeader = (unsigned char *) calloc(54, sizeof(unsigned char));
    char *dynamSourceFile = (char *) calloc(100, sizeof(char));
    char *dynamTargetFile = (char *) calloc(100, sizeof(char));

    //stack mem
    unsigned long imageSize, width, height;          
    int len;                                         //used for removing newline char
    long bytespassed = 0;                            //for VERY large images

    //--give info about program--
    printf("----BMP image inverter program----\n"
           "     Written by Bart Grispen & Ferre Claes\n\n");

    printf("Give filename (relative to executable)\n"
           "OR give full path of the \n");

    printf("Source file: ");
    //--get filename--
    fgets(dynamSourceFile, 100, stdin);               //to prevent overflow of dynamsourcefile var
    len = strlen(dynamSourceFile);
    if (len > 0 && dynamSourceFile[len-1] == '\n')   //code overgenomen: zie titel
        dynamSourceFile[len-1] = '\0';
	
	
	//--attempt to read from file--
    source = fopen(dynamSourceFile, "rb");
    if(source == NULL)
    {
        printf("Failed to read file!\n");
        return 1;
    }
    free(dynamSourceFile);                          //no longer needed after filepointer created

    printf("Destination file: ");

    fgets(dynamTargetFile, 100, stdin);
    len = strlen(dynamTargetFile);                  //code overgenomen: zie titel
    if (len > 0 && dynamTargetFile[len-1] == '\n')
        dynamTargetFile[len-1] = '\0';


    //--attempt to write to file (create pointer)--
    target = fopen(dynamTargetFile, "wb");
    if(target == NULL)
    {
        printf("Failed to create file!\n");
        return 1;
    }
    free(dynamTargetFile);                          //no longer needed after filepointer created

    //--read file header into memory and copy to file--
	//(the header information can be used for other functions)
    for(char count1 = 0; count1 < HEADERSIZE; count1++)
    {
        dynamBMPHeader[count1] = fgetc(source);
        fputc(dynamBMPHeader[count1], target);
    }

    //--read size of file--
    width = dynamBMPHeader[20];
    width = width << 8 | dynamBMPHeader[19];
    width = width << 8 | dynamBMPHeader[18];

    height = dynamBMPHeader[24];
    height = height << 8 | dynamBMPHeader[23];
    height = height << 8 | dynamBMPHeader[22];


    imageSize = width * height * 3;                 //calculate size of image data in bytes (no padding)


    printf("\nwidth = %x height = %x HEX\n", width, height);
    printf("width = %d height = %d\n", width, height);


    //--read and copy data from source -> target (and inverting)--
	//count keeps track of where we are in the row
	//bytespassed is used for calculating the padding
    for(long count1 = 1; count1 <= imageSize; ++count1)
    {
        char copybyte, invertedbyte;

        copybyte = fgetc(source);
        invertedbyte = 255 - copybyte;              //inversion
        fputc(invertedbyte,target);
        bytespassed ++;

        //calculate padding (if necessary)
        if((count1) % (width * 3) == 0)
        {
            while(bytespassed % 4 != 0)             //voor count = 0: skipt
            {
                copybyte = fgetc(source);
                fputc(copybyte,target);
                bytespassed++;
            }
        }
    }

    printf("Copy of file is a success!!\n");
    printf("Copied a total of %d bytes\n", bytespassed + HEADERSIZE);
    free(dynamBMPHeader);
    fclose(source);
    fclose(target);
	return 0;
}
