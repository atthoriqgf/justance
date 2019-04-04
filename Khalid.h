#ifndef Khalid_h
#define Khalid_h
#include <windows.h>
#include <graphics.h>
#include "boolean.h"
#include "Bambang.h"

void move(int *k);
void move_right(int *x, int y);
void move_left(int *x,int y);
void move_upward(int x, int *y);
void move_down(int x, int *y);
void fall(int x, int *y);
void cek_jatoh();

boolean status_fall;
boolean status_rope;
boolean status_menang;

#endif
