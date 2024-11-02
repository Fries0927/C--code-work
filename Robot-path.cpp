https://zerojudge.tw/ShowProblem?problemid=e287
#include <iostream>
#include <vector>
#include <algorithm>

#define wall -1

using namespace std;

struct fie
{
    int val;
    bool iterated;
};

int main() 
{
    int row;
    int col;
    cin >> row; //n
    cin >> col; //m
    int border_row = row;
    int border_col = col;
    int total = 0;
    pair<int,int> smallest = {0,0}; //first = row , second = col
    vector<vector<fie>> field(row,vector<fie>(col));
    for(int i = 0 ; i < row ; i++)
    {
        for(int o = 0 ; o < col ; o++)
        {
            cin >> field[i][o].val;
            field[i][o].iterated = false;
            if(field[i][o].val < field[smallest.first][smallest.second].val)
            {
                smallest.first = i;
                smallest.second = o;
            }
        }
    }
    //cout << field[smallest.first][smallest.second].val;
    row = smallest.first;
    col = smallest.second;
    field[row][col].iterated = true;
    total += field[row][col].val;
    while(1)
    {
        vector<int> pos; //up left down right
        if(row - 1 >= 0 && field[row-1][col].iterated != true) //up
        {
            pos.push_back(field[row-1][col].val);
        }
        else
        {
            pos.push_back(wall);
        }

        if(col - 1 >= 0 && field[row][col-1].iterated != true) //left
        {
            pos.push_back(field[row][col-1].val);
        }
        else
        {
            pos.push_back(wall);
        }

        if(row+1 < border_row && field[row+1][col].iterated != true)//down
        {
            pos.push_back(field[row+1][col].val);
        }
        else
        {
            pos.push_back(wall);
        }

        if(col+1 < border_col && field[row][col+1].iterated != true)//right
        {
            pos.push_back(field[row][col+1].val);
        }
        else
        {
            pos.push_back(wall);
        }
        vector<int>::iterator small = pos.begin();
        for(auto itr = pos.begin()+1 ; itr != pos.end() ; itr++)
        {
            if((*itr < *small && *itr != wall) || (*small == wall && *itr != wall)) 
            {
                small = itr;
            }
        }
        if(*small == wall)
        {
            break;
        }
        switch(small - pos.begin())
        {
            case(0):
            row--;
            field[row][col].iterated = true;
            total += field[row][col].val;
            break;

            case(1):
            col--;
            field[row][col].iterated = true;
            total += field[row][col].val;
            break;

            case(2):
            row++;
            field[row][col].iterated = true;
            total += field[row][col].val;
            break;
            
            case(3):
            col++;
            field[row][col].iterated = true;
            total += field[row][col].val;
            break;
        }
    }
    cout << total;
    return 0;
}
