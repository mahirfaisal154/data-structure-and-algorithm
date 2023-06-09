#include<bits/stdc++.h>
using namespace std;
int tree[10000000],arr[100000];

void segment(int node,int minn,int maxx)
{  
    if(minn==maxx)
    {
        tree[node]=arr[minn];
        return ;
    }
    int left,right;
    left=node*2;
    right=node*2+1;
    int middle=(minn+maxx)/2;
    segment(left,minn,middle);
     segment(right,middle+1,maxx);
   tree[node]=tree[left]+tree[right];

}
int query(int node,int minn,int maxx,int i,int j)
{    
    if(j<minn || i>maxx)
    {    
        return 0;
    }
    if(i<=minn && j>=maxx)
    {   
        return tree[node];
    }
   int p=query(node*2,minn,(minn+maxx)/2,i,j);
    int q=query(node*2+1,(minn+maxx)/2+1,maxx,i,j);
    return p+q;
}
 void update(int node,int minn,int maxx,int i,int value)
 {   cout<<minn<<" "<<maxx<<endl;
      if(minn>i || maxx<i)return ;
    if(minn==maxx && minn==i)
    {    cout<<"meowhhh"<<endl;
        tree[node]=value;
        return ;
    }
    if(minn==maxx)return ;
       update(node*2,minn,(minn+maxx)/2,i,value);
    update(node*2+1,(minn+maxx)/2+1,maxx,i,value);
       
       tree[node]=tree[node*2]+tree[node*2+1];
 } 


int main()
{  
    int n;
    cin>>n;
    ;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

     segment(1,1,n);
     cout<<tree[2]<<" "<<tree[3]<<endl;
      cout<<"press -1 if want to terminate"<<endl;
      int p;
      cout<<"for summation press 1 and for update press 2"<<endl;
      cin>>p;
      while(p!=-1)
      {
           if(p==1)
           { int l,u;
             cout<<"enter the range"<<endl;
            cin>>l>>u;
            cout<<query(1,1,n,l,u);
           }
           else 
           {    int indx,val;
               cout<<"enter the index number and value"<<endl;
           cin>>indx>>val;
           update(1,1,n,indx,val);
           }
            cout<<"press -1 if want to terminate"<<endl;
             cout<<"for summation press 1 and for update press 2"<<endl;
            cin>>p;

     


      }


    return 0;
}