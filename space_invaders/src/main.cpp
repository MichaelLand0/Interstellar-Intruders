#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/time.h>
#include "include/main.h"
#include "include/menu.h"
#include "include/draw.h"
#include "include/tools.h"
#include "include/conio.h"


int menuflag =0;


void lose()
{
	clear();
	int jd=1;
	printf("YOU ARE A COMPLETE LOSER! \npress enter to return to main menu");
	while(jd==1)
	{
		read_key_input();	
		if(KEY_PRESS==10)
		menu();
	}
}


int main()
{
	int offset =0;
	if (menuflag==0)
		menu();

	Map level_1;
	level_1.x=120;
	level_1.y=40;
	
	// spawing Entitys, seting values & configuiring colision shapes
	//create map
	Entity box;
	box.start= offset +10;
	Colshape shape1;
	shape1.start=box.start;
	
	Entity box2;
	box2.start =offset + 20;
	Colshape shape2;
	shape2.start=box2.start;
	
	Entity box3;
	box3.start = offset + 0;
	Colshape shape3;
	shape3.start=box3.start;
	
	Entity box4;
	box4.start= offset +30;
	Colshape shape4;
	shape4.start=box4.start;
	
	Entity box5;
	box5.start= offset + 40;
	Colshape shape5;
	shape5.start=box5.start;
	
	Entity box6;
	box6.start= offset + 50;
	Colshape shape6;
	shape6.start=box6.start;
	
	Entity box7;
	box7.start= offset + 60;
	Colshape shape7;
	shape7.start=box7.start;
	
	Entity box8;
	box8.start= offset + 70;
	Colshape shape8;
	shape8.start=box8.start;
	
	Entity box9;
	box9.start= offset + 80;
	Colshape shape9;
	shape9.start=box9.start;
	
	Entity box10;
	box10.start= offset + 40;
	Colshape shape10;
	shape10.start=box10.start;
	
	Entity player;
	player.start=4000;
	player.x=6;
	player.y=2;
	Colshape playercol;
	playercol.start=player.start;
	playercol.x=player.x;
	playercol.y=player.y;
	
	Entity bullet;
	bullet.start=player.start -118;
	bullet.x=2;
	bullet.y=2;

	Colshape bulletcol;
	bulletcol.start=bullet.start;
	bulletcol.x=player.x;
	bulletcol.y=player.y;
				
	Colshape bottom;
	bottom.start=4680;
	bottom.x=119;
	bottom.y=1;

	Colshape top;
	top.start=0;
	top.x=119;
	top.y=1;
				
	Colshape left;
	left.start=0;
	left.x=1;
	left.y=40;
				
	Colshape right;
	right.start=119;
	right.x=1;
	right.y=40;

	int game_over=0;
	struct timeval now;
	int shot=0;
	int alien_movement=1;
	int count=0;
	int s=0;
	int loop_count =0;
	int score =0;
	int level=0;

	while(0==0)
	{
		//fps controler
		//16666 is 60fps
		//33333 is 30fps	
		gettimeofday(&now, NULL);
		if (now.tv_usec % 16666 ==0)
		{	
			init_empty_square(&level_1);
			playercol.start=player.start;
 			init_colshape(&playercol,&level_1);
			bulletcol.start=bullet.start;	
			init_colshape(&bulletcol,&level_1);
			init_colshape(&right,&level_1);
			init_colshape(&left,&level_1);
			 init_colshape(&top,&level_1);
 			init_colshape(&bottom,&level_1);

			//enemy logic
			//update enties, colisionshapes and drawing into map and check if alive: this should all be separate functions
			if(box.is_alive==0)
			{
				box.start= offset +0;
				shape1.start=box.start;
 				init_colshape(&shape1,&level_1);
				draw_entity(&box, &level_1);
				player.is_alive=is_touching(&shape1,&playercol);
			 	game_over=is_touching(&shape1,&bottom);
				if(player.is_alive==1||game_over==1) 
					lose();
				if(shot==1)
				{
					box.is_alive=is_touching(&shape1,&bulletcol);
					if(box.is_alive==1)
						bullet.is_alive=1;
				}
			}

			if(box2.is_alive==0)
			{
				box2.start= offset +10;
				shape2.start=box2.start;
 				init_colshape(&shape2,&level_1);
				draw_entity(&box2, &level_1);
				player.is_alive=is_touching(&shape2,&playercol);
				game_over=is_touching(&shape2,&bottom);
				if(player.is_alive==1||game_over==1) 
					lose();
				if(shot==1)
				{
					box2.is_alive=is_touching(&shape2,&bulletcol);
					if(box2.is_alive==1)
						bullet.is_alive=1;
				}
			}

			if(box3.is_alive==0)
			{
				box3.start= offset +20;
				shape3.start=box3.start;
 				init_colshape(&shape3,&level_1);
				draw_entity(&box3, &level_1);
				player.is_alive=is_touching(&shape3,&playercol);
			  game_over=is_touching(&shape3,&bottom);
				if(player.is_alive==1||game_over==1) 
					lose();
				if(shot==1)
				{
					box3.is_alive=is_touching(&shape3,&bulletcol);
					if(box3.is_alive==1)
					bullet.is_alive=1;
				}
			}
	
			if(box4.is_alive==0)
			{
				box4.start= offset +30;
				shape4.start=box4.start;
 				init_colshape(&shape4,&level_1);
				draw_entity(&box4, &level_1);
				player.is_alive=is_touching(&shape4,&playercol);
			  game_over=is_touching(&shape4,&bottom);
				if(player.is_alive==1||game_over==1) 
					lose();
				if(shot==1)
				{
					box4.is_alive=is_touching(&shape4,&bulletcol);
					if(box4.is_alive==1)
						bullet.is_alive=1;
				}
			}
	
			if(box5.is_alive==0)
			{
				box5.start= offset +40;
				shape5.start=box5.start;
 				init_colshape(&shape5,&level_1);
				draw_entity(&box5, &level_1);
			  player.is_alive=is_touching(&shape5,&playercol);
			  game_over=is_touching(&shape5,&bottom);
				if(player.is_alive==1||game_over==1)
					lose();
				if(shot==1)
				{
					box5.is_alive=is_touching(&shape5,&bulletcol);
					if(box5.is_alive==1)
						bullet.is_alive=1;
				}
			}

			if(box6.is_alive==0)
			{
				box6.start= offset +50;
				shape6.start=box6.start;
 				init_colshape(&shape6,&level_1);
				draw_entity(&box6, &level_1);
				player.is_alive=is_touching(&shape6,&playercol);
			  game_over=is_touching(&shape6,&bottom);
				if(player.is_alive==1||game_over==1)
					lose();
				if(shot==1)
				{
					box6.is_alive=is_touching(&shape6,&bulletcol);
					if(box6.is_alive==1)
						bullet.is_alive=1;
				}
			}
	
			if(box7.is_alive==0)
			{
				box7.start= offset +60;
				shape7.start=box7.start;
 				init_colshape(&shape7,&level_1);
				draw_entity(&box7, &level_1);
				player.is_alive=is_touching(&shape7,&playercol);
		  	game_over=is_touching(&shape7,&bottom);
				if(player.is_alive==1||game_over==1)
					lose();
				if(shot==1)
				{
					box7.is_alive=is_touching(&shape7,&bulletcol);
					if(box7.is_alive==1)
						bullet.is_alive=1;
				}
			}
	
			if(box8.is_alive==0)
			{
				box8.start= offset +70;
				shape8.start=box8.start;
 				init_colshape(&shape8,&level_1);
				draw_entity(&box8, &level_1);
				player.is_alive=is_touching(&shape8,&playercol);
			  game_over=is_touching(&shape8,&bottom);
				if(player.is_alive==1||game_over==1) 
					lose();
				if(shot==1)
				{
					box8.is_alive=is_touching(&shape8,&bulletcol);
					if(box8.is_alive==1)
					bullet.is_alive=1;
				}
			}
	
			if(box9.is_alive==0)
			{
				box9.start= offset +80;
				shape9.start=box9.start;
 				init_colshape(&shape9,&level_1);
				draw_entity(&box9, &level_1);
				player.is_alive=is_touching(&shape9,&playercol);
				game_over=is_touching(&shape9,&bottom);
				if(player.is_alive==1||game_over==1) 
					lose();
				if(shot==1)
				{
					box9.is_alive=is_touching(&shape9,&bulletcol);
					if(box9.is_alive==1)
						bullet.is_alive=1;
				}		
			}
	
			if(box10.is_alive==0)
			{
				box10.start= offset +90;
				shape10.start=box10.start;
 				init_colshape(&shape10,&level_1);
				draw_entity(&box10, &level_1);
				player.is_alive=is_touching(&shape10,&playercol);
				game_over=is_touching(&shape10,&bottom);
				if(player.is_alive==1||game_over==1)
					lose();
				if(shot==1)
				{
					box10.is_alive=is_touching(&shape10,&bulletcol);
					if(box10.is_alive==1)
						bullet.is_alive=1;
				}
			}
	
			draw_entity(&player, &level_1);



			//player movement
			int coldet;	
			if(kbhit())
			{
					read_key_input();
		 			if(KEY_PRESS == LEFT)
					{
					coldet=is_touching(&left,&playercol);
					if(coldet!=1)
						player.start -=1;
					}
					else if(KEY_PRESS == RIGHT)
					{
						coldet=is_touching(&right,&playercol);
						if(coldet!=1)
							player.start +=1;
					}
					else if(KEY_PRESS ==32)
					{
						if(shot!=1)
							shot=1;	
					}
			}
		
			int bullet_reach_end=is_touching(&top,&bulletcol);
			//bullet logic		
			if(shot==1)
			{
				if(s==0)
				{
					bullet.start=player.start -118;
 					init_colshape(&bulletcol,&level_1);
					s=1;
				}
				draw_entity(&bullet, &level_1);
				bullet.start-=120;
	
				if( bullet.is_alive==1)
				{
					bullet.is_alive=0;
					s=0;
					shot=0;
					bullet.start=player.start -118;
					score +=1;
				}
 				if(bullet_reach_end==1)
				{
					s=0;
					shot=0;
					bullet.start=player.start -118;
				}
			}


			//intruder logic

			if(loop_count % (11-score)==0)
			{
				if(count==10)
				{		
					if(alien_movement==1)
					{
						offset+=120;
						alien_movement=0;
						count=0;
					}
					else if(alien_movement==0)
					{			
						offset+=120;
						alien_movement=1;
						count=0;
					}
				}
				else if(alien_movement==1)
				{
					offset +=1;
					count++;
				}
				else if(alien_movement==0)
				{
					offset-=1;
					count++;
				}
			}

			if(score==10)
			{
				clear();
				int jd=1;
				printf("you win!!\npress enter to continue");
				while(jd==1)
				{
					read_key_input();	
					if(KEY_PRESS==10)
						menu();
				}
			}
	
			system("clear");
			printf("controles: space=fire  arrow keys to move\n");
			printf("[Score: %d]\n",score);	
			draw_grid(&level_1);
			loop_count++;
		}
	}
	return 0;
}


