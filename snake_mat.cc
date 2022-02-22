#include <bits/stdc++.h>
#define s(a) #a

using namespace std;

void snake_mat(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    for (int i = 0; i < m; i++)
    {
        if ((i + 1) & 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            // cout << endl;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
            // cout << endl;
        }
    }

    return;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cout << "Rows & Cols: ";
    cin >> m >> n;
    vector<vector<int>> arr(m);
    for (int i = 0; i < m; i++)
    {
        arr[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    /*Mean while*/
    cout << s(snakeTraversal) << endl;
    snake_mat(arr);

    cout << endl
         << "Original Matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        arr[i].clear();
    }
    arr.clear();
    return 0;
}
