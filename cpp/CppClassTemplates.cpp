

/*Write the class AddElements here*/
template <class T>
class AddElements {
T element;
public:
AddElements (T arg) {element=arg;}
T add (T e) {return element+e;}
};

// class template specialization for string
template <>
class AddElements <string> {
string element;
public:
AddElements (string s) {element=s;}
string concatenate(string s) {return element+s;}
};

