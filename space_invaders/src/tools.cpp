#include <stdio.h>
#include <stdlib.h>
#include "include/tools.h"
#include "include/conio.h"

const int UP =701;
const int DOWN= 702;
const int LEFT =703;
const int RIGHT =704;

void test()
{
	printf("test\n");
	sleep(1);
}

void clear()
{
	system("clear");
}

int KEY_PRESS;
void read_key_input()
{
	int t;	
	t=getch();
	switch(t)
	{
		case'':
			t=getch();
			t=getch();
			switch(t)
			{
				case 'A':
				KEY_PRESS=UP;
				break;
				case 'B':
				KEY_PRESS=DOWN;
				break;
				case 'C':
				KEY_PRESS=RIGHT;
				break;
				case 'D':
				KEY_PRESS=LEFT;
				break;
			}
		break;
	case 32:
		KEY_PRESS=t;
	break;
	case 10:
		KEY_PRESS=t;
	break;
	}
}
