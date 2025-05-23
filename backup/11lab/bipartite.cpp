#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool bipartite(int V,vector<int> adj[]){
    queue<int> q;
    q.push(0);
    int colour[V];
    for(int i=0;i<V;i++){
        colour[i]=-1;
    }
    colour[0]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(colour[it]==-1){
                colour[it]=1-colour[node];
                q.push(it);
            }
            else if(colour[it]==colour[node]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<int> adj[6];
    adj[0].push_back(3);
    adj[0].push_back(4);
    adj[1].push_back(3);
    adj[1].push_back(5);
    adj[2].push_back(3);
    adj[2].push_back(5);
    if(bipartite(6,adj)){
        cout<<"bipartite graph"<<endl;
    }
    else{
        cout<<"not a bipartite graph";
    }
    return 0;
}