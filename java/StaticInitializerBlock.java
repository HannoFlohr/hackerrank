import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

private static Scanner in = new Scanner(System.in);
private static int B = in.nextInt();
private static int H = in.nextInt();
private static boolean flag = false;

static {
    if(B>0 && H>0)
        flag = true;
    else 
        System.out.println("java.lang.Exception: Breadth and height must be positive"); 
}

public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}
		
	}//end of main

}//end of class