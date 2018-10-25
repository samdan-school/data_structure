#include <iostream>
#include <vector>

bool put_in(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n);
void insert_into_stack(std::vector<std::vector<int>> &Stack, int row, int col);
bool check_horizontal(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n);
bool check_vertical(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n);

main() {
    // Board size
    int n = 4;

    // Stack
    std::vector<std::vector<int>> Stack;
    Stack.reserve(n);
    for (auto &it : Stack)
        it.resize(2);

    std::vector<int> a;
    a.push_back(0);
    a.push_back(0);
    Stack.push_back(a);

    // Board
    std::vector<std::vector<int>> Board(n);
    for (auto &it : Board)
        it.resize(n);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n + 1; col++) {
            // if (col == n + 1) {
            //     if ( Stack.size() <= 1 ) {
            //         return 0;
            //     } else {
            //         Board[Stack[Stack.size() - 1][0]][Stack[Stack.size() - 1][1]] = 0;
            //         row = Stack[Stack.size() - 1][0];
            //         col = Stack[Stack.size() - 1][1];
            //         continue;
            //     }
            // }
            
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
    if (check_horizontal(Board, Stack, row, col, n) && check_vertical(Board, Stack, row, col, n)) {
        return false;
    }
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

bool check_horizontal(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n) {
    for (auto &s : Stack) {
        if (s[0] == row)
            return true;
    }
    return false;
}

bool check_vertical(std::vector<std::vector<int>> &Board, std::vector<std::vector<int>> &Stack, int row, int col, int n) {
    for (auto &s : Stack) {
        std::cout << s[1] << std::endl;
        std::cout << col << std::endl;
        if (s[1] == col)
            return true;
    }
    return false;
}