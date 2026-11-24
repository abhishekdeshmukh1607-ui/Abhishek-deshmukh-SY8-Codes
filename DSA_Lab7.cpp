#include <iostream>
using namespace std;

class Graph
{
private:
    int vertices, adj[20][20];

public:
    Graph()
    {
        vertices = 0;

        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void createGraph()
    {
        int edges, source, destination;

        cout << "\nEnter number of vertices: ";
        cin >> vertices;

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                adj[i][j] = 0;
            }
        }

        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "\nEnter edges (source destination):\n";

        for(int i = 0; i < edges; i++)
        {
            cout << "Edge " << i + 1 << ": ";
            cin >> source >> destination;

            if(source >= 0 && source < vertices &&
               destination >= 0 && destination < vertices)
            {
                adj[source][destination] = 1;
                adj[destination][source] = 1;
            }
            else
            {
                cout << "Invalid vertex number.\n";
                i--;
            }
        }

        cout << "\nGraph created successfully.\n";
    }

    void displayMatrix()
    {
        if(vertices == 0)
        {
            cout << "\nGraph is not created.\n";
            return;
        }

        cout << "\nAdjacency Matrix:\n\n";

        for(int i = 0; i < vertices; i++)
        {
            cout << i << ": ";

            for(int j = 0; j < vertices; j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    // DFS using Stack
    void DFS(int startVertex)
    {
        if(vertices == 0)
        {
            cout << "\nGraph is not created.\n";
            return;
        }

        if(startVertex < 0 || startVertex >= vertices)
        {
            cout << "\nInvalid starting vertex.\n";
            return;
        }

        int visited[20];
        int stack[20];
        int top = -1;

        for(int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }

        top++;
        stack[top] = startVertex;

        cout << "\nDFS Traversal: ";

        while(top != -1)
        {
            int current = stack[top];
            top--;

            if(visited[current] == 0)
            {
                cout << current << " ";
                visited[current] = 1;

                for(int i = vertices - 1; i >= 0; i--)
                {
                    if(adj[current][i] == 1 && visited[i] == 0)
                    {
                        top++;
                        stack[top] = i;
                    }
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g;
    int choice;
    int startVertex;

    do
    {
        cout << "\n========== GRAPH MENU ==========";
        cout << "\n1. Create Graph";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. DFS Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                g.createGraph();
                break;

            case 2:
                g.displayMatrix();
                break;

            case 3:
                cout << "\nEnter starting vertex for DFS: ";
                cin >> startVertex;
                g.DFS(startVertex);
                break;

            case 4:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while(choice != 4);

    return 0;
}