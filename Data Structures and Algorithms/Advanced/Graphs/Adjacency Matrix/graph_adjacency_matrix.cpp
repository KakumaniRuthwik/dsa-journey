#include<iostream>
#include<vector>
using namespace std;

class Graph{
    private: 
        int n;
        vector<vector<int>> adjMatrix;
    public:
        Graph(int n){
            this->n = n;
            adjMatrix.resize(n, vector<int>(n, 0));
        }

    void addEdge(int u, int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printGraph(){
        int size = adjMatrix.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << adjMatrix[i][j] <<  " ";
            }
            cout << endl;
        }
    }
};

int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    g.printGraph();

    return 0;
}