

#include <iostream>
#include <queue>
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
        // for(int i=0;i<gm->num_vertices;i++)
        //     delete [] gm->matrix[i];
        // delete [] gm->matrix;
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
                for(int j=0;j<gm->num_vertices;j++){
                    cout<<gm->matrix[i][j]<<" ";
                }
            }
            cout<<"\n";
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
        }
    }
};

class TopologicalOrdering
{
    public:
    int * indegree;
    Graph graph;
    int adjacent_size;
    queue<int> primal_vertices;
    
    TopologicalOrdering(Graph gr)
    {
        graph = gr;
        indegree=new int [graph.gm->num_vertices];
        for(int j=0;j<graph.gm->num_vertices;j++)
        {
            indegree[j] = indegree_for_v(j);
            if(indegree[j]==0)
                primal_vertices.push(j);
        }

    }
    
    inline int indegree_for_v(int v)
    {
        int total=0;
        for(int i=0;i<graph.gm->num_vertices;i++)
            total+=graph.gm->matrix[i][v];
        return total;
    }
    
    int * adjacent_of_v(int v)
    {
        int * adjacent = new int [graph.gm->num_vertices];
        for(int i=0; graph.gm->num_vertices;i++)
        {
            if(graph.gm->matrix[v][i])
            {
                adjacent[adjacent_size]=i;
                adjacent_size++;
            }
        }
        return adjacent;
    }
    
    
    
    void topological_sort()
    {
        /**
             1>>>2>>>>5   -----------------> 1 3 2 4 5 (Topological Order)
                 ^    ^
                 ^    ^
                 ^    ^
                 3 >> 4
         * */
        cout<<"Topologically Sorted Order: ";
        while(!primal_vertices.empty())
        {
            int pv = primal_vertices.front();
            cout<<" "<<pv+1;
            primal_vertices.pop();
            for(int i=0;i<graph.gm->num_vertices;i++)
            {
                if(graph.gm->matrix[pv][i])
                {
                    if(--indegree[i] == 0)
                        primal_vertices.push(i);
                }
            }
        }
    }
};


int main ()
{
    Graph graph;
    graph.build_graph_from_user_input();
    graph.print_graph();
    TopologicalOrdering to(graph);
    to.topological_sort();
    return 0;
}
