#include <iostream>
using namespace std;

class dungeon {
    int rooms;  //15                                         
    int graph[15][15]; //adjacency matrix
    public:
    dungeon(int r) {
        rooms = r;
        for (int i = 0; i < rooms; i++) {
            for (int j = 0; j < rooms; j++) {
                graph[i][j] = 0; // Initialize with no paths
            }
        }
    }

    void add_route(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight; // Assuming undirected graph
    }

    void dijikstra(int src) {
        int dist[15];
        bool visited[15] = {false};

        for (int i = 0; i < rooms; i++) {
            dist[i] = 1000000; // Initialize with large value
        }
        dist[src] = 0;

        for (int count = 0; count < rooms - 1; count++) {
            int u = -1;
            for (int i = 0; i < rooms; i++) {
                if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            visited[u] = true;

            for (int v = 0; v < rooms; v++) {
                if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < rooms; i++) {
            cout << "To room " << i << " -> Distance: " << dist[i] << "\n";
        }
    }
};

int main() {
    dungeon d(4); // create a dungeon with 5 rooms ;
    d.add_route(0, 1, 1);
    d.add_route(0, 2, 4);
    d.add_route(1, 2, 2);
    d.add_route(1, 3, 5);
    
    d.dijikstra(0); // find shortest paths from room 0
}