#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
vector<int> temp;
int n;
int target;
bool found=false;

void print(int len) {
    for (int i=0;i<len;i++) {
        cout<<temp[i];
        if (i<len-1) cout<<" ";
    }
    cout<<endl;
}

void subset(int idx,int currentSum,int len) {
    for (int i=idx;i<n;i++) {
        if (currentSum+arr[i]<=target) {
            temp[len]=arr[i];
            if (currentSum+arr[i]==target) {
                found=true;
                print(len+1);
            }else {
                subset(i+1,currentSum+arr[i],len+1);
                print(len+1);
            }
        }
    }
}

int main() {
    cin>>n;
    arr.resize(n);
    temp.resize(n);
    for (int i=0;i<n;i++) cin>>arr[i];

    cin>>target;
    subset(0,0,0);
    if (found) cout<<"Subset sum found: "<<target<<endl;
    else cout<<"Subset sum not found"<<endl;
}