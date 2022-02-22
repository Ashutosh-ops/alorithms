#include <bits/stdc++.h>
// #define &&and
// #define || or

using namespace std;

// 9580133457

int findMinVertex(int *distance, bool *visited, int n)
{
    // cout << "Line 10:" << endl;
    int min = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min == -1 || distance[i] < distance[min]))
        {
            min = i;
        }
    }
    return min;
}

void dijkstra(int **edges, int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];
    int *parent = new int[n];

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
        parent[i] = INT_MIN;
    }

    parent[0] = distance[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] && !visited[j])
            {
                int dist = distance[minVertex] + edges[minVertex][j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                    parent[j] = minVertex;
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "  " << distance[i] << "  " << parent[i] << endl;
    }
    cout << endl;
}

// void dijkstra(int **edges, int n)
// {
//     cout << "Confirmation Matrix2:"
//          << endl;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << edges[i][j] << " ";
//         }
//         cout << endl;
//     }

//     int *distance = new int[n];
//     // vector<int> distance(n);
//     bool *visited = new bool[n];
//     // vector<bool> visited(n);
//     // int *parent = new int[n];
//     // vector<int> parent(n);

//     for (int i = 0; i < n; i++)
//     {
//         distance[i] = INT_MAX;
//         visited[i] = false;
//         // parent[i] = INT_MIN;
//     }

//     // for (int i = 0; i < n; i++)
//     // {
//     //     distance[i] = INT_MAX;
//     //     visited[i] = false;
//     //     parent[i] = INT_MIN;
//     // }

//     distance[0] = 0;

//     cout << "102" << endl;
//     for (int i = 0; i < n - 1; i++)
//     {
//         int minVertex = findMinVertex(distance, visited, n);
//         visited[minVertex] = true;
//         cout << minVertex <<endl;
//         for (int j = 0; j < n; j++)
//         {
//             cout << "Line 111" << endl;
//             if (edges[minVertex][j] && !visited[j])
//             {
//                 int dist = distance[minVertex] + edges[minVertex][j];
//                 if (dist < distance[j])
//                 {
//                     distance[j] = dist;

//                     // parent[j] = minVertex;
//                 }
//             }
//         }
//     }

//     cout << endl
//          << "|  V |  D |  P |"
//          << endl;
//     cout << "+----+----+----+"
//          << endl;

//     for (int i = 0; i < n; i++)
//     {
//         // cout << i << "  " << distance[i] << "  " << parent[i] << endl;
//         printf("| %2d | %2d |\n", i, distance[i]);
//     }

//     delete[] distance;
//     // distance.clear();
//     delete[] visited;
//     // visited.clear();
//     // delete [] parent;
//     // parent.clear();

//     return;
// }

int main(int argc, char const *argv[])
{
    int n, e;
    cin >> n >> e;
    cout << endl;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    cout << "Confirmation Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << "Enter the Edges:"
         << endl;
    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[s][f] = edges[f][s] = w;
    }

    cout << "Confirmation Matrix2:"
         << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    dijkstra(edges, n);

    return 0;
}
