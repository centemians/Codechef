#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t,n,m,num;
    cin>>t;
    while(t--){
        cin>>n;
        vector <int> v[n];
        for(int i=0;i<n;i++){
            cin>>m;
            v[i].push_back(m);
            while(m --){
                cin>>num;
                v[i].push_back(num);
            }
            int min_a = *min_element(v[i].begin()+1,v[i].end());
            int max_a = *max_element(v[i].begin()+1,v[i].end());
            v[i].push_back(min_a);
            v[i].push_back(max_a);
            
        }
        long long sum=0,sum1=0,sum2=0,max1;
        int first;
        for(int i = n-1;i>0;i--){
            if(i == n-1){
                int diff1 = abs(v[i][v[i][0]+1]-v[i-1][v[i-1][0]+2]);
                int diff2 = abs(v[i][v[i][0]+2]-v[i-1][v[i-1][0]+1]);
                if(diff1>=diff2){
                    first = v[i-1][v[i-1][0]+1];
                    sum+=diff1*i;
                }
                else{
                    first = v[i-1][v[i-1][0]+2];
                    sum+=diff2*i;
                }
                
            }
            else{
                int diff1 = abs(first-v[i-1][v[i-1][0]+2]);
                int diff2 = abs(first-v[i-1][v[i-1][0]+1]);
                if(diff1>=diff2){
                    first = v[i-1][v[i-1][0]+1];
                    sum+=diff1*i;
                }
                else{
                    first = v[i-1][v[i-1][0]+2];
                    sum+=diff2*i;
                }
                
            }
            
            int diff3 = abs(v[i][v[i][0]+1]-v[i-1][v[i-1][0]+2]);
            sum1+=diff3*i;
            
            int diff4 = abs(v[i][v[i][0]+2]-v[i-1][v[i-1][0]+1]);
            sum2+=diff4*i;
            
        }
        max1 = max(sum1,sum2);
        cout<<max(sum,max1)<<endl;
    }
    return 0;
}
