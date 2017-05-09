#include <stdio.h>
#include <stdlib.h>
#define MAX_THESEIS 53

int leof[MAX_THESEIS];   // eksoterikh metavlhth gia na mporoun oi synarthseis na metavaloun thn timh ths
                         // prosopika tha protimousa parametrous deiktes stis synarthseis anti eksoterikwn metavlhtwn

// SYNARTHSH POY ELEGXEI AN O ARITHMOS TON THESEON EINAI APODEKTOS
int check_ar_theseon(int );
// SYNARTHSH EYRESHS PLHTHOYS KENWN THESEWN KAI ARITHMOI AYTWN
void synolo_kenwn_thesewn_arithmoi_tous(int , int []);
// SYNARTHSH POY ELEGXEI AN H THESH EINAI HDH KRATHMENH
int check_krathmenh_thesh(int , int []);  //n:plhthos thesewn lewforiou, pos: thesh gia krathsh a: o pinakas twn thesewn
// SYNARTHSH KRATHSHS SYGKEKRIMENHS THESHS
void krathsh_theshs(int , int);
// EYRESH KAI KRATHSH THS PRWTHS KENHS THESHS SE PARATHYRO
void euresh_prvths_kenhs(int , int []);
// SYNARTHSH AKYRWSHS SYGKEKRIMENHS THESHS
void akyrwsh_theshs(int , int );
// SYNARTHSH DHMIOYRGIAS DIAGRAMMATOS THESEWN LEOFOREIOY SE ARXEIO
void diagramma_leof_se_arxeio(char [], int);


// KYRIWS PROGRAMMA
int main()
{

  FILE *myFile;
  char ak[8];
  int  ar_theseon; // o arithmos thesewn tou leoforiou pou diavazei apo to arxeio
  int i, choice;
  int thesh;      // arithmos theshs gia krathsh

  // MHDENIZO TON PINAKA leof
  for (i = 0; i < MAX_THESEIS ; i++)
       leof[i]=0;
 // DIAVAZO TA DEDOMENA APO TO ARXEIO
  myFile = fopen("bus.txt", "r"); //anoigo gia diavasma to arxeio
  if (myFile != NULL)             //an den yparxei provlima
  {
      fscanf(myFile,"%s %d", ak, &ar_theseon);
      ak[7]='\0';                 //Epeidh o pinakas pernei timh alfarithmitiko
      fclose(myFile);
  }
  else
  {
   	  printf("Provlima anagnoshs arxeiou\n");
      exit(1);
  }


  printf("AR. KYKLOFORIAS:%s\n", ak);
  printf("AR. THESEWN:%d\n", ar_theseon);

  if (check_ar_theseon(ar_theseon) && (ar_theseon <= MAX_THESEIS))   // ELEGXOS AN O ARITHMOS THESEWN TOY ARXEIOY EINAI APODEKTOS
     // MENOY EPILOGWN
     do{
      printf("\n\n");
      printf("1. EMFANISH TOY SYNOLIKOY PLHTHOYS KENWN THESEWN KAI TWN ARITHMWN TOYS\n");
      printf("2. KRATHSH THESHS ME SYGKEKRIMENO ARITHMO\n");
      printf("3. EYRESH KAI KRATHSH THS PRWTHS KENHS THESHS SE PARATHYRO\n");
      printf("4. AKYRWSH KRATHSHS THESHS ME SYGKEKRIMENO ARITHMO\n");
      printf("5. ANAZHTHSH GIA TO AN EINAI KRATHMENH THESH ME SYGKEKRIMENO ARITHMO\n");
      printf("6. EMFANISH LISTAS KRATHMENWN THESEWN TAJINOMHMENHS KATA ARITHMO THESHS\n");
      printf("7. EMANISH PINAKIDAS KYKLOFORIAS KAI DIAGRAMMA THESEWN LEWFORIOY\n");
      printf("8. APOTHHKEYSH PINAKIDAS KYKLOFORIAS KAI DIAGRAMMATOS LEWFORIOY SE ARXEIO\n");
      printf("0. TERMATISMOS PROGRAMMATOS\n");
      scanf("%d", &choice);

      if ((choice != 1) && (choice != 2)&& (choice != 3) && (choice != 4) && (choice != 5) && (choice != 6) && (choice != 7) && (choice != 8) && (choice != 0))
          printf("MH APODEKTH TIMH !!!\n");
      else
      {
          if (choice == 1)
             synolo_kenwn_thesewn_arithmoi_tous(ar_theseon, leof);
          else if (choice == 2)
          {
              printf("DWSE ARITHMO THESHS (1-%d):",ar_theseon);
              scanf("%d", &thesh);
              printf("\n");
              krathsh_theshs(ar_theseon, thesh) ;
          }
          else if (choice == 3)
              euresh_prvths_kenhs(ar_theseon , leof);
          else if (choice == 4)
          {
              printf("DWSE ARITHMO THESHS (1-%d):", ar_theseon);
              scanf("%d", &thesh);
              printf("\n");
              akyrwsh_theshs(ar_theseon, thesh);
          }
          else if (choice == 5)
          {
              printf("DWSE ARITHMO THESHS (1-%d):",ar_theseon);
              scanf("%d", &thesh);
              printf("\n");
              if (thesh <= ar_theseon)
               check_krathmenh_thesh(thesh, leof)  ? printf("KATHLHMENH \n") : printf("ELEYTHERH \n");
              else
                printf("H THESH %i EINAI EKTOS ORIWN!\n", thesh);
          }
          else if (choice == 6)
          {
              printf("KATHLHMENES THESEIS:");
              for (i=0; i < ar_theseon; i++)
                   if (check_krathmenh_thesh(i, leof))
                       printf("%d, ",i);
          }
          else if (choice == 7)
          {
              printf("%s\n", ak);                  // emfanish pinakidas kykloforias
              for (i=1; i <= ar_theseon; i++)
              {
                   check_krathmenh_thesh(i, leof) ? printf("*") : printf("_");    //emanish * an einai kathlhmenh h i- thesh kai _ an einai eleytherh
                   if (i <= ar_theseon - 5)                                       // den afhnw diadromo kai den allazw grammh otan eimai sthn teleytaia seira thesewn
                   {                                                              // H synarthsh check_krathmenh_thesh otan h prvth parametros exei timh 1 , epeksergazetai thn thesh 0 toy pinaka
                       if ((i-2) % 4 == 0)
                           printf(" ");
                       if ((i-4) % 4 == 0)
                       printf("\n");
                   }
              }
          }
          else if (choice == 8)
              diagramma_leof_se_arxeio(ak, ar_theseon);   // klhsh synarthshs gia dhmioyrgia toy arxeioy

          else
          {
   	              printf("Provlima anoigmatos arxeiou\n");
                  exit(1);
          }

      }

      }while (choice != 0);
  else
     if (ar_theseon > MAX_THESEIS)
         printf ("O ARITHMOS TWN THESEWN DEN MPOREI NA YPERVAINEI TO 53");
     else if (!check_ar_theseon(ar_theseon))
         printf("LATHOS ARITHMOS THESEWN (O ARITMOS PREPEI NA EINAI: 4xN+5, N>=0)\n");

return 0;
}

//YLOPOIHSH SYNARTHSEON **************************************************************

// SYNARTHSH POY ELEGXEI AN O ARITHMOS TON THESEON EINAI APODEKTOS
int check_ar_theseon(int num)
{
    if(((num-5) % 4 == 0) && (num >= 5) && num <= MAX_THESEIS)   // YPOTHETIKA TO LEOFOREIO PREPEI NA EXEI TOYLAXISTON
        return 1;                          //  MIA PENTADA DHLADH TO LIGOTERO 5 THESEIS (symfona me ton 4xN+5 gia N=0)
    else
        return 0;
}
// SYNARTHSH EYRESHS PLHTHOYS KENWN THESEWN KAI ARITHMOI AYTWN
void synolo_kenwn_thesewn_arithmoi_tous(int num, int a[])
{
    int i;
    int count =0;

    for(i = 0; i < num; i++)
        if (a[i] == 0)
        {
            count += 1;
            printf("KENH THESH ME ARITHMO:%d\n",i+1);
        }
    printf("\nSYNOLO KENWN THESEWN:%d", count);
}
// SYNARTHSH POY ELEGXEI AN H THESH EINAI HDH KRATHMENH
int check_krathmenh_thesh(int pos, int a[])  //n:plhthos thesewn lewforiou, pos: thesh gia krathsh a: o pinakas twn thesewn
{
    if(a[pos-1] == 1)                        //an einai krathmenh epistrefei 1 alliws epistrefei 0
       return 1;
    else
       return 0;
}
// SYNARTHSH KRATHSHS SYGKEKRIMENHS THESHS
void krathsh_theshs(int n, int pos )
{
    if (pos >= 1 && pos <= n)                  //elegxw an o arithmos ths theshhs einai entos oriwn
        if (!check_krathmenh_thesh(pos, leof)) //  elegxw an h thesh den einai kathlhmenh
         {
            leof[pos-1]=1;
            printf("H KRATHSH THS THESHS: %d EGINE\n", pos);
         }
        else
            printf("H KRATHSH THS THESHS: %d DEN EGINE\n", pos);
    else
        printf("H THESH %d EINAI EKTOS ORIWN\n", pos);
}
// EYRESH KAI KRATHSH THS PRWTHS KENHS THESHS SE PARATHYRO
void euresh_prvths_kenhs(int n, int a[])
{
  int i = 0;
  int desmeuthike  = 0;


  while ((i < n) && (desmeuthike  == 0))
  {
      if (!check_krathmenh_thesh(i+1, a))                                      // Elegxo ean den einai kathlhmenh h thesh
        if (((i != n-2) && ((i % 4 == 0) || ((i-3) % 4 == 0))) || (i == n-1)) // epeidh h teleutaia seira einai 5ada parathiro einai h teleutaia thesh
           {
                   a[i]=1;

                   desmeuthike = 1;  // termatizo thn epanalhch
           }
      ++i;
  }
  desmeuthike ==1 ? printf("EGINE KRATHSH THS THESHS: %d \n", i ) : printf("DEN YPARXEI THESH\n");
}
// SYNARTHSH AKYRWSHS SYGKEKRIMENHS THESHS
void akyrwsh_theshs(int n, int pos)
{

    if (pos >= 1 && pos <= n)                 //elegxw an o arithmos ths theshhs einai entos oriwn
        if (check_krathmenh_thesh(pos, leof)) //  elegxw an h thesh den einai kathlhmenh
         {
            leof[pos-1] = 0;
            printf("H THESH: %d AKYRWTHIKE\n", pos);
         }
        else
            printf("H THESHS %d DEN AKYRWTHIKE\n", pos);
    else
        printf("H THESH %d EINAI EKTOS ORIWN\n", pos);
}
// SYNARTHSH DHMIOYRGIAS DIAGRAMMATOS THESEWN LEOFOREIOY SE ARXEIO
void diagramma_leof_se_arxeio(char a[], int n)  // a:ar. kykloforias, n: ar. thesewn
{
FILE *myFile;
int i;

     myFile = fopen("bus_diag.txt", "w");
     if (myFile != NULL)               //an den yparxei provlima
        {
        fprintf(myFile, "%s\n", a);  // emfanish pinakidas kykloforias
        for (i=1; i <= n; i++)
            {
            check_krathmenh_thesh(i, leof) ? fprintf(myFile, "%c", '*') : fprintf(myFile,"%c", '_');    //emanish * an einai kathlhmenh h i- thesh kai _ an einai eleytherh
            if (i <= n - 5)                                                                             // den afhnw diadromo kai den allazw grammh otan eimai sthn teleytaia seira thesewn
               {                                                                                        // H synarthsh check_krathmenh_thesh otan h prvth parametros exei timh 1 , epeksergazetai thn thesh 0 toy pinaka
               if ((i-2) % 4 == 0)
                  fprintf(myFile,"%c", ' ');
                  if ((i-4) % 4 == 0)
                      fprintf(myFile,"%s", "\n");
               }
            }
        }
     fclose(myFile);
     printf("TO ARXEIO ME ONOMA [bus_diag.txt] DHMIOYRGHTHIKE");
}

//TELOS YLOPOIHSH SYNARTHSEON **************************************************************
