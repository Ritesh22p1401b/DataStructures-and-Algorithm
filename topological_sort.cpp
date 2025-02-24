#include <iostream>
#include <vector>

using namespace std;

void topologicalSort(int n, vector<vector<int>>& adjMatrix) {
    vector<int> inDegree(n, 0);
    vector<int> topoOrder(n, -1);  // Store the topological order
    vector<bool> visited(n, false); // Track processed nodes

    // Compute in-degree for each node
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    int count = 0;
    while (count < n) {
        int node = -1;

        // Find a node with in-degree 0 and not visited
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0 && !visited[i]) {
                node = i;
                break;
            }
        }

        // If no node is found, a cycle exists
        if (node == -1) {
            cout << "The graph has a cycle! Topological sorting is not possible.\n";
            return;
        }

        // Add to topological order
        topoOrder[count++] = node;
        visited[node] = true;

        // Reduce in-degree of its neighbors
        for (int j = 0; j < n; j++) {
            if (adjMatrix[node][j] == 1) {
                inDegree[j]--;
            }
        }
    }

    // Print the topological order
    cout << "Topological Order: ";
    for (int i = 0; i < n; i++) {
        cout << topoOrder[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix (0 for no edge, 1 for edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    // Perform topological sort
    topologicalSort(n, adjMatrix);

    return 0;
}



