import java.util.*;

public class Solution {

    public static boolean canWin(int leap, int[] game) {
        int n = game.length;
        //DFS for possible solution
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        for(int i=0; i<n; i++) 
            visited[i] = false;
        q.add(0);
        visited[0] = true;
        while(!q.isEmpty()) {
            int i = q.remove();
            if(i+1 >= n || i+leap >= n)
                return true;
        
            if(game[i+leap] == 0 && !visited[i+leap]) {
                q.add(i+leap);
                visited[i+leap] = true;
            }
            if(game[i+1] == 0 && !visited[i+1]) {
                q.add(i+1);
                visited[i+1] = true;
            }
            if(i-1 >= 0 && game[i-1] == 0 && !visited[i-1]) {
                q.add(i-1);
                visited[i-1] = true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}

//https://www.hackerrank.com/challenges/java-1d-array/problem