// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reset2darray(int **edges, int n)
{
    for (int i = 0; i < n; i++)
    {
        // edges[i] = new int[n];
        edges[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            // cin >> edges[i][j];
            edges[i][j] = 0;
        }
    }
}

void input2darray(int **edges, int e)
{
    int f, s, w;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s >> w;
        edges[s][f] = edges[f][s] = w;
    }
}

// int findMinVertex(int *distance, bool *visited, int n)
// int findMinVertex(vector<int> &distance, vector<bool> &visited, int n)
int findMinVertex(vector<int> &distance, vector<bool> &visited)
{
    int minVertex = -1;
    for (auto i : distance)
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;

    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
    //     {
    //         minVertex = i;
    //     }
    // }
    return minVertex;
}

void dijkstra(int **edges, int n)
{
    // int *distance = new int[n];
    vector<int> distance(n);
    // bool *visited = new bool[n];
    vector<bool> visited(n);
    // int *parent = new int[n];
    vector<int> parent(n);

    for (auto i : distance)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
        parent[i] = INT_MIN;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     distance[i] = INT_MAX;
    //     visited[i] = false;
    //     parent[i] = INT_MIN;
    // }

    parent[0] = distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
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

    cout << endl
         << "|  V |  D |  P |"
         << endl;
    cout << "________________"
         << endl;

    for (int i = 0; i < n; i++)
    {
        // cout << i << "  " << distance[i] << "  " << parent[i] << endl;
        printf("| %2d | %2d | %2d |\n", i, distance[i], parent[i]);
    }

    // delete [] distance;
    distance.clear();
    // delete [] visited;
    visited.clear();
    // delete [] parent;
    parent.clear();

    return;
}

int main(int argc, char const *argv[])
{
    int n, e; /*To Take number of nodes input*/
    cin >> n >> e;
    // int **edges = new int *[n];
    vector<vector<int>> edges(n);

    // reset 2-D array input ( Adjacency Matrix )
    reset2darray(edges, n);

    cout << "Inputed Matrix: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Take 2-D array input ( Adjacency Matrix )
    input2darray(edges, e);

    cout << endl;
    // Passing Matrix to Dijkstra
    dijkstra(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete [] edges[i];
        // edges[i].clear;
    }

    delete[] edges;

    return 0;
}
