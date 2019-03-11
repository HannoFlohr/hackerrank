

class Person {
public:
    string name;
    int age;

    virtual void getdata() { cin >> name >> age; }
    virtual void putdata() { cout << name << " " << age << endl; }
};

class Professor : public Person {
public: 
    int publications;
    static int id;
    int cur_id;
 
    Professor() { cur_id = ++id; }

    void getdata() {
        cin >> name >> age >> publications;
    }
    void putdata() {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};
int Professor::id = 0;

class Student : public Person {
public: 
    int marks [6];
    static int id;
    int cur_id;

    Student() { cur_id = ++id; }

    void getdata() {
        cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
    }
    void putdata() {
        int sum = 0;
        for(int i=0; i<6; i++) sum += marks[i];
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};
int Student::id = 0;

