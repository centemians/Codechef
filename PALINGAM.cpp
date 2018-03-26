//
//  main.cpp
//  PALINGAM
//
//  Created by Abhishek Kumar Shakya on 12/12/17.
//  Copyright © 2017 Abhishek Kumar Shakya. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    while(t --){
        string s1,s2;
        cin>>s1;
        cin>>s2;
        long len = s1.size();
        if(len<27){
            vector <int> a1(26),a2(26);
            for(int i=0;i<len;i++){
                for(int j=97;j<123;j++){
                    if(int(s1[i])==j)
                       a1[j-97] ++;
                    if(int(s2[i])==j)
                       a2[j-97] ++;
                }
            }
            int counter1 = 0,counter2=0,same=0,diff=0;
            for(int i=0;i<26;i++){
                if(a2[i]>=a1[i]&&a1[i]!=0){
                    counter2 ++;
                    break;
                }
                else if((a1[i]>1&&a2[i]==0)){
                    counter1 ++;
                    break;
                }
                else if(a1[i] == a2[i]){
                    same ++;
                }
                else if((a1[i]==1&&a2[i]==0)||(a2[i]==1&&a1[i]==0)){
                    diff ++;
                }
            }
            if(counter2>0)
                cout<<'B'<<endl;
            else if(counter1>0)
                cout<<'A'<<endl;
            else if(same==26)
                cout<<'B'<<endl;
            else if(diff == 26)
                cout<<'B'<<endl;
        }
            
    }
    return 0;
}
