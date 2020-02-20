/*
Title : Graph Data Structure
Author :  Arjun Adhikari
*/

#include <iostream>
#include <vector>
using namespace std;

/*  2020 Feb 20 Thu  21:09:07 - Arjun Adhikari
Vertex one and two are passed to form an edge.  */
void addEdge(vector<int> adjacent[], int vertex_one, int vertex_two)
{
    /*  2020 Feb 20 Thu  21:15:12 - Arjun Adhikari
    Forms like : For a Vertex 0, the adjacent list will be 0 ->1 ->2 ->3 and so on.
    Remember, the adjacent is an array of vectors.  */
    adjacent[vertex_one].push_back(vertex_two);
    adjacent[vertex_two].push_back(vertex_one);
}

void printGraph(vector<int> adjacent[], int vertex_no)
{
    for (int vertex = 0; vertex < vertex_no; vertex++)
    {
        cout << "Adjacency List of Vertex : " << vertex;
        // vector<int>::iterator element = adjacent[vertex].begin();
        for (auto element : adjacent[vertex])
        {
            cout << " -> " << element;
        }

        cout << endl;
    }
}

int main()
{
    /*  2020 Feb 20 Thu  21:04:18 - Arjun Adhikari
    We are representing Graph through Adjancency List.  */
    int vertex_no = 5;

    /*  2020 Feb 20 Thu  21:04:44 - Arjun Adhikari
    Creating an array of linked lists for representing as adjacency list.  */
    vector<int> adjacent[5];

    addEdge(adjacent, 0, 1);
    addEdge(adjacent, 1, 2);
    addEdge(adjacent, 0, 3);
    addEdge(adjacent, 2, 4);
    addEdge(adjacent, 4, 1);
    addEdge(adjacent, 4, 3);
    addEdge(adjacent, 3, 1);
    addEdge(adjacent, 3, 2);

    /*  2020 Feb 20 Thu  21:07:30 - Arjun Adhikari
    We are passing the adjacent linked list array and total no of vertex for printing.  */
    printGraph(adjacent, vertex_no);
}
