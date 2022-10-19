#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int width=20,height=20,gameover;
int x,y,fruitx,fruity,score,flag;
int tailx[100],taily[100];
int counttail=0;

void save(){

    	char name[50],c,d;

	FILE *fptr;
	fptr=(fopen("sankerecord2.txt","a+"));
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}

		printf("\n\nenter the name for score %d\nEnter name: ",score);
		scanf("%s",name);

		fprintf(fptr,"\nName: %s \n score:  %d \n",name,score);
	fclose(fptr);
	      system("cls");
	      fflush(stdin);
         printf("for previous score press y:");
         scanf("%c",&d);

         if(d=='y'){
                fptr=(fopen("sankerecord2.txt","r"));
                while (c!=EOF)      {

                 printf("%c",c);
       c=fgetc(fptr);

            }
   fclose(fptr);
   }
}

void setup()
{    system("cls");
  gameover=0;
  x=width/2;
  y=height/2;

   label1:
  fruitx=rand()%20;
  if(fruitx==0)
    goto label1;
    label2:
  fruity=rand()%20;
  if(fruity==0)
    goto label2;
    score=0;
}
void draw()
{
    system("cls");
    int i,j,k;
    for(i=0;i<=width;i++)
    {
    for(j=0;j<=height;j++)
    {
        if(i==0||i==height||j==0||j==width)
    {
      printf("*");
    }
       else
        {  if(i==x && j==y)
            printf("0");
            else if(i==fruitx && j==fruity)
                printf("o");
            else
        {   int ch=0;
            for(k=0;k<counttail;k++)
            {
                if(i==tailx[k] && j==taily[k])
                {
                    printf("o");
                    ch=1;

                }
            }
            if(ch==0)
            printf(" ");
        }
       }



    }
    printf("\n");
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
             flag=1;
             break;
        case 'd':
             flag=2;
             break;
        case 'w':
             flag=3;
             break;
        case 's':
             flag=4;
             break;
        case 'x':
            gameover=1;
            system("cls");
            break;
        }
    }
}
void makelogic()

{    int i,j;
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;

    for(i=1;i<counttail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;

    }

    switch(flag)
    {
        case 1:
              y--;
              break;
        case 2:
              y++;
              break;
        case 3:
              x--;
              break;
        case 4:
             x++;
             break;
        default:
            break;
    }
    if(x<0||x>width||y<0||y>height)
       gameover=1;
        fflush(stdin);


    for(i=0;i<counttail;i++)
{
        if(x==tailx[i] && y==taily[i])
            gameover=1;

}
         if(x==fruitx && y==fruity)
    {
             label3:
  fruitx=rand()%20;
  if(fruitx==0)
    goto label3;
    label4:
  fruity=rand()%20;
  if(fruity==0)
    goto label4;
    score+=10;
    counttail++;
    }

}
int main()
{   int n,m;
    char c,a; 
printf("press s to start:  ");
        scanf("%c",&a);
         fflush(stdin);
    setup();

    if(a == 's'){
    while(!gameover)
        {

    draw();
    input();
    makelogic();
    printf("your score is : %d", score);
    for(m==0;m<10000000;m++){
         for(n==0;n<10000000;n++){

         }
    }
    for(m=0;m<100;m++){
        for(n=0;n<100;n++){

        }
    }
    a = '0';
    }
    save();
    getch();

    return 0;
}
}
