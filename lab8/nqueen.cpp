#include <iostream>
#include <vector>

bool put_in(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n);
void insert_into_stack(std::vector<std::vector<int>> &Stack, int row, int col);
bool check_horizontal(std::vector<std::vector<int>> &Stack, int row);
bool check_vertical(std::vector<std::vector<int>> &Stack, int col);
bool check_diagonal_left_to_right(std::vector<std::vector<int>> &Stack, int row, int col, int n);
bool check_diagonal_right_to_left(std::vector<std::vector<int>> &Stack, int row, int col, int n);
void print_board(std::vector<std::vector<int>> &Board);
void print_stack(std::vector<std::vector<int>> &Stack);
void reset_board(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack);
void reset_stack(std::vector<std::vector<int>> &Stack, int &row, int &col, int n);

main() {
    // Board size
    int n = 10;
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
            if (check_horizontal(Stack, row)) {
                continue;
            }

            if (check_vertical(Stack, col)) {
                continue;
            }

            if (check_diagonal_left_to_right(Stack, row, col, n)) {
                continue;
            }

            if (check_diagonal_right_to_left(Stack, row, col, n)) {
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

bool put_in(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n) {
    if (Board[row][col] == 0) {
        Board[row][col] = 1;
        insert_into_stack(Stack, row, col);
        return true;
    } else
        return false;
}

void insert_into_stack(std::vector<std::vector<int>> &Stack, int row, int col) {
    std::vector<int> position;
    position.reserve(2);
    position.push_back(row);
    position.push_back(col);
    Stack.push_back(position);
}

bool check_horizontal(std::vector<std::vector<int>> &Stack, int row) {
    for (auto &s : Stack) {
        if (s[0] == row)
            return true;
    }
    return false;
}

bool check_vertical(std::vector<std::vector<int>> &Stack, int col) {
    for (auto &s : Stack) {
        if (s[1] == col)
            return true;
    }
    return false;
}

bool check_diagonal_left_to_right(std::vector<std::vector<int>> &Stack, int row, int col, int n) {
    int c_row = row, c_col = col;
    while (c_row >= 0 && c_col >= 0) {
        for (auto &s : Stack) {
            if (s[0] == c_row && s[1] == c_col)
                return true;
        }
        c_row--;
        c_col--;
    }

    c_row = row;
    c_col = col;
    while (c_row <= n && c_col <= n) {
        for (auto &s : Stack) {
            if (s[0] == c_row && s[1] == c_col)
                return true;
        }
        c_row++;
        c_col++;
    }
    return false;
}

bool check_diagonal_right_to_left(std::vector<std::vector<int>> &Stack, int row, int col, int n) {
    int c_row = row, c_col = col;
    while (c_row <= n && c_col >= 0) {
        for (auto &s : Stack) {
            if (s[0] == c_row && s[1] == c_col)
                return true;
        }
        c_row++;
        c_col--;
    }

    c_row = row;
    c_col = col;
    while (c_row >= 0 && c_col <= n) {
        for (auto &s : Stack) {
            if (s[0] == c_row && s[1] == c_col)
                return true;
        }
        c_row--;
        c_col++;
    }
    return false;
}

void print_board(std::vector<std::vector<int>> &Board) {
    // Print Board
    for (auto &it : Board) {
        for (auto &val : it) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
}
void print_stack(std::vector<std::vector<int>> &Stack) {
    for (auto &it : Stack) {
        for (auto &val : it) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
}

void reset_stack(std::vector<std::vector<int>> &Stack, int &row, int &col, int n) {
    col = Stack[Stack.size() - 1][1];
    Stack.pop_back();
}

void reset_board(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack) {
    Board[Stack[Stack.size() - 1][0]][Stack[Stack.size() - 1][1]] = 0;
}