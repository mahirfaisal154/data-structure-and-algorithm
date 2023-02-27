///dijkstra's algorithm

#include<bits/stdc++.h>
#define  inf 10e9;
using namespace std;
int main()
{        priority_queue<pair<int,int>> q;

    int n;
    cin>>n;                                    /// n vertices
    int edge;                                 ///n edges
    cin>>edge;
    vector<vector<pair<int,int>>> v(n+1);    //adjacency list
    vector<int> dis(n+1,INT32_MAX);          //minimum distance  record 
    for(int i=1;i<=edge;i++)
    { 
          int a,b,w;
        cin>>a>>b>>w;                       //input of edges and corespond vertices
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
       int starting_index;               //strating index
       cin>>starting_index;
    
    dis[starting_index]=0; 
    vector<bool> visit(n,false);
    q.push({0,starting_index});
    while(!q.empty())
    {   
        int element=q.top().second;
        q.pop();
       if(visit[element]){continue;}
       visit[element]=true;
         for(auto x:v[element])
         {   if(dis[element]+x.second<dis[x.first])
              {
                dis[x.first]=dis[element]+x.second;    //relaxetion
                q.push({dis[x.first],x.first});
                    
              }
            
         }                                                                                 
 


    }

   for(auto x:dis)
   {
    cout<<x<<endl;
   }      
    
    

                                       
      
    
    


    return 0;
}