#include<iostream>
#include<string>
using namespace std;

void print(string str,int low,int high) {
    for (int i=low;i<=high;i++) cout<<str[i];
    cout<<endl;
}

int main() {
    string str;
    if (!getline(cin,str)) return 0;

    int n=str.length();
    int maxlength=0;
    int start=0;
    int low,high;
    for (int i=0;i<n;i++) {
        low=i;
        high=i;
        while (low>=0 && high<n && str[low]==str[high]) {
            if (high-low+1>maxlength) {
                maxlength=high-low+1;
                start=low;
                print(str,start,maxlength+start-1);
            }
            low--;
            high++;
        }
        low=i;
        high=i+1;
        while (low>=0 && high<n && str[low]==str[high]) {
            if (high-low+1>maxlength) {
                maxlength=high-low+1;
                start=low;
                print(str,start,maxlength+start-1);
            }
            low--;
            high++;
        }
    }

    cout<<"Longest Palindrome is ";
    print(str,start,maxlength+start-1);
}