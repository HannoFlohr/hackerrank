

class Message {
private: 
    static int id;
public: 
    Message() {
        myid = ++id;
    }
    Message(const string &text) {
        ++id;
        myid = id;
        s = text;
    }

    const string& get_text() {
        return s;
    }

    int get_id() {
        return myid;
    }

    friend bool operator<(const Message& m1, const Message& m2) {
        return m1.myid < m2.myid ;
    }

    int myid;
    string s;
};
int Message::id=0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m (text);
        return m;
    }
};

