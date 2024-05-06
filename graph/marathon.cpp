#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;
template <typename T>
class graph
{
    // code is working on code help compiler.
public:
    unordered_map<T, list<pair<T, int>>> adjlist;
    unordered_map<T, list<int>> adj; // for kosaraju algo
    void adjEdge(T u, T v, int wt, bool direction)
    {
        if (direction == 0)
        {
            adjlist[u].push_back({v, wt});
            adjlist[v].push_back({u, wt});
        }
        else
        {
            adjlist[u].push_back({v, wt});
        }
    }
    void adjEdge1(T u, T v, bool direction)
    {
        if (direction == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
        {
            adj[u].push_back(v);
        }
    }
    void printadj()
    {
        for (auto &&i : adjlist)
        {
            cout << i.first << "->";
            for (auto &&j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "}, ";
            }
            cout << endl;
        }
    }

    void bellmanford(int n, int src)
    {
        /// initial state
        vector<int> dist(n, INT_MAX);
        dist[src - 'A'] = 0;
        // n-1 times relaxation

        for (int i = 1; i < n; i++)
        {
            // traverse on entire edgelist
            for (auto &&a : adjlist)
            {
                for (auto &&b : a.second)
                {
                    T u = a.first;
                    T v = b.first;
                    int wt = b.second;

                    if ((dist[u - 'A'] != INT_MAX) && dist[u - 'A'] + wt < dist[v - 'A'])
                    {
                        dist[v - 'A'] = dist[u - 'A'] + wt;
                    }
                }
            }
        }
        // yaha tk shortest distance ready hai
        // check for negative cycle;
        // 1 baar relaxation or chala do
        bool update = false;
        for (auto a : adjlist)
        {
            for (auto b : a.second)
            {
                T u = a.first;
                T v = b.first;
                int wt = b.second;

                if ((dist[u - 'A'] != INT_MAX) && dist[u - 'A'] + wt < dist[v - 'A'])
                {
                    update = true;
                    break;
                    dist[v - 'A'] = dist[u - 'A'] + wt;
                }
            }
        }

        if (update == true)
        {
            cout << "-ve cycle presrnt" << endl;
        }
        else
        {
            cout << "no -ve cycle in this graph" << endl;
            cout << "printing distance array" << endl;

            for (auto i : dist)
            {
                cout << i << ", ";
            }
            cout << endl;
        }
    }
    void flyodWarshal(int n)
    {
        // initial state
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // diagonal  pr 0;
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // kuch weights graph ke ander given hai
        // update dist array accordingly

        for (auto &&a : adjlist)
        {
            for (auto &&b : a.second)
            {
                int u = a.first;
                int v = b.first;
                int wt = b.second;

                dist[u][v] = wt;
            }
        }
        // main logic
        // helper logic
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
                {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }
        // print distance array
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    
    void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &vis)
    {
        vis[node] = true;

        for (auto nbr : adj[node])
        {
            if(!vis[nbr]){
                dfs1(nbr,ordering,vis);
            }
        }
        // wapas aate hue stack me push krna
        ordering.push(node);
    }
    void dfs2(int src,unordered_map<int,bool>&vis,unordered_map<int, list<int>> & adjNew){
        vis[src] = true;

        for (auto nbr : adjNew[src])
        {
            if(!vis[nbr]){
                dfs2(nbr,vis,adjNew);
            }
        }
        
    }
    int getSCC(int n)
    {
        // step1:- get the ordering
        stack<int> ordering;
        unordered_map<int, bool> vis;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs1(i, ordering, vis);
            }
        }

        // step2:- reverse edges
        unordered_map<int, list<int>> adjNew;
        for (auto a : adj)
        {
            for (auto b : a.second)
            {
                int u = a.first;
                int v = b;

                // v->u ki entry reverse
                adjNew[v].push_back(u);
            }
            
        }
        
        // step3:- traverse using ordering and count components
        int count = 0;
        unordered_map<int, bool> vis2;
        while (!ordering.empty())
        {
            int node = ordering.top();
            ordering.pop();
            if(!vis2[node]){
                dfs2(node,vis2,adjNew);
                count++;
            }
        }
        return count;
    }
};
int main()
{
    // graph<char> g;
    // g.adjEdge('A', 'B', -1, 1);
    // g.adjEdge('B', 'E', 2, 1);
    // g.adjEdge('E', 'D', -3, 1);
    // g.adjEdge('D', 'C', 5, 1);
    // g.adjEdge('A', 'C', 4, 1);
    // g.adjEdge('B', 'C', 3, 1);
    // g.adjEdge('B', 'D', 2, 1);
    // g.adjEdge('D', 'B', 1, 1);
    // g.printadj();
    // g.bellmanford(5, 'A');

    // graph<int> g;
    // g.adjEdge(0, 1, 3, 1);
    // g.adjEdge(1, 0, 2, 1);
    // g.adjEdge(0, 3, 5, 1);
    // g.adjEdge(1, 3, 4, 1);
    // g.adjEdge(3, 2, 2, 1);
    // g.adjEdge(2, 1, 1, 1);

    // g.flyodWarshal(4);

    graph<int> g;
    g.adjEdge1(0,1,1);
    g.adjEdge1(1,2,1);
    g.adjEdge1(2,3,1);
    g.adjEdge1(3,0,1);


    g.adjEdge1(2,4,1);
    
    
    g.adjEdge1(4,5,1);
    g.adjEdge1(5,6,1);
    g.adjEdge1(6,4,1);


    g.adjEdge1(6,7,1);

    int n = g.getSCC(8);

    cout<<"SCC count: "<<n;
    return 0;
}