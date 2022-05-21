#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct {
int j,m,aa ;
}Date;

typedef struct {
    char code[30];
    int cp_stck;
    char etat[3];
    Date date_fab ;
    int nbre_vol;
}Avion;
typedef struct noeuds noeuds;
struct noeuds {
    Avion data ;
    noeuds* next;
};
typedef noeuds* liste ;
void ajout_avion (liste* l,Avion a )
{  noeuds* P ;
   noeuds* ne;
   ne= (noeuds*) malloc(sizeof(noeuds));
   ne->data = a;
   ne->next=NULL;
   if ( (*l) == NULL)
     (*l)= ne;
   else
    { P = (*l);
      while ( P->next != NULL)
        {P = P->next;}
         P->next = ne ;
    }
}
   void afficher (liste l)
   { noeuds* P ;
     if (l== NULL)
        printf("la liste est vide");
     else
        {
         P = l;
         while (P )
        {
           printf("[%s | %d | %s| %d |%d |%d |%d ]->",P->data.code,P->data.cp_stck,P->data.etat,P->data.date_fab.j,P->data.date_fab.m,P->data.date_fab.aa,P->data.nbre_vol);
           P = P->next ;
        }
        }
   }
int dans_aeroport (Avion a)
{ int i;
  char car[3]="A";
  i= strcmp(car,a.etat);
  if ( i == 0)
  printf(" l'avion de code %s se trouve dans l'aeroport:  ", a.code);
  return i ;
}

 void supprimer (liste* l)
 {
  liste q =(*l),k;
  char ch[3]= "M" ;
  if ((*l) != NULL)
  {
     do {
       if ((q->data.date_fab.aa < 2001 ) && strcmp(ch,q->data.etat)==0 )
        { if (q == (*l))
         {
             (*l) = (*l)->next ;
             free(q);
             q = (*l) ;
         }

         else

         {   k->next = q->next;
             free (q);
             q = k->next;
         }
     }
        k = q;
        q = q->next;

  } while (q == NULL);
}
 }
 void afficher_nbre (liste l)
 {  char ch1[3]= "A" ;
    char ch2[3]= "D" ;
    int i1=0,i2=0;
    while (l!= NULL)
    {
        if (strcmp(l->data.etat,ch1)==0 )
            i1++;
        if (strcmp(l->data.etat,ch2)==0)
            i2++;
      l= l->next;

    }
    printf("\nle nombre des avions atteris est:%d\n",i1);
    printf("le nombre des avions decolles est:%d\n",i2);
 }
 int max_vol (liste l)
 {
  int max=0 ;
  liste P = l;
  if (l!= NULL)
      max= P->data.nbre_vol;
  P= P->next;
  while (P != NULL)
  {
      if ( P->data.nbre_vol > max )
        max = P->data.nbre_vol;
      P= P->next;
  }
  return max ;
 }

void affiche_avion_vol_max_age_10(liste l)
{  liste P =l;
  while (P != NULL)
  {
    if ((P->data.nbre_vol == max_vol(l)) && (P->data.date_fab.aa >= 2001))
      printf("les avions qui ont le maximum des vols et qui sont ages moins de 10 ans sont:[%s | %d | %s| %d |%d |%d |%d ]->",P->data.code,P->data.cp_stck,P->data.etat,P->data.date_fab.j,P->data.date_fab.m,P->data.date_fab.aa,P->data.nbre_vol);
    P=P->next;
  }
}
int min_vol (liste l)
 {
  int min=0 ;
  liste P = l;
  if (l!= NULL)
      min= P->data.nbre_vol;
  P= P->next;
  while (P != NULL)
  {
      if ( P->data.nbre_vol < min )
        min = P->data.nbre_vol;
      P= P->next;
  }
  return min ;
 }
 void affiche_avion_vol_min_age_10(liste l)
{  liste P =l;
  while (P != NULL)
  {
    if ((P->data.nbre_vol == min_vol(l)) && (P->data.date_fab.aa >= 2001))
      printf("les avions qui ont le minimum des vols et qui sont ages moins de 10 ans sont:[%s | %d | %s| %d |%d |%d |%d ]->",P->data.code,P->data.cp_stck,P->data.etat,P->data.date_fab.j,P->data.date_fab.m,P->data.date_fab.aa,P->data.nbre_vol);
    P=P->next;
  }
}
 void afficher_atteri(liste l)
 {   char s[3]="A";
     liste q=l;
     while (q != NULL)
     {
       if (strcmp(s,q->data.etat)== 0)
         printf("les avions atteris sont:[%s | %d | %s| %d |%d |%d |%d ]->",q->data.code,q->data.cp_stck,q->data.etat,q->data.date_fab.j,q->data.date_fab.m,q->data.date_fab.aa,q->data.nbre_vol);
       q= q->next;
     }
 }


void scinder (liste l,liste* A,liste* M,liste* D)
{
  A=NULL,M=NULL,D=NULL;
 liste k=l;
 char cha[3]="A";
 char chd[3]="D";
 char chm[3]="M";

 while (k != NULL)
 { if (strcmp(k->data.etat,cha)== 0)
{
liste nouvelElement = malloc(sizeof(noeuds));

nouvelElement->data = k->data;

nouvelElement->next = NULL;

if( (*A)== NULL)
{
 (*A)= nouvelElement;
}
else
{
liste temp=l;
while(temp->next != NULL)
{
temp = temp->next;
}
temp->next = nouvelElement;
}
}
if (strcmp(k->data.etat,chd)== 0)
{
liste nouvelElement = malloc(sizeof(noeuds));

nouvelElement->data = k->data;

nouvelElement->next = NULL;

if((*D) == NULL)
{
 (*D)= nouvelElement;
}
else
{
liste temp=l;
while(temp->next != NULL)
{
temp = temp->next;
}
temp->next = nouvelElement;
}
}
if (strcmp(k->data.etat,chm)== 0)
{
liste nouvelElement = malloc(sizeof(noeuds));

nouvelElement->data = k->data;

nouvelElement->next = NULL;

if((*M) == NULL)
{
 (*M)= nouvelElement;
}
else
{
liste temp=l;
while(temp->next != NULL)
{
temp = temp->next;
}
temp->next = nouvelElement;

}
}
   k= k->next;
 }
 (*A)->next =NULL;
 (*M)->next =NULL;
 (*D)->next = NULL;
 printf("la liste des avions atterris :\n");
 afficher(*A);
 printf("la liste des avions en maintenance technique :\n");
 afficher(*M);
 printf("la liste des avions decolles :\n");
 afficher(*D);

}




void  main ()
{
 Avion AV ;
 liste T = NULL ;
 liste* A=NULL;
 liste* M=NULL;
 liste* D=NULL;
 int choix,X,max,d;
 printf("Bonjour, veuillez remplisser la liste des avions et verifiez pour chacun s'il est dans l'aeroport ou pas !\n");

 do
 {

 printf("donnez le code d'avion :\n");
 scanf("%s",AV.code);

 printf("donnez la capacite d'avion :\n");
 scanf("%d",&AV.cp_stck);

 printf("donnez l'etat d'avion tapez la lettre A pour atteri,D pour decole,ou M pour en maintenance technique: \n ");
 scanf("%s",AV.etat);

do
{
 printf("donnez le jour de la fabrication d'avion:\n");
 scanf("%d",&AV.date_fab.j);
 }
 while (AV.date_fab.j < 0 || AV.date_fab.j > 31 );

 do
{
 printf("donnez le mois de la fabrication d'avion:\n ");
 scanf("%d",&AV.date_fab.m);
 }
 while (AV.date_fab.m <0 || AV.date_fab.m >12);

 do
{
 printf("donnez l'annee  de la fabrication d'avion:\n");
 scanf("%d",&AV.date_fab.aa);
 }
 while (AV.date_fab.aa < 1960);

 do {
 printf("donnez le nombre de vols pour cet avion : \n ");
 scanf("%d",&AV.nbre_vol);}
 while (AV.nbre_vol < 0);

 ajout_avion(&T,AV);
 X= dans_aeroport(AV);
 printf("%d\n",X);

 printf(" A vous de choisir : une autre avion, sinon tapez 0 :\n");
 scanf("%d",&choix);

 } while (choix != 0);
 printf(" 1- les informations concernant tous les avions\n");
 printf(" 2- les avions qui sont ni ages de plus de 20 ans, ni en maintenance technique\n");
 printf(" 3- le nombre des avions atteris et decolles\n");
 printf(" 4- les avions qui ont le maximum des vols et qui sont ages moins de 10 ans\n");
 printf(" 5- les avions qui ont le minimum des vols et qui sont ages moins de 10 ans\n");
 printf(" 6- les avions atterris\n ");
 printf(" *- les 3 types d'avion :atterris,decolles,en maintenance technique\n");
 scanf("%d",&d);

 if  (d == 1)
  {printf("les informations  de tous les avions sont :\n");
  afficher(T);
  printf("\n");}
 else if (d==2)
 {
  printf("voici la liste des avions qui sont ni ages de plus de 20 ans, ni en maintenance technique: \t ");
  supprimer(&T);
  afficher(T);}
 else if (d == 3)
  afficher_nbre(T);
 else if (d==4)
 {
  affiche_avion_vol_max_age_10(T);
  printf("\n");}
  else if (d ==5)
  affiche_avion_vol_min_age_10(T);
  else if (d==6)
    afficher_atteri(T);
  else
    scinder(T,A,M,D);
 }
