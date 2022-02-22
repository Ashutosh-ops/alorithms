#include <bits/stdc++.h>
#define minn(a, b) ((a < b) ? a : b)
#define tk2str(a) #a

using namespace std;



int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 2;
    cout << minn(a, b) << endl;
    cout << tk2str(a) << endl;
    cout << "Line: " << __LINE__ << endl
         << "Path: " << __FILE__ << endl
         << "Date: " << __DATE__ << endl
         << "Time: " << __TIME__ << endl
         << endl;
    return 0;
}
