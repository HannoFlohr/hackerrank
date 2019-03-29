#include <bits/stdc++.h>
using namespace std;

void test() {
    string S = " abab";
    int N = S.size();
    vector<int> kmp (N);
    kmp[1] = 0;
    int i,l;
    for (i = 2; i <= N; i = i + 1){
        l = kmp[i - 1];
        while (l > 0 && S[i] != S[l + 1]){
            l = kmp[l];
        }
        if (S[i] == S[l + 1]){
            kmp[i] = l + 1;
        }
        else{
            kmp[i] = 0;
        }
    }
    for(i=1;i<kmp.size(); i++)cout<<kmp[i]<<" ";cout<<endl;
}

int main()
{ 
    int n=0, index1 = -1, index2 = -1, indexSmallestFreq, indexSmallestFreqValue=INT_MAX;
    vector<int> x (26);
    for(int i=0; i<26; i++) {
        cin >> x[i];
        n += x[i];
        //find index of second character
        if(index1 != -1 && index2 == -1 && x[i])
            index2 = i;
        //find index of first character
        if(index1 == -1 && x[i])
            index1 = i;
        //find character with smallest frequency
        if(x[i] && x[i] < indexSmallestFreqValue) {
            indexSmallestFreqValue = x[i];
            indexSmallestFreq = i;
        }
    }

    string s (n,' ');
    int i = 0, j;

    //put char with minimum freq as first char of string and decrement frequency
    s[i++] = indexSmallestFreq + 97; 
    x[indexSmallestFreq]--;

    //if min freq is also first char and not only char and freq>1
    if(index1 == indexSmallestFreq && index2 != -1 && x[index1]) {
        s[i++] = indexSmallestFreq + 97;
        x[indexSmallestFreq]--;

        //interleaving of characters as far as possible
        j = index2;
        while(x[indexSmallestFreq] > 0) {
            while(j < 26 && !x[j]) j++;
            if(j>25) break;
        
            while(x[indexSmallestFreq]-- && x[j]--) {
                s[i++] = j + 97;
                s[i++] = indexSmallestFreq + 97; 
            }
        }
        for(int k=j; k<26; k++)
            while(x[k]--)
                s[i++] = k + 97;
    }
    //earliest char does not have lowest freq
    else { 
        for(int k=0; k<26; k++)
            while(x[k]--)
                s[i++] = k + 97;
    }

    cout << s <<endl;
    return 0;
}
