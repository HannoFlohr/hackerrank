#include <bits/stdc++.h>

using namespace std;

bool isValid(map<char,int> m, const int& ofeach) {
    for(auto a:m) 
        if(a.second > ofeach) return false; 
    return true;
}

int steadyGene(string gene) {
    int n = gene.size();
    int ofeach = n / 4;
    map<char,int> freq;
    int minIndex, maxIndex=0, subLength, result=numeric_limits<int>::max();
    for(int i=n-1; i>=0; i--) {
        freq[gene[i]]++;
        if(!isValid(freq,ofeach)) {
            maxIndex = i+1;
            freq[gene[i]]--;
            break;
        }
    }

    for(minIndex=-1; minIndex<n-1 && maxIndex<n && minIndex<maxIndex; minIndex++) {
        while(!isValid(freq,ofeach) && maxIndex<n) {
            freq[gene[maxIndex]]--;
            maxIndex++;
        }
        if(maxIndex>n || !isValid(freq,ofeach)) break;

        subLength = max(0, maxIndex-minIndex-1); 
        if(subLength < result) result = subLength;

        freq[gene[minIndex+1]]++;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}
