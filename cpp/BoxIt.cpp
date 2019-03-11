
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 
class Box {
private:
    long int length;
    long int breadth;
    long int height;
public:
// Constructors: 
// Box();
    Box() { length = breadth = height = 0;}
// Box(int,int,int);
    Box(int l, int b, int h) {
        length = l;
        breadth = b;
        height = h;
    }
// Box(Box);
    Box(const Box& b) {
        length = b.length;
        breadth = b.breadth;
        height = b.height;
    }
// int getLength(); // Return box's length
    int getLength() { return length; }
// int getBreadth (); // Return box's breadth
    int getBreadth() { return breadth; }
// int getHeight ();  //Return box's height
    int getHeight() { return height; }
// long long CalculateVolume(); // Return the volume of the box
    long long CalculateVolume() { return (long long)length*breadth*height;}

//Overload operator < as specified
//bool operator<(Box& b)
    bool operator<(Box& b) {
        if(length < b.getLength() ) 
            return true;
        else if(breadth < b.getBreadth() && length==b.getLength() )
            return true;
        else if(height < b.getHeight() && breadth==b.getBreadth() 
                    && length==b.getLength())
            return true;
        else
            return false;
    }

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
    friend ostream& operator<<(ostream& out, Box& B) {
        out << B.length << " " << B.breadth << " " << B.height;
        return out;
    }
};

