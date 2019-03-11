

		/* Enter your code here */
        int a,b,c;
        string s;

        //transform A
        cout << hex << left << showbase << nouppercase;
        cout << (long long) A << endl;

        //B
        cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2);
        cout << B << endl;

        //C
        cout << scientific << uppercase << noshowpos << setprecision(9);
        cout << C << endl;        

