#ifndef O_X_H
#define O_X_H

#include <irrKlang.h>
#include "menu.h"
#include "o_x_constant.h"

#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

// show witch user should put
int user_turn = 1;

bool return_game = false;

int board_array[LINE_NUMBER][LINE_NUMBER];
int ani_column = 5;
int ani_row = 14;

void display();
void resize();
void mouse(int button, int state, int x, int y);
void draw_board();
void draw_line_horizontal(int y);
void draw_line_vertex(int x);
void draw_circle(int column, int row);
void draw_cross(int column, int row);
void click_on_draw(int x, int y);
int find_row(int x);
int find_column(int y);
bool check_position(int x, int y);
bool check_win(int column, int row);
int count_horizontal(int column, int row);
int count_count_vertical(int column, int row);
int count_left_to_right_diagnal(int column, int row);
int count_right_to_left_diagnal(int column, int row);

void keyboard(unsigned char key, int x, int y);

// Animation
bool animation_check_position(int column, int row);

void start_game(int value);
void render_string(const float color[], GLdouble x, GLdouble y, const std::string& string);

void resize(int w, int h) {
    w = BOARD_WIDTH;
    h = BOARD_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluOrtho2D(0, w, 0, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    switch (game_state) {
        case 0:
            // engine->stopAllSounds();
            engine->play2D(SOUND_BATTLE, true);
            draw_board();
            break;
        case 1:
            engine->stopAllSounds();
            engine->play2D(SOUND_INTRO, true);
            draw_menu();
            break;
        case 2:
            engine->stopAllSounds();
            draw_help();
            break;
        case 3:
            engine->stopAllSounds();
            draw_option();
            break;
        case 4:
            engine->stopAllSounds();
            engine->play2D(SOUND_WIN, false);
            draw_win((user_turn == 1) ? 2 : 1);
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (game_state == 0) {
        switch (key) {
            case 'o':
                game_state = 3;
                glutPostRedisplay();
                break;
            default:
                break;
        }
    }
}

void draw_board() {
    if (!return_game) {
        for (int i = 0; i < LINE_NUMBER; i++) {
            for (int j = 0; j < LINE_NUMBER; j++)
                board_array[i][j] = 0;
        }
    } else {
        return_game = false;
        for (int row = 0; row < LINE_NUMBER; row++) {
            for (int col = 0; col < LINE_NUMBER; col++) {
                if (board_array[row][col] == 1) {
                    draw_circle(row, col);
                }

                if (board_array[row][col] == 2) {
                    draw_cross(row, col);
                }
            }
        }
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLineWidth(1);
    glColor3f(0.0f, 0.0f, 0.0f);

    for (int y = 0; y <= BOARD_HEIGHT; y += (BOARD_HEIGHT / LINE_NUMBER))
        draw_line_horizontal(y);

    for (int x = 0; x <= BOARD_WIDTH; x += (BOARD_WIDTH / LINE_NUMBER))
        draw_line_vertex(x);
    glutSwapBuffers();
}

void draw_line_horizontal(int y) {
    glBegin(GL_LINES);
    glVertex2f(0, y);
    glVertex2f(BOARD_WIDTH, y);
    glEnd();
}

void draw_line_vertex(int x) {
    glBegin(GL_LINES);
    glVertex2f(x, 0);
    glVertex2f(x, BOARD_HEIGHT);
    glEnd();
    // glutSwapBuffers();
}

void start_game(int value) {
    game_state = 0;
    glutPostRedisplay();
    return;
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (game_state == 0) {
            click_on_draw(x, y);
        }
        if (game_state == 1) {
            if ((x >= POSITION_X_GAME_START && x <= POSITION_X_GAME_START + 210) && (y >= BOARD_HEIGHT - POSITION_Y_GAME_START - 30 && y <= BOARD_HEIGHT - POSITION_Y_GAME_START)) {
                // cout << x << " " << y << endl;
                game_state = 2;
                glutPostRedisplay();
                glutTimerFunc(1000, start_game, 1);
            }

            if ((x >= POSITION_X_GAME_EXIT && x <= POSITION_X_GAME_EXIT + 195) && (y >= BOARD_HEIGHT - POSITION_Y_GAME_EXIT - 30 && y <= BOARD_HEIGHT - POSITION_Y_GAME_EXIT)) {
                // cout << x << " " << y << endl;
                engine->drop();
                exit(EXIT_SUCCESS);
            }
        }
        if (game_state == 3) {
            if ((x >= POSITION_X_OPTION_RETURN && x <= POSITION_X_OPTION_RETURN + 120) && (y >= BOARD_HEIGHT - POSITION_Y_OPTION_RETURN - 30 && y <= BOARD_HEIGHT - POSITION_Y_OPTION_RETURN)) {
                return_game = true;
                game_state = 0;
                glutPostRedisplay();
            }
            if ((x >= POSITION_X_OPTION_RESTART && x <= POSITION_X_OPTION_RESTART + 125) && (y >= BOARD_HEIGHT - POSITION_Y_OPTION_RESTART - 30 && y <= BOARD_HEIGHT - POSITION_Y_OPTION_RESTART)) {
                game_state = 0;
                glutPostRedisplay();
            }
            if ((x >= POSITION_X_OPTION_EXIT && x <= POSITION_X_OPTION_EXIT + 70) && (y >= BOARD_HEIGHT - POSITION_Y_OPTION_EXIT - 30 && y <= BOARD_HEIGHT - POSITION_Y_OPTION_EXIT)) {
                game_state = 1;
                glutPostRedisplay();
            }
        }
    }
}

void animation_menu(int value) {
    if (game_state == 1) {
        if (user_turn == 1) {
            animation_array[ani_column][ani_row] = user_turn;
            draw_circle(ani_column, ani_row);
            user_turn = 2;
        } else {
            animation_array[ani_column][ani_row] = user_turn;
            draw_cross(ani_column, ani_row);
            user_turn = 1;
        }

        ani_column = rand() % ANIMATION_HEIGHT_LINE;
        ani_row = rand() % LINE_NUMBER;
    }
    glutTimerFunc(1000, animation_menu, 1);
}

void draw_circle(int column, int row) {
    int const cell_width = BOARD_WIDTH / LINE_NUMBER;
    int radius = (BOARD_WIDTH / LINE_NUMBER) / 2 - 3;
    double degree;

    glColor3f(0.913, 0.117, 0.384);
    glBegin(GL_POLYGON);
    for (int circle_point = 0; circle_point < 360; circle_point++) {
        degree = circle_point * M_PI / 180;
        glVertex2f(radius * cos(degree) + cell_width * row + cell_width / 2, radius * sin(degree) + (BOARD_HEIGHT - cell_width * column - cell_width / 2));
    }
    glEnd();
    glutSwapBuffers();
};

void draw_cross(int column, int row) {
    int const cell_width = BOARD_WIDTH / LINE_NUMBER;

    glColor3f(0.129, 0.584, 0.952);
    glLineWidth(5);
    glBegin(GL_LINES);
    // Draw left to rihgt line
    glVertex2f(row * cell_width + (5), BOARD_WIDTH - (column * cell_width + 5));
    glVertex2f(row * cell_width + (cell_width - 5), BOARD_WIDTH - (column * cell_width + cell_width - 5));

    // Draw rihgt to left line
    glVertex2f(row * cell_width + (cell_width - 5), BOARD_WIDTH - (column * cell_width + 5));
    glVertex2f(row * cell_width + (5), BOARD_WIDTH - (column * cell_width + cell_width - 5));

    glEnd();
    glutSwapBuffers();
};

void click_on_draw(int x, int y) {
    int row = find_row(x);
    int column = find_column(y);

    if (check_position(column, row) != 1) {
        if (user_turn == 1) {
            board_array[column][row] = user_turn;
            draw_circle(column, row);
            user_turn = 2;
        } else {
            board_array[column][row] = user_turn;
            draw_cross(column, row);
            user_turn = 1;
        }
        check_win(column, row);
    }
}

int find_row(int x) {
    return x / (BOARD_WIDTH / LINE_NUMBER);
}

int find_column(int y) {
    return y / (BOARD_WIDTH / LINE_NUMBER);
}

bool check_position(int column, int row) {
    if (board_array[column][row] != 0) {
        return 1;
    } else {
        return 0;
    }
}

bool animation_check_position(int column, int row) {
    if (animation_array[column][row] != 0) {
        return 1;
    } else {
        return 0;
    }
}

bool check_win(int column, int row) {
    if (count_right_to_left_diagnal(column, row) == 5 || count_left_to_right_diagnal(column, row) == 5 || count_horizontal(column, row) == 5 || count_count_vertical(column, row) == 5) {
        game_state = 4;
        glutPostRedisplay();
        return 1;
    }

    return 0;
}

int count_horizontal(int column, int row) {
    int play_number = board_array[column][row];
    int count = 0;
    int start_row = 0;

    start_row = (row - 5 < 0) ? 0 : (row - 5);
    int end_row = (row + 5 < LINE_NUMBER) ? (row + 5) : LINE_NUMBER;

    for (int i = start_row; i < end_row; i++) {
        if (count == 5) {
            break;
        }

        if (board_array[column][i] == play_number) {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

int count_count_vertical(int column, int row) {
    int play_number = board_array[column][row];
    int count = 0;
    int start_column = 0;

    start_column = (column - 5 < 0) ? 0 : (column - 5);
    int end_column = (column + 5 < LINE_NUMBER) ? (column + 5) : LINE_NUMBER;

    for (int i = start_column; i < end_column; i++) {
        if (count == 5) {
            break;
        }

        if (board_array[i][row] == play_number) {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

int count_left_to_right_diagnal(int column, int row) {
    int play_number = board_array[column][row];
    int count = 0;
    int i = 0;
    int max_of_two;
    int end_point;

    while (column > 0 && row > 0 && i < 5) {
        column--;
        row--;
        i++;
    }

    max_of_two = column > row ? column : row;
    end_point = (max_of_two + 5 < LINE_NUMBER) ? max_of_two + 5 : LINE_NUMBER;

    for (int i = 0; i < end_point; i++) {
        if (count == 5) {
            break;
        }

        if (board_array[column + i][row + i] == play_number) {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

int count_right_to_left_diagnal(int column, int row) {
    int play_number = board_array[column][row];
    int count = 0;
    int i = 0;
    int max_of_two;
    int end_point;

    while (column < LINE_NUMBER && row > 0 && i < 5) {
        column++;
        row--;
        i++;
    }

    max_of_two = column > row ? column : row;
    end_point = (max_of_two + 5 < LINE_NUMBER) ? max_of_two + 5 : LINE_NUMBER;

    for (int i = 0; i < end_point; i++) {
        if (count == 5) {
            break;
        }

        if (board_array[column - i][row + i] == play_number) {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

#endif