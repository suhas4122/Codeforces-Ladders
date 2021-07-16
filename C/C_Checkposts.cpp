#include <iostream>
#include <list>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
long long int price[100000];
const long long int N = 1e9 + 7;
long long int modM(long long int n, long long int m) { return ((n % N * m % N) + N) % N; }
long long int modA(long long int n, long long int m) { return ((n % N + m % N) + N) % N; }
#define for0(n) for (long long i = 0; i < (long long)(n); ++i) // 0 based indexing
#define for0j(n) for (long long j = 0; j < (long long)(n); ++j) // 0 based indexing

long long int cost = 0;
long long int counter = 1;

class Graph
{
    long long int V;    // No. of vertices
    list<long long int> *adj;    // An array of adjacency lists
  
    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing 
    // time
    void fillOrder(long long int v, bool visited[], stack<long long int> &Stack);
  
    // A recursive function to prlong long int DFS starting from v
    void DFSUtil(long long int v, bool visited[], vector<long long int>& order);
public:
    Graph(long long int V);
    void addEdge(long long int v, long long int w);
  
    // The main function that finds and prlong long ints strongly connected
    // components
    void printSCCs();
  
    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};
  
Graph::Graph(long long int V)
{
    this->V = V;
    adj = new list<long long int>[V];
}
  
// A recursive function to prlong long int DFS starting from v
void Graph::DFSUtil(long long int v, bool visited[], vector<long long int>& order)
{
    // Mark the current node as visited and prlong long int it
    visited[v] = true;
    order.push_back(price[v]);
  
    // Recur for all the vertices adjacent to this vertex
    list<long long int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited, order);
}
  
Graph Graph::getTranspose()
{
    Graph g(V);
    for (long long int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<long long int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
  
void Graph::addEdge(long long int v, long long int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
  
void Graph::fillOrder(long long int v, bool visited[], stack<long long int> &Stack)
{
    // Mark the current node as visited and prlong long int it
    visited[v] = true;
  
    // Recur for all the vertices adjacent to this vertex
    list<long long int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
  
    // All vertices reachable from v are processed by now, push v 
    Stack.push(v);
}
  
// The main function that finds and prlong long ints all strongly connected 
// components
void Graph::printSCCs()
{
    stack<long long int> Stack;
  
    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(long long int i = 0; i < V; i++)
        visited[i] = false;
  
    // Fill vertices in stack according to their finishing times
    for(long long int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
  
    // Create a reversed graph
    Graph gr = getTranspose();
  
    // Mark all the vertices as not visited (For second DFS)
    for(long long int i = 0; i < V; i++)
        visited[i] = false;
  
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        long long int v = Stack.top();
        Stack.pop();

        vector<long long int> order;
        // Prlong long int Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited, order);
            long long int minimum = *min_element(order.begin(), order.end());
            cost += minimum;
            // cout << "Minimum : " << minimum << endl;
            long long int number = count(order.begin(), order.end(), minimum);
            counter = modM(counter, number);
            order.clear();
        }
    }
}
  
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    long long int n;
    cin >> n;
    Graph g(n);
    for0(n) 
        cin >> price[i];

    long long int m;
    cin >> m;

    for0(m){
        long long int x, y;
        cin >> x >> y;
        g.addEdge(x-1,y-1);
    }  

    g.printSCCs();

    cout << cost << " " << counter;
  
    return 0;
}