int z;
//����
char *KitchenknifeARR[5][10]={{"�����⡿�˵�"},{"����ͨ���˵�"},{"���������˵�"},{"����Ʒ���˵�"},{"�������𡿲˵�"}};
char *BranchARR[5][10]={{"�����⡿���"},{"����ͨ�����"},{"�����������"},{"����Ʒ�����"},{"�����������"}};
char *MacheteARR[5][10]={{"�����⡿���ϵ�"},{"����ͨ�����ϵ�"},{"�����������ϵ�"},{"����Ʒ�����ϵ�"},{"�����������ϵ�"}};
char *MagicwandARR[5][10]={{"�����⡿ħ����"},{"����ͨ��ħ����"},{"��������ħ����"},{"����Ʒ��ħ����"},{"��������ħ����"}};

//�·�
char *ChouisARR[5][10]={{"���ƾɡ�����"},{"����ͨ������"},{"������������"},{"����͡�����"},{"�������𡿲���"}};

//�����ṹ��
struct arms
{
	char *name;  //��������
	int force;  //����
	int intelligence;  //����
	int grade;  //�ȼ�
	int *state;  //�Ƿ񴩴�
}Kitchenknife[5],Magicwand[5],Machete[5];


//�·��ṹ��
struct clothes
{
	char *name;  //�·�����
	int defense;  //����
	int HP;  //Ѫ��
	int MP;  //ħ��
	int grade;  //�ȼ�
	int *state;  //�Ƿ񴩴�
}Choui[5];


void Kitchenknifes()  //�˵�
{
	for(z=0;z<5;z++)
	{
		Kitchenknife[z].name=*KitchenknifeARR[z];
		Kitchenknife[z].force=(z+1)*z+(z+1);
		Kitchenknife[z].intelligence=z+1;
		Kitchenknife[z].grade=1;
		Kitchenknife[z].state=1;  //1δװ��2��װ��
	}
}

void Chouis()  //���
{
	for(z=0;z<5;z++)
	{
		Choui[z].name=*ChouisARR[z];
		Choui[z].defense=(z+1)*z+(z+1);
		Choui[z].HP=(z+1)*10+(z*10);
		Choui[z].MP=(z+1)*10+(z*10);
		Choui[z].grade=1;
		Choui[z].state=1;  //1δװ��2��װ��
	}
}