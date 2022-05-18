#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> graph[], bool visited[], int firstVertex, int curVertex, int length, int *curLength) {
    visited[curVertex] = true;
    for (int i = 0 ; i < graph[curVertex].size() ; i++) {
        int nextVertex = graph[curVertex][i];
        if (!visited[nextVertex]) {
            dfs(graph, visited, firstVertex, nextVertex, length + 1, curLength);
        } else if(length >= 3 && nextVertex == firstVertex && (*curLength == 0 || length < *curLength)) {
            *curLength = length;
        }
    }
    visited[curVertex] = false;
    return *curLength;
}

int main() {

    int nVert, nEdge;
    cin >> nVert >> nEdge;
    vector<int> graph[nVert];
    vector<int> empty(0);
    fill(graph, graph + nVert, empty);

    for(int i = 0; i < nEdge; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min = nEdge + 1;
    bool found = false;
    for(int i = 0; i < nVert; i++) {
        bool visited[nVert] ;
        fill(visited, visited+nVert, false);
        int curLength = 0;

        int length = dfs(graph, visited, i, i, 1, &curLength);
        if (length >= 3 && length < min) {
            min = length;
            found = true;
        }
    }

    if (found) {
        cout << min;
    } else {
        cout << "gamau gasuka gelay";
    }

    return 0;
}
