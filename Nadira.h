#ifndef Rasya_H
#define Rasya_H
#include <windows.h>
#include <graphics.h>


void matrix();
void matrix2();
void isiMain();

typedef struct{
	int map[18][33]=
	{ 
	{1,6,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,1},
	{1,6,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,1},
	{1,6,0,0,5, 0,0,0,0,0, 0,0,0,3,4, 4,4,4,4,4, 4,4,3,0,3, 1,1,1,1,1, 1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 3,1,1,1,1, 0,0,0,0,0, 0,1,1,1,3, 0,0,0,0,0, 0,0,1},
	{1,0,0,0,0, 0,0,0,0,0, 3,0,0,0,0, 0,0,0,0,0, 0,0,0,0,3, 0,5,0,0,0, 0,0,1},
		
	{1,0,0,0,0, 0,0,0,0,0, 3,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 1,1,1,3,1, 1,1,1},
	{1,0,0,0,0, 0,0,0,0,0, 3,0,0,0,0, 0,0,1,3,0, 0,0,0,0,0, 0,0,0,3,0, 0,0,1},
	{1,0,0,0,0, 0,0,0,0,0, 3,0,0,0,0, 0,0,1,3,0, 0,0,0,0,0, 0,5,0,3,0, 0,0,1},
	{1,1,7,7,1, 1,1,3,1,1, 1,1,0,0,0, 0,0,1,1,1, 3,1,1,1,1, 1,1,1,1,1, 1,1,1},
	{1,0,0,0,0, 0,0,3,0,0, 0,0,0,0,0, 0,0,0,0,0, 3,0,0,0,0, 0,0,0,0,0, 0,0,1},
		
	{1,0,0,0,0, 0,0,3,0,0, 0,0,0,0,0, 0,0,0,0,0, 3,0,0,0,0, 0,0,0,0,0, 0,0,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,3,1,1, 1,1,1,1,1, 3,0,0,0,0, 0,0,0,0,0, 0,0,1},
	{1,0,0,0,0, 0,0,0,0,0, 0,0,3,0,0, 0,0,0,0,0, 3,0,0,0,0, 0,0,0,0,0, 0,0,1},
	{1,0,0,0,0, 0,8,0,0,0, 0,5,3,4,4, 4,4,4,4,4, 3,0,0,0,0, 0,5,0,0,0, 0,0,1},
	{1,0,0,0,3, 1,1,1,1,1, 1,1,1,0,0, 0,0,0,0,0, 1,1,1,1,1, 1,1,1,1,1, 1,3,1},
		
	{1,0,0,0,3, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,3,1},
	{1,0,0,0,3, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 5,0,0,0,0, 0,0,0,0,0, 0,3,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,7,7,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1},
	};
	
	int bot;
	
	int player[18][33]=
	{ 
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
		
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
		
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},	
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},	
	{0,2,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0},
	};
} game;

game test;

#endif
