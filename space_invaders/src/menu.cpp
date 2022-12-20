#include <stdio.h>
#include <stdlib.h>
#include "include/main.h"
#include "include/tools.h"
#include "include/conio.h"

const int numofop=2;
char options1[numofop][10]= {">START","start"};
char options2[numofop][10]= {"exit",">EXIT"};
int optionindex=0;





void draw_menu()
{	
	clear();
	printf("   _____      _                _       _ _              _____      _                  _               \n");
	printf("  |_   _|    | |              | |     | | |            |_   _|    | |                | |              \n");
	printf("    | | _ __ | |_ ___ _ __ ___| |_ ___| | | __ _ _ __    | | _ __ | |_ _ __ _   _  __| | ___ _ __ ___ \n");
	printf("    | || '_ \\| __/ _ \\ '__/ __| __/ _ \\ | |/ _` | '__|   | || '_ \\| __| '__| | | |/ _` |/ _ \\ '__/ __|\n");
	printf("   _| || | | | ||  __/ |  \\__ \\ ||  __/ | | (_| | |     _| || | | | |_| |  | |_| | (_| |  __/ |  \\__ \\\n");
	printf("   \\___/_| |_|\\__\\___|_|  |___/\\__\\___|_|_|\\__,_|_|     \\___/_| |_|\\__|_|   \\__,_|\\__,_|\\___|_|  |___/\n");
	printf("()=====================================================================================================()\n\n");
	printf("%s\n",options1[optionindex]);
	printf("%s\n",options2[optionindex]);
}

void menu()
{	
	menuflag=1;
	draw_menu();
	int i=0;
	while(i==0)
	{
		if(_kbhit())	
		{	
			read_key_input();
			switch(KEY_PRESS)
			{
				case 701:
					if(optionindex>0)
						optionindex = optionindex-1;
				break;	
				case 702:	
					if(optionindex<numofop-1)
						optionindex +=1;
				break;
				case 10:
				/*enter key and what option is selected*/
					switch(optionindex)
					{
						case 0:
						main();
						return;
						break;
						case 1:
						/*exit*/
						clear();
						printf("Thank you for playing! :D\n");
						exit(0);
						break;
					}	
				break;
			}		
			draw_menu();
		}
	}
}
