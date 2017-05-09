#include <stdio.h>
//Askhsh 1

int main()
{
   float a,b;
   char ch;


     printf("Dwse arithmo praji arithmo\n");
     scanf("%f %c%f", &a, &ch, &b);    // Diavasma dedomenon

     if (ch == '+')
         printf("apotelesma = %.2f\n",a + b);
     else if (ch == '-')
         printf("apotelesma = %.2f\n",a - b);
     else if (ch == '*')
         printf("apotelesma = %.2f\n",a * b);
     else if (ch == '/')
         if (b != 0)
             printf("apotelesma = %.2f\n",a / b);
         else
             printf("adynath praji!\n");
    else
         printf("Lathos telesths prajis\n");

return 0;
}
