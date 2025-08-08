#include<iostream>
#include<vector>
using namespace std;

//   DIRECTED UNWEIGHTED GRAPH
//   ADJACENCY MATRIX representation hai ye



int main()
{
    int vertex  , edges;
    cin>>vertex>>edges;
    int u , v;

    vector<vector<bool> >AdjacencyMat(vertex , vector<bool>(vertex,0));  // ye line bta rha hai ki adjacency matrix ka size vertex ke size ke braabr hai aur initialize 0 se kiya gya hai
    for(int i = 0; i<edges ; i++)
    {
       cin>>u>>v;
       AdjacencyMat[u][v]=1;
       

    }

    for(int i = 0 ; i<vertex ; i++)
    {
        for(int j = 0 ; j< vertex ; j++)
        {
            cout<<AdjacencyMat[i][j]<<" ";
        }
        cout<<endl;
    }

}