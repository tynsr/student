#include <getch.h>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

#include"mfunc.h"
#include"tools.h"

int count = 0;
int temp = 0;

//管理员添加教师
void admin_add_tch(void)
{
	puts("添加一个教师");
	char Ateacher_name[20];
	char Ateacher_sex;
	int Ateacher_id;
	puts("请输入教师名字：");
	scanf("%s",Ateacher_name);
	fflush(stdin);
	puts("请输入教师性别：");
	scanf(" %c",&Ateacher_sex);
	fflush(stdin);
	puts("请输入教师工号：");
	scanf("%d",&Ateacher_id);
	fflush(stdin);
	int pos = -1; //用来确定插入的位置
	for(int i=0;i<50;i++)
	{
		if(tch[i].sex == '\0' && pos == -1)
		{
			puts("已经寻找好插入位置");//后期可注释掉
			pos = i;
		}
		if(tch[i].id == Ateacher_id)
		{
			puts("工号重复，请重新输入！\n");
			break;
		}
		if(i == 49)
		{
			strcpy(tch[pos].name,Ateacher_name);
			tch[pos].sex = Ateacher_sex;
			tch[pos].id = Ateacher_id;
			tch[pos].key = 123456;
			tch[pos].flag = true;
			tch[pos].root = 0;
			show_msg("添加成功!",1.5);
		}
	}
	
}

//管理员删除教师
void admin_del_tch(void)
{
	puts("请删除教师\n");
	puts("请输入教师工号：");
	int Ateacher_id = 0;
	scanf("%d",&Ateacher_id);
	fflush(stdin);
	for(int i=0;i<50;i++)
	{
		if(Ateacher_id == tch[i].id)
		{
			tch[i].flag = 0;
			show_msg("删除成功！",1.5);
			break;
		}
		if(i==49)
		{
			puts("没有这个工号\n");
		}
	}
}

//管理员显示离职教师列表
void admin_list_untch(void)
{
	puts("显示离职教师");
	for(int i=0; i<50; i++)
	{
		if(tch[i].flag==0 && tch[i].sex != '\0')
		{
			printf("\n姓名:%s 性别:%s 工号:%d\n\n",tch[i].name,tch[i].sex=='w'?"女":"男",tch[i].id);
		}
		else
		{
			break;
		}
	}
	anykey_continue();
}

//管理员显示在职教师列表
void admin_list_tch(void)
{
	puts("显示在职教师");
	for(int i=0; i<50; i++)
	{
		if(tch[i].flag==1 && tch[i].sex != '\0')
		{
			printf("\n姓名:%s 性别:%s 工号:%d\n\n",tch[i].name,tch[i].sex=='w'?"女":"男",tch[i].id);
		}
		else
		{
			continue;
		}
	}
	anykey_continue();
}

//管理员重置教师密码
void admin_reset_tch(void)
{
	puts("重置密码");
	puts("请输入教师工号：");
	int Ateacher_id;
	scanf("%d",&Ateacher_id);
	fflush(stdin);
	for(int i=0;i<50;i++)
	{
		if(tch[i].id == Ateacher_id)
		{
			tch[i].key = 123456;
			tch[i].root = 0;;
			show_msg("重置成功！",1.5);
			break;
		}
		if(i==49)
		{
			puts("没有这个工号！");
		}
	}
}

//管理员登陆
bool admin_login(void)
{
	char Aadmin_name[20] = {};
	int Aadmin_key = 0;
	printf("%s %d %hhd\n",adm[0].name, adm[0].key, adm[0].root);
	anykey_continue();
	puts("请输入用户名：");
	scanf("%s",Aadmin_name);
	fflush(stdin);
	if(Aadmin_name[0] == '\0')
	{
		puts("用户名不能为空！");
		return false;
	}
	puts("请输入密码：");
	scanf("%d",&Aadmin_key);
	fflush(stdin);
	if(strcmp(Aadmin_name,adm[0].name)==0 && Aadmin_key==adm[0].key)
	{
		show_msg("密码正确！",1);
		return true;
	}
	else
	{
		printf("%d\n", adm[0].key);
		printf("%s", adm[0].name);
		//show_msg("密码错误！",1);
		return false;
	}
	
}

//管理员修改密码
void admin_change_key(void)
{
	int old_key = 0;
	int new_key = 0;
	int new_two_key = 0;
	puts("请输入原密码：");
	scanf("%d",&old_key);
	if(old_key!=adm[0].key)
	{
		show_msg("原密码错误！",1.5);
		return;
	}
	puts("请输入新密码：");
	scanf("%d",&new_key);
	puts("请第二次输入新密码：");
	scanf("%d",&new_two_key);
	fflush(stdin);
	if(old_key==adm[0].key)
	{
		if(new_key==new_two_key)
		{
			show_msg("修改密码成功",1.5);
			if(adm[0].root==0)
			{
				adm[0].root = 1;
			}
			adm[0].key = new_key;
		}
		else
		{
			show_msg("两次密码不一致！",1.5);
		}
	}
}

//学生加一
void add_one(void)
{
	if(50 <= count)
	{
		printf("系统维护中，请稍候...\n");
		return;
	}
	int i=0;
	while(stu[i].sex) i++;
	
	puts("请输入学生的姓名：");
	scanf("%s",stu[i].name);
	puts("请输入性别：");
	scanf(" %c",&stu[i].sex);
	stu[i].id=100000+i;	
	stu[i].key=123456;
	stu[i].root=0;
	stu[i].flag=1;
	count++;	
	show_msg("添加学生成功\n",1.5);
}

//批量导入学生
void  add_list(int num)
{
	FILE* frp=fopen("add_stu.txt","r");
	if(NULL ==frp)
	{
		show_msg("学生文件不存在，请检查!\n",1.5);
		return;
	}
	int i=0;
	while(stu[i].sex) i++;
	int n=i;
	for(i=n;i<num+n && i<50;i++)
	{
		if(2==fscanf(frp,"%s %c", stu[i].name,&stu[i].sex))
		{
			stu[i].id=100000+i;	
			stu[i].key=123456;
			stu[i].root=0;
			stu[i].flag=1;
			count++;
		}
	}
	fclose(frp);
	show_msg("批量添加学生成功\n",1.5);
}

//删除学生
void del(void)
{
	char key[20] = {};
	int Id=0;
	puts("请输入学生的姓名：");
	scanf("%s",key);
	fflush(stdout);
	puts("请输入学号：");
	scanf(" %d",&Id);
	for(int i=0; i<1000; i++)
	{
		if(stu[i].sex)	
		{
			if(0 == strcmp(stu[i].name,key) && stu[i].id==Id)	
			{
				printf("删除%s %s %d 学生成功\n",stu[i].name, 'w'==stu[i].sex?"女":"男" ,stu[i].id);
				stu[i].sex = 0;
				stu[i].flag = 0;
				show_msg("",1.5);
				return;
			}
		}
	}
	printf("没找到学生%s,请检查查询条件\n",key);
	show_msg("",1.5);
}

//查询学生
void find(void)
{
	char key[20] = {};
	int Id=0;
	printf("请输入学生的姓名：\n");
	scanf("%s",key);
	printf("请输入学号：\n");
	scanf(" %d",&Id);
	for(int i=0; i<1000; i++)
	{
		if(stu[i].sex)	
		{
			if(0 == strcmp(stu[i].name,key) && Id==stu[i].id)	
			{

				printf("查找成功\n姓名:%s 性别:%s 学号:%d 状态:%s\n ",stu[i].name, 'w'==stu[i].sex?"女":"男" ,stu[i].id,stu[i].flag?"在校":"离校");
				anykey_continue();
				return;
			}
		}
	}
	printf("没找到学生%s,请检查查询条件\n",key);
	show_msg("",1.5);
}

//修改学生
void modify(void)
{
	char key[20] = {};
	int Id=0;
	printf("请输入学生的姓名：\n");
	scanf("%s",key);
	printf("请输入学号：\n");
	scanf(" %d",&Id);
	for(int i=0; i<1000; i++)
	{
		if(stu[i].sex)	
		{
			if(0 == strcmp(stu[i].name,key) && Id==stu[i].id)	
			{
				printf("请重新输入学生姓名、性别：");
				scanf(" %s",stu[i].name);
				scanf(" %c",&stu[i].sex);
				show_msg("修改学生信息成功!\n",1.5);			
				return;
			}
		}
	}
	printf("没找到学生%s,请检查查询条件\n",key);
	show_msg("",1.5);
}

//添加学生成绩
void input_score_one(void)
{
	char key[20] = {};
	int Id=0;
	printf("请输入学生的姓名：\n");
	scanf("%s",key);
	printf("请输入学号：\n");
	scanf(" %d",&Id);
	for(int i=0;i<1000;i++)
	{
		if(stu[i].sex)	
		{
			if(0 == strcmp(stu[i].name,key) && Id==stu[i].id)	
			{
				printf("请输入该学生的成绩（数学、语文、英语）:\n");
				scanf("%lf %lf %lf",&stu[i].sco.math,&stu[i].sco.chinese,&stu[i].sco.english);
				fflush(stdin);
				show_msg("添加学生成绩成功",1.5);
				return;
			}
		}
	}
	printf("没找到学生%s,请检查查询条件\n",key);
	show_msg("",1.5);
}

//批量倒入学生成绩
void input_score_list(int src, int num)
{
	FILE* frp=fopen("add_stu_score.txt","r");
	if(NULL == frp)
	{
		show_msg("学生成绩文件不存在!\n",1.5);
		return;	
	}
	for(int i=src;i<src+num;i++)
	{
		if(3!=fscanf(frp,"%lf %lf %lf %d",&stu[i].sco.math,&stu[i].sco.chinese,&stu[i].sco.english, &stu[i].id))
		{
			break;
		}
	}
	fclose(frp);
	show_msg("批量添加成绩成功\n",1.5);
}

//显示学生成绩
void list(int flag)
{
	if(1==flag)
	{
		for(int i=0;i<count;i++)
		{
			if(1==stu[i].flag)
			{
				printf("姓名:%s 性别:%s 学号:%d 状态:在校 数学:%.2lf 语文:%.2lf 英语:%.2lf \n",stu[i].name,'w'==stu[i].sex?"女":"男",stu[i].id,stu[i].sco.math,stu[i].sco.chinese,stu[i].sco.english);
			}
			
		}
		anykey_continue();
	}
	else if(0==flag)
	{
		for(int i=0;i<count;i++)
		{
			if(0==stu[i].flag)
			{
				printf("姓名:%s 性别:%s 学号:%d 状态:离校 数学:%.2lf 语文:%.2lf 英语:%.2lf\n",stu[i].name,'w'==stu[i].sex?"女":"男",stu[i].id,stu[i].sco.math,stu[i].sco.chinese,stu[i].sco.english);
			}
		}
		anykey_continue();
	}

}

//查询老师信息
void check(int num)
{
	printf("姓名:%s 性别:%s 工号:%d\n", tch[num].name, 'w'==tch[num].sex?"女":"男", tch[num].id);
	anykey_continue();
}

//学生登陆
int log_sucess(void)
{
	debug("%s\n",__func__);
	int sid = 0,skey = 0,schance = 3;
	printf("请输入学号: ");
	scanf("%d",&sid); 
	printf("请输入密码: ");
	scanf("%d",&skey);
	for( int i=0; i<count; i++)
	{
		while(sid == stu[i].id)
		{
			if(stu[i].key == skey)
			{
				if(2 < stu[i].root)
				{
					printf("帐号被锁定请找教师解锁!\n");
					return -1;
				}
				else
				{
					printf("登陆成功!\n");
					return i;
				}
			}
			else
			{
				printf("学号或密码错误，请重新输入学号、密码!\n");
				scanf("%d %d",&sid,&skey);
				schance--;
				if(!schance)
				{
					printf("帐号被锁定!\n");
					stu[i].root = 3;
					return -1;
				}
			}
		}
	}		
	printf("未找到该帐号！\n");
	return -1;
}

//查询自己的成绩
void seek_score_stu(void)
{
	debug("%s\n",__func__);
	printf("数学：%lf，语文：%lf，英语：%lf \n",stu[temp].sco.math,stu[temp].sco.chinese,stu[temp].sco.english);
	double sum = 0, ave = 0, t = 0, max = 0, min = 0;
	double t_stu = stu[temp].sco.math+stu[temp].sco.chinese+stu[temp].sco.english;
	int rank_stu = 0;
	for(int i=0; i<count; i++)
	{
		t = stu[i].sco.math + stu[i].sco.chinese + stu[i].sco.english;
		if( t > t_stu)
		{
			rank_stu++;
		}
		sum = sum+t;
		if(max < t)
		{
			max = t;
		} 
		if(min > t)
		{
			min = t;
		}
	}
	/*int i=0;
	while(stu[i].sex != '\0') i++;*/
	ave = sum/count;
	printf("排名：%d，平均分：%lf，最高分：%lf，最低分：%lf\n",rank_stu,ave,max,min);
	return;
}


//修改密码
void ch_key_student(void)
{
	debug("%s\n",__func__);
	int old_key_stu = 0;
	int new_key_stu = 0;
	int new_key_stu_two = 0;
	printf("请输入原密码: ");
	scanf("%d",&old_key_stu);
	if( old_key_stu != stu[temp].key)
	{
		printf("密码不正确\n");
	}
	else
	{
		printf("请输入新密码: ");
		scanf( "%d",&new_key_stu);
		printf("请再次输入密码: "); 
		scanf("%d",&new_key_stu_two);
		if(new_key_stu == new_key_stu_two)
		{
			stu[temp].key = new_key_stu;
			printf("修改密码成功\n");
			if(0 == stu[temp].root)
			{
				stu[temp].root = 1;
			} 
		}
		else
		{
			printf("两次密码不一样\n");
		}
		return;
	}
	
}

//查询个人信息
void check_student(void)
{
	debug("%s\n",__func__);
	printf("姓名：%s，性别：%c，学号：%d\n",stu[temp].name,stu[temp].sex,stu[temp].id);
	anykey_continue();
}



