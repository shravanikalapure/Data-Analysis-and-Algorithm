#include <iostream>
#include <limits>
#include <cstring>
using namespace std;

#define MAX_DEPTS 100

int mindist(int dist[], bool visited[], int V) {

    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {

        if (!visited[v] && dist[v] <= min) {

            min = dist[v];

            min_index = v;

        }

    }

    return min_index;

}

void dijkstra(int graph[MAX_DEPTS][MAX_DEPTS], int V, int SN, char locations[][50]) {

    int dist[V];     

    bool visited[V]; 

 

    for (int i = 0; i < V; i++) {

        dist[i] = INT_MAX;

        visited[i] = false;

    }

 

    dist[SN] = 0;

 

    for (int count = 0; count < V - 1; count++) {

        int u = mindist(dist, visited, V);

        if (u == -1) break;

        visited[u] = true;

 

        for (int v = 0; v < V; v++) {

            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&

                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];

            }

        }

    }

 

    cout << "\nDepartment \t\t Distance from " << locations[SN] << endl;

    for (int i = 0; i < V; i++) {

        cout << locations[i] << "\t\t\t" << dist[i] << endl;

    }

}

 

int main() {

    int V;

    cout << "Enter number of locations: ";

    cin >> V;

    cin.ignore();

    char locations[MAX_DEPTS][50];

    cout << "Enter department names:\n";

    for (int i = 0; i < V; i++) {

        cout << "Department " << i << ": ";

        cin.getline(locations[i], 50);

    }

 

    int graph[MAX_DEPTS][MAX_DEPTS];

    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            cin >> graph[i][j];

        }

    }

 

    int startNode;

    cout << "Enter starting department index: ";

    cin >> startNode;

 

    dijkstra(graph, V, startNode, locations);

 

    return 0;

}

