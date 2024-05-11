#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int count = 0;
class NQueens
{
private:
    int gsize;
    vector<int> qpos;

public:
    NQueens(int size) : gsize(size), qpos(size, -1) {}
    bool isSafe(int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            if (qpos[i] == col || abs(qpos[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }
    bool btrack(int row)
    {
        if (row == gsize)
        {
            display();
            return true;
        }
        for (int col = 0; col < gsize; ++col)
        {
            if (isSafe(row, col))
            {
                qpos[row] = col;
                if (btrack(row + 1))
                    return true;
                qpos[row] = -1;
            }
        }
        return false;
    }
    void display()
    {
        cout << "Solution:" << endl;
        for (int i = 0; i < gsize; ++i)
        {
            for (int j = 0; j < gsize; ++j)
            {
                if (qpos[i] == j)
                    cout << "Q ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void branchbound(int row)
    {

        if (row == gsize)
        {
            display();
            count++;
            return;
        }
        for (int col = 0; col < gsize; ++col)
        {
            if (isSafe(row, col))
            {
                qpos[row] = col;
                branchbound(row + 1);
            }
        }
    }
};
int main()
{
    int size;
    cout << "Enter the size of grid: ";
    cin >> size;
    NQueens q1(size);
    NQueens q2(size);
    cout << "\nBACKTRACKING:\n";
    if (!q1.btrack(0))
    {
        cout << "No solution exists.\n";
    }
    cout << "\nBRANCH and BOUND Solution:\n";
    q2.branchbound(0);
    cout << "No of solutions - " << count << endl;
    return 0;
}