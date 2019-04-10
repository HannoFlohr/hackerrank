#include <bits/stdc++.h>
using namespace std;

int n, sumElements, sumAbsDif;
bool visited [51][201][2001] = {0}; // max n=50, sumElements=200, sumAbsDif=2000

int arrayConstruction(vector<int> &result, int sum, int dif, int index) {
    //if max index is reached, check if sum and dif are correct
    if(index == n) {
        if(sum == sumElements && dif == sumAbsDif) 
            return 1;
        else  
            return 0;
    }

    //check if these values have been parsed before
    if(visited[index][sum][dif])
        return -1;
    else 
        visited[index][sum][dif] = true;

    int nextElement, lb_newSum, lb_newDif, check;
    nextElement = index==0 ? 0 : result[index-1];
    for( ; nextElement <= sumElements; nextElement++) {
        //compute lower bounds for the sum and dif and compare
        lb_newSum = sum + nextElement * (n-index);
        lb_newDif = dif + (nextElement * index - sum) * (n-index);
        if(lb_newSum > sumElements || lb_newDif > sumAbsDif)
            return 0;

        result[index] = nextElement;
        
        check = arrayConstruction(result, sum+nextElement, dif+nextElement*index-sum, index+1);
        if(check == 1)
            return 1;
    }
    return 0;
}

int main()
{
    int q;
    cin >> q;
    while(q--) {
        cin >> n >> sumElements >> sumAbsDif;
        vector<int> result (n);
        memset(visited, 0, sizeof visited);
        if( arrayConstruction(result,0,0,0) == 1 ) {
            for(auto a:result)
                cout << a << " ";
            cout<<endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
