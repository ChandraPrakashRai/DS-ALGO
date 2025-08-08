#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int vertex ,edges, weight;
    cin>>vertex >> edges;
    int u , v;

    vector<vector<int> >AdjMat(vertex,vector<int>(vertex,0));

    for(int i=0 ; i<edges ; i++)
    {
        cin>>u>>v>>weight;
        AdjMat[u][v] = weight;
        AdjMat[v][u] = weight;
    }

    // print them
    for(int i =0 ; i<vertex ; i++)
    {
        for(int j =0 ; j<vertex ;  j++)
        {
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}