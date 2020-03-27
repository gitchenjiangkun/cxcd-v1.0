int z;
//武器
char *KitchenknifeARR[5][10]={{"【生锈】菜刀"},{"【普通】菜刀"},{"【精良】菜刀"},{"【极品】菜刀"},{"【土豪金】菜刀"}};
char *BranchARR[5][10]={{"【生锈】树杈"},{"【普通】树杈"},{"【精良】树杈"},{"【极品】树杈"},{"【土豪金】树杈"}};
char *MacheteARR[5][10]={{"【生锈】西瓜刀"},{"【普通】西瓜刀"},{"【精良】西瓜刀"},{"【极品】西瓜刀"},{"【土豪金】西瓜刀"}};
char *MagicwandARR[5][10]={{"【生锈】魔法棒"},{"【普通】魔法棒"},{"【精良】魔法棒"},{"【极品】魔法棒"},{"【土豪金】魔法棒"}};

//衣服
char *ChouisARR[5][10]={{"【破旧】草衣"},{"【普通】草衣"},{"【华丽】草衣"},{"【天赐】草衣"},{"【土豪金】草衣"}};

//武器结构体
struct arms
{
	char *name;  //武器名字
	int force;  //武力
	int intelligence;  //智力
	int grade;  //等级
	int *state;  //是否穿戴
}Kitchenknife[5],Magicwand[5],Machete[5];


//衣服结构体
struct clothes
{
	char *name;  //衣服名字
	int defense;  //防御
	int HP;  //血量
	int MP;  //魔法
	int grade;  //等级
	int *state;  //是否穿戴
}Choui[5];


void Kitchenknifes()  //菜刀
{
	for(z=0;z<5;z++)
	{
		Kitchenknife[z].name=*KitchenknifeARR[z];
		Kitchenknife[z].force=(z+1)*z+(z+1);
		Kitchenknife[z].intelligence=z+1;
		Kitchenknife[z].grade=1;
		Kitchenknife[z].state=1;  //1未装备2已装备
	}
}

void Chouis()  //树杈
{
	for(z=0;z<5;z++)
	{
		Choui[z].name=*ChouisARR[z];
		Choui[z].defense=(z+1)*z+(z+1);
		Choui[z].HP=(z+1)*10+(z*10);
		Choui[z].MP=(z+1)*10+(z*10);
		Choui[z].grade=1;
		Choui[z].state=1;  //1未装备2已装备
	}
}