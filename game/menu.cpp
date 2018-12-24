#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"
#include "o_x.h"
#include "o_x_constant.h"

#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

std::vector<float> rain_x(20);
std::vector<float> rain_y(20);

void make_it_rain(int user);

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
    // render_string(BLACK, POSITION_X_GAME_START, POSITION_Y_GAME_START, "GAME START!");
    // render_string(BLACK, POSITION_X_GAME_EXIT, POSITION_Y_GAME_EXIT, "EXIT THE GAME!");

    glutSwapBuffers();
}

void draw_help() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_option1_bg);

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
    // render_string(BLACK, 220, 275, "GAME START!");
    // render_string(BLACK, 203, 200, "EXIT THE GAME!");

    glutSwapBuffers();
}

void draw_option() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_option2_bg);

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
    // render_string(BLACK, 275, 124, "GAMe");

    glutSwapBuffers();
}

void draw_win(int user) {
    glEnable(GL_TEXTURE_2D);
    if (user == 1) {
        glBindTexture(GL_TEXTURE_2D, texture_win_circle);
    }

    if (user == 2) {
        glBindTexture(GL_TEXTURE_2D, texture_win_cross);
    }

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
    glutSwapBuffers();

    for (int i = 0; i < rain_x.size(); i++) {
        rain_x[i] = rand() % 500 + 50;
        rain_y[i] = rand() % 200 + 400;
    }

    // make_it_rain(user);
    // glutTimerFunc(100, make_it_rain, user);

    glutTimerFunc(3500, [](int value) {
        game_state = 1;
        glutPostRedisplay();
    },
                  1);
}

void make_it_rain(int user) {
    int radius = (BOARD_WIDTH / LINE_NUMBER) / 2 - 3;
    double degree;

    glColor3f(0.913, 0.117, 0.384);
    for (int i = 0; i < rain_x.size(); i++) {
        glBegin(GL_POLYGON);
        for (int circle_point = 0; circle_point < 360; circle_point++) {
            degree = circle_point * M_PI / 180;
            glVertex2f(radius * cos(degree) + rain_x[i], radius * sin(degree) + rain_y[i]);
        }
        glEnd();
        rain_y[i] -= 20;
    }
    glutSwapBuffers();
    glutTimerFunc(100, make_it_rain, user);
}

#endif
