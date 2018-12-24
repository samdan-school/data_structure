#ifndef MENU_H
#define MENU_H

#include "menu.cpp"
#include "o_x.h"
#include "o_x_constant.h"

void draw_menu();
void draw_help();
void draw_option();
void draw_win(int user);
void make_it_rain(int user);
void render_string(const float color[], GLdouble x, GLdouble y, const std::string &string);

#endif
