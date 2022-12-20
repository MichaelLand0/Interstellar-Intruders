#ifndef draw_h
#define draw_h


typedef struct map{
	char *array;
 	int y;
 	int x;
}Map;


typedef struct entity{
	int start;
	int y=5;
	int x=5;
	int is_alive=0;
}Entity;


typedef struct collision{
int start;
int y=5;
int x=5;
int *array;

}Colshape;


//rendering map
void init_grid(Map * map);
void draw_grid(Map * map);
void init_empty_square(Map *map);


//drawing to map
void draw_entity(Entity *square, Map *map);


//colision detection
void init_colshape(Colshape *shape,Map *map);
int is_touching(Colshape *shape1, Colshape *shape2);


#endif
