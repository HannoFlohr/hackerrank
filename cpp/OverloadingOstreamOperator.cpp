
ostream& operator<<(ostream &o, Person &p) {
    cout << "first_name="<<p.get_first_name()<<",last_name="<<p.get_last_name();
    return o;
}

