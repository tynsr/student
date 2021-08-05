#include<stdlib.h>

#include"mfunc.h"
#include"tools.h"
#include"admin.h"


//运行管理员系统
void admin_start(void)
{
	if(!admin_login())
	{
		show_msg("登陆失败！",1.5);
		return;
	}
	while(1)
	{
		if(adm[0].root==0)
		{
			admin_change_key();
		}
		else
		{
			system("clear");
			switch(menu_admin())
			{
				case '1': admin_add_tch(); break;
				case '2': admin_del_tch(); break;
				case '3': admin_list_tch(); break;
				case '4': admin_list_untch(); break;
				case '5': admin_reset_tch(); break;
				case '6': return;			
			}
		}
	}
}








