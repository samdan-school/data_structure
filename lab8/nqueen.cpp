#include <iostream>
#include <vector>

bool put_in(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n);
void insert_into_stack(std::vector<std::vector<int>> &Stack, int row, int col);
bool check_horizontal(std::vector<std::vector<int>> &Stack, int row);
bool check_vertical(std::vector<std::vector<int>> &Stack, int col);
bool check_diagonal_left_to_right(std::vector<std::vector<int>> &Stack, int row, int col, int n);
bool check_diagonal_right_to_left(std::vector<std::vector<int>> &Stack, int row, int col, int n);

main() {
    // Board size
    int n = 4;

    // Stack
    std::vector<std::vector<int>> Stack;
    Stack.reserve(n);
    for (auto &it : Stack)
        it.resize(2);

    // std::vector<int> a;
    // a.push_back(0);
    // a.push_back(0);
    // Stack.push_back(a);

    // Board
    std::vector<std::vector<int>> Board(n);
    for (auto &it : Board)
        it.resize(n);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n + 1; col++) {
            if (col == n + 1) {
                if (Stack.size() <= 1) {
                    return 0;
                } else {
                    Board[Stack[Stack.size() - 1][0]][Stack[Stack.size() - 1][1]] = 0;
                    row = Stack[Stack.size() - 1][0];
                    col = Stack[Stack.size() - 1][1];
                    continue;
                }
            }
            if (check_horizontal(Stack, row)) {
                std::cout << "Horizontal" << std::endl;
                continue;
            }

            if (check_vertical(Stack, col)) {
                std::cout << "Vertical" << std::endl;
                continue;
            }

            if (check_diagonal_left_to_right(Stack, row, col, n)) {
                std::cout << "L to R" << std::endl;
                continue;
            }

            if (check_diagonal_right_to_left(Stack, row, col, n)) {
                std::cout << "R to L" << std::endl;
                continue;
            }

            if (put_in(Board, Stack, row, col, n)) {
                break;
            }
        }
    }

    // Print Board
    for (auto &it : Board) {
        for (auto &val : it) {
            std::cout << val;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (auto &it : Stack) {
        for (auto &val : it) {
            std::cout << val;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

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