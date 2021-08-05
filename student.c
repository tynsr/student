#include"mfunc.h"
#include"tools.h"
#include"student.h"



//运行学生系统
void student(void)
{
	debug("%s\n",__func__);
	
	//学生登陆
	int num = log_sucess();
	if( -1 != log_sucess()) 
	{
		if(0 == stu[num].root)
		{
			reset(stu[num].root,&stu[num].key);
		}
		for(;;)
		{
		
			switch(menu_stu())
			{
				case '1': seek_score_stu(); break;
      			case '2': ch_key_student(); break;
      			case '3': check_student( ); break;
      			case '4': return;
      			default : 
      			printf("命令有误请重新输入\n");
      			return;
			}
		}
	}
}
