#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string str1,str2;
    if (!getline(cin,str1) || !getline(cin,str2)) return 0;

    int len1=str1.length();
    int len2=str2.length();

    vector<vector<int>> l(len1+1,vector<int>(len2+1));

    for (int i=0;i<=len1;i++) {
        for (int j=0;j<=len2;j++) {
            if (i==0 || j==0) l[i][j]=0;
            else if (str1[i-1] == str2[j-1]) l[i][j]=l[i-1][j-1]+1;
            else l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }

    for (int i=0;i<=len1;i++) {
        for (int j=0;j<=len2;j++) {
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Length of LCS is "<<l[len1][len2]<<endl;
    return 0;
}