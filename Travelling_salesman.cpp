#include<iostream>
#include<vector>
using namespace std;

int costed=0;
void tour(int n,vector<vector<int> > cost,vector<int > visited,int current,int start){
  int next;
  visited[current]=1;
  cout<<current+1<<"->";
    
  int min=999,kmin=999,nc=999;
  for(int i=0;i<n;i++){
    if(cost[current][i]!=0 && visited[i]==0 && cost[current][i]<kmin){
      min=cost[i][0]+cost[current][i];
      kmin=cost[current][i];
      nc=i;
    }
  }
  if(min!=999)
    costed+=kmin;
  next=nc;
  
  if(next==999){
    cout<<start+1;
    costed+=cost[current][start];
    return;
  }
  tour(n,cost,visited,next,start);
}

int main(){
  int n,start;
  cout<<"Enter the number of cities : ";
  cin>>n;
  vector<vector<int> > cost(n,vector<int>(n,0));
  cout<<"Enter the cost adjacency matrix : "<<endl;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>cost[i][j];
  cout<<"Enter the starting city : ";
  cin>>start;
  start--;
  
  vector<int > visited(n,0);
  tour(n,cost,visited,start,start);
  
  cout<<endl<<"Minimum cost : "<<costed<<endl;
  return 0;
}