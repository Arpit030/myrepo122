#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void FCFS(vector<int> Process,vector<int> BT){
    int x=0;
    for(int i=0;i<Process.size();i++){
        cout<<"|"<<" P"<<Process[i];
    }
    cout<<"|"<<endl<<x;
    for(int i=0;i<BT.size();i++){
        x=x+BT[i];
        cout<<"   "<<x;
    }
    cout<<endl<<"Process\tTat\tWt";
    int l=0;
    for(int i=0;i<Process.size();i++){

        l=l+BT[i];
        cout<<l<<"  ";
    }
    cout<<endl<<"WT=";
    int p=0;
    for(int i=0;i<Process.size();i++){
        p=p+BT[i];
        cout<<p-BT[i]<<"  ";
    }
}
int main(){
vector<int> Process={1,2,3,4,5};
vector<int> BT={4,3,2,1,3};
FCFS(Process,BT);

return 0;
}
