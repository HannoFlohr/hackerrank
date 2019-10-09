import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Comparator;
import java.util.PriorityQueue;

/*
 * Create the Student and Priorities classes here.
 */
class Student {
    private int id;
    private String name;
    private double cgpa;

    Student(int i, String n, double c) {
        id = i;name = n;cgpa = c;
    }

    int getID() {return id;}
    String getName() {return name;}
    double getCGPA() {return cgpa;}
}

class Priorities {
    List<Student> getStudents(List<String> events) {
        PriorityQueue<Student> q = new PriorityQueue(Comparator.comparing(Student::getCGPA).reversed().thenComparing(Student::getName).thenComparing(Student::getID));
        List<Student> students = new ArrayList<Student>();

        for(String event : events) {
            Scanner in = new Scanner(event);
            String e = in.next();
            if(e.equals("ENTER")) {
                String name = in.next();
                double cgpa = (double)in.nextDouble();
                int id = in.nextInt();
                Student s = new Student(id, name, cgpa);

                q.add(s);
            }
            else if(e.equals("SERVED")) 
                q.poll();

            in.close();
        }

        while(!q.isEmpty()) 
             students.add(q.poll());
                
        return students;
    }
}

public class Solution {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();
    
    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());    
        List<String> events = new ArrayList<>();
        
        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }
        
        List<Student> students = priorities.getStudents(events);
        
        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}
//https://www.hackerrank.com/challenges/java-priority-queue/problem