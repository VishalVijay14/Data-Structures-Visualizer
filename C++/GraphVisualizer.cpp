#include <iostream>
#include <list>
#include <vector>
#include <queue>

class GraphVisualizer {
public:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

    // Constructor
    GraphVisualizer(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
    }

    // BFS traversal from a given source
    void BFS(int s) {
        std::vector<bool> visited(V, false);
        std::queue<int> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            std::cout << s << " ";
            queue.pop();

            for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }
        }
        std::cout << std::endl;
    }

    // DFS traversal from a given source
    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

    // DFS traversal, starting from a given vertex v
    void DFS(int v) {
        std::vector<bool> visited(V, false);
        DFSUtil(v, visited);
        std::cout << std::endl;
    }

    // Function to visualize the graph traversal
    static void visualize() {
        GraphVisualizer g(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);

        std::cout << "Breadth-First Search (BFS) starting from vertex 0:\n";
        g.BFS(0);

        std::cout << "Depth-First Search (DFS) starting from vertex 0:\n";
        g.DFS(0);
    }
};

// Main function to run the visualization
int main() {
    GraphVisualizer::visualize();
    return 0;
}