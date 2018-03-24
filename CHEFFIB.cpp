//
//  main.cpp
//  CHEFFIB
//
//  Created by Abhishek Kumar Shakya on 10/12/17.
//  Copyright Â© 2017 Abhishek Kumar Shakya. All rights reserved.

#include<iostream>
#include<vector>
#include<queue>
#define no 1000000007
using namespace std;

int minEdgeBFS(vector <int> edges[], int u,
               int v, int n)
{
    
    vector<bool> visited(n, 0);
    
    vector<int> distance(n, 0);
    
    queue <int> Q;
    distance[u] = 0;
    
    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        
        for (int i=0; i<edges[x].size(); i++)
        {
            if (visited[edges[x][i]])
                continue;
            
            distance[edges[x][i]] = distance[x] + 1;
            Q.push(edges[x][i]);
            visited[edges[x][i]] = 1;
        }
    }
    return distance[v];
}

void addEdge(vector <int> edges[], int u, int v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t --){
        int n,q,x,y;
        cin>>n>>q;
        vector <int> edges[n];
        vector <int> arr(n);
        int min_dis[n][n];
        for(int i=1;i<n;i++){
            cin>>x>>y;
            addEdge(edges, x-1, y-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                min_dis[i][j] = minEdgeBFS(edges, j, i, n);
            }
        }
        int query,v,k,a,b;
        for(int i=0;i<q;i++){
            cin>>query;
            if(query == 1){
                cin>>v>>k>>a>>b;
                int fibo[k+1];
                if(k>=0)
                    fibo[0] = a;
                if(k>=1)
                    fibo[1] = b;
                for(int j=2;j<=k;j++)
                    fibo[j] = fibo[j-1]+fibo[j-2];
                
                if(k==0)
                    arr[v-1] += fibo[0];
                else{
                for(int j=0;j<n;j++){
                    int d = min_dis[v-1][j];
                    if(d<=k){
                        arr[j] += fibo[d];
                    }
                }
                }
            }
            else if(query == 2){
                cin>>v;
                cout<<arr[v-1]%no<<endl;
            }
        }
    }
    
    return 0;
}
