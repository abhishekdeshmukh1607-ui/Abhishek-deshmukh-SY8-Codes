#include <iostream>
using namespace std;
class Node
{
public:
    int vertex;
    Node *next;
    Node(int v)
    {
        vertex = v;
        next = NULL;
    }
};

class Graph
{
private:
    int vertices;

    Node *adj[20];
    int queue[20],front ,rear;
    int visited[20];
public:
    Graph(int v)
    {
        vertices = v;
        
        for (int i = 0; i < vertices; i++)
        {
            adj[i] = NULL;
            visited[i] = 0;
        }
       front = -1;
        rear = -1;
    }


        void addEdge(int src, int dest)
    {
        
        Node *newNode = new Node(dest);
       
        newNode->next = adj[src];
        adj[src] = newNode;
       
        newNode = new Node(src);
        
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }
        void displayGraph()
    {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " -> ";
            Node *temp = adj[i];
            while (temp != NULL)
            {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
        void enqueue(int vertex)
    {
        
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = vertex;
    }
        int dequeue()
    {
        int vertex = queue[front];
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        return vertex;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    void BFS(int start)
    {
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }
        visited[start] = 1;

        enqueue(start);
        cout << "\nBFS Traversal: ";

        while (!isEmpty())
        {

            int current = dequeue();

            cout << current << " ";
            
            Node *temp = adj[current];
            
            while (temp != NULL)
            {
                int neighbour = temp->vertex;
                
                if (visited[neighbour] == 0)
                {
                    
                    visited[neighbour] = 1;
                   
                    enqueue(neighbour);
                }
               
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    g.displayGraph();

    int start;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;

    g.BFS(start);

    return 0;
}