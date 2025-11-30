#include <iostream>
using namespace std;

class Node4 {
public:
    int data;
    Node4 *next, *prev, *up, *down;

    Node4(int d) {
        data = d;
        next = prev = up = down = NULL;
    }
};

Node4* convertToDLL(int arr[][3], int r, int c) {

    // create nodes in 2D array (no STL)
    Node4* nodes[10][10];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            nodes[i][j] = new Node4(arr[i][j]);
        }
    }

    // link pointers
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            // right
            if (j + 1 < c)
                nodes[i][j]->next = nodes[i][j + 1];

            // left
            if (j - 1 >= 0)
                nodes[i][j]->prev = nodes[i][j - 1];

            // down
            if (i + 1 < r)
                nodes[i][j]->down = nodes[i + 1][j];

            // up
            if (i - 1 >= 0)
                nodes[i][j]->up = nodes[i - 1][j];
        }
    }

    return nodes[0][0]; // return head (top-left)
}

int main() {
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Node4* head = convertToDLL(arr, 3, 3);

    cout << "Head node: " << head->data << endl;
    cout << "Right: " << head->next->data << endl;
    cout << "Down: " << head->down->data << endl;

    return 0;
}
