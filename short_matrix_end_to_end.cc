#include <bits/stdc++.h>
#define minn(a, b) ((a < b) ? a : b)
#define maxx(a, b) ((a > b) ? a : b)

using namespace std;

// int minn(int a, int b)
// {
//     return (a < b) ? a : b;
// }

int shrt_diag_mat_dp(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &loc)
{
    int m = arr.size();
    int n = arr[0].size();

    if ((i == m - 1) && (j == n - 1))
    {
        return arr[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    int a, b, c;

    if (loc[i + 1][j] == INT_MIN)
    {
        a = shrt_diag_mat_dp(arr, i + 1, j, loc);
        loc[i + 1][j] = a;
    }
    else
    {
        a = loc[i + 1][j];
    }

    if (loc[i][j + 1] == INT_MIN)
    {
        b = shrt_diag_mat_dp(arr, i, j + 1, loc);
        loc[i][j + 1] = b;
    }
    else
    {
        b = loc[i][j + 1];
    }

    if (loc[i + 1][j + 1] == INT_MIN)
    {
        c = shrt_diag_mat_dp(arr, i + 1, j + 1, loc);
        loc[i + 1][j + 1] = c;
    }
    else
    {
        c = loc[i + 1][j + 1];
    }

    return arr[i][j] + minn(minn(a, b), c);
}
int shrt_diag_mat(vector<vector<int>> &arr, int i, int j)
{
    if ((i == arr.size() - 1) && (j == arr[0].size() - 1))
    {
        return arr[i][j];
    }
    if (i >= arr.size() || j >= arr[0].size())
    {
        return INT_MAX;
    }

    int a = shrt_diag_mat(arr, i + 1, j);
    int b = shrt_diag_mat(arr, i, j + 1);
    int c = shrt_diag_mat(arr, i + 1, j + 1);

    return arr[i][j] + minn(minn(a, b), c);
}

int shrt_diag_mat_idp(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    vector<vector<int>> loc(m + 1);
    for (int i = 0; i < loc.size(); i++)
    {
        loc[i] = vector<int>(n + 1);
        for (int j = 0; j < loc[0].size(); j++)
        {
            loc[i][j] = INT_MAX;
        }
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                loc[i][j] = arr[m - 1][n - 1];
            }
            else
            {
                int a, b, c;
                a = loc[i][j + 1];
                b = loc[i + 1][j];
                c = loc[i + 1][j + 1];

                loc[i][j] = arr[i][j] + minn(a, minn(b, c));
            }
        }
    }

    // for (int i = 0; i < loc.size(); i++)
    // {
    //     for (int j = 0; j < loc[0].size(); j++)
    //     {
    //         cout << loc[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return loc[0][0];
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

    vector<vector<int>> loc(m + 1);
    for (int i = 0; i < loc.size(); i++)
    {
        loc[i] = vector<int>(n + 1);
        for (int j = 0; j < loc[0].size(); j++)
        {
            loc[i][j] = INT_MIN;
        }
    }

    cout << endl
         << shrt_diag_mat_idp(arr) << endl;
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
