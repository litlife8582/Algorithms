#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

tuple<long long,int,int> midpointSum(vector<int>& A,int low,int mid,int high,long long limit) {
    long long bestSum=-1;
    int start=-1,end=-1;

    long long currentLeftSum=0;
    for (int i=mid;i>=low;i--) {
        currentLeftSum+=A[i];

        long long currentRightSum=0;
        for (int j=mid+1;j<=high;j++) {
            currentRightSum+=A[j];

            long long totalSum=currentLeftSum+currentRightSum;

            if (totalSum<=limit) {
                if (totalSum>bestSum) {
                    bestSum=totalSum;
                    start=i;
                    end=j;
                }else if (totalSum==bestSum){
                    start=i;
                    end=j;
                }
            }
        }
    }
    return {bestSum,start,end};
}

tuple<long long,int,int> solve(vector<int>& A,int low,int high,long long limit) {
    if (low>=high) {
        if (A[low]<=limit) return {A[low],low,high};
        return {-1,-1,-1};
    }

    int mid=(low+high)/2;
    auto[lsum,lstart,lend]=solve(A,low,mid,limit);
    auto[rsum,rstart,rend]=solve(A,mid+1,high,limit);
    auto[csum,cstart,cend]=midpointSum(A,low,mid,high,limit);

    long long maxSum=-1;
    int start,end;
    if (lsum>maxSum) {
        maxSum=lsum;
        start=lstart;
        end=lend;
    }
    if (rsum>maxSum) {
        maxSum=rsum;
        start=rstart;
        end=rend;
    }
    if (csum>maxSum) {
        maxSum=csum;
        start=cstart;
        end=cend;
    }

    return {maxSum,start,end};
}

int main(){
    int n;
    long long limit;
    if (cin>>n>>limit) {
        vector<int> A(n);

        for (int i=0;i<n;i++) cin>>A[i];

        auto[sum,start,end]=solve(A,0,n-1,limit);
        cout<<start+1<<" "<<end+1<<endl;
    }
    return 0;
}