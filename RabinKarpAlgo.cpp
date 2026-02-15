#include<iostream>
#include<string>
using namespace std;

const int d=256;

void search(string txt,string pat,int q) {
    int N=txt.length();
    int M=pat.length();
    int i,j;
    int p=0,t=0,h=1;

    for (int i=0;i<M-1;i++) {
        h=(h*d)%q;
    }

    for (int i=0;i<M;i++) {
        t=(d*t+txt[i])%q;
        p=(d*p+pat[i])%q;
    }

    for (i=0;i<=N-M;i++) {
        if (p==t) {
            for (j=0;j<M;j++) {
                if (txt[i+j]!=pat[j]) break;
            }
            if (j==M) {
                cout<<"Pattern found at position: "<<i+1<<endl;
                return;
            }
        }

        if (i<N-M) {
            t=(d*(t-txt[i]*h)+txt[i+M])%q;
            if (t<0) t=t+q;
        }
    }
    cout<<"Pattern not found"<<endl;
}

int main() {
    string txt,pat;
    int q=101;
    if (!getline(cin,txt) || !getline(cin,pat)) {
        return 0;
    }

    search(txt,pat,q);
    return 0;
}