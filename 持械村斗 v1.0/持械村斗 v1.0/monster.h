int p;
char *IndiamonsterARR[5][10]={{"��ӡ�ȡ����񣨾��鱦����"},{"��ӡ�ȡ�ǿ�鷸����ͨ��  "},{"��ӡ�ȡ��������ͨ��    "},{"��ӡ�ȡ�������Ա����Ӣ��"},{"��ӡ�ȡ������ߣ�BOSS��  "}};

struct Indiamonster
{
	char *name;  //��������
	int force;  //����
	int defense;  //����
	int HP;  //Ѫ��
	int exp;  //����ֵ
	int grade;  //�ȼ�
	int Kill;  //��ɱ״̬ 1��2��
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