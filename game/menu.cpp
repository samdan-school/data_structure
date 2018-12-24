#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"
#include "o_x.h"
#include "o_x_constant.h"

#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

void render_string(const float color[], GLdouble x, GLdouble y, const std::string &string) {
    glColor3fv(color);
    glRasterPos2d(x, y);
    for (int charAt = 0; charAt < string.size(); ++charAt) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[charAt]);
    }
}

void draw_menu() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_menu_bg);

    glBegin(GL_QUADS);
    glTexCoord2f(0.1, 0.1);
    glVertex2f(0, 0);

    glTexCoord2f(0.1, 1);
    glVertex2f(0, BOARD_HEIGHT);

    glTexCoord2f(1, 1);
    glVertex2f(BOARD_WIDTH, BOARD_HEIGHT);

    glTexCoord2f(1, 0.1);
    glVertex2f(BOARD_WIDTH, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    render_string(BLACK, 300, 350, "GAME START!");
    render_string(BLACK, 285, 275, "EXIT THE GAME!");

    glutSwapBuffers();
}

#endif
