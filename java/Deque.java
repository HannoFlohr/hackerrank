    import java.util.*;
    public class test {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            Deque<Integer> deque = new ArrayDeque<>();
            int n = in.nextInt();
            int m = in.nextInt();

            HashSet<Integer> set = new HashSet<>();
            int first, maxUnique = 0;
            for (int i = 0; i < n; i++) {
                int num = in.nextInt();

                //add new number to deque and set (if not duplicate)
                deque.addLast(num);
                set.add(num);
                
                if(deque.size() == m) {
                    //update max uniques
                    if(maxUnique < set.size())
                        maxUnique = set.size();
                    //remove first number and if it was the only occurence also remove from set
                    first = deque.removeFirst();
                    if(!deque.contains(first))
                        set.remove(first);
                }
                
                if(maxUnique == m)
                    break;
            }
            System.out.println(maxUnique);
            in.close();
        }
    }
//https://www.hackerrank.com/challenges/java-dequeue/problem