//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 3                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//***                   Α.Μ.:123617                         ***
//***                   ΛΟΥΚΑΣ ΤΡΙΑΝΤΗΣ                     ***
//*************************************************************
#include <stdio.h>  /* printf(), scanf() */
#include <stdlib.h> /* rand(), srand()*/
#include <time.h>   /* time()*/
#include <string.h> /*  strcpy() */

struct card {              //orizw domh card me ta xarakthristika ths kartas
    char color;
    char shape;
    int number;
    char texture;
};

struct card cards[81];     //dhlwnw pinaka global 81 thesewn typou domhs card pou periexei oles tis kartes (olous tous diaforetikous syndyasmous)

struct player {            //orizw domh player gia ta xarakthristika tou paixth symfwna me thn ekfwnhsh
    char id;
    char name[18];         //epdeidh h timh tou pinaka einai alfarithmitiko pernw mia thesh parapanw gia to \0
    unsigned char score;
};

struct player players[3]={{'a',"Marina Andreou\0",0},      //dhlwnw pinaka global triwn thesewn typoy domhs player kai toy apodidw times symfwna me thn ekfwnhsh
                          {'g',"Kostas Grammenos\0",0},
                          {'p',"Maria Perdika\0",0}
};

//TYXAIA EPILOGH 12 KARTWN APO TIS 81
void getNextCard(struct card c[81] ,struct card (*a)[4]);

//EMFANIZEI TO PLEGMA 3X4 ME TIS 12 TYXAIES KARTES
void display_cards(struct card (*r_c)[4]);

//DIAVAZEI TIS SYNTETAGMENES TRIWN KARTWN
void select_cards(int (*c_c)[2]);

//ELEGXEI AN H EPILOGH TOY PAIXTH APOTELEI SET KAI EPISTREFEI 1 DIAFORETIKA EPISTREFEI 0
int check_set(struct card (*r_c)[4],int (*c_c)[2]);

//ENHMERWNEI TO SCORE TOY PAIXTH KAI EMFANIZEI AN EKANE SET H OXI
void update_score(char ,  struct card (*r_c)[4], struct player *p);

/********************************* KYRIWS PROGRAMMA ************************************************************/
int main()
{
char choice='1';    /*choice=1 gia na arxizei h epanalhpsh*/
int number[3]={1,2,3},i=0;
char color[4]={'r','g','b','\0'}, shape[4]={'c','t','r','\0'}, texture[4]={'b','h','e','\0'};   /*pinakes pou periexoun tis dynates times kathe xarakriristikou tis kartas*/
struct card random_cards[3][4];   /* tha gemizei me tis 12=3x4 tyxaies kartes */
int clr, shp, nmr, txr;           /* metavlhtes epanalhpsewn */
char winer_name[18];              /* pinakas xarakthrwn pou pairnei ws timh to onoma tou nikhth */

        winer_name[0]='\0';       /* arxikopooiw me timh ton keno xarakthra '\0'  */
        //arxikopoihsh ths rand
        srand(time(NULL));
        //gemizei ton pinaka cards typou card me tis 81 diaforetikes kartes - olous tous dynatous syndyasmous
        for(clr=0;clr<3;clr++)
            for(shp=0;shp<3;shp++)
                for(nmr=0;nmr<3;nmr++)
                    for(txr=0;txr<3;txr++)
                    {
                        cards[i].color=color[clr];
                        cards[i].shape=shape[shp];
                        cards[i].number=number[nmr];
                        cards[i].texture=texture[txr];
                        i++;
                    }
   getNextCard(cards,random_cards);    /*epilegei 12 tyxaies kartes*/
   display_cards(random_cards);        /*emfanizei 12 kartes sthn othonh tou xrhsth- plegma 3x4*/
   printf("\n\n");
   /*arxizei h epanalhpsh mexri na dothei 0 h na symplhrwsei enas apo tous treis paixtes varhmologia 10*/
   while ((choice!='0') && (players[0].score<10) && (players[1].score<10) && (players[2].score<10))
    {
        printf("Dose id paixth (a/g/p) - (0) gia termatismo:");
        scanf("%s",&choice);    /*diavazei id paixth h mhden gia termatismo*/
         if ((choice=='a')|| (choice=='g')|| (choice=='p')) update_score(choice,random_cards,players);   //enhmerwnei to score tou paixth analoga me to an ekane SET h oxi
         else if (choice=='0') printf("to programma termatisthke.\n");
         else
            {
              printf("lathos epilogh!\n\n");
              getNextCard(cards,random_cards);    /*anakateuei tis kartes se periprwsh epiloghs diaforetikhs tou a/g/p/0*/
              display_cards(random_cards);        /*efmanizei tis kartes*/
              printf("\n\n");
            }
   }
   /*emfanish apotelesmatwn*/
    printf("\n**************** APOTELESMATA ***********************\n\n");

   for(i=0;i<3;i++)
   {
        printf("Id:%c Onoma:%-18s Score:%d\n",players[i].id,players[i].name,players[i].score);
        printf("-----------------------------------------------------\n");
        //vriskei to onoma tou nikhth kai to antigrafei sthn metavlhth winer_name
        if (players[i].score>=10) strcpy(winer_name,players[i].name);
   }
   printf("\n*****************************************************\n\n");
   if (winer_name[0]!='\0')    /*elegxei an vrethike nikhths gia na emfanisei to onoma tou*/
   {
        printf("\n*******************NIKHTHS*************************\n");
        printf("   o nikhths einai o/h: %s",winer_name);
        printf("\n***************************************************\n");
   }
    return 0;
}
/**********************************************TELOS KYRIWS PROGRAMMATOS****************************************/

//SYNARTHSH POU EPILEGEI 12 TYXAIES KARTES MONADIKES
void getNextCard(struct card c[81],struct card (*a)[4]){
int i,j,card_numder;
int tmp[81];

    for (i=0;i<81;i++)  tmp[i]=0;   // arxikopoiw ton pinaka tmp me mhdenika. Kathe fora pou epilegetai mia karta allazw thn timh se 1 sthn thesh tou pinaka me arithmo ton arithmo ths kartas, gia na mhn epilegei ksana

    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
        {
            int done=0;
            do {                                 /*loop pou stamataei an epileksei karta pou den exei ksanaepileksei*/
                card_numder=rand()%81;           /*h card_number  pairnei tyxaio arithmo apo 0-80 */
                if (tmp[card_numder]==0)         /*elegxei an den exei epilegei ksana h karta*/
                {
                    done=1;                      /*flag gia na termatizw thn epanalhpsh otan epilegetai karta*/
                    tmp[card_numder]=1;          /*allazw thn timh se 1 gia na dhlwsw oti exei epilegei h karta*/
                    a[i][j]=cards[card_numder];  /*topothetw thn karta ston pinaka*/
                }
            }while (done==0);
        }
}

//SYNARTHSH POU EMFANIZEI  TIS KARTES SE PLEGMA 3X4
void display_cards(struct card (*r_c)[4]){
int i,j;

    for(i=0;i<3;i++)
    {
            for (j=0;j<4;j++)
                printf("[%c,%c,%d,%c] ",r_c[i][j].color, r_c[i][j].shape, r_c[i][j].number, r_c[i][j].texture);
                printf("\n");
    }
}

//SYNARTHSH EPILOGHS KARTWN - DIAVAZEI TRIA ZEUGH SYNTETAGMENWN
void select_cards(int (*c_c)[2]){
int x,y,i,j;                          /*syntetagmenes kartas poy epilegei o xrhsths*/
int count_same_coordinates=0;         /*metrhths gia na elegxw an dwthoun perissoteres apo mia fores idies syntetagmenes*/

    printf("EPILOGH KARTWN\n");
    for (i=0;i<3;i++)
    {
        do{                           /*elegxei an oi syntetagmenes einai ektos oriwn kai an to zeugos exei dothei pali*/
               printf("\nDwse syntetagmenes (x,y) ths %dhs kartas: ar. grammhs keno ar. sthlhs ENTER:",i+1);
               scanf("%d %d",&x, &y);

               if (((x<0) || (x>2)) || ((y<0) || (y>3))) printf("Lathos Syntetagmenes\n");
                  if (i>0)  /*elegxw an dothikan idies syntetegmenes me prohgoymenh karta*/
                  {
                      count_same_coordinates=0;
                      for (j=0;j<i;j++) if ((c_c[j][0]==x) && (c_c[j][1]==y)) count_same_coordinates++;   /*an to trexon zeugos syntetagmenwn einai idio me ta prohgoymena auksanw ton metrhth*/
                      if(count_same_coordinates!=0) printf("Epilejate idio zeugos syntetagmenwn\n");
                  }
        }while ((((x<0) || (x>2)) || ((y<0) || (y>3)))||(count_same_coordinates!=0));

        c_c[i][0]=x;        /*kataxwrei ta zeygei syntetagmenwn se pinaka 3x2*/
        c_c[i][1]=y;
    }
}

// ELEGXEI AN OI KARTES APOTELOUN SET H OXI KAI EPISTREFEI 1 H 0 ANTISTOIXA
int check_set(struct card (*r_c)[4],int (*c_c)[2]){
int i;
int count_color=0;     /*metrhths pou metraei ta idia xrwmata twn kartwn*/
int count_shape=0;     /*metrhths pou metraei ta idia sxhmata twn kartwn*/
int count_number=0;    /*metrhths pou metraei tous idious arithmous twn kartwn*/
int count_texture=0;   /*metrhths pou metraei thn idia yfh twn kartwn*/


    for(i=1;i<3;i++)
    {
      if(r_c[c_c[i][0]][c_c[i][1]].color == r_c[c_c[0][0]][c_c[0][1]].color) count_color++;    /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros to xrwma kai an einai idio metraw*/
      if(r_c[c_c[i][0]][c_c[i][1]].shape == r_c[c_c[0][0]][c_c[0][1]].shape) count_shape++;    /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros to sxhma kai an einai idio metraw*/
      if(r_c[c_c[i][0]][c_c[i][1]].number == r_c[c_c[0][0]][c_c[0][1]].number) count_number++; /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros ton arithmo kai an einai idios metraw*/
      if(r_c[c_c[i][0]][c_c[i][1]].texture == r_c[c_c[0][0]][c_c[0][1]].texture) count_texture++; /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros thn yfh kai an einai idia metraw*/
    }
    for(i=2;i<3;i++)
    {
      if(r_c[c_c[i][0]][c_c[i][1]].color == r_c[c_c[1][0]][c_c[1][1]].color) count_color++;    /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros to xrwma kai an einai idio metraw*/
      if(r_c[c_c[i][0]][c_c[i][1]].shape == r_c[c_c[1][0]][c_c[1][1]].shape) count_shape++;    /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros to sxhma kai an einai idio metraw*/
      if(r_c[c_c[i][0]][c_c[i][1]].number == r_c[c_c[1][0]][c_c[1][1]].number) count_number++; /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros ton arithmo kai an einai idios metraw*/
      if(r_c[c_c[i][0]][c_c[i][1]].texture == r_c[c_c[1][0]][c_c[1][1]].texture) count_texture++; /*sygkrinw thn 2h kai thn 3h karta me thn 1h ws pros thn yfh kai an einai idia metraw*/
    }
    if(((count_color==3)||(count_color==0)) && ((count_shape==3)||(count_shape==0)) && ((count_number==3)||(count_number==0)) && ((count_texture==3)||(count_texture==0))) return 1;


return 0;
}

//SYNARTHSH POU ENHMERWNEI TO SCORE TOU PAIXTH KAI EMFANIZEI AN EKANE SET H OXI
void update_score(char id, struct card (*r_c)[4], struct player *p){
int i, c_c[3][2];

    for (i=0;i<3;i++)
    {
        if (p[i].id==id)                                        /*elegxei to id pou dexthhke  ws parametro se poio id paixth anhkei*/
        {
                printf("\n");
                select_cards(c_c);                              /*epilogh kartwn - diavazei tis syntetagmenes triwn kartwn*/
                if( check_set(r_c,c_c))                         /*elegxei an einai h triada syntetatmenwn SET kai epistrefei 1 diaforetika 0*/
                {
                        printf("\nSET!\n\n");                   /*emfanizei thn leksh SET sthn othonh*/
                        p[i].score+=2;                          /*auksanei to score tou paixth kata 2 monodes*/
                        getNextCard(cards,r_c);                 /*anakateuei tis kartes*/
                        display_cards(r_c);                     /*emfanizei plegma kartwn 3x4*/
                }
                else
                {
                        printf("\nNO SET!\n\n");                /*emfanizei thn leksh NO SET sthn othonh*/
                        if (p[i].score-1>=0) p[i].score-=1;     /*afairei mia monada mono an to scrore den ginetai arnhtikos*/
                        display_cards(r_c);                     /*emfanizei to plegma kartwn 3x4*/
                }
        }
    }
}
