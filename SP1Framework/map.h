#ifndef _MAP_H
#define _MAP_H
#include "game.h"

void menu();
void help();
void sidemenu();
void level1();
void level2();
void level3();
void level4();
void level5();
void level6();
void level7();
void level8();
void level9();
void level10();
void level11();
void level12();
void level13();
void level14();
void level15();
void lose();
void levelskip(COORD *charLocation , COORD *charLocation2);
void levelPreloader();
void levelloader(int a);
void levelloader(char a, char b);
void levelselect(char a, char b);
#endif