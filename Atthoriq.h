#ifndef Atthoriq_H
#define Atthoriq_H
#include <windows.h>
#include "graphics.h"
#pragma comment(lib, "Winmm.lib")


void check_tileL(int x,int y);
void check_tileR(int x,int y);
void holeL(void *arg);
void holeR(void *arg);
void bgm();

#endif
