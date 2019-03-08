#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string dayOfProgrammer(int year) {
    int months [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int sum = 0, i = 0;
    while(sum<256) {
        if(i==1) { 
            if(year < 1918) { 
                if(year%4==0) 
                    sum += 1;
            }
            else if(year > 1918) {
                if( (year%4==0 && year%100!=0) || year%400==0 ) {
                    sum += 1;  
                }
            }
            else 
                sum = sum - 28 + 14 + 1;
        }
        sum += months[i];
        if(sum+months[i+1] >= 256) break;
        i++;
    }


    string day,month,y;
    y = to_string(year);
    month = to_string(i+2);
    if(month.length()==1) month = '0'+month;

    int diff = 256-sum;
    if(diff<10) day = '0'+to_string(diff);
    else day = to_string(diff);

    return (day+'.'+month+'.'+y);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
