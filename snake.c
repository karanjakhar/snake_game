#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<windows.h>


void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}

int food_x=30,food_y=10,x=1,y=0,gameover=1,score=0,option;
struct snake                  //structure is declared for linklist
  { int snake_x;
    int snake_y;
   struct  snake  *next;
     }*end_part,*p,*r,*n,*mouth;

char ch;
void food();
void update();
void input();
void setup();
int main()                       //start of main body
{      r=  malloc(sizeof(struct snake));
       r->next=NULL;
       r->snake_x=35;
       r->snake_y=12;
       p=  malloc(sizeof(struct snake));
       p->next=r;
       p->snake_x=34;
       p->snake_y=12;
       end_part= malloc(sizeof(struct snake));
       end_part->next=p;
       end_part->snake_x=33;
       end_part->snake_y=12;
	mouth=r;
   k:  printf("\n\t\t\tSAIKAPIAN SNAKE GAME");
     printf("\n\n\t\tLET SEE HOW MUCH YOU CAN SCORE")   ;
     printf("\n\n\n\t\t\t\tpress:I for UP");
     printf("\n\n\t\t\t\tpress:J for LEFT");
     printf("\n\n\t\t\t\tpress:L for RIGHT");
     printf("\n\n\t\t\t\tpress:K for DOWN");
     printf("\n\n\t\tI\n\tJ\t\tL\n\t\tK");
     printf("\n\npress any key to pause and press any of I J K L to continue");
     printf("\n1.START THE GAME ");
     printf("\n2.EXIT\n");
     scanf("%d",&option);
     system("cls");
     switch(option)
     {case 1: setup();
     while(gameover)
    {    system("cls");

   setup();
  snake_body();  Sleep(100);      //functions called
  input();
  update();


     }
  system("cls");
  printf("gameover!");
  printf("\nSCORE = ");printf("%d",score) ;
  getch();
  free (p);free(n);free(r);free(end_part);free(mouth);
  break;
  case 2: break;
  default: printf("\nWRONG CHOICE!!! Try Again "); goto k;break;}
  return 0;
    }             //end of main body



  void setup()                //function for setup
   {  int i;
       for( i=0;i<160;i++)     //horizontal lines
       {  printf("*");
       if(i==79)
	 gotoxy(1,24);

       }

      gotoxy(1,2);       //left vertical line
      for(i=0;i<22;i++)
       printf("*\n");

      gotoxy(80,2);     //right vertical line
      for(i=0;i<23;i++)
       { printf("*\n");
	 gotoxy(80,2+i);

       }
   }
       void snake_body()
       {


	n=end_part;
       while(n!=mouth)            //snake body
       { gotoxy(n->snake_x,n->snake_y)   ;
	 printf("O");
	 if(mouth->snake_x==n->snake_x&&mouth->snake_y==n->snake_y)
	 gameover=0;

	 n=n->next;
	  gotoxy(mouth->snake_x,mouth->snake_y)  ;
	  printf("X"); }
      if(mouth->snake_x==food_x&&mouth->snake_y==food_y)
	 food();
	gotoxy(food_x,food_y);  //food created
	printf("o");
     }


     void food()  //function for snake food
       {  score++;
        p= malloc(sizeof(struct snake));
        p->next=end_part;
       end_part=p;    k:  srand(time(NULL));
      food_x=rand()%76 +4;
      food_y=rand()%20 +4;

      if(food_x==mouth->snake_x&&food_y==mouth->snake_y)
      goto k  ;

 }
   void input()    //funtion to get input
    { if(kbhit())
    {
       ch=getch();
    switch(ch)
    { case 'j':
	x= -1,y=0;break;
     case 'l':
       x=1;y=0;break;
    case 'i':
      x=0;y= -1;break;
   case 'k':
      x=0;y=1;break;
 default : while(!kbhit());
  break;
	     }

    }    }

   void update()     //function to update information
       { p=end_part;
       r=p->next;
       while(r!=NULL)
	{ p->snake_x=r->snake_x;
	  p->snake_y=r->snake_y;
	  p=p->next;
	  r=r->next;

	  }
    mouth->snake_x=mouth->snake_x+x;
       mouth->snake_y=mouth->snake_y+y;
       if(mouth->snake_x==80||mouth->snake_x==1||mouth->snake_y==1||mouth->snake_y==24)
	   gameover=0;

	   }
