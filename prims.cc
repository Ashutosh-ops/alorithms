#include <bits/stdc++.h>

using namespace std;

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

void prims(int **edges, int n)
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
        int u = findMinVertex(distance, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (edges[u][v])
            {
                if (!visited[v] && edges[u][v] < distance[v])
                {
                    parent[v] = u;
                    distance[v] = edges[u][v];
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << "  "  << i << "  " << distance[i] << endl;
    }
    cout << endl;

    delete[] distance;
    delete[] visited;
    delete[] parent;
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

    prims(edges, n);

    return 0;
}
