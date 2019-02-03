#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int size=3,a[50][2]={14,7,
	                 14,6,
					 14,5,
					 14,4,
					 14,3};
int get2c(){
	char c;
	int d;
	c=getch();
	fflush(stdin);
	d=c;
	return 256+d;
}
int arrow(){long int a=(get2c());
    if(a==224)
	a=(a)*1000+(get2c()-256);
	else a=a-256;

	return a;

}
void hidecursor(){
CONSOLE_FONT_INFOEX console_info  ;
    console_info.cbSize = sizeof(console_info);
	console_info.dwFontSize.X = 14;
	console_info.dwFontSize.Y= 23;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,  &console_info);
	CONSOLE_CURSOR_INFO info;
	info.dwSize=100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void gotoxy(int col,int row)
{
	COORD position ={row,col};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);	}

void delay(){
	int i,j;
	for(i=0;i<2000;i++){
		for(j=0;j<20000;j++){
			i-j;	}}}

int getkey(){
	int j;
   long int c;
    c=arrow();
	if(c==224072){return 1;}
	else if(c==224080){return 2;}
	else if(c==224075){return 3;}
	else if(c==224077){return 4;}
	else if(c==' '){
	        pause:
			for(j=0;j<20000;j++){
			j=j;
			if(kbhit())
			{if(getch()==' ')break;}
			goto pause;}
	 return 0;}}


	void checklose(int j, int score)
	{static int s;int i,hs;
	FILE *fp;
		if(j==1) s=score;
		fp=fopen("highscore.dat","r");
       fscanf(fp,"%d",&hs);
       fclose(fp);
       if(s>hs)
      {
      fp=fopen("highscore.dat","w");
	  fprintf(fp,"%d",s);fclose(fp);}
        if(j==0){	system("cls");
        		for(i=1;i<27;i++){
			gotoxy(i,1);
			printf("%c",178);
			gotoxy(i,100);
			printf("%c",178);
		}
		for(i=1;i<100;i++){
			gotoxy(27,i);
			printf("%c",254);
			gotoxy(0,i);
			printf("%c",254);
		}


       if(s==hs)
      { gotoxy(0,0);

        gotoxy(14,44);
		printf("High score",s);
		gotoxy(15,44);
		printf("   %04d  ",s);
	  }
	  else
{gotoxy(0,0);
	    gotoxy(14,44);
		printf("Your score",s);
		gotoxy(15,44);
		printf("   %04d  ",s);
}
		delay();delay();delay();
		gotoxy(27,0);

		exit(1);
		}
	}
void checkscore (int c,int b){static int r;static int s,flag=1;
    int i,hs;
	food:
	if (flag==1)
    {a:
    	srand(time(NULL)+getpid());
		r=(rand()%24)+2;

		srand(time(NULL)+2*getpid());
		s=(rand()%97)+2;
		for(i=0;i<size;i++)
		{if((r==a[i][0])&&(s==a[i][1]))goto a;
		}
		gotoxy(r,s);
		printf("O");flag=0;
	}
	static score=0;
	if((c==r)&&(b==s)){
		flag=1;
		score+=5;size++;
		checklose(1,score);

		goto food;
	}		gotoxy(28,2);printf("score");	gotoxy(29,2);
	printf("%04d",score);
	FILE *fp;
	       fp=fopen("highscore.dat","r");
       fscanf(fp,"%d",&hs);
       fclose(fp);
       	gotoxy(28,90);printf("High score");	gotoxy(29,90);
	printf("%04d",hs);

}













	int main(){
      hidecursor();
     gotoxy(0,0);


    int i,v;

		for(i=1;i<27;i++){
			gotoxy(i,0);
			printf("%c",178);
			gotoxy(i,100);
			printf("%c",178);gotoxy(0,0);
		}
		for(i=1;i<100;i++){
			gotoxy(27,i);
			printf("%c",254);
			gotoxy(0,i);
			printf("%c",254);gotoxy(0,0);
		}
		for(i=0;i<size;i++)

 delay();delay();delay();delay();
    checkscore(a[0][0],a[0][1]);
	right:
	while(a[0][1]<99){
		gotoxy(a[size-1][0],a[size-1][1]);
		printf(" ");
        for(i=size-1;i>0;i--)
         {a[i][1]=a[i-1][1];a[i][0]=a[i-1][0];}
        a[0][1]=a[0][1]+1;
		for(i=0;i<size;i++)
        {gotoxy(a[i][0],a[i][1]);
		printf("%c",1);gotoxy(0,0);}
		for(i=1;i<size;i++)
        {if((a[0][1]==a[i][1])&&(a[0][0]==a[i][0]))checklose(0,0);}
		delay();checkscore(a[0][0],a[0][1]);


		if(kbhit()){
	      v=getkey();
		  if(v==1)goto up;
		  if(v==2)goto down;}}
		  checklose(0,0);
	up:
	while(a[0][0]>1){
		gotoxy(a[size-1][0],a[size-1][1]);
		printf(" ");
       for(i=size-1;i>0;i--)
         {a[i][0]=a[i-1][0];a[i][1]=a[i-1][1];}
        a[0][0]=a[0][0]-1;
		for(i=0;i<size;i++)
        {gotoxy(a[i][0],a[i][1]);
		printf("%c",1);gotoxy(0,0);}
		delay();checkscore(a[0][0],a[0][1]);
		for(i=size-1;i>0;i--)
        {if((a[0][1]==a[i][1])&&(a[0][0]==a[i][0]))checklose(0,0);}
		if(kbhit()){
	      v=getkey();
		  if(v==3)goto left;
		  if(v==4)goto right;}}
		  checklose(0,0);
	down:
	while(a[0][0]<26){
		gotoxy(a[size-1][0],a[size-1][1]);
		printf(" ");
        for(i=size-1;i>0;i--)
         {a[i][0]=a[i-1][0];a[i][1]=a[i-1][1];}
        a[0][0]=a[0][0]+1;
		for(i=0;i<size;i++)
        {gotoxy(a[i][0],a[i][1]);
		printf("%c",1);gotoxy(0,0);}
		delay();checkscore(a[0][0],a[0][1]);
		for(i=size-1;i>0;i--)
         {if((a[0][1]==a[i][1])&&(a[0][0]==a[i][0]))checklose(0,0);}
		if(kbhit()){
	      v=getkey();
		  if(v==3)goto left;
		  if(v==4)goto right;}}
		 checklose(0,0);
	left:
	while(a[0][1]>2){
		gotoxy(a[size-1][0],a[size-1][1]);
		printf(" ");
        for(i=size-1;i>0;i--)
         {a[i][1]=a[i-1][1];a[i][0]=a[i-1][0];}
        a[0][1]=a[0][1]-1;
		for(i=0;i<size;i++)
        {gotoxy(a[i][0],a[i][1]);
		printf("%c",1);gotoxy(0,0);}
		delay();checkscore(a[0][0],a[0][1]);
		for(i=size-1;i>0;i--)
        {if((a[0][1]==a[i][1])&&(a[0][0]==a[i][0]))checklose(0,0);}
		if(kbhit()){
	      v=getkey();
		  if(v==1)goto up;
		  if(v==2)goto down;}}
		  checklose(0,0);


		  }











