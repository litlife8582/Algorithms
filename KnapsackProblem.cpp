#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n,limit;
    cin>>n;

    double arr[100][3];
    for(int i=0;i<n;i++) cin>>arr[i][0];
    for(int i=0;i<n;i++) cin>>arr[i][1];

    cin>>limit;

    for (int i=0;i<n;i++) {
        arr[i][2]=arr[i][1]/arr[i][0];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j][2]<arr[j+1][2]){
                for (int k=0;k<3;k++) swap(arr[j][k],arr[j+1][k]);
            }
        }
    }

    double rw=limit;
    double tw,tv;
    double cw=0;
    for (int i=0;i<n;i++) {
        if (cw+arr[i][0]<=limit) {
            cw+=arr[i][0];
            tv+=arr[i][1];
            cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
        }else {
            double rw=limit-cw;
            tv+=arr[i][1]*(rw/arr[i][0]);
            cout<<rw<<" "<<arr[i][1]*(rw/arr[i][0])<<endl;
            break;
        }
    }

    cout<<"Total Profit: "<<tv<<endl;

    return 0;
}