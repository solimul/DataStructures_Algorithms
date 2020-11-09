

#include <iostream>

using namespace std;

class Graph
{
    public:
    struct GraphMatrix
    {
        int **matrix;
        int num_vertices;
        int num_edges;
    };
    
    GraphMatrix *gm;
    
    Graph()
    {
        gm = new GraphMatrix();        
    }
    
    ~Graph()
    {
        for(int i=0;i<gm->num_vertices;i++)
            delete [] gm->matrix[i];
        delete [] gm->matrix;
    }
    
    void allocate()
    {
        gm->matrix = new int*[gm->num_vertices];
        for(int i=0;i<gm->num_vertices;i++)
        {
            gm->matrix[i] = new int [gm->num_vertices];
            for(int j=0;j<gm->num_vertices;j++)
                gm->matrix[i][j]=0;
        }
    }
    
    
        
        void print_graph()
        {
            for(int i=0;i<gm->num_vertices;i++)
            {
                cout<<"\n";
                for(int j=0;j<gm->num_vertices;j++)
                    cout<<gm->matrix[i][j]<<" ";
            }
        }
    
    
    void build_graph_from_user_input()
    {
        cout<<"\nEnter number of vertices: ";
        cin>>gm->num_vertices;
        cout<<"\nEnter number of edges: ";
        cin>>gm->num_edges;
        
        allocate();
        
        int u,v;
        cout<<"\nEnter "<<gm->num_edges<<" for the vertices 1 .."<<gm->num_vertices<<" as pairs e=(u, v):";
        for(int i=0; i<gm->num_edges;i++)
        {
            cout<<"\n edge "<<i+1<<":";
            cin>>u>>v;
            gm->matrix[u-1][v-1] = 1;
            gm->matrix[v-1][u-1] = 1;
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