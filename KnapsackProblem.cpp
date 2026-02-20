#include<iostream>
#include<vector>
using namespace std;

int main() {
    double n;
    cin>>n;
    vector<vector<double>> A(n,vector<double>(3));

    for (int i=0;i<n;i++) cin>>A[i][0];
    for (int i=0;i<n;i++) cin>>A[i][1];
    for (int i=0;i<n;i++) A[i][2]=A[i][1]/A[i][0];

    double limit;
    cin>>limit;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (A[j][2]<A[j+1][2]) {
                double temp0=A[j][0];
                double temp1=A[j][1];
                double temp2=A[j][2];
                A[j][0]=A[j+1][0];
                A[j][1]=A[j+1][1];
                A[j][2]=A[j+1][2];
                A[j+1][0]=temp0;
                A[j+1][1]=temp1;
                A[j+1][2]=temp2;
            }
        }
    }

    double totalValue=0,totalWeight=0;

    for (int i=0;i<n;i++) {
        if (totalWeight+A[i][0]<=limit) {
            totalWeight+=A[i][0];
            totalValue+=A[i][1];
        }else if(totalWeight+A[i][0]>limit){
            double remainingWeight=limit-totalWeight;
            totalValue+=A[i][2]*remainingWeight;
            totalWeight+=remainingWeight;
        }
    }


    cout<<"Total profit: "<<totalValue<<endl;
    return 0;
}
