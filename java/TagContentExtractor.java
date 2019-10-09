import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution{
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		while(testCases>0){
			String line = in.nextLine();
			
          	//Write your code here
            boolean found = false;

            // <(.+)> matches HTML start tag; parentheses save contents into group #1
            // ([^<]+) matches everything between start and end tag, cant include '<'; group #2
            // </\\1> matches HTML end tag corresponding to start tag; \1 to match all text of group #1
            Pattern r = Pattern.compile("<(.+)>([^<]+)</\\1>");
            Matcher m = r.matcher(line);
			
            while(m.find()) {
                System.out.println(m.group(2));
                found = true;
            }
            if(!found)
                System.out.println("None");

			testCases--;
		}
	}
}
//https://www.hackerrank.com/challenges/tag-content-extractor/problem