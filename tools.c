#include"tools.h"
#include<getch.h>
#include"mfunc.h"
#include<stdlib.h>


struct Admin *adm;
struct Teacher *tch;
struct Student *stu;


//密码修改与重置函数
int reset(char lock,int* key)
{
	debug("%s\n",__func__);
	if(1 == lock)
	{
		//重置密码
		*key = 123456;
		printf("重置密码成功！\n");
		return 0;
	}
	else if(0 == lock)
	{
		//修改密码
		int pwd=*key;	//定义了pwd为新密码
		printf("请输入一个六位新密码：\n");
		while(pwd == *key)	//如果新密码与旧密码相等则重新输入
		{
			scanf("%d", &pwd);
			printf("请重新输入:\n");
		}
		*key = pwd;
		printf("密码修改成功:%d！\n", *key);
		return 1;
	}
	else if(2 == lock)
		return 0;	//正常登陆
	else
	{
		printf("帐号存在问题！暂停使用\n");
		return 2;
	}

}

////释放堆内存，保存数据到文件
void exit_main()
{
	debug("%s\n",__func__);
	FILE* afwp = fopen("admin.txt","w");    
    fprintf(afwp,"%s %d %hd", adm[0].name, adm[0].key, adm[0].root);
    fclose(afwp);
 	int i=0;
     FILE* sfwp = fopen("stu.txt","w");
     for(i=0; i<50; i++)
     {
        
         if(stu[i].sex != 0)
         {
             fprintf(sfwp,"%s %c %d %d %.2lf %.2lf %.2lf %d %hhd %hhu",stu[i].name,stu[i].sex,stu[i].id,stu[i].key,stu[i].sco.chinese,stu[i].sco.english,stu[i].sco.math,stu[i].rank,stu[i].root,stu[i].flag);
         }
     }
     fclose(sfwp);
 
     FILE* tfwp = fopen("tea.txt","w");
     for(i=0; i<50; i++)
     {
         
         if(tch[i].sex != 0)
         {
             fprintf(tfwp,"%s %c %d %d %hhd %hhd\n",tch[i].name,tch[i].sex,tch[i].id,tch[i].key,tch[i].root,tch[i].flag);
         }    
     }
     fclose(tfwp);
     tfwp = NULL;
     // 释放内存、保存数据
     free(stu);
     free(tch);
     free(adm);
     printf("系统退出...\n");

}


//校长菜单
int menu_admin(void)
{
  debug("%s\n",__func__);
  puts("--------选择您想使用的功能---------");
  puts("1、添加教师");
  puts("2、删除教师");
  puts("3、显示在职教师");
  puts("4、显示离职教师");
  puts("5、重置教师密码");
  puts("6、退出");
  puts("------------------------------------");
  char ch = getch();
  printf("%c\n",ch); //为了回显
  return ch;
}

//主菜单
int menu_main(void)
{
	system("clear");
  debug("%s\n",__func__);
  puts("--------欢迎进入系统---------");
  puts("1、校长");
  puts("2、教职工");
  puts("3、学生");
  puts("4、退出");
  puts("------------------------------------");
  char ch = getch();
  printf("%c\n",ch); //为了回显
  return ch;
}

//教师菜单
char menu_tea(void)
{
	system("clear");
	puts("---------选择您想要的功能----------");
	puts("1、添加学生");
	puts("2、删除学生");
	puts("3、查找学生");
	puts("4、修改学生");
	puts("5、修改密码");
	puts("6、查看个人信息");
	puts("7、录入学生成绩");
	puts("8、重置学生密码");
	puts("9、显示学生");
	puts("0、退出");
	puts("-----------------------------------------");
	puts("请输入指令:");
	char ch=getch();
	return ch;
}

//学生菜单
int menu_stu(void)
{
  system("clear");
  puts("--------选择您想使用的功能---------");
  puts("1、查询成绩");
  puts("2、修改密码");
  puts("3、查看个人信息");
  puts("4、退出");
	puts("-----------------------------------------");
  char ch = getch();
  printf("%c\n",ch);
  return ch;
 } 

//对于批量增加和单个增加
int choose_add(void)
{
	int num=0;
	for(;;)
	{
		printf("请问是单个输入(1)还是批量添加(2)？\n");
		switch(getch())
		{
			case '1': add_one(); return 0;
			case '2': 
			printf("请输入一次批量添加的人数:");
			scanf("%d",&num);
			add_list(num); 
			return -1;
			default : break;
		}
	}
}

//初始化数据
void init_main(void)
{
 	debug("%s\n",__func__);
	adm = calloc(2, sizeof(adm));
	tch = calloc(50, sizeof(tch));
	stu = calloc(50, sizeof(stu));
	
	FILE* afrp = fopen("admin.txt","r");
	//int i = 0;
	fscanf(afrp,"%s %d %hhd", adm[0].name, &adm[0].key, &adm[0].root);
	printf("init:%s init:%d init:%hhd\n",adm[0].name, adm[0].key, adm[0].root);
	anykey_continue();
	fclose(afrp);
	afrp = NULL;
	FILE* sfrp = fopen("stu.txt","r");
	for(int i=0; i<50; i++)
	 {
          fscanf(sfrp,"%s %c %d %d %lf %lf %lf %d %hhd %hhu",stu[i].name,&stu[i].sex,&stu[i].id,&stu[i].key,&stu[i].sco.chinese,&stu[i].sco.english,&stu[i].sco.math,&stu[i].rank,&stu[i].root,&stu[i].flag);
      }
      fclose(sfrp);
  	sfrp = NULL;
      FILE* tfrp = fopen("tea.txt","r");
      for(int i=0; i<50; i++)
      {
          fscanf(tfrp,"%s %c %d %d %hhd %hhd ",tch[i].name,&tch[i].sex,&tch[i].id,&tch[i].key,&tch[i].root,&tch[i].flag);
      }
      fclose(tfrp);
		tfrp = NULL; 
      
}


//选择批量增加成绩还是单个增加成绩
void choose_score_add(void)
{
	int src=0,num=0;
	for(;;)
	{
		printf("请问是单个输入(1)还是批量添加(2)？\n");
		switch(getch())
		{
			case '1': input_score_one(); return;
			case '2':
			 	printf("请输入添加起始位置： ");
			 	scanf("%d",&src);
			 	printf("一次批量添加成绩的人数: ");
				scanf("%d",&num);
			 	input_score_list(src,num); 
			 	return;
			default : break;
		}
	}
}

//选择查看在校学生还是离校学生
void choose_list(void)
{
	for(;;)
	{
		printf("请问查看在校学生(1)还是离校学生(2)？\n");
		switch(getch())
		{
			case '1': list(1); return;
			case '2': list(0); return;
			default : break;
		}
	}
}

//	打印提示信息
void show_msg(const char* msg,double sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}

//	任意键继续
void anykey_continue(void)
{
	puts("任意键继续...");
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

