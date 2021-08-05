#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdbool.h>

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else
	#define debug(...)
#endif

#define PRM_KEY 123456

//成绩结构体
typedef struct Score{
    double math;
    double chinese;
    double english;
}Score;

//学生结构体
struct Student{
    char name[20];
    char sex;
    int id; //6位学号
    int key;    //密码,初始化123456
    char root;  //关于密码重置的开关
    char flag;  //是否在校  1：在校 0：离职
    int rank;	//学生排名
    Score sco;
};

//教师结构体
struct Teacher{
    char name[20];
    char sex;
    int id;//6位工号
    int key; //密码,初始化123456
    char flag;  //是否在校 1：在校 0：离职
    char root;  //关于密码重置的开关
};

//校长结构体
struct Admin{
    char name[20];
    int key; //密码,初始化123456
    char root;  //关于密码重置的开关
};

extern struct Admin *adm;
extern struct Teacher *tch;
extern struct Student *stu;

//密码修改与重置函数
int reset(char lock, int*key);
//释放堆内存，保存数据到文件
void exit_main();
//校长菜单
int menu_admin(void);
//主菜单
int menu_main(void);
//教师菜单
char menu_tea(void);
//学生菜单
int menu_stu(void);
//初始化数据
void init_main(void);
//对于批量增加和单个增加
int choose_add(void);
//选择批量增加成绩还是单个增加成绩
void choose_score_add(void);
//选择查看在校学生还是离校学生
void choose_list(void);
//	打印提示信息
void show_msg(const char* msg,double sec);
//	任意键继续
void anykey_continue(void);



#endif//TOOLS_H




