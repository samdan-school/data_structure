#include "./o_x.h"

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                                                 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );                                                 
    glutInitWindowSize(BOARD_WIDTH, BOARD_HEIGHT);                                      
    glutInitWindowPosition(700, 0);
    glutCreateWindow("O X");                                                                      

    glutDisplayFunc(display);

    glutReshapeFunc(resize);
//   glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
