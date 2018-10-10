#ifndef O_X_H
#define O_X_H

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
bool check_position(int x, int y);
bool check_win(int column, int row);
int count_horizontal(int column, int row);
int count_count_vertical(int column, int row);
int count_left_to_right_diagnal(int column, int row);
int count_right_to_left_diagnal(int column, int row);

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

    cout << check_position(column, row) << endl;
	
    if (check_position(column, row) != 1)
    {
        if (user_turn == 1)
        {
            board_array[column][row] = user_turn;
            user_turn = 2;
        } else {
            board_array[column][row] = user_turn;
            user_turn = 1;
        }
        check_win(column, row);
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

bool check_position(int column, int row)
{
    if (board_array[column][row] != 0)
    {
        return 1;
    } else {
        return 0;
    }
}

bool check_win(int column, int row)
{
    if (count_right_to_left_diagnal(column, row) == 5 || count_left_to_right_diagnal(column, row) == 5 || count_horizontal(column, row) == 5 || count_count_vertical(column, row) == 5)
    {
        cout << "WIN" << endl;
        return 1;
    }

    return 0;
}

int count_horizontal(int column, int row)
{
    int play_number = board_array[column][row];
    int count = 0;
    int start_row = 0;
    
    start_row = ( row - 5 < 0 ) ? 0 : (row - 5);
    int end_row = ( row + 5  < LINE_NUMBER) ? ( row + 5 ) : LINE_NUMBER; 

    for(int i = start_row; i < end_row; i++)
    {
        if (count == 5)
        {
            break;
        }

        if (board_array[column][i] == play_number)
        {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

int count_count_vertical(int column, int row)
{
    int play_number = board_array[column][row];
    int count = 0;
    int start_column = 0;
    
    start_column = ( column - 5 < 0 ) ? 0 : (column - 5);
    int end_column = ( column + 5  < LINE_NUMBER) ? ( column + 5 ) : LINE_NUMBER; 

    for(int i = start_column; i < end_column; i++)
    {
        if (count == 5)
        {
            break;
        }

        if (board_array[i][row] == play_number)
        {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

int count_left_to_right_diagnal(int column, int row)
{
    int play_number = board_array[column][row];
    int count = 0;
    int i = 0;
    int max_of_two;
    int end_point;

    while (column > 0 && row > 0 && i < 5)
    {
        column--;
        row--;
        i++;
    }

    max_of_two = column > row ? column : row;
    end_point = (max_of_two + 5 < LINE_NUMBER) ? max_of_two + 5 : LINE_NUMBER;    

    for (int i = 0; i < end_point; i++)
    {
        if (count == 5)
        {
            break;
        }

        if (board_array[column + i][row + i] == play_number)
        {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}


int count_right_to_left_diagnal(int column, int row)
{
    int play_number = board_array[column][row];
    int count = 0;
    int i = 0;
    int max_of_two;
    int end_point;

    while (column < LINE_NUMBER && row > 0 && i < 5)
    {
        column++;
        row--;
        i++;
    }

    max_of_two = column > row ? column : row;
    end_point = (max_of_two + 5 < LINE_NUMBER) ? max_of_two + 5 : LINE_NUMBER;    

    for (int i = 0; i < end_point; i++)
    {
        if (count == 5)
        {
            break;
        }

        if (board_array[column - i][row + i] == play_number)
        {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

#endif
