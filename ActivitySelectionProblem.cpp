#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[100][2];
    for(int i=0;i<n;i++) cin>>arr[i][0];
    for(int i=0;i<n;i++) cin>>arr[i][1];

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j][1]>arr[j+1][1]){
                int temp0=arr[j][0];
                int temp1=arr[j][1];
                arr[j][0]=arr[j+1][0];
                arr[j][1]=arr[j+1][1];
                arr[j+1][0]=temp0;
                arr[j+1][1]=temp1;
            }
        }
    }

    int index=0;
    cout<<"("<<arr[0][0]<<","<<arr[0][1]<<")";
    for (int i=1;i<n;i++) {

        if (arr[i][0]>=arr[index][1]) {
            index=i;
            cout<<"("<<arr[i][0]<<","<<arr[i][1]<<")";
        }
    }


    return 0;
}