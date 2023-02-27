//warshel algorithm

#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n,edge;                   //number of nodes and edges  
    cin>>n>>edge;
    int adj[n+1][n+1];               ///adjacency matrix 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {                             //  initialing adjacency matrix with a big value
            adj[i][j]=1000;
            if(i==j)adj[i][j]=0;
        }
    }
    for(int i=1;i<=edge;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a][b]=w;         //taking  input edge and coresponding node and inserting it to adjacency matrix
        adj[b][a]=w;
    }
   
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);        ///relaxation 
                
            }
        }
    }
   cout<<endl;
   for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        { 
            cout<<adj[i][j]<<" ";       //printing the final adjacency matrix after completing relaxation
        }
        cout<<endl;
    }
   

    return 0;
}