#include <GL/glut.h>
#include <iostream>
using namespace std;

// Board Constants
#define BOARD_WIDTH 800
#define BOARD_HEIGHT 800
#define LINE_NUMBER 20

// show witch user should put
int user_turn = 1;

int board_array[LINE_NUMBER][LINE_NUMBER];

void display();
void resize();
void mouse(int button, int state, int x, int y);
void draw_board();
void draw_line_horizontal(int y);
void draw_line_vertex(int x);
void click_on_draw(int x, int y);
int find_row(int x);
int find_column(int y);

void resize(int w, int h)
{
    w = BOARD_WIDTH;
    h = BOARD_HEIGHT;
	glMatrixMode   (GL_PROJECTION);
	glLoadIdentity ();

   	glViewport     (0, 0, w, h);

	gluOrtho2D     (0, w, 0, h);

	glMatrixMode   (GL_MODELVIEW);
    glLoadIdentity();       
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    draw_board();
}

void draw_board()
{
    glLineWidth(1);
    glColor3f(0.0f, 0.0f, 0.0f);

    for (int i = 0; i < LINE_NUMBER; i++)
    {
        for (int j = 0; j < LINE_NUMBER; j++)
            board_array[i][j] = 0;
    }

    for (int y = 0; y <= BOARD_HEIGHT; y += ( BOARD_HEIGHT / LINE_NUMBER ) )
        draw_line_horizontal(y);

    for (int x = 0; x <= BOARD_WIDTH; x += ( BOARD_WIDTH / LINE_NUMBER ) )
        draw_line_vertex(x);
}

void draw_line_horizontal(int y)
{
    glBegin(GL_LINES);
    glVertex2f(0, y);
    glVertex2f(BOARD_WIDTH, y);
    glEnd();
    glFlush();
}

void draw_line_vertex(int x)
{
    glBegin(GL_LINES);
    glVertex2f(x, 0);
    glVertex2f(x, BOARD_HEIGHT);
    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        click_on_draw(x, y);
    }
}

void click_on_draw(int x, int y)
{
    int row = find_row(x);
    int column = find_column(y);

    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
	
	if (user_turn == 1)
    {
        board_array[column][row] = user_turn;
        user_turn = 2;
    } else {
        board_array[column][row] = user_turn;
        user_turn = 1;
    }
        cout << "************" << endl;
    for (int i = 0; i < LINE_NUMBER; i++)
    {
        for (int j = 0; j < LINE_NUMBER; j++)
            cout << board_array[i][j] << ", ";
        cout << endl;
    }
}

int find_row(int x)
{
    return x / (BOARD_WIDTH / LINE_NUMBER);
}

int find_column(int y)
{
    return y / (BOARD_WIDTH / LINE_NUMBER);
}
