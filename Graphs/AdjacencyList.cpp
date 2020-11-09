

#include <iostream>
using namespace std;



class Graph
{
    public:
    
    
    struct Node
    {
        int vertex_key;
        struct Node *prev; 
    };
    
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
    //    print_graph();  
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
};


int main ()
{
    Graph graph;
    graph.build_graph_from_user_input();
    graph.print_graph();
    return 0;
}

