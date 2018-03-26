//
//  main.cpp
//  RECTANGL
//
//  Created by Abhishek Kumar Shakya on 12/01/18.
//  Copyright © 2018 Abhishek Kumar Shakya. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    while(t --){
        int a[4];
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        sort(a,a+4);
        if(a[0]==a[1]&&a[2]==a[3])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
    
    
}
