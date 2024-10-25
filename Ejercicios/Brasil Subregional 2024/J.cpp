#include <bits/stdc++.h>
using namespace std;

// Node structure to hold destination and color of an edge
struct Edge {
    int dest;  // Destination node
    int id;
};

// Graph class to handle the adjacency list representation and Eulerian cycle
class Graph {
public:
    int N, K, id; // Number of nodes and colors
    unordered_map<int, vector<Edge>> adj; // Adjacency list for each node-color pair

    Graph(int n, int k) : N(n), K(k), id(0) {}

    // Function to add a bidirectional edge between nodes u and v with color c
    void addEdge(int u, int v, int color) {
        adj[u * K + color].push_back({v * K + color, id});
        adj[v * K + color].push_back({u * K + color, id++});
    }

    // Function to perform the Eulerian cycle
    vector<int> eulerianCycle() {
        vector<int> cycle;
        unordered_map<int, vector<Edge>> temp_adj = adj; // Copy to manipulate edges
        stack<int> currentPath;
        vector<int> circuit;
        vector<int> V(id, 0);

        // Start from any node with outgoing edges
        int startNode = -1;
        for(const auto& node : adj) {
            if (!node.second.empty()) {
                startNode = node.first;
                break;
            }
        }

        currentPath.push(startNode);
        int current = startNode;

        while (!currentPath.empty()) {
            if(!temp_adj[current].empty()) {
                Edge nextEdge = temp_adj[current].back();
                temp_adj[current].pop_back();
                if(V[nextEdge.id]) continue;
                V[nextEdge.id] = 1;
                currentPath.push(current);
                current = nextEdge.dest;
            } else {
                circuit.push_back(current);
                current = currentPath.top();
                currentPath.pop();
            }
        }

        return circuit;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;  // N nodes, M edges, K colors

    Graph graph(N, K);

    for (int i = 0; i < M; ++i) {
        int u, v, color;
        cin >> u >> v >> color; u--, v--, color--;
        graph.addEdge(u, v, color);
    }

    // Get the Eulerian cycle
    vector<int> cycle = graph.eulerianCycle();

    // Print the Eulerian cycle
    for (int node : cycle) {
        cout << node / K + 1 << " "; // Converting back from the subnode format
    }

    return 0;
}
