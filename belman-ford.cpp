 //belman ford algorithm
  #include<bits/stdc++.h>
  using namespace std;
  struct EDGE      /// creat a  to save the information of edges
  {
       int a,b,e;
  };
  
  int main()
  {
    int n,edge;   //number of vertices and edges
    cin>>n>>edge;   //input of vertices and edges
    struct EDGE edge_of_graph[edge];   //structure created for edges
       int dis[n+1];    //distance tracker
       for(int i=1;i<=n;i++)
       {
         dis[i]=INT16_MAX;
       }
           
       for(int i=0;i<edge;i++)
       { 
         int a,b,val;
         cin>>a>>b>>val;    //edges information input
          edge_of_graph[i].a=a;  //save
          edge_of_graph[i].b=b;   //save
          edge_of_graph[i].e=val;  //save


      }
        
   cout<<"enter the starting node"<<endl;
   int starting_node;  //starting node container
   cin>>starting_node;   //input
   dis[starting_node]=0;
   bool meow;
   for(int i=1;i<n;i++)    //belman ford starts here
   {    meow=true;
      for(auto x:edge_of_graph)   //inner edge loops
      {   
         if(dis[x.b]>dis[x.a]+x.e)   //relaxation
         {
            dis[x.b]=dis[x.a]+x.e;
    meow=false;
         }        
    

      }
         if(meow){break;} //if remains relax then terminate
   }
 meow=false;
  for(auto x:edge_of_graph)    //negetive cycle check 
      {
         if(dis[x.b]>dis[x.a]+x.e)
         {
            dis[x.b]=dis[x.a]+x.e;
    meow=true;
         }        
    

      }
if(meow)
{
    cout<<"NEGETIVE CYCLE CONTAINS"<<endl;
    cout<<"BELLMAN-FORD ALGORITHM IS NOT APPLICABLE"<<endl;
  return 0;
}
   for(int i=1;i<=n;i++)
   {
     cout<<i<<" "<<dis[i]<<endl;   //output
   }         

     



    return 0;
  }

