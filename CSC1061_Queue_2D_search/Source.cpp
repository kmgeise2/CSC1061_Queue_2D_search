/*
File: CSC1061_Queue_2D_search
Author: Ram Longman
Revised: 9/22/23 by Kathy Geise
Description:
	Given a 2D integer array, a location (x, y), and a target to search for. 
    Determine the minimum number of steps to reach the target from the given location.
	Can move up, down, left, or right.
	Return -1 if target was not found.

    Use the template library version of queue

*/

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

const int ROWS = 8;
const int COLS = 10;


int search(int arr[ROWS][COLS], int x, int y, int target);

int main()
{
    int arr[ROWS][COLS] = { {11,2, 43,24,95,19,7, 81,94,60},
                     {91,16,4, 82,5, 19,74,82,81,64},
                     {17,71,36,61,91,64,7, 51,29,30},
                     {31,80,38,50,25,92,72,71,82,72},
                     {49,88,93,37,72,82,76,40,37,98},
                     {12,42,18,44,85,34,70,81,46,15},
                     {1, 22,52,23,27,89,16,65,14,37},
                     {66,26,76,20,61,14,7, 92,12,71} };

    cout << "Search a 2D array" << endl;
    cout << "Start at location (3,1) and search for 76" << endl;
    cout << "Location is (row, column)" << endl;
    cout << "The minimum distance to the target is ";
    cout << search(arr, 3, 1, 76) << endl;

    return 0;
}

int search(int arr[ROWS][COLS], int sx, int sy, int target)
{
    unordered_set<int> s;
    queue<int> q;
    q.push(sx * COLS + sy);
    s.insert(sx * COLS + sy);

    while (!q.empty()) {

        int c = q.front();
        q.pop();
        int x = c / COLS, y = c % COLS;

        if (arr[x][y] == target) {
            return abs(sx - x) + abs(sy - y);
        }
        if (y > 0) {
            if (!s.count(c - 1)) {
                s.insert(c - 1);
                q.push(c - 1);
            }
        }
        if (y < COLS) {
            if (!s.count(c + 1)) {
                s.insert(c + 1);
                q.push(c + 1);
            }
        }
        if (x > 0) {
            if (!s.count(c - COLS)) {
                s.insert(c - COLS);
                q.push(c - COLS);
            }
        }
        if (x < ROWS) {
            if (!s.count(c + COLS)) {
                s.insert(c + COLS);
                q.push(c + COLS);
            }
        }
    }
    return -1;
}
