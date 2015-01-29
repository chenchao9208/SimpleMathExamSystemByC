#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
char ID[7];/*set 7 to identify and avoid inputting more than 6 characters and entering the system.*/
FILE *file;
int main()
{
 int qualify();
 int starttest();
 int checkscore(); /*These 3 functions make up the majority of the program.*/
 int a;
 if(qualify()==0)
  return 0;
 printf("\n\nWelcome!  ID:  %s\n",ID);
 for(;a!=3;)
  {
   printf(" (1)Start a test\n");
   printf(" (2)Check scores\n");
   printf(" (3)Exit\n ");
   printf("Tell me the number of your choice:");
   if(scanf("%d",&a)==EOF) /*protect program from collapsing.*/
     a=3;
   if(a==1)
    starttest();
   else if(a==2)
    checkscore();
   else if(a!=3)  /*Protect it from giving no response so that the user might be confused.*/
    printf("Error.\n");
  }
  return 0;
}

 int qualify()
 {
  printf("Press Ctrl and Z keys simultaneously to stop inputting.\n");
  printf("The ID should be in form of AB1234.\n");
  printf("Please input your 4 digit ID no:");
  if(scanf("%s",&ID)==EOF)       /*Protest the program from circulating endlessly.*/
   return 0;
  int i;
  int a=1;
  if(strlen(ID)!=6)
    a=0;
  for(i=0;i<2;i++)
   {
    if(ID[i]<'A'||ID[i]>'Z')
      a=0;
   }
  for(;i<6;i++)
   {
    if(ID[i]<'0'||ID[i]>'9')
      a=0;
   }
  if(a==0)
   {
     return (qualify());     /*Circulating.*/
   }

 return 1;
}

int starttest()
{
 int i,start,end;
 int score=0,num1[10], sig[10], num2[10], ans[10], input[10];
 char r[4]={'+','-','*','/'};
 printf("**************TEST**************\n");
 printf("Now you'll solve 10 math problems one by one\n");
 printf("Enter your answer and press Enter key for the next.\n");
 printf("**DON'T PRESS Ctrl and Z keys simultaneously during the test,\nor your score will be 0!!!!!"); 
 printf("\nTime is counterd from now.\n");  /*Some pieces of caution for those who use this system first time.*/
 srand(time(NULL));
 start=time(NULL);
 for(i=0;i<10;i++)
  {
   sig[i]=rand()%4;
   switch(sig[i])
    {
     case 0:
      num1[i]=rand()%100;
      num2[i]=rand()%(100-num1[i]);
      ans[i]=num1[i]+num2[i];
      break;
     case 1:
      num1[i]=rand()%100;
      num2[i]=rand()%(num1[i]);
      ans[i]=num1[i]-num2[i];
      break;
     case 2:
      num1[i]=1+rand()%50; /*multiplying equations containing ' 1' and '0' are meaningless, so decrease their apprearance probability.*/
      num2[i]=rand()%(100/num1[i]);
      ans[i]=num1[i]*num2[i];
      break;
     case 3:
      num2[i]=1+rand()%50;    /*Transformed from multyplying.*/
      ans[i]=rand()%(100/num2[i]);
      num1[i]=num2[i]*ans[i];
      break;
    }
  printf("%2d %c %2d = ",num1[i],r[sig[i]],num2[i]);
  scanf("%d",&input[i]);

  if(input[i]==ans[i])
   score+=10;
  }
 end=time(NULL);
 printf("\n********************************\n");
 printf("\nThe time you have used is %d%c\n",end-start,'s');
 printf("And your score is %3d\n",score);
 file=fopen("record.txt","a");
 fprintf(file,"%s %3d %6d%c\n",ID,score,end-start,'s');
 printf("\n     Prob.  |Correct Answ.|Ur Answ\n");
 for(i=0;i<10;i++)
  {                                      
   printf("  %2d %c %2d =       %2d         %2d\n",num1[i],r[sig[i]],num2[i],ans[i],input[i]);
  }
 printf("\n\n\n\n");
 fclose(file);
 return 0;
}


int checkscore()
{
 char I[7];
 int s;
 int t;
 int i=0;
 file=fopen("record.txt","r");
 if(file==NULL)
  {
    printf("System Error.\n");   /*Mention the system error.*/
    return 0;
  }
 printf("**************SCORE**************\n");
 printf("Your previous records are:\n");
 for(;fscanf(file,"%s %d %d%c",I,&s,&t,'s')!=EOF;)
  {
   if (strcmp(ID,I)==0)
    {
     printf("%s %d %d%c\n",I,s,t,'s');
     i++;
    }

  }
 if(i==0)
  printf("Sorry, there is no your record.");  /*Prevent users from being confused.*/
 printf("\n\n\n");
 fclose(file);
 return 0;
}ó¿:ã]ôó®¶ßŸ?™¨¥nêmyÛœ