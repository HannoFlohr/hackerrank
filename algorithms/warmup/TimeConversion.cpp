#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
     string app = s.substr(8,2);
     string hours = s.substr(0,2);
     string middle = s.substr(2,6);

	//Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock. 
    int i = stoi(hours);
    if(app=="PM") {
        if(i!=12) {
            i+=12; 
            hours = to_string(i); 
            if(hours.size()==1) hours = "0"+hours;
        }
    }
    else if(i==12 && app=="AM") {
        i=0;
        hours = to_string(i);
        if(hours.size()==1) hours = "0"+hours;
    }

    return (hours+middle);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
