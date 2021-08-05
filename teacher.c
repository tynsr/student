#include"mfunc.h"
#include"tools.h"
#include"teacher.h"

#include<getch.h>
#include<stdlib.h>
#include"mfunc.h"
#include"tools.h"
#include"teacher.h"











int tea_login(void)
{
	printf("请输入工号:\n");
	int tkey=0, tid = 0, chance = 3;
	scanf("%d", &tid);
	for(int i=0; i<50; i++)
	{
		while(tch[i].id == tid)
		{
			printf("请输入密码：\n");
			scanf("%d", &tkey);
			if(tch[i].key == tkey)
			{
				printf("登陆成功");
				return i;
			}	
			else
			{	
				printf("输入错误");
				chance--;
				if(!chance)
				{
					printf("你已经完蛋了！\n");
					tch[i].root = 0;
					return -1;	
				}
			}	
		}
	}	
	return -1;	
}

void stu_key_set(void)
{
	printf("这位同学，请告诉我你的学号：\n");
	int sid = 0;
	scanf("%d", &sid);
	for(int i=0; i<1000; i++)
	{
		if(stu[i].id == sid)
		{
			reset(0, &stu[i].key);
			return;
		}
	}
	printf("查无此人，换个人试试\n");
}


void teacher(void)
{
	int num = tea_login();
	if(num >= 0)
	{	
		if(tch[num].root == 0)
		{
			reset(0, &tch[num].key);
			tch[num].root = 1;
		}
		if(2 <= tch[num].root)
		{
			printf("帐号锁定\n");
			return;
		}	
		else
		{		
			for(;;)
			{
				switch(menu_tea())
				{
					
					case '1': choose_add();break;
					case '2': del();break;
					case '3': find();break;
					case '4': modify();break;
					case '5': reset(0, &tch[num].key);break;
					case '6': check(num);break;
					case '7': choose_score_add();break;
					case '8': stu_key_set();break;
					case '9': choose_list();break;
					case '0': return;
				}
			}
		}
	}
	else
	{
		printf("没有此帐号！\n");
		return;
	}
}







