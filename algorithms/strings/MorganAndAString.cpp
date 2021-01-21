#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, length_a, length_b, index_a, index_b, count; 
    string a, b, result;
    char c;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        length_a = a.length();
        length_b = b.length(); 
        result = "";
        index_a = 0, index_b = 0;
        
        a += 'z';
        b += 'z';
        
        while(index_a < length_a && index_b < length_b) {
            if(a[index_a] < b[index_b]) 
                result += a[index_a++];
            else if(a[index_a] > b[index_b])
                result += b[index_b++];
            else {
                int start_a = index_a, start_b = index_b;
                
                while(a[index_a] == b[index_b]){
                    index_a++; index_b++;
                    
                    if(index_a>=a.length() && index_b>=b.length()) { // a and b are the same
                        index_a = start_a;
                        index_b = start_b;
                        break;
                    }
                    else if(index_a >= a.length()) { // a is shorter than b
                        c = b[start_b];
                        while(b[start_b] <= c) {
                            result += b[start_b];
                            c = b[start_b];
                            start_b++;
                        }
                        index_a = start_a;
                        index_b = start_b;
                    }
                    else if(index_b >= b.length()) { // b is shorter than a
                        c = a[start_a];
                        while(a[start_a] <= c) {
                            result += a[start_a];
                            c = a[start_a];
                            start_a++;
                        }
                        index_a = start_a;
                        index_b = start_b;
                    }
                }
                
                if(a[index_a] <= b[index_b]) {
                    c = a[start_a];
                    while(a[start_a] <= c) {
                        result += a[start_a];
                        c = a[start_a];
                        start_a++;
                    }
                    index_a = start_a;
                    index_b = start_b;
                }
                else {
                    c = b[start_b];
                    while(b[start_b] <= c) {
                        result += b[start_b];
                        c = b[start_b];
                        start_b++;
                    }
                    index_a = start_a;
                    index_b = start_b;
                }
            }
        }   
        
        while(index_a < length_a)
            result += a[index_a++];
        while(index_b < length_b)
            result += b[index_b++];

        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/morgan-and-a-string/problem