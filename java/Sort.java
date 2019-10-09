import java.util.*;

class Student implements Comparable<Student> {
	private int id;
	private String fname;
	private double cgpa;
	public Student(int id, String fname, double cgpa) {
		super();
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}
	public int getId() {
		return id;
	}
	public String getFname() {
		return fname;
	}
	public double getCgpa() {
		return cgpa;
	}
    public boolean equals(Student s) {
        if(id == s.getId() && fname == s.getFname() && cgpa == s.getCgpa())
            return true;
        return false;
    }
    public int compareTo (Student s) {
        if(cgpa == s.getCgpa()) {
            if(fname == s.getFname()) {
                if(id > s.getId())
                    return -1;
                return 1;
            }
            if(fname.compareTo(s.getFname()) > 0)
                return 1;
            return -1;
        }
        if(cgpa > s.getCgpa())
            return -1;
        return 1;
    }
}

//Complete the code
public class Solution
{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		
		List<Student> studentList = new ArrayList<Student>();
		while(testCases>0){
			int id = in.nextInt();
			String fname = in.next();
			double cgpa = in.nextDouble();
			
			Student st = new Student(id, fname, cgpa);
			studentList.add(st);
			
			testCases--;
		}

        Collections.sort(studentList);
      
      	for(Student st: studentList){
			System.out.println(st.getFname());
		}
	}
}
//https://www.hackerrank.com/challenges/java-sort/problem