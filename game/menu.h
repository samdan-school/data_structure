#ifndef MENU_H
#define MENU_H

#include "menu.cpp"
#include "o_x.h"
#include "o_x_constant.h"

void draw_menu();
void render_string(const float color[], GLdouble x, GLdouble y, const std::string &string);

#endif
