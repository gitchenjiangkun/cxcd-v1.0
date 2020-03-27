int p;
char *IndiamonsterARR[5][10]={{"【印度】刁民（经验宝宝）"},{"【印度】强奸犯（普通）  "},{"【印度】民兵（普通）    "},{"【印度】吸毒人员（精英）"},{"【印度】开挂者（BOSS）  "}};

struct Indiamonster
{
	char *name;  //怪物名字
	int force;  //武力
	int defense;  //防御
	int HP;  //血量
	int exp;  //经验值
	int grade;  //等级
	int Kill;  //击杀状态 1否2是
}Indiamonsters[5];

void Indiafun()
{
	for(p=0;p<5;p++)
	{
		Indiamonsters[p].name=*IndiamonsterARR[p];
		Indiamonsters[p].force=(p+1)*(p+2)+(2*p);
		Indiamonsters[p].defense=(p+1)*(p+1);
		Indiamonsters[p].HP=((p+1)*(p+2)+(2*p))*12;
		Indiamonsters[p].exp=(p+1)*30;  
		Indiamonsters[p].grade=(p+1)*2;  
		Indiamonsters[p].Kill=1; 
	}
}