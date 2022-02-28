#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h> 
using namespace std; 

const int MAXN = 5e5; 
const int MAXN2 = MAXN<<1;
const int MAXLEAVES = 1<<20; 
int radii [2][MAXN2+1];
int max_length [2][MAXN2+1];
int heap [MAXLEAVES+1];
int n, leaves, heap_left, heap_right, heap_val;
string s; 

//https://en.wikipedia.org/wiki/Longest_palindromic_substring - Manacher's algorithm
void manacher(const int size, const int rx) {
    int center=0, radius=0, distance;
    int* r = radii[rx];
    for(; center<size; center+=distance) {
        while(center-radius >= 0 && center+radius+rx < size && s[center-radius] == s[center+radius+rx])
            radius++;
            
        r[center] = radius;
        
        for(distance=1; distance<radius && r[center-distance] != r[center]-distance; distance++)
            r[center+distance] = min(r[center-distance], r[center]-distance);
        
        radius = max(radius-distance, 0);
    }
}

void update_heap(const int position, const int left, const int right) {
    if(heap_left > right || heap_right < left)
        return;
        
    if(heap_left <= left && right <= heap_right) 
        heap[position] = max(heap[position], heap_val);
    else {
        int middle = (left + right) >> 1;
        update_heap(position * 2, left, middle);
        update_heap(position * 2 + 1, middle+1, right);
    }
    
}

void make_heap(const int position, const int parity) {
    int& radius = radii[parity][position];
    int difference = ((radius<<1) - (!parity) - n), left, right, length;
    
    if(difference > 0) {
        difference += (difference & 1);
        radius -= difference / 2;
    }
    
    left = position - radius + 1;
    right = position + radius - (!parity);
    length = 2 * radius - (!parity);
    
    if((parity==0 && radius>1) || (parity==1 && radius>0)) {
        max_length[0][left] = max(max_length[0][left], length);
        max_length[1][right] = max(max_length[1][right], length);
        heap_left = max(0, right-n+1); 
        heap_right = min(n-1, left);
        heap_val = length;
        update_heap(1, 0, leaves-1);   
    }
} 

int read_heap(const int position) {
    int cur = position + leaves;
    int result = 1;
    while(cur) {
        result = max(result, heap[cur]);
        cur /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> s;
    
    int i, result;
    int manacher_size = 2*n-1;
    s = s+s.substr(0,n-1);
    
    leaves = 1;
    while(leaves<n)
        leaves *= 2;

    manacher(manacher_size, 0);
    manacher(manacher_size, 1);
    
    for(i=0; i<manacher_size; i++) {
        make_heap(i, 0);
        make_heap(i, 1);
    } 
    
    for(i=1; i<manacher_size; i++) {
        max_length[0][i] = max(max_length[0][i], max_length[0][i-1]-2);
        max_length[1][manacher_size-i-1] = max(max_length[1][manacher_size-i-1], max_length[1][manacher_size-i]-2);
    }
    
    for(i=0; i<n; i++){
        result = read_heap(i);
        result = max(result, max_length[0][i]);
        result = max(result, max_length[1][i+n-1]);
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/circular-palindromes/problem

/* 
First attempt using Manacher's algorithm for each shifted string of the input; clears 13/26 test cases, timeouts for the rest 

#include<bits/stdc++.h>
using namespace std;

string addSeparator(const string& s, string sep="|") {
    if(!s.size()) return "";
    
    stringstream ss;
    for(int i=0; i<s.size(); i++)
        ss << sep << s[i];
    ss << sep;
    return ss.str();
}

//https://en.wikipedia.org/wiki/Longest_palindromic_substring - Manacher's algorithm
unsigned longest_palindrome(string input) {
    const int size_input = input.size();
    const int size_s = 2*size_input+1;
    string s = addSeparator(input);
    vector<int> palindrome_radii (size_s, 0);
    
    int center=0, radius=0, old_center, old_radius, mirrored_center, max_mirrored_radius;
    while(center < size_s) {
        while(center-(radius+1) >= 0 && center+(radius+1) < size_s && s[center-(radius+1)] == s[center+(radius+1)])
            radius++;
        
        palindrome_radii[center] = radius;
        
        old_center = center;
        old_radius = radius;
        center++;
        radius = 0; 
        
        while(center <= old_center + old_radius) {
            mirrored_center = old_center - (center - old_center);
            max_mirrored_radius = old_center + old_radius - center;
            if(palindrome_radii[mirrored_center] < max_mirrored_radius) {
                palindrome_radii[center] = palindrome_radii[mirrored_center];
                center++;
            }
            else if(palindrome_radii[mirrored_center] > max_mirrored_radius) {
                palindrome_radii[center] = max_mirrored_radius;
                center++;
            }
            else {
                radius = max_mirrored_radius;
                break;
            }
        }
    }
    
    unsigned longest_palindrome_s = 2 * (*max_element(palindrome_radii.begin(),palindrome_radii.end())) + 1;
    return (longest_palindrome_s - 1) / 2;  
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<n; i++) {
        cout << longest_palindrome(s) << endl;
        s = s.substr(1,n-1) + s.substr(0,1);
    }
    return 0;
}
*/