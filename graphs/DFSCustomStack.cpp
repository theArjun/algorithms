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
    Graph(int vertex)
    {
        this->vertex_no = vertex;
        adjacent = new vector<int>[vertex];
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
    Graph graph(0);

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