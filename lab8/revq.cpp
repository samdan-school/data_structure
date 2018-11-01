#include <iostream>
#include <vector>

using board_type = std::vector<std::vector<int>>;
using stack_type = std::vector<std::vector<int>>;

bool put_in(board_type &Board, stack_type &Stack, int row, int col, int n);
void insert_into_stack(stack_type &Stack, int row, int col);
bool threatens_horizontal(const stack_type &Stack, int row);
bool threatens_vertical(const stack_type &Stack, int col);
bool threatens_diagonal_left_to_right(const stack_type &Stack, int row, int col, int n);
bool threatens_diagonal_right_to_left(const stack_type &Stack, int row, int col, int n);
void print_board(const board_type &Board);
void print_stack(const stack_type &Stack);
void reset_board(board_type &Board, stack_type &Stack);
void reset_stack(stack_type &Stack, int &row, int &col, int n);

int main() {
    // Board size
    int n = 8;
    int number_of_solution = 1;

    // Stack
    std::vector<std::vector<int>> Stack;
    Stack.reserve(n);
    for (auto &it : Stack)
        it.resize(2);

    // Board
    std::vector<std::vector<int>> Board(n);
    for (auto &it : Board)
        it.resize(n);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n + 1; col++) {
            if (col == n) {
                // ! IMPORTANT
                // * Ends when row is 0 and col is n!
                if (row == 0 && col == n) {
                    return 0;
                }
                // * End condition
                // ! IMPORTANT

                Board[Stack[Stack.size() - 1][0]][Stack[Stack.size() - 1][1]] = 0;
                row = Stack[Stack.size() - 1][0];
                col = Stack[Stack.size() - 1][1];
                Stack.pop_back();

                continue;
            }
            if (threatens_horizontal(Stack, row)) {
                continue;
            }

            if (threatens_vertical(Stack, col)) {
                continue;
            }

            if (threatens_diagonal_left_to_right(Stack, row, col, n)) {
                continue;
            }
            if (threatens_diagonal_right_to_left(Stack, row, col, n)) {
                continue;
            }

            if (put_in(Board, Stack, row, col, n)) {
                if (Stack.size() == n) {
                    std::cout << std::endl;
                    std::cout << number_of_solution++ << std::endl;
                    print_board(Board);
                    reset_board(Board, Stack);
                    reset_stack(Stack, row, col, n);
                    continue;
                }
                break;
            }
        }
    }
    print_board(Board);

    return 0;
}

bool put_in(board_type &Board, stack_type &Stack, int row, int col, int n) {
    if (Board[row][col] == 0) {
        Board[row][col] = 1;
        insert_into_stack(Stack, row, col);
        return true;
    } else
        return false;
}

void insert_into_stack(stack_type &Stack, int row, int col) {
    // std::vector<int> position;
    // position.reserve(2);
    // position.push_back(row);
    // position.push_back(col);
    // Stack.push_back(position);

    // to use std::initializer_list
    // const std::vector<int> position = {row, col};
    // Stack.push_back(position);

    // Better way
    Stack.emplace_back(std::initializer_list<int>{row, col});
}

bool threatens_horizontal(const stack_type &Stack, int row) {
    for (auto &Queen : Stack) {
        if (Queen[0] == row)
            return true;
    }
    return false;
}

bool threatens_vertical(const stack_type &Stack, int col) {
    for (auto &Queen : Stack) {
        if (Queen[1] == col)
            return true;
    }
    return false;
}

bool threatens_diagonal_left_to_right(const stack_type &Stack, int row, int col, int n) {
    int c_row = row, c_col = col;
    while (c_row >= 0 && c_col >= 0) {
        for (auto &Queen : Stack) {
            if (Queen[0] == c_row && Queen[1] == c_col)
                return true;
        }
        c_row--;
        c_col--;
    }

    c_row = row;
    c_col = col;
    while (c_row <= n && c_col <= n) {
        for (auto &Queen : Stack) {
            if (Queen[0] == c_row && Queen[1] == c_col)
                return true;
        }
        c_row++;
        c_col++;
    }
    return false;
}

bool threatens_diagonal_right_to_left(const stack_type &Stack, int row, int col, int n) {
    int c_row = row, c_col = col;
    while (c_row <= n && c_col >= 0) {
        for (auto &Queen : Stack) {
            if (Queen[0] == c_row && Queen[1] == c_col)
                return true;
        }
        c_row++;
        c_col--;
    }

    c_row = row;
    c_col = col;
    while (c_row >= 0 && c_col <= n) {
        for (auto &Queen : Stack) {
            if (Queen[0] == c_row && Queen[1] == c_col)
                return true;
        }
        c_row--;
        c_col++;
    }
    return false;
}

void print_board(const board_type &Board) {
    // Print Board
    for (auto &row : Board) {
        for (auto &val : row) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
}
void print_stack(const stack_type &Stack) {
    for (auto &row : Stack) {
        for (auto &val : row) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
}

void reset_stack(stack_type &Stack, int &row, int &col, int n) {
    col = Stack[Stack.size() - 1][1];
    Stack.pop_back();
}

void reset_board(board_type &Board, stack_type &Stack) {
    Board[Stack[Stack.size() - 1][0]][Stack[Stack.size() - 1][1]] = 0;
}