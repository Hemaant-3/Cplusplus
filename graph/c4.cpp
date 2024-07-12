#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction - 0- undirected
        // direction 1 - directed

        if (direction == 1)
        {
            adj[u].push_back({v, wt});
        }
        else
        {
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << ": {";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << "}" << endl;
        }
    }

    void topoorderdfs(int src, stack<int> &topo, unordered_map<int, bool> &visi)
    {
        visi[src] = true;
        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrdist = nbrPair.second;
            if (!visi[nbrNode])
            {
                topoorderdfs(nbrNode, topo, visi);
            }
        }

        topo.push(src);
    }

    void shortestPathDfs(stack<int> &topOrd, int n)
    {
        vector<int> dist(n, INT_MAX);

        // initailly maintain src.. we are taking most independent node src
        int src = topOrd.top();
        topOrd.pop();
        dist[src] = 0;

        // update nbr dist for this src node;

        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;

            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        // apply the same above conccept for all the remaining node,
        // int the topo ordering

        while (!topOrd.empty())
        {
            int src = topOrd.top();
            topOrd.pop();

            for (auto nbrPair : adj[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }
        // ab mera distance arrya taiyar hai

        cout << "printing the distance  array: " << endl;
        for (auto &&i : dist)
        {
            cout << i << " ";
        }
    }

    void dijkstraShortestDist(int n, int src, int dest)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // maintain initial state
        st.insert({0, src});
        dist[src] = 0;

        // update logic

        while (!st.empty())
        {
            auto element = st.begin(); // starting element address
            pair<int, int> topPair = *element;
            int topdist = topPair.first;
            int topNode = topPair.second;
            // remove the topnode
            st.erase(st.begin());

            // update nbr distance
            for (pair<int, int> nbrPair : adj[topNode])
            {
                int nbrNode = nbrPair.first;
                int nbrdist = nbrPair.second;

                if (topdist + nbrdist < dist[nbrNode])
                {
                    // found a new shorter distance now update
                    //  1- entry of set
                    auto prevEntry = st.find({dist[nbrNode], nbrNode});
                    if(prevEntry!=st.end()){
                        //entry present in set
                        st.erase(prevEntry);
                    }
                    // 2 - distance array
                    dist[nbrNode] = topdist + nbrdist;

                    // create a new entry in set
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        cout<<"shortest distance from "<<src<<" Node to "<<dest<<" Node: "<<dist[dest]<<endl;
    }
};
using namespace std;
int main()
{
    graph g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(2, 1, 2, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(2, 4, 6, 1);
    // g.addEdge(4, 3, 1, 1);

    g.addEdge(1,6,14,0);
    g.addEdge(1,3,9,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,3,10,0);
    g.addEdge(2,4,15,0);
    g.addEdge(3,4,11,0);
    g.addEdge(6,3,2,0);
    g.addEdge(6,5,9,0);
    g.addEdge(5,4,6,0);
    

    int edge = 7;
    // g.printadj();
    int src = 0;
    stack<int> toporder;
    unordered_map<int, bool> visi;
    g.topoorderdfs(src, toporder, visi);

    // cout<<"printing topo"<<endl;
    // while (!toporder.empty())
    // {
    //     cout<<toporder.top()<<" ";
    //     toporder.pop();
    // }
    int n = 5;
    // g.shortestPathDfs(toporder, n);
    g.dijkstraShortestDist(6,5,2);
    return 0;
}