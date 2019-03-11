

struct BadLengthException : public exception {
    int n;
    BadLengthException(int error) {
        n = error;
    }
    int what() {
        return n;
    }
};
