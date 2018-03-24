//
//  main.cpp
//  CHEFEXQ
//
//  Created by Abhishek Kumar Shakya on 02/12/17.
//  Copyright Ã�Â© 2017 Abhishek Kumar Shakya. All rights reserved.
//

// bit_xor example
#include <iostream>     // std::cout
#include <functional>   // std::bit_xor
#include <algorithm>    // std::accumulate
#include <iterator>     // std::end
#include <numeric>
using namespace std;
int n,arr[1000001],xorarray[1000001],counter;
int count(int num1,int num2){
    for(int j=1;j<=num1;j++){
        if(xorarray[j] == num2)
            counter ++;
    }
    return counter;
}

int minimum(int a,int b){
    return a<b?a:b;
}

void update(int min){
    for(int i=min;i<=n;i++){
        xorarray[i] = arr[i]^xorarray[i-1];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q,query,num1,num2,min;
    cin>>n>>q;
    //int arr[n+1];
    //int xorarray[n+1];
    //int copy_arr[n+1];
    min = 1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        //copy_arr[i] = arr[i];
    }
    xorarray[0] = 0;
    update(min);
    min = n+1;
    for(int i=0;i<q;i++){
        counter = 0;
        cin>>query>>num1>>num2;
        if(query==1){
            arr[num1] = num2;
            if(num1<min)
                min = num1;
        }
        else if(query==2){
            if(num1>=min){
                update(min);
                min = n+1;
            }
            
            for(int j=1;j<=num1;j++){
                if(xorarray[j] == num2)
                    counter ++;
            }
            cout<<counter<<endl;
        }
    }
    
    return 0;
}
