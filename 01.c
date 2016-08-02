#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct player
{  char   id[16];
   double rate;
}player[];

void main()
{
	int i,k,s;
	static n=1;
    void game(int n);
	void found(int n);
 

	do
	{
		printf("==================================================\n");
		printf("欢迎进入剪刀石头布游戏，本游戏胜利机制为三局两胜制\n");
		printf("    输入1可进行比赛模式，输入2可进行练习模式\n");
		printf("          输入3可查看玩家胜率排行榜\n");
		printf("                   输入4可退出游戏\n");
        printf("==================================================\n");
 
		printf("输入i\n");
		scanf("%d",&i);
        printf("输入玩家信息\n");
		printf("当前你是第%d位玩家\n",n);
		printf("输入n\n");
		scanf("%d",&n);
		printf("输入玩家id\n");
		scanf("%s",&player[n].id);
	switch(i)
	{
	   case 1:game(n);
		      printf("是否再来一局？1—是，0—否\n");
			  scanf("%d",s);
			  if(s) continue; else break;
	   case 2:game(n=0);
		      printf("是否再来一局？1—是，0—否\n");
			  scanf("%d",s);
			  if(s) continue; else break;
	   case 3:found(n);
		      printf("胜率排行榜\n");
			  printf("胜率 玩家id\n");
		      for(k=1;k>=n;k++)
			  {
				  printf("%.2lf,%s",player[k].rate,player[k].id);
			  }break;
	   case 4:break;
	}
    printf("输入-1，游戏结束:");
	scanf("%d",&k);
	}while(k!=-1);
}
   
void game(int n)
{
  int static s=0,a=0,count=0;
  int i,m,c,q=0,w=0;
  for(i=0;i<=3;i++)
  {printf("拳头-1，剪刀-2，布-3");
   printf("出手吧!\n");
   scanf("%d",&m);
   srand(time(NULL));
   c=rand()%2+1;
   if(m==1&&c==2){printf("玩家胜利\n");a++;q++;} else 
   {if(m==1&&c==3){printf("电脑胜利\n");s++;w++;}else 
   {if(m==1&&c==1)printf("平局");                else 
   {if(m==2&&c==3){printf("玩家胜利\n");a++;q++;}else 
   {if(m==2&&c==1){printf("电脑胜利\n");s++;w++;}else 
   {if(m==2&&c==2)printf("平局");                else 
   {if(m==3&&c==1){printf("玩家胜利\n");a++;q++;}else 
   {if(m==3&&c==2){printf("电脑胜利\n");s++;w++;}else 
   {if(m==3&&c==3)printf("平局");}}}}}}}}
   count++;
   
   player[n].rate=a*1.00/count;
  }
  if(q==2)printf("玩家胜利\n");else if(w==2)printf("电脑胜利\n");else printf("平局\n");
}

void found(int n)
{
  int i,k;
  double temp;
  for(i=1;i<=n;i++)
  {
	  for(k=1;k<=n-i+1;k++)
	  {
		  if(player[k].rate>player[k+1].rate)
		  {
		    temp=player[k+1].rate;
			player[k+1].rate=player[k].rate;
			player[k].rate=temp;
		  }
	  }
  }
}
