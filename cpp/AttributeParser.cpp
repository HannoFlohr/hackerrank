#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string,string> tagsMap;

void createTags(int &n, string pretag) {
    if(!n) return;
    
    string line, tag, attr, value;
    getline(cin, line);

    int i=1;
    if(line[i]=='/') { //closing tag
        while(line[i]!='>') i++;
        if(pretag.size()>(i-2))
            tag = pretag.substr(0,pretag.size()-i+1);
        else 
            tag = "";
    }
    else { //opening tag
        while(line[i]!=char(32) && line[i]!='>') i++;    
        tag = line.substr(1,i-1);
        if(pretag!="") tag = pretag + "." + tag;
   
        int j;
        while(line[i]!='>') { //attribute
            j = ++i;
            while(line[i]!=' ') i++;
            attr = line.substr(j, i-j); //attribute name

            while(line[i]!='\"') i++;
            j = ++i;
            while(line[i]!='\"') i++;
            value = line.substr(j, i-j); // attribute value
            i++;

            tagsMap[tag+"~"+attr] = value;
        }
    }

    createTags(--n, tag);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q, pos;
    cin >> n >> q;
    cin.ignore();
    createTags(n,"");

    string attr, value;
    while(q--) {
        getline(cin, attr);
        value = tagsMap[attr];
        if(value=="") value = "Not Found!";
        cout << value <<endl;
    }


    return 0;
}
