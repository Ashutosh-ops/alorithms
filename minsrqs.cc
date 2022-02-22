#include <bits/stdc++.h>

using namespace std;

int minsqrr(int n)
{
    if (!n)
    {
        return n;
    }
    int min = INT_MAX;
    for (int j = 1; j * j <= n; j++)
    {
        int curr = minsqrr(n - j * j);
        if (curr < min)
        {
            min = curr;
        }
    }
    return min + 1;
}

int minsqrdpr(int n, vector<int>& dp)
{
    if (!n)
    {
        return n;
    }

    int min = INT_MAX;
    for (int j = 0; j * j <= n; j++)
    {
        int curr;
        if (dp[n - j * j] == -1)
        {
            curr = minsqrr(n - j * j);
            dp[n - j * j] = curr;
        }
        else
        {
            curr = dp[n - j * j];
        }
        if (curr < min)
        {
            min = curr;
        }
    }
    return min + 1;
}

int minsqrdpi(int n)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int minsqr = INT_MAX;
        for (int j = 1; j*j <= i; j++)
        {
            int curr  = dp[i-j*j];
            if (minsqr > curr)
            {
                minsqr = curr;
            }
        }
        dp[i] = minsqr+1;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int k = 0;
    cout << "Enter the Number: ";
    cin >> k;
    // int *dp = new int[k + 1];
    vector<int> dp[k+1];
    for (int i = 0; i <= k; i++)
    {
        dp[i] = -1;
    }

    // cout << minsqrr(k) << endl;
    cout << minsqrdpr(k, dp) << endl;
    // cout << minsqrdpi(k) << endl;
    delete [] dp;
    return 0;
}
