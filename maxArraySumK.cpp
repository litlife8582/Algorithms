#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

long long midPointSum(vector<int>& A,int low,int mid,int high,int k) {
    long long bestSum=LLONG_MIN;
    int start=max(low,mid-k+1);
    int end=min(mid,high-k+1);

    for (int i=start;i<=end;i++) {
        long long currentSum=0;
        for (int j=0;j<k;j++) {
            currentSum=A[i+j];
        }
        if (currentSum>bestSum) {
            bestSum=currentSum;
        }
    }

    return bestSum;

}

long long maxSubarray(vector<int>& A,int low,int high,int k) {
    if (high-low+1<k) return LLONG_MIN;

    if (high-low+1==k) {
        long long sum=0;
        for (int i=low;i<=high;i++) sum+=A[i];
        return sum;
    }

    int mid=(low+high)/2;
    long long left=maxSubarray(A,low,mid,k);
    long long right=maxSubarray(A,mid+1,high,k);
    long long center=midPointSum(A,low,mid,high,k);

    return max({left,right,center});
}

int main() {
    int n,k;
    if (cin>>n>>k) {
        vector<int> A(n);
        for (int i=0;i<n;i++) {
            cin>>A[i];
        }

        long long sum=maxSubarray(A,0,n-1,k);
        cout<<sum<<endl;
    }
    return 0;
}