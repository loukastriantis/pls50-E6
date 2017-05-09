#include <stdio.h>
//Askhsh 3

int main()
{
   int num,  ypol;
   const int base = 2;                                           //Orizw thn vash tou diadikou systhmatos

   do  // pragmatopoio elegxo dedomenon 
   {
     printf("Dwse thetiko akeraio arithmo\n");
     scanf("%d", &num);                                       // Diavasma arithmou
     if (num < 0 )
         printf("o arithmos den einai thetikos\n");
     else if (num >0 )
     {
         printf ("antistrofh diadikh anaparastash:");
         while (num > 0)
         {
             ypol = num % base;                            // vrisko ta ypoloipa ths akeraias diaireshs
             (ypol == 0) ? putchar('0') : putchar ('1'); // emfanizo ta diadika pshfia
             num /= base;                                     //allazo ton trexon arithmo me to phliko
         }
     }                                                               //ths akeraias diaireshs
     else
         printf("antistrofh diadikh anaparastash: %d", num);
   }while (num < 0);

     return 0;
}
