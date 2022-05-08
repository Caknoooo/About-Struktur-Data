#include <bits/stdc++.h>
#include <string.h>
#include <vector>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 1005

struct edge{
    
    int u, v, w;
};

typedef struct edge E;

int parent[MAX];
vector<E> graph, selected_edges;

bool comp(const E&, const E&);
int findParent(int);
int Kruskal_MST(int);

int main()
{
    E getEdge;
    
    int node, edge, u, v, w, kasus = 1;;
    cin >> node >> edge;
        
    for(int i = 0; i < edge; i++)
    {
        cin >> u >> v >> w;
        
        getEdge.u = u;
        getEdge.v = v;
        getEdge.w = w;
        graph.push_back(getEdge);    
    }
        
    repp(i, 1, node)
        parent[i] = i;

    int totalCost = Kruskal_MST(node); 
        
    cout << totalCost << endl;
}

bool comp(const E& l, const E& r)
{
    return l.w < r.w;
}

int Kruskal_MST(int node)
{    
    sort(graph.begin(), graph.end(), comp);
    
    int edgeCounter = 0, totalCost = 0;
    
    rep(i, 0, graph.size())
    {
        int parent_of_u = findParent(graph[i].u);
        int parent_of_v = findParent(graph[i].v);
        
        if(parent_of_u != parent_of_v)
        {
            parent[parent_of_u] = parent_of_v;
            totalCost += graph[i].w;
            
            selected_edges.push_back(graph[i]);
            
            edgeCounter++;
            
            if(edgeCounter == node - 1)    
                break;
        }
    }
    return totalCost;
}

int findParent(int r)
{
    if(r == parent[r])
        return r;
    return parent[r] = findParent(parent[r]);
}
