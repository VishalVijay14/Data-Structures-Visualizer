#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <climits>

class DijkstraVisualizer {
public:
    int V; // Number of vertices
    std::vector<std::list<std::pair<int, int>>> adj; // Adjacency list with weights

    // Constructor
    DijkstraVisualizer(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(std::make_pair(v, weight));
        adj[v].push_back(std::make_pair(u, weight)); // For undirected graph
    }

    // Dijkstra's algorithm to find shortest path from a source
    void dijkstra(int src) {
        std::vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        std::set<std::pair<int, int>> setds;
        setds.insert(std::make_pair(0, src));

        while (!setds.empty()) {
            int u = setds.begin()->second;
            setds.erase(setds.begin());

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    if (dist[v] != INT_MAX) {
                        setds.erase(setds.find(std::make_pair(dist[v], v)));
                    }
                    dist[v] = dist[u] + weight;
                    setds.insert(std::make_pair(dist[v], v));
                }
            }
        }

        std::cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < V; ++i) {
            std::cout << i << "\t\t" << dist[i] << std::endl;
        }
    }

    // Function to visualize Dijkstra's algorithm
    static void visualize() {
        DijkstraVisualizer g(5);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 4, 20);
        g.addEdge(1, 2, 30);
        g.addEdge(2, 3, 40);
        g.addEdge(3, 4, 50);

        std::cout << "Dijkstra's Algorithm starting from vertex 0:\n";
        g.dijkstra(0);
    }
};

// Main function to run the visualization
int main() {
    DijkstraVisualizer::visualize();
    return 0;
}
