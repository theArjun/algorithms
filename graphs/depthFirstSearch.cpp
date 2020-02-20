/*
Title : Depth First
Author :  Arjun Adhikari
Approach Used : Recursion Stack
*/

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int vertex_no;
    vector<int> *adjacent;

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

    /*  2020 Feb 20 Thu  22:17:11 - Arjun Adhikari
    Recursive Algorithm for Depth First Search  */
    void depthFirstSearch(int vertex, bool visited[])
    {
        /*  2020 Feb 20 Thu  22:17:27 - Arjun Adhikari
        Once the vertex is visited, assign it as visited on a separate boolean array.  */
        visited[vertex] = true;
        cout << vertex << " ";

        /*  2020 Feb 20 Thu  22:17:58 - Arjun Adhikari
        Traverse every adjacent vertex of the root vertex. */
        for(auto adjacent_vertex: adjacent[vertex]) {

            /*  2020 Feb 20 Thu  22:19:01 - Arjun Adhikari
            If the vertex is not visited, recursively call the function.   */
            if(!visited[adjacent_vertex]) {
                depthFirstSearch(adjacent_vertex, visited);
            }
        }
    }
};


int main()
{
    Graph graph(5);
    /*  2020 Feb 20 Thu  22:19:57 - Arjun Adhikari
    Initializing boolean array with false.  */
    bool visited[5] = { false };
    
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
