#include <iostream>
#include <string>
#include <utility>
#include <utility>
#include <queue>
using namespace std;

const string target = "ICPCASIASG";

pair<int, int> index2loc(const int index, const int width)
{
    int col = (index % width) + 1;
    int row = (index / width) + 1;
    return make_pair(col, row);
}

int loc2index(const int col, const int row, const int width)
{
    int index = (row-1)*width + (col-1);
    return index;
}

bool onBoard(const int col, const int row, const int width)
{
    return 0 < row && row <= width && 0 < col && col <= width;
}

int matched(const string chessboard, const int index, const int width, const int cur_count)
{
    return chessboard[index]==target[cur_count];
}

vector<pair<int, int> > getNextNodes(const int index, const int cur_count, const int width)
{
    vector<pair<int, int> > next_nodes;

    pair<int, int> loc = index2loc(index, width);
    int cur_col = loc.first;
    int cur_row = loc.second;

    int col_diff[] = {+1, -1, +1, -1, -2, +2, -2, +2};
    int row_diff[] = {+2, -2, -2, +2, -1, +1, +1, -1};

    for (int i=0; i<8; i++)
    {
        int new_col = cur_col + col_diff[i];
        int new_row = cur_row + row_diff[i];
        if (onBoard(new_row, new_col, width))
        {
            int next_index = loc2index(new_col, new_row, width);
            int next_count = cur_count + 1;
            next_nodes.push_back(make_pair(next_index, next_count));
        }
    }

    return next_nodes;
}

int main()
{
    int width;
    bool found = false;
    string chessboard;

    cin >> width;
    cin >> chessboard;

    queue<pair<int, int> > toSearch;
    int cur_count = 0;

    for (int index=0; index<chessboard.length(); index++)
        if (chessboard[index] == target[cur_count])
            toSearch.push(make_pair(index, cur_count));
    while (!found && !toSearch.empty())
    {
        pair<int, int> next_node = toSearch.front(); toSearch.pop();
        int index = next_node.first;
        cur_count = next_node.second;
        if (matched(chessboard, index, width, cur_count))
        {
            if (cur_count == target.length()-1)
                found = true;
            else
            {
                vector<pair<int, int> > next_nodes = getNextNodes(index, cur_count, width);
                for (pair<int, int> next_node : next_nodes)
                    toSearch.push(next_node);
            }
        }
    }
    if (found)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0; 
}