#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/draw.h"


void draw_grid(Map *map)
{
	int maxrow_size = map->x;
	int maxcol_size = map->y;
	
	for(int row =0; row<maxcol_size; row++)
	{
		for(int col=0; col<maxrow_size; col++)
			{
				int square = row *maxrow_size + col;
				printf("%c",map->array[square]);
			}
		printf("\n");
	}
}


void init_empty_square(Map *map)
{
	int maxrow_size = map->x;
	int maxcol_size = map->y;
	int size = map->x * map->y;

	char *array;
	map->array = (char*)malloc(size * sizeof(char));

	for(int row =0; row<maxcol_size; row++)
	{
		for(int col=0; col<maxrow_size; col++)
			{
				if(row==0 || row == maxcol_size -1)
				{
					int square = row *maxrow_size + col;
					map->array[square]= 'o';	
				}
				else if(col==0 || col == maxrow_size -1)
				{
					int square = row * maxrow_size + col;
					map->array[square]= 'o';	
				}		
				else	
				{
					int square = row *maxrow_size + col;
					map->array[square]= ' ';	
				}
			}
	}

}


void init_grid(Map *map)
{
	int size = map->x * map->y;
	char *array;
	map->array = (char*)malloc(size * sizeof(char));
	int i;
	for(i=0; i<size ;i++)
		{
			map->array[i]= 'o';	
		}
}


void draw_entity(Entity *square, Map *map)
{
	int offset= map->x - square->x;
	int start= square->start;
	int rowlen= square->x;
	int collen= square->y;	
	
	for(int row=0; row<collen; row++)
	{
		for(int col=0; col<rowlen; col++)
		{
			map->array[start] = '*';
			start ++;
		}	
	start += offset;
	}					
}


void init_colshape(Colshape *shape,Map *map)
{
	int offset= map->x - shape->x;
	int start=shape->start;
	int rowlen= shape->x;
	int collen= shape->y;	
	int i=0;
	int size = shape->x * shape->y;
	shape->array = (int*)malloc(size * sizeof(int));

	for(int row=0; row<collen; row++)
	{
		for(int col=0; col<rowlen; col++)
		{
			shape->array[i] = start;
			start++;
			i++;
		}	
	start += offset;
	}					
}


int is_touching(Colshape *shape1, Colshape *shape2)
{
	int len=shape1->x*shape1->y;
	int len2=shape2->x*shape2->y;

	for(int i=0;i<len; i++)
	{			
		for(int k=0;k<len2; k++)
		{
			if(shape1->array[i]==shape2->array[k])
				return 1;
		}
	}
	return 0;
}
