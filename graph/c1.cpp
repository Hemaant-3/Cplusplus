#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// class Graph{
// public:
//     unordered_map<int,list<int>> adjlist;
//     void addEdge(int u, int v, bool direction){
//         // direction = 1 --> directed edge
//         // direction = 0 --> undirected edge

//         if(direction==1){
//             //directed edge
//             // u se v ki taraf
//             adjlist[u].push_back(v);
//         } else{
//             // undirected edge
//             // u se v
//             adjlist[u].push_back(v);
//             // v se u
//             adjlist[v].push_back(u);

//         }
//             cout<<endl<<"printing"<<endl;
//         print();
//             cout<<endl<<"printing"<<endl;
//     }

//     void print(){
//         for(auto i: adjlist){
//             cout<<i.first<<" -> "<<"{ ";
//             for(auto j:i.second){
//                 cout<<j<<", ";
//             }
//             cout<<" }"<<endl;
//         }
//     }
// };
template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, T>>> adjlist;

    void addEdge(T u, T v, int wt, bool direction)
    {
        // direction  = 0 -->undirectd
        // direction = 1 - > directed graph

        if (direction == 1)
        {
            // u->v
            adjlist[u].push_back(make_pair(v, wt));
        }
        else
        {
            // direction = 0;
            //  u---v
            //  u -> v; v-> u
            adjlist[u].push_back({v, wt});
            adjlist[v].push_back({u, wt});
        }

        // cout << endl
        //      << endl;
        // printadj();
        // cout << endl
        //      << endl;
    }

    void printadj()
    {
        for (auto i : adjlist)
        {
            cout << i.first << " : { ";
            for (pair<T, int> p : i.second)
            {
                cout << "[ " << p.first << ", " << p.second << " ],";
            }
            cout << " }" << endl;
        }
    }

    void bfsTraversal(T src,unordered_map<char, bool>& vis)
    {
        // adjlist already data memeber me hai
        //  visited

        // queue
        queue<T> q;

        // initial state
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            // go to nbr
            for (auto nbr : adjlist[frontNode])
            {
                T nbrData = nbr.first;

                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }
    void dfs(T src, unordered_map<T,bool>& vis){
        vis[src] = true;
        cout<<src<<" ";

        for (auto &&nbr : adjlist)
        {
            T nbrData= nbr.first;

            if(!vis[nbrData]){
                dfs(nbrData,vis); // no need base case if this condn fail no further call goes
            }
        }
        
    }
};

int main()
{
    // Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(2,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(2,0,0);

    Graph<char> g;
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 10, 0);


    g.addEdge('c', 'd', 20, 0);

    g.addEdge('c', 'e', 40, 0);
    // g.addEdge('c', 'e', 40, 0);
g.addEdge('d', 'e', 40, 0);
    g.addEdge('e', 'f', 40, 0);
// for disconnected graph
        unordered_map<char, bool> vis;
for (char i = 'a'; i <='f'; i++)
{
    if(!vis[i]){
        g.dfs(i, vis);
        
    }
}


// this is extra test case......
// for(char ch = 'a'; ch<='f'; ch++){
//     if(!vis[ch]){
//    g.bfsTraversal(ch,vis);
//     }
// }

    return 0;
}