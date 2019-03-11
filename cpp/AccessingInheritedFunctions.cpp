

class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            int value = new_val, a=0, b=0, c=0;
            while(value>1) {
                if(value%2==0) {
                    value/=2; 
                    a++;
                }
                else if(value%3==0) {
                    value/=3; 
                    b++;
                }
                else if(value%5==0) {
                    value/=5; 
                    c++;
                }
            }

            while(a--) A::func(val);
            while(b--) B::func(val);
            while(c--) C::func(val);
			
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

