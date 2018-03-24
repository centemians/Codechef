//
//  main.cpp
//  CHEFCOUN
//
//  Created by Abhishek Kumar Shakya on 13/10/17.
//  Copyright © 2017 Abhishek Kumar Shakya. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    long long n;
    while(t --){
        unsigned int sum=0;
        cin>>n;
        cout<<1<<" "<<970<<" ";
        sum = 971;
        for(int i=2;i<=100;i++){
            cout<<670<<" ";
            sum+=670;
        }
        for(int i=101;i<=43048;i++){
            cout<<100000<<" ";
            sum+=100000;
        }
        for(int i=43049;i<n;i++){
            cout<<1<<" ";
            sum+=1;
        }
        int temp = 4294967295-sum-1;
        //unsigned int sum1 = sum;
        cout<<temp;
        cout<<endl;
        //sum1+=temp;
        //unsigned int sum2 = sum1 + 1;
        //unsigned int sum3 = sum1 + temp;
        //cout<<"\n"<<sum2<<endl;
        //cout<<sum3;
    
    }
    return 0;
}


