#include <bits/stdc++.h>

using namespace std;

int minimumNumber(int n, string s) {
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    int missing = 0;
    for(int i=0; i<numbers.size(); i++) {
        if (s.find(numbers[i]) != std::string::npos) break;
        if(i==numbers.size()-1) missing++;
    }
    for(int i=0; i<lower_case.size(); i++) {
        if (s.find(lower_case[i]) != std::string::npos) break;
        if(i==lower_case.size()-1) missing++;
    }
    for(int i=0; i<upper_case.size(); i++) {
        if (s.find(upper_case[i]) != std::string::npos) break;
        if(i==upper_case.size()-1) missing++;
    }
    for(int i=0; i<special_characters.size(); i++) {
        if (s.find(special_characters[i]) != std::string::npos) break;
        if(i==special_characters.size()-1) missing++;
    }

    return max(missing, 6-n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
