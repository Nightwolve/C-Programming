//Arne Niesten - 1PBEAI B//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *out;
    char c;
    int header[54];
    unsigned int i = 0;
    unsigned long widthO,heigthO = 0;
    unsigned long widthN, heigthN = 0;
    char str1[100];
    char str2[100];
    //Voorbeeld voor het invullen van de directory:
    //Bij output ook naam van de afbeelding +.bmp toevoegen
    //Geef de locatie van de afbeelding die geinverteerd moet worden:
    //C:\Users\11700372\Desktop\fruit.bmp
    //Geef de locatie+naam van uw output file:
    //C:\Users\11700372\Desktop\Fruit_inv.bmp
    printf("Geef de locatie van de afbeelding die geinverteerd moet worden:\n");
    scanf("%s", &str1);
    printf("Geef de locatie+naam van uw output file:\n");
    scanf("%s", &str2);
    in = fopen(str1, "rb");
    out = fopen (str2, "wb");

    if (in == NULL)
    {
        printf("Geen/foutieve input locatie");
        exit(EXIT_FAILURE);
    }

    if (out == NULL)
    {
        printf("Geen/foutieve output locatie");
        exit(EXIT_FAILURE);
    }
	
	do
     {
        c = getc (in);
        header[i] = c;
        i++;
        putc(c,out);
    }
        while (i < 54);
//breedte afbeelding, internet(verschillende bronnen samengevoegd)//
    widthO = header [20] & 0x000000FF;
    widthO = widthO << 8;
    widthO = widthO | header [19] & 0x000000FF;
    widthO = widthO << 8;
    widthO = widthO | header [18]& 0x000000FF;
//hoogte afbeelding, internet(verschillende bronnen samengevoegd)////
    heigthO = header [24];
    heigthO = heigthO << 8;
    heigthO = heigthO | header [23];
    heigthO = heigthO << 8;
    heigthO = heigthO | header [22];

do  {
        widthO= widthO + 1;
        }
        while ((widthO*3)%4 != 0);
        
        widthN = widthO;

do
 {
        c = getc (in);
        c= 255 - c;
        putc(c,out);
        i++;
  
    }
    while (i < (3*widthN*heigthO)+54);  
    
    fclose (in);
    fclose (out);

printf("De omvang van de afbeelding bedraagt:  %d x %d \n", widthO, heigthO );

    return 0;
}
