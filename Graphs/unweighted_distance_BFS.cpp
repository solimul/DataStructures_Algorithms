

#include <iostream>
#include <queue>
using namespace std;



class Graph
{
    public:
    
    int * distance;
    struct Node
    {
        int vertex_key;
        struct Node *prev; 
    }; 
    
    queue<Node*> frontier;    

    Node ** adjacent_list_heads;
    int num_vertices;
    int num_edges;
    
    
    
    ~Graph()
    {
        // for(int i=0;i<gm->num_vertices;i++)
        //     delete [] gm->matrix[i];
        // delete [] gm->matrix;
    }
    
    void allocate()
    {
        adjacent_list_heads = new Node *[num_vertices];
        Node * temp;
        for(int i=0;i<num_vertices;i++)
        {
            temp = new Node;
            temp->vertex_key = i;
            temp->prev = NULL;
            adjacent_list_heads[i] = temp;
            temp=NULL;
        }
        distance = new int [num_vertices];
    }
    
    
        
        void print_graph()
        {
            Node *end;
            for(int i=0;i<num_vertices;i++)
            {
                cout<<"\n"<<i+1<<">>";
                end = adjacent_list_heads[i];
                while(end->prev!=NULL)
                {
                    cout<<end->vertex_key+1<<" ";
                    end = end->prev;
                }
            }
        }
    
    inline void add_edge(int u, int v)
    {
        Node *edge_end = new Node(); 
        edge_end->vertex_key = v-1;
        edge_end->prev = adjacent_list_heads[u-1];
        adjacent_list_heads[u-1] = edge_end;
    }
    
    void build_graph_from_user_input()
    {
        cout<<"\nEnter number of vertices: ";
        cin>>num_vertices;
        cout<<"\nEnter number of edges: ";
        cin>>num_edges;
        
        allocate();
        int u,v;
        cout<<"\nEnter "<<num_edges<<" with "<<num_vertices;
        
        for(int i=0; i<num_edges;i++)
        {
            cout<<"\n edge "<<i+1<<":";
            cin>>u>>v;
            add_edge(u,v);
            add_edge(v,u);
        }
    }
    
    void compute_distance(int start)
    {
        /**
            Computes distance from the 'start' node to the other nodes of the unweighted graph.
            Uses
                (i) a 'distance' table where distance from 'start' to other nodes are stored and updated iteratively. 
                    distance is initialized to 0.
                (ii) a 'queue' to perform a BFS search: only unvisited neighbors of a node is examined and gets update on the distance.
            
         */
        Node * s = index_to_node(start);
        frontier.push(s);
        for(int i=0;i<num_vertices;i++)
            distance[i]=-1;
        distance[s->vertex_key]=0;
        Node* node;
        while(!frontier.empty())
        {
            node = frontier.front();
            frontier.pop();
            Node* edge_end = adjacent_list_heads[node->vertex_key];
            while(edge_end->prev!=NULL)
            {
                if(distance[edge_end->vertex_key]==-1)
                {
                    distance[edge_end->vertex_key] = distance[node->vertex_key] + 1;
                    frontier.push(edge_end);
                }
                edge_end=edge_end->prev;
            }
        }
        
        for(int i=0;i<num_vertices;i++)
            cout<<"\nDistance from "<< start+1<<" to "<<i+1<<" is "<<distance[i]<<" ";
    }
    
    Node* index_to_node(int index)
    {
        Node * n = adjacent_list_heads[index];
        while(n->prev!=NULL)
            n=n->prev;
        return n; 
    }
};


int main ()
{
    Graph graph;
    graph.build_graph_from_user_input();
    graph.print_graph();
    graph.compute_distance(1);
    return 0;
}
