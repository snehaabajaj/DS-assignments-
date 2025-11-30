#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    // Input adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int key[100], parent[100];
    bool mst[100];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        // Pick min key vertex not in MST
        for (int i = 0; i < n; i++) {
            if (!mst[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        mst[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Prim MST:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " = " << graph[i][parent[i]] << endl;
}
