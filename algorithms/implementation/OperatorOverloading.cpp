

class Matrix {
public: 
    vector<vector<int> > a;

    Matrix() {}

    Matrix& operator+(const Matrix& m2) {
        for(int i=0; i<m2.a.size(); i++) {
            for(int j=0; j<(m2.a[0]).size(); j++) { 
                this->a[i][j] = this->a[i][j] + m2.a[i][j];
            }
        }
        return *this;
    }
};

