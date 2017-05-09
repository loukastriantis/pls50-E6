//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 2                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//***                   Α.Μ.:123617                         ***
//***                   ΛΟΥΚΑΣ ΤΡΙΑΝΤΗΣ                     ***
//*************************************************************
#include <stdio.h>  /* logw printf(), fscanf(), fopen(), fclose() */
#include <stdlib.h> /* logw exit(), atoi() */
#include <string.h> /*strcpy(), strcmp(), strncpy(), strcat() */

// ORISMOS DOMHS
struct bus_struct {
    char name[40];                 /* gia to onomatepwnymo */
    unsigned short phone[10];
    unsigned int seat;
};
// ORISMOS KOMVOY LISTAS
struct node {
    char name[40];                /* gia to onomatepwnymo */
    unsigned short phone[10];
    unsigned int seat;
    struct node *next;            /* deikths se epomeno komvo ths listas, xreiazetai gia thn syndesh twn komvwn */
};

/* SYNARTHSH POU DIAVAZEI TON AR. KYKLOFORIAS KAI TO PLHTHOS TWN THESEWN TOU LEOFWRIOU APO ARXEIO bus.txt. AN EPISTREPSEI 0 KATI PHGE STRAVA ALLIWS EPISTREFEI 1*/
int license_and_seats(char *, int*);

/* SYNARTHSH POU DIAVAZEI TON ARITHMO THLEFWNOU WS ALFARITHMITIKO KAI TO METATREPEI SE ARITHMO */
void thlefono_epivath(unsigned short *);

/* SYNARTHSH POU DIAVAZEI EPWNYMO KAI ONOMA EPIBATH*/
int onomateponymo_epivath(char *);

/* SYNARTHSH POU METRAEI TO PLHTHOS TWN ELEYTHERWN THESEWN  */
void free_seats(struct bus_struct *, int);
/* SYNARTHSH POU KANEI KRATHSH ELEYTHERHS THESHS KAI EPISTREFEI 1 DIAFORETIKA 0  */
int add_seat(struct bus_struct *,int);

/* SYNARTHSH POU EMFANIZEI THN LISTA KRATHMENWN THESEWN*/
void show_list(struct bus_struct *,int);

/* SYNARTHSH POU ANAZHTA  THESH ME KRHTHRIO ONOMATEPWNYMO KAI EPISTREFEI 1 GIA KATHLHMENH KAI 0 DIAFORETIKA*/
int find_seat_by_name(struct bus_struct *,int, char  n_epiv[]);

/* SYNARTHSH POU ANAZHTA THESH ME KRHTHRIO THLEFWNO KAI EPISTREFEI 1 GIA KATHLHMENH KAI 0 DIAFORETIKA*/
int find_seat_by_phone(struct bus_struct *, int, unsigned short p_epiv[]);

/* SYNARTHSH AKYRWSHS KRATHMENHS THESHS, EPISTREFEI 1 AN GINEI 0 AN DEN GINEI*/
int cancel_seat(struct bus_struct*, int);

/* SYNARTHSH POU FORTWNEI TIS KRATHMENES THESEIS APO TO ARXEIO STON PINAKA*/
void seats_from_file(struct bus_struct*);

/* SYNARTHSH POU ENHMERWNEI TO ARXEIO ME TIS KRATHMENES THESEIS*/
void insert_to_file(struct node*, char lic[], int);

/* SYNARTHSH POY EMFANIZEI TAJINOMHMENH THN LISTA TWN EPIVATWN KATA ONOMATEPWNYMO*/
void sort_by_name(struct bus_struct *,int);

/* SYNARTHSH POY TAJHNOMEI TON PINAKA KATA AR. THESHS POY EINAI KATAXWRHMENH STHN DOMH */
void sort_by_seat(struct bus_struct *,int );

/* SYNARTHSH GIA THN DHMIOYRGIA LISTAS ME STOIXEIA TOYS KOMVOUS TOY PINAKA bus */
struct node *add_node_to_list(struct node *,struct bus_struct *, int );

char filename[]="bus.txt";                             /*Katholikh metavlhth me periexomeno to onoma tou arxeiou*/

/**********************************************KYRIWS PROGRAMMA*********************************************/
int main()
{
char license[8];                                       /* pinakida kykloforias, 7 grammata-arithmoi kai to '\0' */
int seat, seats;                                       /* plithos thesewn */
int reserved_seats,i,j, choice, choice_serch;          /* boithitikes metablites */
char name_epiv[40];                                    /* onomateponymo epivath  */
unsigned short phone_epiv[10];                         /* thlefwno se unsigned short */
struct node  *list=NULL;
struct bus_struct *bus ;                               /* deikths se  domh  bus_struct*/
int status;                                            /* pairnei tis times tis synarthshs add_seat(), 0,1,2 an einai h thesh einai kathlhmenh , krath8hke , den krath8hke logo megalou epwnymou antistoixa */

   if(license_and_seats(license ,&seats) ==0 )         /*diavazw theseis kai adeia kykloforias apo to arxeio bus.txt kai elegxw an kati den phge kala */
   {
      printf("To arxeio bus.txt de mporese na anagnwstei\n");
      exit(1);                                         /* ejodos apo to programma */
   }
   printf("Ar.Kykoforias:%s Ar.Thesewn:%d\n\n", license, seats);  /* ektypwsi pinakidas kai plithous thesewn */
   //if (seats > MAX_THESEIS) {                             /*AFOY O PINAKAS EINAI DYNAMIKOS DEN YPARXEI PROVLHMA THESEWN*/
   //  printf("megisto plitos thesewn %d\n",MAX_THESEIS);
   //  exit(1);
   //}
   /* elegxos elaxistou kai megistou plithous thesewn */
   if (seats < 5 || (seats-5)%4 != 0 ) {
     printf("mi egkyro plithos thesewn\n");
     exit(1);
   }
   bus=(struct bus_struct*) malloc(seats*sizeof(struct bus_struct));   /* desmeush mnhmhs - dynamikos pinakas*/
   /* arxikopoiisi Pinaka typou domhs */
   for (i=0;i<seats;i++){
     bus[i].name[0]='\0';                      /* nenh symvoloseira sto onomateponymo epivath*/
     for (j=0;j<10;j++)bus[i].phone[j]=0;      /* mhdenizei oles tis theseis tou pinaka me mhdenika  */
     bus[i].seat=i;                            /* ekxwrei ton ar. thshs epivath arxizwntas apo 0 gia thn thesh 1 */
   }
   seats_from_file(bus); /* fortwnei tis krathmenes theseis apo to arxeio ston pinaka*/
   choice = 1;           /* arxiki timi gia eisodo sto loop */
   while (choice != 0) { /* mexri na epilegei termatismos */
      printf("***********************MENU EPILOGWN****************************************************\n");
      printf("* 1. Emfanish synolikoy plhthous kenwn thesewn kai twn arithmwn  tous                  *\n");
      printf("* 2. Krathsh theshs me sygkekrimeno arithmo                                            *\n");
      printf("* 3. Anazhthsh theshs me krithrio onomatepwnymou h thlefwnou                           *\n");
      printf("* 4. Akyrwsh krathshs theshs me sygkekrimeno arithmo                                   *\n");
      printf("* 5. Emfanish listas krathmenwn thesewn taksinomhmenhs(kata onomateponymo h ar.theshs) *\n");
      printf("* 0. Termatismos                                                                       *\n");
      printf("****************************************************************************************\n");
      printf("Dose epilogh:");
      scanf("%d", &choice); printf("Epilogi: %d\n",choice);
      printf("\n");
      switch(choice) {
        case 0:
           sort_by_name(bus,seats);                 /* tajhnomhsh kata onomateponymo */
           for(i=0;i<seats;i++)
              if(bus[i].name[0]!='\0' )  list=add_node_to_list(list,bus,i);  /* gemizei thn lista me tous komvous tou pinaka bus twn krathmenwn thesewn*/
           insert_to_file(list, license, seats);    /* eisagei sto arxeio ta periexomena ths listas */
           printf("To programma termatistike.");
           break;
        case 1:
           free_seats(bus, seats);                  /* emfanizei plhthos kenwn thesewn kai tous arithmous tous */
           printf("\n");
           break;
        case 2:
           printf("Dwse arithmo thesis:");
           scanf("%d", &seat);
           printf("\n");
           if (seat<1 || seat>seats)                /* elegxei oti o arithmos theshs einai entos oriwn */
                printf("Arithmos thesis ektos oriwn\n");
           else{
                status=add_seat(bus, seat);        /* pernaei me anafora to struct kai ton arithmo thesis gia krathsh. Epistrefei 1 an ginei krathsh 0 diaforetika*/
                if (status==1)
                   printf("H thesi: %i kratithike\n",seat);
                else if (status==0)
                   printf("H thesi: %i einai idi kateilhmmeni\n",seat);
                else if (status==2)
                    printf("Den mporei na kataxwrh8ei onomatepwnymo megalhtero apo 40 xarakthres mhkos\n");
           }
           break;
        case 3:
            printf("1. anazhthsh me onomatepwnymo\n");
            printf("2. anazhthsh me thlefwno\n");
            scanf("%d",&choice_serch);
            if (choice_serch==1){                  /* anazhthsh bash onomatepwnymou */
                onomateponymo_epivath(name_epiv);  /* diavazei to onomatepwnymo epivath */

               ((reserved_seats=find_seat_by_name(bus, seats,name_epiv))==0) ? printf("Den vrethike thesh me auto to onomateponymo\n") : printf("\n Synolo krathmenwn thesewn:%d\n",reserved_seats);
            }
            else if(choice_serch==2){              /* anazhthsh bash thlefwnou */
                    thlefono_epivath(phone_epiv);  /* diavazei to thlefwno epivath */
                    ((reserved_seats=find_seat_by_phone(bus, seats, phone_epiv))==0) ? printf("Den vrethike thesh me auto to thlefwno\n") : printf("\n Synolo krathmenwn thesewn:%d\n",reserved_seats);
                 }
            else
                printf("Lathos epilogh.\n");
            break;
        case 4:
            printf("Dose arithmo thesis:");
            scanf("%d", &seat);
            printf("\n");
            if (seat<1 || seat > seats)
                printf("Lathos arithmos thesis\n");
            else
            (cancel_seat(bus,seat)==1) ? printf("H akyrwsh egine\n") : printf("H akyrwsh den egine\n");
            break;
        case 5:
            printf("1. taksinomhsh kata onomatepwnymo\n");
            printf("2. taksinomhsh kata ar. theshs\n");
            scanf("%d",&choice_serch);
            if (choice_serch==1){
                printf("\tLista krathmenwn thesewn tajinomhmenh kata onomateponymo\n");
                sort_by_name(bus,seats); /* tajhnomhsh kata onomateponymo  */
                show_list(bus,seats);    /* emfanish stoixeiwn pinaka   */
                sort_by_seat(bus,seats); /* tajhnomhsh kata ar. thseshs */
            }
            else if (choice_serch==2){
                printf("\tLista krathmenwn thesewn tajinomhmenh kata ar. theshs\n");
                show_list(bus,seats);    /* emfanish stoixeiwn pinaka */
            }
            else
                printf("Lathos epilogh\n");
            break;
        default:
            printf("Lathos epilogi\n");
    }
 }
 free(bus);  /* apeleutherwsh ths mnhmhs pou desmeuthike me thn malloc */
 return 0;
}
/**********************************************TELOS KYRIWS PROGRAMMATOS****************************************/

/* YLOPOIHSH SYNARTHSHS GIA THN ANAGNWSH AR. KYKLOFORIAS KAI THESEWN TOU LEOFWRIOY */
int license_and_seats(char *l, int *s){
FILE *f_in= fopen(filename, "r");   /* Anoigei to arxeio eisodou*/
   if(f_in == NULL)                 /* se periptwsi problimatos kata to anoigma */
   {
      return 0;      /* epistrefei 0  */
   }
   fscanf(f_in,"%s %d", l, s);
   fclose(f_in);    /* kleisimo arxeiou eisodou */
   return 1;
}

/* YLOPOIHSH SYNARTHSHS POU METRAEI TO PLHTHOS TWN ELEYTHERWN THESEWN */
void free_seats(struct bus_struct *b, int n){
int i,  count = 0;

    for (i=0;i<n;i++)
         if (b[i].name[0] == '\0') count++; /* metraei tis eleutheres theseis */
    printf("Plithos kenwn thesewn = %d apo %d\n Arithmoi thesewn:\n",count,n);
    for (i=0;i<n;i++)
         if (b[i].name[0] == '\0')         /* an thesi eleutheri den exei onomateponymo epivath */
             printf("%d ",b[i].seat+1);    /* typwse ton arithmo twn eleutherwn thesewn  */
}

/* YLOPOIHSH SYNARTHSHS POU KANEI THN KRATHSH THESHS KAI EPISTREFEI 1 H 0 OTAN EINAI KATHLHMENH  */
int add_seat(struct bus_struct *a, int seat){
int  i=0;
char name_passenger[40];                                        /* name_passenger[40] lamvanei to onomatepwnymo */
unsigned short phone_epiv[10];                                  /* lamvanei ta psifia tou thlefwnou */

     if (strlen((a+seat-1)->name)==0)                           /* elegxei an h sygkekrimenh thesh einai kenh */
     {
            if(onomateponymo_epivath(name_passenger)==0) return 2;     /* Kalei synarthsh onomateponymo_epivath() poy diavazei to onomatepwnymo tou epivath kai epistrefei 1 diaforetika epistrefei 0. H synarthsh add_seat() Epistrefei 2 sthn periptwsh pou to onomatepwnymo einai megalitero apo 40 xarakthres */
            strcpy((a+seat-1)->name , name_passenger);                 /* Kataxwrei to onoma tou epivath sthn thesh poy egine krathsh sthn domh*/
            thlefono_epivath(phone_epiv);                              /* Kalei thn synarthsh me thn opoia diavazei to thlefwno tou epivath */
            for(i = 0; i<10 ; i++)
                   (a+seat-1)-> phone[i] = phone_epiv[i];       /*  Topothetei sto antistoixo melos ths domhs ta psifia tou thlefwnou */
            return 1;                                           /*  An h thesh einai eleu8erh kai topotheteitai epivaths h synarthsh add_seat() epistrefei  1*/
      }
      else
            return 0;                                           /* An h thesh einai kathlhmenh h synarthsh add_seat() epistrefei 0*/
}

/* YLOPOIHSH SYNARTHSHS POU EMFANIZEI THN LISTA KRATHMENWN THESEWN */
void show_list(struct bus_struct *b,int n){
int i, j;
    printf("---------------------------------------------------------------\n");
    for (i=0;i<n;i++,b++)
    {
        if(b->name[0]=='\0')continue;                   /* An h thesh einai eleutherh den thn emfanizei */
        printf("%-40s ",b->name);
        for (j=0;j<10;j++) printf("%d",b->phone[j]);
        printf("  %2d\n",b->seat+1);
    printf("---------------------------------------------------------------\n");        /* H entolh ayth einai entos tou loop alla thn topothethsa etsi wste na emfanizontai stoiximenes oi paules sthn othonh */
    }
}

/* YLOPOIHSH SYNARTHSHS GIA NA DIAVAZEI TO ONOMATEPONYMO EPIBATH*/
int onomateponymo_epivath(char *name_passenger){
char fname[40],lname[40];                                /* ston pinaka lname kataxwrei to eponymo kai ston fname to onoma, o temp proxeiros */

        printf("Dose Eponymo keno onoma epivath:");
        scanf("%s", lname);
        scanf("%s", fname);

        if (strlen(lname)+strlen(" ")+strlen(fname)<40)  /* elegxei an to onomatepwnymo (epwnymo, onoma, keno) exei mhkos to poyly 39 xarakthrwn, sthn 39 thesh to \0 */
        {
            strcpy(name_passenger,lname);                /* Antigrafei to eponymo lname ston name_passenger */
            strcat(name_passenger," ");                  /* topothetei ena keno meta to epwnymo  */
            strcat(name_passenger,fname);                /* atnigrafei to onoma meta to keno*/
            name_passenger[39]='\0';
        }
        else  return 0;                                  /* AN to epwnymo einai > 40 xarakthres den mporei na ginei krathsh kai epistrefei thn timh 0 */
return 1;
}

/* SYNARTHSH POY DIAVAZEI THLEFWNO EPIVATH WS ALFARITHMITIKO KAI TO METATREPEI SE AKERAIA PSIFIA*/
void thlefono_epivath(unsigned short *p_e){
int i;
char phone_num[11], temp[2];

   printf("Dose Thlefono epivath (megisto 10 psifia):");
   scanf("%s",phone_num);
   phone_num[10]='\0';
   printf("\n");
   /* Topothetei ta psifia tou arithmou ston pinaka p_e*/
   for(i = 0; i<10 ; i++)
   {
       strncpy(temp,phone_num+i,1);                 /* prospelavnei ana xarakthra ton pinaka phone_num  kai ton atnigrafei ston temp - ena xarakthra kathe fora*/
       p_e[i]=(unsigned short)atoi(temp);           /* metatrepei ton xarakthra tou temp se akeraio kai ton kataxwrei ston p_e */
   }
}

/*EYRESH THESHS ME ONOMATEPONYMO KAI PLHTHOS KRATHMENWN THESEWN*/
int find_seat_by_name(struct bus_struct *b, int n, char  n_epiv[]){
int i,found=0;

   /* Seiriakh anazhthsh poy sarwnei olo ton pinaka giati mporei na exoun karththei me to idio onoma perissoteres apo mia theseis */
    for (i=0; i < n ;i++)
    {
        if (strcmp(b++->name, n_epiv)==0)
        {
            found++;                              /* metraei to plhthos twn thesewvn pou exei krathsei sygkekrimenos epivaths  */
            printf("ar. theshs:%d ",i+1);
        }
    }
return found;
}

/*EYRESH THESHS ME THLEFWNO*/
int find_seat_by_phone(struct bus_struct *b, int n, unsigned short p_epiv[]){
int j, i, found=0, count;

   /* Seiriakh anazhthsh poy sarwnei olo ton pinaka giati mporei na exoun karththei me to idio thlefwno perissoteres apo mia theseis */
   for (i=0; i < n; i++, b++)
    {
      for(count=0,j=0;j<10;j++)
          if(b->phone[j] == p_epiv[j]) count++;
      if (count==10)
      {
          found++;                               /* metraei to plhthos twn thesewvn pou exei krathsei epivaths me to idio onoma */
          printf("ar. theshs:%d ",i+1);
      }
   }
return found;
}

/* AKYRWSH THESHS ME SYGKEKRIMENO ARITHMO */
int cancel_seat(struct bus_struct *b, int s){
int j;

    (b+s-1)->name[0]='\0';                      /* diagrafei to onoma */
    for (j=0;j<10;j++)(b+s-1)->phone[j]=0;      /* diagrafei to thhlefwno*/
return 1;
}

/* SYNARTHSH POY FORTWNEI TA STOIXEIA TWN KRATHMENWN THESEWN STHN DOMH */
void seats_from_file(struct bus_struct *b){
char license[8], lname[40], fname[40],phone_epiv[11],name_epiv[40];     /* metavlhtes gia thn anagnwsh dedomenwn tou arxeiou */
char temp[2];
unsigned int seat_num;
int i, seats;
FILE* f_in=fopen(filename,"r");

    if(f_in == NULL)                                                    /* se periptwsh problimatos kata to anoigma */
    {
      printf("To arxeio bus.txt de mporese na anagnwstei\n");
      exit(1);                                                          /* ejodos apo to programma */
    }
    fscanf(f_in,"%s %d", license, &seats);
    /* fortwnei sthn domh bus ta stoixeia twn kathlhmenwn thesewn toy arxeiou */
    while(!feof(f_in))
    {
        fscanf(f_in,"%s%s%d%s",lname, fname, &seat_num, phone_epiv);
        strcpy(name_epiv,lname);
        strcat(name_epiv," ");
        strcat(name_epiv,fname);
        strcpy((b+seat_num-1)->name, name_epiv);
        (b+seat_num-1)->seat=seat_num-1;
        /* metatroph tou thlefwnou se psifia */
         for(i = 0; i<10 ; i++)
         {
            strncpy(temp,phone_epiv+i,1);                     /* prospelavnei ana xarakthra ton pinaka phone_num pou periexei ta psifia thlefwnou ws xarakthres kai antigrafei ston pinaka temp */
            temp[1]='\0';                                     /* temp voh8itikos pinakas 2 thesewn. Sthn 1h thesh topo8ethtai o xarakthras me thn prohgroumenh grammh kwdika pou einai psifio thlefwnou, sthn 2h thesh topothetei /0 */
            (b+seat_num-1)->phone[i]=atoi(temp);              /* metatrepei tous xarakthres tou pinaka phone_num se akeraious */
         }
    }
fclose(f_in);  /* kleisimo arxeiou eisodou */
}

/*SYNARTHSH POY GRAFEI STO ARXEIO bus.txt TIS KRATHMENES THESEIS*/
void insert_to_file(struct node *lst, char lic[], int n){
FILE * f_out=fopen(filename,"w");
int j;
struct node *current=NULL;
    if(f_out == NULL)                                        /* se periptwsh problimatos kata to anoigma */
    {
        printf("To arxeio %s de mporese na dhmiourghthei\n",filename);
        exit(1);                                             /* ejodos apo to programma */
    }
    fprintf(f_out,"%s %d",lic,n);                            /* grafei sto arxeio ton ar.kykloforias kai ton ar. twn thesewn */
    current=lst;
    while (current!= NULL)
    {
        fprintf(f_out,"\n%s %d ",current->name,current->seat+1);    /* grafei ta periexomena ths listas sto arxeio */
        for(j=0;j<10;j++)
           fprintf(f_out,"%d",current->phone[j]);
        current=current->next;
    }
free(lst);
fclose(f_out);
}

/*SYNARTHSH POY TAJINOMEI THN LISTA TWN EPIVATWN KATA ONOMATEPWNYMO*/
void sort_by_name(struct bus_struct *b,int s){
int i,j;
struct bus_struct tmp;

/* tajinomhsh stoixeiwn pinaka - selection sort*/
for (i=0;i<s;i++)
    for (j=i+1;j<s;j++)
         if (strcmp(b[i].name,b[j].name)>0)
         {
             tmp=b[i];
             b[i]=b[j];
             b[j]=tmp;
         }
}

/*SYNARTHSH POY TAJINOMEI THN LISTA TWN EPIVATWN KATA AR. THESHS*/
void sort_by_seat(struct bus_struct *b,int s){
int i,j;
struct bus_struct tmp;
  //epanafora pinaka sthn arxikh tou diatajh
  //tajinomhsh stoixeiwn pinaka kata thesh
for (i=0;i<s;i++)
    for (j=i+1;j<s;j++)
         if ((b[i].seat)>(b[j].seat))
         {
             tmp=b[i];
             b[i]=b[j];
             b[j]=tmp;
         }

}

/*SYNARTHSH POY DHMIOYRGEI THN APLA SYNDEDEMENH LISTA ME KOMVOUS TA STOIXEIA TOU PINAKA bus ANADROMIKA*/
struct node *add_node_to_list(struct node *head, struct bus_struct * b, int i){
int j;

    if (head==NULL)
    {
        head=(struct node *)malloc(sizeof(struct node));
        strcpy(head->name,b[i].name);
        for(j=0;j<10;j++) head->phone[j]=b[i].phone[j];
        head->seat=b[i].seat;
        head->next=NULL;

    }
    else
    {
       head->next=add_node_to_list(head->next, b,i);    /*anadromikh klhsh ths synarthshs */
    }
    return head;
}
