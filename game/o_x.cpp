#include "./o_x.h"
#include "o_x_constant.h"
#include "texture.cpp"

void setup() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    texture_menu_bg = LoadBitmap("./texture/o_x.bmp");
};

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(BOARD_WIDTH, BOARD_HEIGHT);
    glutInitWindowPosition(700, 0);
    glutCreateWindow("O X");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    //   glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    setup();
    glutMainLoop();
    return 0;
}
