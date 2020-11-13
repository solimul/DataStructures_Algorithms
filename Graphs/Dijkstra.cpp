

#include <iostream>
#include<vector>
#include<climits>
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
    
    int * distance;
    int * path;
    bool *visited;
    int source;
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
        distance = new int [gm->num_vertices];
        visited = new bool [gm->num_vertices];
        path = new int [gm->num_vertices];
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
        
        int u,v,w;
        cout<<"\nEnter "<<gm->num_edges<<" for the vertices 1 .."<<gm->num_vertices<<" as pairs e=(u, v):";
        for(int i=0; i<gm->num_edges;i++)
        {
            cout<<"\n edge "<<i+1<<":";
            cin>>u>>v>>w;
            gm->matrix[u-1][v-1] = w;
            gm->matrix[v-1][u-1] = w;
        }
    }
    
    int get_min_node()
    {
        int min=INT_MAX, min_idx;
        for(int i=0; i<gm->num_vertices;i++)
        {
            if(min>distance[i] && !visited[i])
            {
                min = distance[i];
                min_idx = i;
            }
        }
        return min_idx;
    }
    
    void dijkstra_shorted_distance(int src)
    {
        source = src;
        for(int i=0; i< gm->num_vertices;i++)
        {
            distance[i] = INT_MAX;
            visited[i] = false;
        }
        
        distance[source] = 0;
        
        for(int i=0;i<gm->num_vertices;i++)
        {
            int u = get_min_node();
            visited[u] = true;
            for(int v=0;v<gm->num_vertices;v++)
            {
                if(gm->matrix[u][v] 
                    && gm->matrix[u][v] + distance[u] < distance[v] 
                    && distance[u]!=INT_MAX 
                    )
                    {
                        distance[v] = gm->matrix[u][v] + distance[u];
                        path[v] =u;
                        //if(visited[v]) visited[v] = false; //For negative weight .. Bellman-Ford
                    }
            }
        }
        
        for(int i=0;i<gm->num_vertices;i++)
            cout<<"\nSource "<< source+1 << " to vertex "<<i+1<<" is: "<<distance[i];
    }
    
    void print_path_from_source(int destination)
    {
        int temp=destination;
        vector<int> constructed_path;
        do
        {
            constructed_path.push_back(temp);
            temp=path[temp];
        } while(temp!=source);
        
        constructed_path.push_back(source);
        cout<<"\nPath from "<<source+1<<" to "<<destination+1<<": ";
        for(int i = constructed_path.size()-1; i>=0; i--)
            cout<<constructed_path[i]+1<<"-";
    }
    
    void print_path()
    {
        cout<<"\n";
        for(int i=0;i<gm->num_vertices;i++)
        {
            if(i!=source)
                print_path_from_source(i);
        }
    }
    
};

int main ()
{
    Graph graph;
    graph.build_graph_from_user_input();
    graph.print_graph();
    graph.dijkstra_shorted_distance(0);
    graph.print_path();
    return 0;
}
