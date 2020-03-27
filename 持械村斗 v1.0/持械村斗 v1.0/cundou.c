#include<stdio.h>
#include<stdlib.h>
#include <conio.h> 
#include <windows.h>
#include"arms.h"
#include"monster.h"
#include "D:/日常软件/mysql/mysql-5.7.16-winx64/include/mysql.h" 
#pragma comment(lib, "winmm")  

char name[100];
int key;
int chinakey;
int i,y,j;
char *user[50]={0};
char *pass[50]={0};
int Gradenum1;  //等级
int Gradenum2;  //经验
int Gradenums=0;  //防止覆盖
int nums1,nums2;  
int chinanum = 1;
int randoms[10];  //设立10个怪物随机数
int Indianum=1;
int HPs=1;
int Kill[10];
struct attribute
{
	int force;  //武力
	int intelligence;  //智力
	int defense;  //防御
	int speed;  //速度
	int HP;  //血量
	int MP;  //魔法
}Attribute;
char *knapsacks[20][6][20]={0};  //背包
char *randomL[10][7][20]={0};  //怪物列表
int knapsacksize=2;  //背包大小
int armsnum=1;  //判断是否穿戴武器 1=否 2等是
int clothesnum=1;  //判断是否穿戴衣服
int armsoff = 1;  //判断是否脱下武器 1=否 2等是
int clothesoff = 1;  //判断是否脱下衣服 
char *Skills[10][50]={{"   猛击【单体】   "},{"人妻擒拿手【单体】"},{" 天降陨石【群体】 "},{" 无限月赎【单体】 "},{" 草帽三挡【状态】 "},{" 神盾护体【状态】 "},{" 撒钱大法【单体】 "}};  //技能名称
char *upgrades[10][50]={{"【印度村】（1—9）————新手推荐"},{"【越南村】（10—19）————未开放"}};  //村名列表
char *Battles[2][20]={{"普通攻击"},{"技能（暂无）"}}; 
//MYSQL mysql;
//函数定义
void initial();  //游戏初始页面
void menu();  //主菜单
void newgame();  //新游戏页面
void registers();  //注册页面;
void login();  //登录页面
void author();  //联系作者
void chian();  //华夏村（游戏默认进入）
void Grade();  //等级设定
void information();  //人物信息页面
void Esc();  //返回游戏默认页面
void Skill();  //人物技能页面
void knapsack();  //背包页面
void upgrade();  //升级页面
void India();  //印度
void random();  //随机怪物
void Battle();  //战斗
void Drop();  //装备掉率

//主程序
main()  //主程序
{
	//mysql_init(&mysql);
	printf("\t\t\t   ┏━━━━━━━━━━┓\n");
	printf("\t\t\t   ┃      持械村斗      ┃\n");
	printf("\t\t\t   ┗━━━━━━━━━━┛\n");
	/*if(mysql_real_connect(&mysql,"localhost","root","","cundou",0,NULL,0))
	{
		printf("\t\t\t\t数据载入成功...");
	
	}
	else
	{
		printf("\t\t\t   数据载入失败...");
	}
	mysql_query(&mysql,"set names utf8");*/
	PlaySound (TEXT("郑伊健 - 乱世巨星.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("title 持械村斗");
	initial();
	getchar();
}

void china()  //中国村
{
	char *chinas[50][50] = {{"【人物信息】"},{"【人物技能】"},{"  【背包】  "},{"【武器店铺】"},{"【衣服店铺】"},{"【首饰店铺】"},{"【草药店铺】"},{"【技能店铺】"},{"  【赌场】  "},{"  【升级】  "},{"  【寻宝】  "},{"【BOSS之家】"}};
	
	Grade();
	HPs=Attribute.HP;
	fflush(stdin);
	chinakey = getch();
	while(chinakey)
	{
		system("cls");
		printf("\t\t     ┏━━━━━━━━━━━━━━━━┓想知道怪物怎么刷新么？\n");
		printf("\t\t     ┃  华夏村（世界四大文明古村之一）┃\n");
		printf("\t\t     ┗━━━━━━━━━━━━━━━━┛\n");
		printf("	  华夏是以华夏文明为源泉、华夏文化为基础并以汉族为主体民族的多民\n	族国家，通用汉语。华夏人常以龙的传人、炎黄子孙自居。 Ps：单身狗居多");
		printf("\n\n\n\n");
		for(i=0;i<12;i++)
		{
		if((i+1)%3==0)
		{
			if(i==chinanum-1)
			{
				printf("\t ▲ %s\n\n\n\n",*chinas[i]);
			}
			else
			{
				printf("\t    %s\n\n\n\n",*chinas[i]);
			}
		}
		else
		{
			if(i==chinanum-1)
			{
				printf("\t ▲ %s",*chinas[i]);
			}
			else
			{
				printf("\t    %s",*chinas[i]);
			}
		}
		}
		chinakey=getch();
		switch(chinakey)
		{
		case 72: chinanum-=3;
		    break;  
		case 80: chinanum+=3;
		    break; 
		case 75: chinanum--;
			break;
		case 77: chinanum++;
			break;
		case 13: 
			switch(chinanum)
			{
			case 1: information();
				return;
			case 2: Skill();
				return;
			case 3:	knapsack();
			case 10: upgrade();
				return;
			}
			break;
		}
		if(chinanum<=0)chinanum=12;
		else if(chinanum>=13)chinanum=1;
	}
	

}

void Esc()  //返回游戏默认页面
{
	int esckey;
	printf("\n\n【Esc】返回华夏村(2次)...");
	esckey = getch();
	if(esckey==27) china();
}

void initial()  //初始页面
{
	Kitchenknifes();
	Chouis();
	knapsacks[0][0][20] = Kitchenknife[0].name;
	knapsacks[0][1][20] = Kitchenknife[0].force;
	knapsacks[0][2][20] = Kitchenknife[0].intelligence;
	knapsacks[0][3][20] = Kitchenknife[0].grade;
	knapsacks[0][4][20] = Kitchenknife[0].state;

	knapsacks[1][0][20] = Choui[0].name;
	knapsacks[1][1][20] = Choui[0].defense;
	knapsacks[1][2][20] = Choui[0].HP;
	knapsacks[1][3][20] = Choui[0].MP;
	knapsacks[1][4][20] = Choui[0].grade;
	knapsacks[1][5][20] = Choui[0].state;
	for(i=0;i<10;i++)
	{
		Kill[i]=1;
	}
	printf("\n\n\n\n\t\t\t    一场场村斗正在上演...\n\n\n\n\n任意键继续");
	key=getch();
	menu();
}

void menu()  //主菜单
{
	char *menus[50][50]={{"登录游戏"},{"注册账号"},{"联系作者"},{"退出游戏"}};
	int num=1;
	system("cls");
	while(key)
	{
		system("cls");
		printf("\t\t\t   ┏━━━━━━━━━━┓\n");
		printf("\t\t\t   ┃      持械村斗      ┃\n");
		printf("\t\t\t   ┗━━━━━━━━━━┛\n");
		printf("\n\n\n\n");
		random();
		for(i=0;i<4;i++)
		{
		if(i==num-1)
		{
			printf("\t\t\t\t★ %s\n",*menus[i]);
		}
		else
		{
			printf("\t\t\t\t   %s\n",*menus[i]);
		}
		}
		key=getch();
		_sleep(100);
		switch(key)
		{
		case 72: num--;
		    break;  
		case 80: num++;
		    break;  
		case 13: 
			switch(num)
			{
			case 1: china();
				return;
			//case 2: registers();
			//	return;
			case 3:	author();
				return;
			case 4:
				exit(0);
				break;
			}
			break;
		}
		if(num==0)num=4;
		else if(num==5)num=1;
	}
	
}

void author()  //联系作者
{
	system("cls");
	fflush(stdin);
	printf("\t\t\t   ┏━━━━━━━━━━┓\n");
	printf("\t\t\t   ┃      持械村斗      ┃\n");
	printf("\t\t\t   ┗━━━━━━━━━━┛\n");
	printf("\n\n\n\n\t\t\t         QQ:252108115");
	printf("\n\n\n任意键返回");
	getchar();
	menu();
}

void login()  //登录页面
{
	char *login[500]={0};
	int res={0};
	fflush(stdin);
	system("cls");
	printf("\t\t\t   ┏━━━━━━━━━━┓\n");
	printf("\t\t\t   ┃   持械村斗(登录)   ┃\n");
	printf("\t\t\t   ┗━━━━━━━━━━┛\n");
	//printf("\n\n\t\t\t     请输入账号：");
	//scanf("%s",&*user);
	//getchar();
	//printf("\n\n\t\t\t     请输入密码：");
	//scanf("%s",&*pass);
	//sprintf(login,"select * from user where user='%s' and pass='%s'",user,pass);
	//res = mysql_query(&mysql,login);
	//printf("%d",res);
	//getchar();
	//if(res!=0)
	//{
		china();
	//	return;
	//}
	//else
	//{
	//	int failnum=3;
	//	while(1)
	//	{
	//		system("cls");
	//		printf("\t\t\t   ┏━━━━━━━━━━┓\n");
	//		printf("\t\t\t   ┃      持械村斗      ┃\n");
	//		printf("\t\t\t   ┗━━━━━━━━━━┛\n");
	//		printf("\n\n\t\t        登录失败...%d秒后跳转主菜单页面",failnum);
	//		_sleep(1000);
	//		failnum--;
	//		if(failnum==0)
	//		{
	//			menu();
	//			return;
	//		}
	//	}
	//}
}

/*void registers()  //注册页面
{
	char *name[50]={0};
	char *user[50]={0};
	char *password[50]={0};
	char *password2[50]={0};
	int failnum=3;
	fflush(stdin);
	system("cls");
	printf("\n");
	printf("\t\t\t   ┏━━━━━━━━━━┓\n");
	printf("\t\t\t   ┃   持械村斗(注册)   ┃\n");
	printf("\t\t\t   ┗━━━━━━━━━━┛\n");
	printf("\n\n\t\t\t     尊姓大名：");
	scanf("%s",&*name);
	getchar();
	printf("\n\n\t\t\t     请输入账号：");
	scanf("%s",&*user);
	getchar();
	printf("\n\n\t\t\t     请输入密码：");
	scanf("%s",&*password);
	getchar();
	printf("\n\n\t\t\t     再次输入密码：");
	scanf("%s",&*password2);
	getchar();
	if(*password!=*password2)
	{
		printf("\t\t\t     密码不一样");
		registers();
		
	}
	else
	{
		int failnum=3;
		char newuser[100];
		sprintf(newuser,"insert into user(name,user,pass) value('%s','%s','%s')",name,user,password);
		mysql_query(&mysql,newuser);
		while(1)
		{
			system("cls");
			printf("\t\t\t   ┏━━━━━━━━━━┓\n");
			printf("\t\t\t   ┃      持械村斗      ┃\n");
			printf("\t\t\t   ┗━━━━━━━━━━┛\n");
			printf("\n\n\t\t        注册成功...%d秒后跳转登录页面",failnum);
			_sleep(1000);
			failnum--;
			if(failnum==0)
			{
				login();
				return;
			}
		}
	}
}*/

void Grade()  //等级设定
{
	if((Gradenum2>=0) && (Gradenum2<=49)) {Gradenum1 = 1;}
	else if((Gradenum2>=50) && (Gradenum2<=199)) {Gradenum1 = 2;}
	else if((Gradenum2>=200) && (Gradenum2<=399)) {Gradenum1 = 3;}
	else if((Gradenum2>=400) && (Gradenum2<=699)) {Gradenum1 = 4;}
	else if((Gradenum2>=700) && (Gradenum2<=1099)) {Gradenum1 = 5;}
	else if((Gradenum2>=1100) && (Gradenum2<=1599)) {Gradenum1 = 6;}
	else if((Gradenum2>=1600) && (Gradenum2<=2199)) {Gradenum1 = 7;}
	else if((Gradenum2>=2200) && (Gradenum2<=2899)) {Gradenum1 = 8;}
	else if((Gradenum2>=2900) && (Gradenum2<=3699)) {Gradenum1 = 9;}
	else if((Gradenum2>=3700) && (Gradenum2<=4599)) {Gradenum1 = 10;}
	else if((Gradenum2>=4600) && (Gradenum2<=5599)) {Gradenum1 = 11;}
	else if((Gradenum2>=5600) && (Gradenum2<=6699)) {Gradenum1 = 12;}
	else if((Gradenum2>=6700) && (Gradenum2<=7899)) {Gradenum1 = 13;}
	else if((Gradenum2>=7900) && (Gradenum2<=9199)) {Gradenum1 = 14;}
	else if((Gradenum2>=9200) && (Gradenum2<=10599)) {Gradenum1 = 15;}
	else if((Gradenum2>=10600) && (Gradenum2<=12099)) {Gradenum1 = 16;}
	else if((Gradenum2>=12100) && (Gradenum2<=13699)) {Gradenum1 = 17;}
	else if((Gradenum2>=13700) && (Gradenum2<=15399)) {Gradenum1 = 18;}
	else if((Gradenum2>=15400) && (Gradenum2<=17199)) {Gradenum1 = 19;}
	else if(Gradenum2>=17200) {Gradenum1 = 20;}

	if(Gradenum1!=Gradenums)
	{
		Gradenums++;
		switch(Gradenum1)
		{
		case 1: 
			Attribute.force = 3;
			Attribute.intelligence = 3;
			Attribute.defense = 2;
			Attribute.HP=20+Attribute.force*2;
			Attribute.MP=25+Attribute.intelligence*4;
			Attribute.speed = 1;
			break;
		case 2:
			Attribute.force = 4;
			Attribute.intelligence = 4;
			Attribute.defense = 3;
			Attribute.HP=30+Attribute.force*2;
			Attribute.MP=35+Attribute.intelligence*4;
			Attribute.speed = 2;
			break;
		case 3: 
			Attribute.force = 5;
			Attribute.intelligence = 5;
			Attribute.defense = 4;
			Attribute.HP=40+Attribute.force*2;
			Attribute.MP=45+Attribute.intelligence*4;
			Attribute.speed = 3;
			break;
		case 4: 
			Attribute.force = 6;
			Attribute.intelligence = 6;
			Attribute.defense = 5;
			Attribute.HP=50+Attribute.force*2;
			Attribute.MP=55+Attribute.intelligence*4;
			Attribute.speed = 4;
			break;
		case 5: 
			Attribute.force = 7;
			Attribute.intelligence = 7;
			Attribute.defense = 6;
			Attribute.HP=60+Attribute.force*2;
			Attribute.MP=65+Attribute.intelligence*4;
			Attribute.speed = 5;
			break;
		case 6: 
			Attribute.force = 9;
			Attribute.intelligence = 9;
			Attribute.defense = 7;
			Attribute.HP=75+Attribute.force*2;
			Attribute.MP=80+Attribute.intelligence*4;
			Attribute.speed = 6;
			break;
		case 7: 
			Attribute.force = 11;
			Attribute.intelligence = 11;
			Attribute.defense = 8;
			Attribute.HP=90+Attribute.force*2;
			Attribute.MP=95+Attribute.intelligence*4;
			Attribute.speed = 7;
			break;
		case 8: 
			Attribute.force = 13;
			Attribute.intelligence = 13;
			Attribute.defense = 9;
			Attribute.HP=105+Attribute.force*2;
			Attribute.MP=110+Attribute.intelligence*4;
			Attribute.speed = 8;
			break;
		case 9: 
			Attribute.force = 15;
			Attribute.intelligence = 15;
			Attribute.defense = 10;
			Attribute.HP=120+Attribute.force*2;
			Attribute.MP=125+Attribute.intelligence*4;
			Attribute.speed = 9;
			break;
		case 10: 
			Attribute.force = 17;
			Attribute.intelligence = 17;
			Attribute.defense = 11;
			Attribute.HP=135+Attribute.force*2;
			Attribute.MP=140+Attribute.intelligence*4;
			Attribute.speed = 10;
			break;
		case 11: 
			Attribute.force = 19;
			Attribute.intelligence = 19;
			Attribute.defense = 12;
			Attribute.HP=150+Attribute.force*2;
			Attribute.MP=155+Attribute.intelligence*4;
			Attribute.speed = 11;
			break;
		case 12: 
			Attribute.force = 22;
			Attribute.intelligence = 22;
			Attribute.defense = 13;
			Attribute.HP=170+Attribute.force*2;
			Attribute.MP=175+Attribute.intelligence*4;
			Attribute.speed = 12;
			break;
		case 13: 
			Attribute.force = 25;
			Attribute.intelligence = 25;
			Attribute.defense = 14;
			Attribute.HP=190+Attribute.force*2;
			Attribute.MP=195+Attribute.intelligence*4;
			Attribute.speed = 13;
			break;
		case 14: 
			Attribute.force = 28;
			Attribute.intelligence = 28;
			Attribute.defense = 15;
			Attribute.HP=210+Attribute.force*2;
			Attribute.MP=215+Attribute.intelligence*4;
			Attribute.speed = 14;
			break;
		case 15: 
			Attribute.force = 31;
			Attribute.intelligence = 31;
			Attribute.defense = 16;
			Attribute.HP=230+Attribute.force*2;
			Attribute.MP=235+Attribute.intelligence*4;
			Attribute.speed = 15;
			break;
		case 16: 
			Attribute.force = 34;
			Attribute.intelligence = 34;
			Attribute.defense = 17;
			Attribute.HP=250+Attribute.force*2;
			Attribute.MP=255+Attribute.intelligence*4;
			Attribute.speed = 16;
			break;
		case 17: 
			Attribute.force = 37;
			Attribute.intelligence = 37;
			Attribute.defense = 18;
			Attribute.HP=270+Attribute.force*2;
			Attribute.MP=275+Attribute.intelligence*4;
			Attribute.speed = 17;
			break;
		case 18: 
			Attribute.force = 40;
			Attribute.intelligence = 40;
			Attribute.defense = 19;
			Attribute.HP=290+Attribute.force*2;
			Attribute.MP=295+Attribute.intelligence*4;
			Attribute.speed = 18;
			break;
		case 19: 
			Attribute.force = 43;
			Attribute.intelligence = 43;
			Attribute.defense = 20;
			Attribute.HP=310+Attribute.force*2;
			Attribute.MP=315+Attribute.intelligence*4;
			Attribute.speed = 19;
			break;
		case 20: 
			Attribute.force = 47;
			Attribute.intelligence = 47;
			Attribute.defense = 22;
			Attribute.HP=335+Attribute.force*2;
			Attribute.MP=340+Attribute.intelligence*4;
			Attribute.speed = 20;
			break;
		}
	}
}

void information()  //人物信息
{
	system("cls");
	Grade();
	printf("\t\t\t   ┏━━━━━━━━━━┓\n");
	printf("\t\t\t   ┃      人物信息      ┃\n");
	printf("\t\t\t   ┗━━━━━━━━━━┛\n");
	printf("\n\n\n");
	printf("\t人物名：GM\n\n");
	printf("\t  等级：%d（%d）\n\n",Gradenum1,Gradenum2);
	printf("\t  武力：%d\n\n",Attribute.force);
	printf("\t  智力：%d\n\n",Attribute.intelligence);
	printf("\t  防御：%d\n\n",Attribute.defense);
	printf("\t  速度：%d\n\n",Attribute.speed);
	printf("\t  血量：%d\n\n",Attribute.HP);
	printf("\t  魔法：%d\n\n",Attribute.MP);
	Esc();
}

void Skill()
{
	system("cls");
	fflush(stdin);
	random();
	for(i=0;i<10;i++)
	{
		Kill[i]=1;
	}
	printf("\t\t\t   ┏━━━━━━━━━━┓\n");
	printf("\t\t\t   ┃      人物技能      ┃\n");
	printf("\t\t\t   ┗━━━━━━━━━━┛\n");
	printf("\n");
	printf("\t技能列表\t\t描述\t\t\t  状态 \n\n");
	printf("    %s\t 伤害值为：武力X1.5 \t\t 未学习 \n\n",*Skills[0]);
	printf("    %s\t 搞笑技能 \t\t\t 未学习 \n\n",*Skills[1]);
	printf("    %s\t 伤害值为：智力X1.2 \t\t 未学习 \n\n",*Skills[2]);
	printf("    %s\t 让单个敌人50%几率陷入睡眠 \t 未学习 \n\n",*Skills[3]);
	printf("    %s\t 提升2倍攻击力三回合 \t\t 未学习 \n\n",*Skills[4]);
	printf("    %s\t 提升2倍防御三回合 \t\t 未学习 \n\n",*Skills[5]);
	printf("    %s\t 投掷2000大洋造成1000滴伤害 \t 未学习 \n\n",*Skills[6]);
	Esc();
}

void knapsack()
{
	int knapsacknum=1,knapsacknums={0},knapsackkey;
	Chouis();
	Kitchenknifes();
	Grade();
	while(1)
	{
		system("cls");
		printf("\t\t\t   ┏━━━━━━━━━━┓\n");
		printf("\t\t\t   ┃        背包        ┃\n");
		printf("\t\t\t   ┗━━━━━━━━━━┛\n");
		printf("\n");
		printf("    物品列表    【Esc】返回华夏村（2次）    【F11】穿戴装备    【F12】脱下装备\n\n");
		for(i=0;i<knapsacksize;i++)
		{
			if(knapsacks[i][5][20]==NULL)
			{
				if(i==knapsacknum-1)
				{
					printf("▲  %s",knapsacks[i][0][20]);
					printf("      武力%d",knapsacks[i][1][20]);
					printf("      智力%d",knapsacks[i][2][20]);
					printf("      等级%d",knapsacks[i][3][20]);
					if(knapsacks[i][4][20]==1)
					{
						nums1=1;
						knapsacks[i][4][20]="";
					}
					else if(knapsacks[i][4][20]==2)
					{
						nums1=2;
						knapsacks[i][4][20]="☆ 已装备";
					}
					printf("      %s\n\n",knapsacks[i][4][20]);
					knapsacks[i][4][20]=nums1;
				}
				else
				{
					printf("    %s",knapsacks[i][0][20]);
					printf("      武力%d",knapsacks[i][1][20]);
					printf("      智力%d",knapsacks[i][2][20]);
					printf("      等级%d",knapsacks[i][3][20]);
					if(knapsacks[i][4][20]==1)
					{
						nums1=1;
						knapsacks[i][4][20]="";
					}
					else if(knapsacks[i][4][20]==2)
					{
						nums1=2;
						knapsacks[i][4][20]="☆ 已装备";
					}
					printf("      %s\n\n",knapsacks[i][4][20]);
					knapsacks[i][4][20]=nums1;
				}
			}
			else
			{
				if(i==knapsacknum-1)
				{
					printf("▲  %s",knapsacks[i][0][20]);
					printf("      防御%d",knapsacks[i][1][20]);
					printf("      血量%d",knapsacks[i][2][20]);
					printf("      魔法%d",knapsacks[i][3][20]);
					printf("      等级%d",knapsacks[i][4][20]);
					if(knapsacks[i][5][20]==1)
					{
						nums2=1;
						knapsacks[i][5][20]="";
					}
					else if(knapsacks[i][5][20]==2)
					{
						nums2=2;
						knapsacks[i][5][20]="☆ 已装备";
					}
					printf("      %s\n\n",knapsacks[i][5][20]);
					knapsacks[i][5][20]=nums2;
				}
				else
				{
					printf("    %s",knapsacks[i][0][20]);
					printf("      防御%d",knapsacks[i][1][20]);
					printf("      血量%d",knapsacks[i][2][20]);
					printf("      魔法%d",knapsacks[i][3][20]);
					printf("      等级%d",knapsacks[i][4][20]);
					if(knapsacks[i][5][20]==1)
					{
						nums2=1;
						knapsacks[i][5][20]="";
					}
					else if(knapsacks[i][5][20]==2)
					{
						nums2=2;
						knapsacks[i][5][20]="☆ 已装备";
					}
					printf("      %s\n\n",knapsacks[i][5][20]);
					knapsacks[i][5][20]=nums2;
				}
			}
			knapsacknums=i+1;
		}
		knapsackkey=getch();
		_sleep(100);
		switch(knapsackkey)
		{
		case 72: knapsacknum--;
		    break;  
		case 80: knapsacknum++;
		    break;  
		case 27: china();
			break;
		case 133:
			if(knapsacks[knapsacknum-1][5][20]==NULL)
			{
				if(Gradenum1>=(int)knapsacks[knapsacknum-1][3][20] && armsnum==1)  //等级判断
				{
					knapsacks[knapsacknum-1][4][20] = 2;
					Attribute.force+=(int)knapsacks[knapsacknum-1][1][20];
					Attribute.intelligence+=(int)knapsacks[knapsacknum-1][2][20];
					armsnum=2;
					armsoff=1;
				}
			}
			else
			{
				if(Gradenum1>=(int)knapsacks[knapsacknum-1][4][20] && clothesnum==1)  //等级判断
				{
					knapsacks[knapsacknum-1][5][20] = 2;
					Attribute.defense+=(int)knapsacks[knapsacknum-1][1][20];
					Attribute.HP+=(int)knapsacks[knapsacknum-1][2][20];
					Attribute.MP+=(int)knapsacks[knapsacknum-1][3][20];
					clothesnum=2;
					clothesoff=1;
				}
			}
			break;
		case 134:
			if(knapsacks[knapsacknum-1][5][20]==NULL)
			{
				if(Gradenum1>=(int)knapsacks[knapsacknum-1][3][20] && armsoff==1)  //等级判断
				{
					knapsacks[knapsacknum-1][4][20] = 1;
					Attribute.force-=(int)knapsacks[knapsacknum-1][1][20];
					Attribute.intelligence-=(int)knapsacks[knapsacknum-1][2][20];
					armsnum=1;
					armsoff=2;
				}
			}
			else
			{
				if(Gradenum1>=(int)knapsacks[knapsacknum-1][4][20] && clothesoff==1)  //等级判断
				{
					knapsacks[knapsacknum-1][5][20] = 1;
					Attribute.defense-=(int)knapsacks[knapsacknum-1][1][20];
					Attribute.HP-=(int)knapsacks[knapsacknum-1][2][20];
					Attribute.MP-=(int)knapsacks[knapsacknum-1][3][20];
					clothesnum=1;
					clothesoff=2;
				}
			}
			break;
		}
		if(knapsacknum>knapsacknums)knapsacknum=1;
		if(knapsacknum<1) knapsacknum=knapsacknums;
	}
}

void upgrade()
{
	int upgradenum=1;
	int upgradekey;  //升级key
	fflush(stdin);
	while(1)
	{
		system("cls");
		printf("\t\t\t   ┏━━━━━━━━━━┓\n");
		printf("\t\t\t   ┃        升级        ┃\n");
		printf("\t\t\t   ┗━━━━━━━━━━┛\n");
		printf("\n\n\n");
		for(i=0;i<2;i++)
		{
			if(i==upgradenum-1)
			{
				printf("\t▲ %s\n\n",*upgrades[i]);
			}
			else
			{
				printf("\t   %s\n\n",*upgrades[i]);
			} 
			
		}
		Esc();
		upgradekey=getch();
		_sleep(100);
		switch(upgradekey)
		{
		case 72: upgradenum--;
		    break;  
		case 80: upgradenum++;
		    break; 
		case 13: 
			switch(upgradenum)
			{
			case 1: India();
				return;
			}
			break;
		}
		if(upgradenum<=0)upgradenum=2;
		else if(upgradenum>2)upgradenum=1;
	}
}

void India()
{
	int Indiakey;  //升级key
	fflush(stdin);
	while(1)
	{
		system("cls");
		Indiafun();
		printf("\t\t\t   ┏━━━━━━━━━━┓\n");
		printf("\t\t\t   ┃       印度村       ┃\n");
		printf("\t\t\t   ┗━━━━━━━━━━┛\n");
		printf("\n\n");
		printf("\t      怪物列表\n\n");
		for(i=0;i<10;i++)
		{
			if(randoms[i]<=5)
			{
				randomL[i][0][20]=Indiamonsters[4].name;
				randomL[i][1][20]=Indiamonsters[4].force;
				randomL[i][2][20]=Indiamonsters[4].defense;
				randomL[i][3][20]=Indiamonsters[4].HP;
				randomL[i][4][20]=Indiamonsters[4].exp;
				randomL[i][5][20]=Indiamonsters[4].grade;
				randomL[i][6][20]=Kill[i];
			}
			else if((randoms[i]>=6)  &&  (randoms[i]<=15))
			{
				randomL[i][0][20]=Indiamonsters[3].name;
				randomL[i][1][20]=Indiamonsters[3].force;
				randomL[i][2][20]=Indiamonsters[3].defense;
				randomL[i][3][20]=Indiamonsters[3].HP;
				randomL[i][4][20]=Indiamonsters[3].exp;
				randomL[i][5][20]=Indiamonsters[3].grade;
				randomL[i][6][20]=Kill[i];
			}
			else if((randoms[i]>=16)  &&  (randoms[i]<=30))
			{
				randomL[i][0][20]=Indiamonsters[2].name;
				randomL[i][1][20]=Indiamonsters[2].force;
				randomL[i][2][20]=Indiamonsters[2].defense;
				randomL[i][3][20]=Indiamonsters[2].HP;
				randomL[i][4][20]=Indiamonsters[2].exp;
				randomL[i][5][20]=Indiamonsters[2].grade;
				randomL[i][6][20]=Kill[i];
			}
			else if((randoms[i]>=31)  &&  (randoms[i]<=50))
			{
				randomL[i][0][20]=Indiamonsters[1].name;
				randomL[i][1][20]=Indiamonsters[1].force;
				randomL[i][2][20]=Indiamonsters[1].defense;
				randomL[i][3][20]=Indiamonsters[1].HP;
				randomL[i][4][20]=Indiamonsters[1].exp;
				randomL[i][5][20]=Indiamonsters[1].grade;
				randomL[i][6][20]=Kill[i];
			}
			else if((randoms[i]>=51)  &&  (randoms[i]<=100))
			{
				randomL[i][0][20]=Indiamonsters[0].name;
				randomL[i][1][20]=Indiamonsters[0].force;
				randomL[i][2][20]=Indiamonsters[0].defense;
				randomL[i][3][20]=Indiamonsters[0].HP;
				randomL[i][4][20]=Indiamonsters[0].exp;
				randomL[i][5][20]=Indiamonsters[0].grade;
				randomL[i][6][20]=Kill[i];
			}
			
		}
		for(i=0;i<10;i++)
		{
			if(i==Indianum-1)
			{
				if(randomL[i][6][20]==2)
				{
					printf("    ▲%s  ",randomL[i][0][20]);
					printf("攻击%d  ",randomL[i][1][20]);
					printf("防御%d  ",randomL[i][2][20]);
					printf("血量%d  ",randomL[i][3][20]);
					printf("经验%d  ",randomL[i][4][20]);
					printf("等级%d  ",randomL[i][5][20]);
					printf("已击杀\n");
				}
				else
				{
					printf("    ▲%s  ",randomL[i][0][20]);
					printf("攻击%d  ",randomL[i][1][20]);
					printf("防御%d  ",randomL[i][2][20]);
					printf("血量%d  ",randomL[i][3][20]);
					printf("经验%d  ",randomL[i][4][20]);
					printf("等级%d  \n",randomL[i][5][20]);
				}
			}
			else
			{
				if(randomL[i][6][20]==2)
				{
					printf("      %s  ",randomL[i][0][20]);
					printf("攻击%d  ",randomL[i][1][20]);
					printf("防御%d  ",randomL[i][2][20]);
					printf("血量%d  ",randomL[i][3][20]);
					printf("经验%d  ",randomL[i][4][20]);
					printf("等级%d  ",randomL[i][5][20]);
					printf("已击杀\n");
				}
				else
				{
					printf("      %s  ",randomL[i][0][20]);
					printf("攻击%d  ",randomL[i][1][20]);
					printf("防御%d  ",randomL[i][2][20]);
					printf("血量%d  ",randomL[i][3][20]);
					printf("经验%d  ",randomL[i][4][20]);
					printf("等级%d  \n",randomL[i][5][20]);
				}
			}
			
		}
		Esc();
		Indiakey=getch();
		_sleep(100);
		printf("%d",randomL[Indianum-1][6][20]);
		switch(Indiakey)
		{
		case 72: Indianum--;
		    break;  
		case 80: Indianum++;
		    break; 
		case 13: 
			if(randomL[Indianum-1][6][20]==1)
			{
				Battle();
			}
			break;
		}
		if(Indianum<=0)Indianum=10;
		else if(Indianum>10)Indianum=1;
	}
}

void random()  //随机怪物
{
	for(i=0;i<10;i++)
	{
		randoms[i] = rand()%101;
	}
}

void Battle()
{
	int Battlekey=0;
	int Battlenum=1;
	int HPy,HPx;
	int rounds=1;
	while(1)
	{
		system("cls");
		printf("\t\t\t   ┏━━━━━━━━━━┓\n");
		printf("\t\t\t   ┃        战斗        ┃\n");
		printf("\t\t\t   ┗━━━━━━━━━━┛\n");
		printf("\t\t\t            %d回合\n",rounds);
		printf("\n\n\n");
		printf("   %s    攻击%d    防御%d    血量%d    经验%d    等级%d\n\n\n",randomL[Indianum-1][0][20],randomL[Indianum-1][1][20],randomL[Indianum-1][2][20],randomL[Indianum-1][3][20],randomL[Indianum-1][4][20],randomL[Indianum-1][5][20]);
		
		if(HPs<=0)
		{
			printf("\t战斗失败\n\n");
			printf("\t任意键返回\n\n");
			china();
			return;
		}
		else if((int)randomL[Indianum-1][3][20]<=0)
		{
			Gradenum2 += (int)randomL[Indianum-1][4][20];
			Kill[Indianum-1]=2;
			printf("\t战斗胜利\n\n");
			Drop();
			printf("\t任意键返回\n\n");
			getchar();
			India();
			return;
		}
		else
		{
			if(Battlekey==13)
			{
				HPy=Attribute.force - (int)randomL[Indianum-1][2][20];
				HPx=randomL[Indianum-1][1][20] - Attribute.defense;
				if(HPy<0)
				{
					HPy=0;
				}
				else if(HPx<0)
				{
						HPx=0;
				}
				randomL[Indianum-1][3][20] -= HPy;
				HPs -= HPx;
				printf("\t你攻击了%s，造成%d滴伤害\n\n",randomL[Indianum-1][0][20],HPy);
				printf("\t%s攻击了你，造成%d滴伤害\n\n",randomL[Indianum-1][0][20],HPx);
			}
		}
		printf("\n\n");
		for(i=0;i<2;i++)
		{
			if(i==Battlenum-1)
			{
				printf("\t▲ %s\n\n",*Battles[i]);
			}
			else
			{
				printf("\t   %s\n\n",*Battles[i]);
			}
		}
		printf("\t   当前血量：%d",HPs);
		Battlekey=getch();
		switch(Battlekey)
		{
		case 72: Battlenum--;
		    break;  
		case 80: Battlenum++;
		    break; 
		case 13: rounds++;
			break;
		}
		if(Battlenum<=0)Battlenum=2;
		else if(Battlenum>2)Battlenum=1;
	}
}

void Drop()  //掉率
{
	int dropnum,dropnums;
	dropnum=rand()%101;
	if((dropnum<=2) && (randomL[Indianum-1][1][20]==15))
	{
		knapsacksize++;
		dropnums=4;
		knapsacks[knapsacksize-1][0][20]=Kitchenknife[dropnums].name;
		knapsacks[knapsacksize-1][1][20]=Kitchenknife[dropnums].force;
		knapsacks[knapsacksize-1][2][20]=Kitchenknife[dropnums].intelligence;
		knapsacks[knapsacksize-1][3][20]=Kitchenknife[dropnums].grade;
		knapsacks[knapsacksize-1][4][20]=Kitchenknife[dropnums].state;
		printf("\t恭喜！获得了%s\n\n\n",Kitchenknife[dropnums].name);
	}
	else if(((dropnum>=3) && (dropnum<=8)) && ((randomL[Indianum-1][1][20]==12) || (randomL[Indianum-1][1][20]==9)))
	{
		knapsacksize++;
		dropnums=3;
		knapsacks[knapsacksize-1][0][20]=Kitchenknife[dropnums].name;
		knapsacks[knapsacksize-1][1][20]=Kitchenknife[dropnums].force;
		knapsacks[knapsacksize-1][2][20]=Kitchenknife[dropnums].intelligence;
		knapsacks[knapsacksize-1][3][20]=Kitchenknife[dropnums].grade;
		knapsacks[knapsacksize-1][4][20]=Kitchenknife[dropnums].state;
		printf("\t恭喜！获得了%s\n\n\n",Kitchenknife[dropnums].name);
	}
	else if((dropnum>=9) && (dropnum<=19) && ((randomL[Indianum-1][1][20]==9) || (randomL[Indianum-1][1][20]==6)))
	{
		knapsacksize++;
		dropnums=2;
		knapsacks[knapsacksize-1][0][20]=Kitchenknife[dropnums].name;
		knapsacks[knapsacksize-1][1][20]=Kitchenknife[dropnums].force;
		knapsacks[knapsacksize-1][2][20]=Kitchenknife[dropnums].intelligence;
		knapsacks[knapsacksize-1][3][20]=Kitchenknife[dropnums].grade;
		knapsacks[knapsacksize-1][4][20]=Kitchenknife[dropnums].state;
		printf("\t恭喜！获得了%s\n\n\n",Kitchenknife[dropnums].name);
	}
	else if((dropnum>=20) && (dropnum<=35) && ((randomL[Indianum-1][1][20]==6) || (randomL[Indianum-1][1][20]==3)))
	{
		knapsacksize++;
		dropnums=1;
		knapsacks[knapsacksize-1][0][20]=Kitchenknife[dropnums].name;
		knapsacks[knapsacksize-1][1][20]=Kitchenknife[dropnums].force;
		knapsacks[knapsacksize-1][2][20]=Kitchenknife[dropnums].intelligence;
		knapsacks[knapsacksize-1][3][20]=Kitchenknife[dropnums].grade;
		knapsacks[knapsacksize-1][4][20]=Kitchenknife[dropnums].state;
		printf("\t恭喜！获得了%s\n\n\n",Kitchenknife[dropnums].name);
	}
	else if((dropnum>=36)  &&  (dropnum<=60))
	{
		knapsacksize++;
		dropnums=0;
		knapsacks[knapsacksize-1][0][20]=Kitchenknife[dropnums].name;
		knapsacks[knapsacksize-1][1][20]=Kitchenknife[dropnums].force;
		knapsacks[knapsacksize-1][2][20]=Kitchenknife[dropnums].intelligence;
		knapsacks[knapsacksize-1][3][20]=Kitchenknife[dropnums].grade;
		knapsacks[knapsacksize-1][4][20]=Kitchenknife[dropnums].state;
		printf("\t恭喜！获得了%s\n\n\n",Kitchenknife[dropnums].name);
	}
	else
	{
		printf("\t很遗憾啥也没有！！\n\n");
	}
}