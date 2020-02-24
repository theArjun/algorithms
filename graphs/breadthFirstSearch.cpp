/*
Title : Breadth First Traversal
Author :  Arjun Adhikari
Approach Used : Queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int vertex_no;
    vector<int> *adjacent;
    queue<int> Queue;

public:
    /*  2020 Feb 20 Thu  21:57:24 - Arjun Adhikari
    Constructor for creating object from no of vertex.  */
    Graph(int vertex)
    {
        this->vertex_no = vertex;
        adjacent = new vector<int>[vertex];
    }

    /*  2020 Feb 20 Thu  22:16:37 - Arjun Adhikari
    Basic Edge Adding Stuff  */
    void addEdge(int vertex_one, int vertex_two)
    {
        adjacent[vertex_one].push_back(vertex_two);
        adjacent[vertex_two].push_back(vertex_one);
    }

    void breadthFirstSearch(int vertex, bool visited[])
    {
        /*  2020 Feb 20 Thu  22:26:38 - Arjun Adhikari
        Two Steps:
        1. Visiting the vertex
        2. Exploring the vertex  */

        // First element in the queue.
        Queue.emplace(vertex);
        visited[vertex] = true;

        while (!Queue.empty())
        {
            vertex = Queue.front();
            cout << vertex << " ";
            Queue.pop();

            /*  2020 Feb 24 Mon  18:09:37 - Arjun Adhikari
            Adds unvisited adjacent vertex to the queue. to the queue.  */
            for (auto adjacent_vertex : adjacent[vertex])
            {
                if (!visited[adjacent_vertex])
                {
                    visited[adjacent_vertex] = true;
                    Queue.emplace(adjacent_vertex);
                }
            }
        }
    }
};

int main()
{
    Graph graph(5);
    /*  2020 Feb 24 Mon  17:54:01 - Arjun Adhikari
    Mark all vertices as not visited.  */
    bool visited[5] = {false};

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(0, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 1);
    graph.addEdge(4, 3);
    graph.addEdge(3, 1);
    graph.addEdge(3, 2);

    graph.breadthFirstSearch(0, visited);
}
