#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include"teacher.h"
#include"admin.h"
#include"tools.h"

int main()
{
	debug("%s\n",__func__);
	
    init_main();
    
    printf("main:%s main:%d main:%hhd\n",adm[0].name, adm[0].key, adm[0].root);
	anykey_continue();
    //printf("系统开始运行...\n");
    for(;;)
    {
    	
        switch(menu_main())
        {
            case '1': admin_start(); break;
            case '2': teacher(); break;
            case '3': student(); break;
			case '4':  exit_main(); return 0;
            default: 
            
            	
				break;            
        }
    }
    
    //exit_main();
}
