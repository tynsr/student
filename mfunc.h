#ifndef MFUNC_H
#define MFUNC_H

#include <stdbool.h>

extern int count;
extern int temp;

//管理员添加教师
void admin_add_tch(void);
//管理员删除教师
void admin_del_tch(void);
//管理员显示在职教师列表
void admin_list_untch(void);
//管理员显示离职教师列表
void admin_list_tch(void);
//管理员重置教师密码
void admin_reset_tch(void);
//管理员登陆
bool admin_login(void);
//管理员修改密码
void admin_change_key(void);

//学生加一
void add_one(void); 
//批量导入学生
void add_list(int num); 
//删除学生
void del(void);
//查询学生
void find(void);
//修改学生
void modify(void);
//查询老师信息
void check(int num);
//添加学生成绩
void input_score_one(void); 
//批量倒入学生
void input_score_list(int src,int num);
//显示学生成绩
void list(int flag);

//学生登陆 
int log_sucess(void);
//查询成绩
void seek_score_stu(void);
//修改密码
void ch_key_student(void);
//查询个人信息
void check_student(void);


#endif//MFUNC_H
