#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846


//Askhsh 2

// DHLWSH SYNARTHSEWN

// YPOLOGISMOS PERIMETROU TETRAGWNOY
float perimetros_tetragonou(float );
// YPOLOGISMOS PERIMETROY PARALLHLOGRAMMOY
float perimetros_parllhlogrammou(float , float );
// YPOLOGISMOS PERIMETROY TRIGWNOY
float perimetros_trigwnou(float , float );
// YPOLOGISMOS PERIMETROY KYKLOY
float perimetros_kykloy(float );



int main()
{
    int choice;
    float a, b, y;

    do
    {
        // Menu Epilogon
        printf("0. Ejodos\n");
        printf("1. Tetragono\n");
        printf("2. Parallhlogrammo\n");
        printf("3. Orthogonio trigono\n");
        printf("4. Kyklos\n");

        scanf("%d", &choice);    // Diavasma epiloghs

        if (choice == 0)
            printf("To programma termatisthke\n");
        else if (choice == 1)
        {
            printf("Dwse pleura tetragonou:");
            scanf("%f", &a);
            printf("\nH perimetros tetragonou einai:%.2f\n",perimetros_tetragonou(a));
        }
        else if (choice == 2)
        {
            printf("Dwse vash kai ypsos parallhlogrammou:");
            scanf("%f%f", &b,&y);
            printf("\nH perimetros parallhlogrammou einai:%.2f\n",perimetros_parllhlogrammou(b,y));
        }
        else if (choice == 3)
        {
            printf("Dwse to mhkos ths mias kathetou:");
            scanf("%f", &b);
            printf("Dwse to mhkos ths allhs kathetou:");
            scanf("%f", &y);
            printf("\nH perimetros trigwnoy einai:%.2f\n",perimetros_trigwnou(b,y));
        }
        else if (choice == 4)
        {
            printf("Dwse aktina kykloy:");
            scanf("%f", &a);
            printf("H perimetros kykloy einai:%.2f\n",perimetros_kykloy(a));
        }
        else
            printf("Lathos epilogh! \n");
    }
    while (choice);
    return 0;
}



// ORISMOS SYNARTHSEWN

float perimetros_tetragonou(float pleura)
{
    return 4 * pleura;
}

float perimetros_parllhlogrammou(float vash, float ypsos)
{
    return 2 * (vash + ypsos);
}

float perimetros_trigwnou(float vash, float ypsos)
{

    return vash + ypsos + sqrt(vash * vash + ypsos * ypsos);
}

float perimetros_kykloy(float aktina)
{
    return 2 * PI * aktina;
}
