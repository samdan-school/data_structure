#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INFINITY ((unsigned)~0)

class node {
   public:
    int with;
    int wight;
    node(int with, int wight) {
        this->with = with;
        this->wight = wight;
    }
};
class table {
    class row {
       public:
        // known shortest path
        int nsp;
        int previous;

        row() {
            nsp = 2147483647;
            previous = -1;
        }
    };

   public:
    vector<row> info;

    table(int size) {
        this->info.reserve(size);
        for (int i = 0; i < size; ++i) {
            row temp;
            this->info.push_back(temp);
        }
    }

    void print_table() {
        if (this->info.size() <= 0)
            return;

        printf("%4s | %10s | %10s\n", "Node", "KSP", "Previous");
        for (int i = 0; i < this->info.size(); ++i) {
            printf("%4d | %10d | %10d\n", i, this->info[i].nsp, this->info[i].previous);
        }
        printf("\n");
    }
};

vector<vector<node>> graph;

int add_node() {
    vector<node> temp;
    graph.push_back(temp);
    return graph.size();
}

int add_edge(int index_one, int index_two, int wight = 1) {
    if (index_one >= graph.size() || index_one < 0 || index_two >= graph.size() || index_two < 0)
        return -1;

    if (index_one == index_two)
        return -1;

    if (wight < 1)
        return -1;

    for (const node &element : graph[index_one]) {
        if (element.with == index_two)
            return -1;
    }

    graph[index_one].push_back(node(index_two, wight));
    graph[index_two].push_back(node(index_one, wight));
    return 0;
}

void print_graph() {
    for (int i = 0; i < graph.size(); ++i) {
        cout << i << ": ";
        for (const node &element : graph[i]) {
            cout << element.with << "|" << element.wight << " => ";
        }
        cout << endl;
    }
}

void update_neighbor(int s_index, vector<int> &visited, vector<int> &unvisited, table &path) {
    if (unvisited.size() == 1) {
        return;
    } else {
        vector<node> neighbors = graph[s_index];
        int s_wight = path.info[s_index].nsp;

        for (const int &index : visited) {
            neighbors.erase(remove_if(
                                neighbors.begin(), neighbors.end(),
                                [index](const node &neighbor) {
                                    cout << index << " i " << (neighbor.with == index) << endl;
                                    return neighbor.with == index;
                                }),
                            neighbors.end());
        }

        for (const node &neighbor : neighbors) {
            int n_index = neighbor.with;
            int total_wight = s_wight + neighbor.wight;

            // cout << s_index << " -> " << n_index << " t:" << total_wight << " n:" << path.info[n_index].nsp << endl;

            if (total_wight < path.info[n_index].nsp) {
                path.info[n_index].nsp = total_wight;
                path.info[n_index].previous = s_index;
            }
        }

        int low_index = neighbors[0].with;
        int low_wight = neighbors[0].wight;

        for (int i = 1; i < neighbors.size(); ++i) {
            if (low_wight > neighbors[i].wight) {
                low_index = neighbors[i].with;
                low_wight = neighbors[i].wight;
            }
        }

        visited.push_back(s_index);
        unvisited.erase(remove_if(unvisited.begin(), unvisited.end(),
                                  [&s_index](const int &with) { return with == s_index; }),
                        unvisited.end());

        // for (const int &v : visited) {
        //     cout << v << ", ";
        // }
        // cout << endl;

        // for (const int &v : unvisited) {
        //     cout << v << ", ";
        // }
        // cout << endl;
        return update_neighbor(low_index, visited, unvisited, path);
    }
}

void find_short_path(int start, int end) {
    if (start >= graph.size() || start < 0 || end >= graph.size() || end < 0)
        return;

    if (start == end)
        return;

    vector<int> visited;
    vector<int> unvisited;

    unvisited.reserve(graph.size());
    for (int i = 0; i < graph.size(); ++i)
        unvisited.push_back(i);

    table path(graph.size());

    // *********
    path.info[start].nsp = 0;
    update_neighbor(start, visited, unvisited, path);
    // *********

    path.print_table();
}

int main() {
    add_node();
    add_node();
    add_node();
    add_node();
    add_node();

    add_edge(0, 1, 7);
    add_edge(0, 2, 3);
    // add_edge(1, 2, 1);
    add_edge(1, 3, 2);
    add_edge(1, 4, 6);
    // add_edge(2, 3, 2);
    add_edge(3, 4, 4);

    find_short_path(0, 4);

    // # include algorithm this is prety cool way to delete specific element from vector
    // vec.erase(remove(vec.begin(), vec.end(), 10), vec.end());
    return 0;
}