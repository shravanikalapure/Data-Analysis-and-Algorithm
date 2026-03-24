#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void print_matrix(vector<vector<int>> &dist) {
    int v = dist.size();
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl; // for spacing
}

void floyd_warshall(vector<vector<int>> &dist){
    int V = dist.size();

    for (int k =0; k<V; k++){
        for (int i = 0; i<V; i++){
            for (int j = 0; j<V; j++){
                if (dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        print_matrix(dist);
    }
}

int main(){
    int INF = 1e9;
    vector<vector<int>> dist = {{0, 8, INF, 1},
                                {INF, 0, 1, INF},
                                {4, INF, 0, INF},
                                {INF, 2, 9, 0}};

    floyd_warshall(dist);
    
    for(int i = 0; i < dist.size(); i++) {
        for(int j = 0; j < dist.size(); j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << endl;
    return 0;
}