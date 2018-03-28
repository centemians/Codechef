//
//  main.cpp
//  CPLAY
//
//  Created by Abhishek Kumar Shakya on 02/12/17.
//  Copyright © 2017 Abhishek Kumar Shakya. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,winner;
    int goal_a,goal_b,no_kicks;
    int temp_goal_a,temp_goal_b,goal_rem;
    //for(int i=0;i<1000000;i++)
    while(std::getline(std::cin,s)){
        //cin>>s;
        goal_a = (s[0]-'0')+(s[2]-'0')+(s[4]-'0')+(s[6]-'0')+(s[8]-'0');
        goal_b = (s[1]-'0')+(s[3]-'0')+(s[5]-'0')+(s[7]-'0')+(s[9]-'0');
        if(goal_b > goal_a){
            temp_goal_a = 0;
            temp_goal_b = 0;
            goal_rem = 5;
            for(int j=0;j<10;j++){
                if(j % 2 == 0){
                    temp_goal_a += s[j]-'0';
                    goal_rem --;
                }
                else
                    temp_goal_b += s[j]-'0';
                if((temp_goal_a + goal_rem) < temp_goal_b){
                    no_kicks = j+1;
                    break;
                }
            }
        }
        else if(goal_b < goal_a){
            temp_goal_a = 0;
            temp_goal_b = 0;
            goal_rem = 5;
            for(int j=0;j<10;j++){
                if(j % 2 == 0){
                    temp_goal_a += s[j]-'0';
                }
                else{
                    temp_goal_b += s[j]-'0';
                    goal_rem --;
                }
                if((temp_goal_b + goal_rem) < temp_goal_a){
                    no_kicks = j+1;
                    break;
                }
            }
        }
        else{
            for(int j=10;j<20;j++){
                if(j % 2 == 0)
                    goal_a += s[j]-'0';
                else{
                    goal_b += s[j]-'0';
                    if(goal_a != goal_b){
                        no_kicks = j+1;
                        break;
                    }
                }
            }
        }
        
        if(goal_a > goal_b){
            cout<<"TEAM-A"<<" "<<no_kicks;
            cout<<endl;
        }
        else if(goal_b > goal_a){
            cout<<"TEAM-B"<<" "<<no_kicks;
            cout<<endl;
        }
        else
            cout<<"TIE"<<endl;
        
    }
    return 0;
    
}
