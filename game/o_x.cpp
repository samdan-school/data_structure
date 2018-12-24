#include "./o_x.h"
#include <irrKlang.h>
#include "o_x_constant.h"
#include "texture.cpp"

void setup() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    texture_menu_bg = LoadBitmap("./texture/o_x.bmp");
    texture_option1_bg = LoadBitmap("./texture/option1.bmp");
    texture_option2_bg = LoadBitmap("./texture/option2.bmp");
    texture_win_circle = LoadBitmap("./texture/circle_win.bmp");
    texture_win_cross = LoadBitmap("./texture/cross_win.bmp");

    // Animation array initialize
    for (int row = 0; row < ANIMATION_HEIGHT_LINE; row++) {
        for (int column = 0; column < ANIMATION_HEIGHT_LINE; column++) {
            animation_array[row][column] = 0;
        }
    }
};

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(BOARD_WIDTH, BOARD_HEIGHT);
    glutInitWindowPosition(700, 0);
    glutCreateWindow("O X");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    setup();
    glutTimerFunc(1000, animation_menu, 1);
    glutMainLoop();

    engine->drop();

    return 0;
}
