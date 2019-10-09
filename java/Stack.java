import java.util.*;
class Solution{
	
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input=sc.next();
            
            boolean valid = true;
            Stack<Character> s = new Stack<Character>();
            for(int i=0; i<input.length(); i++) {
                char c = input.charAt(i);
                if(c=='{' || c=='(' || c=='[') 
                    s.push(c);
                else {
                    if(s.isEmpty()) {
                        valid = false;
                        break;
                    }
                    char top = s.pop();
                    if((c=='}' && top!='{') ||
                       (c==')' && top!='(') ||
                       (c==']' && top!='[') ) {
                           valid = false;
                           break;
                       }
                }
            }

            if(valid && s.isEmpty())
                System.out.println("true");
            else
                System.out.println("false");
		}
		sc.close();
	}
}
//https://www.hackerrank.com/challenges/java-stack/problem