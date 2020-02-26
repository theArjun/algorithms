#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int vertex_no;
    vector<int> *adjacent;
    stack<int> Stack;

public:
    Graph(int vertex_size)
    {
        this->vertex_no = vertex_size;
        adjacent = new vector<int>[vertex_size];
    }

    void addEdge(int vertex_one, int vertex_two)
    {
        adjacent[vertex_one].push_back(vertex_two);
        adjacent[vertex_two].push_back(vertex_one);
    }

    void depthFirstSearch(int vertex, bool visited[])
    {
        Stack.push(vertex);
        visited[vertex] = true;

        while(!Stack.empty())
        {
            vertex = Stack.top();
            cout << vertex << " ";
            Stack.pop();

            for(auto adjacent_vertex : adjacent[vertex])
            {
                if(!visited[adjacent_vertex])
                {
                    visited[adjacent_vertex] = true;
                    Stack.push(adjacent_vertex);
                }
            }
        }
    }

    
};

int main()
{
    /*  2020 Feb 26 Wed  18:57:48 - Arjun Adhikari
    Total no. of vertices in graph. */    
    Graph graph(5);

    bool visited[5] = {false};

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(0, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 1);
    graph.addEdge(4, 3);
    graph.addEdge(3, 1);
    graph.addEdge(3, 2);

    graph.depthFirstSearch(0, visited);
}