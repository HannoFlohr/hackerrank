import java.util.ArrayList;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import java.util.ArrayList;
import java.util.Scanner;

enum Color {
    RED, GREEN
}

abstract class Tree {

    private int value;
    private Color color;
    private int depth;

    public Tree(int value, Color color, int depth) {
        this.value = value;
        this.color = color;
        this.depth = depth;
    }

    public int getValue() {
        return value;
    }

    public Color getColor() {
        return color;
    }

    public int getDepth() {
        return depth;
    }

    public abstract void accept(TreeVis visitor);
}

class TreeNode extends Tree {

    private ArrayList<Tree> children = new ArrayList<>();

    public TreeNode(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitNode(this);

        for (Tree child : children) {
            child.accept(visitor);
        }
    }

    public void addChild(Tree child) {
        children.add(child);
    }
}

class TreeLeaf extends Tree {

    public TreeLeaf(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitLeaf(this);
    }
}

abstract class TreeVis
{
    public abstract int getResult();
    public abstract void visitNode(TreeNode node);
    public abstract void visitLeaf(TreeLeaf leaf);

}

class SumInLeavesVisitor extends TreeVis {
    private int result = 0;
    
    public int getResult() {
        return result;
    }

    public void visitNode(TreeNode node) {
      	//only Leaf values are of interest, so nothing to do here
    }

    public void visitLeaf(TreeLeaf leaf) {
      	result += leaf.getValue();
    }
}

class ProductOfRedNodesVisitor extends TreeVis {
    private final int MOD = 1000000007;
    private long result = 1;

    public int getResult() {
        return (int)result;
    }

    public void visitNode(TreeNode node) {
      	if(node.getColor().equals(Color.RED)) {
            result = (result * node.getValue()) % MOD; 
          }
    }

    public void visitLeaf(TreeLeaf leaf) {
      	if(leaf.getColor().equals(Color.RED)) {
            result = (result * leaf.getValue()) % MOD;
          }
    }
}

class FancyVisitor extends TreeVis {
    private int evenDepthSum = 0;
    private int greenSum = 0;

    public int getResult() {
        return Math.abs(evenDepthSum - greenSum);
    }

    public void visitNode(TreeNode node) {
    	if(node.getDepth() % 2 == 0)
            evenDepthSum += node.getValue();
    }

    public void visitLeaf(TreeLeaf leaf) {
    	if(leaf.getColor().equals(Color.GREEN))
            greenSum += leaf.getValue();
    }
}

public class Solution {
    static int n;
    static int[] values;
    static int[] colors;
    static boolean[] visited;
    static HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
    
    public static Tree dfs(int nodeId, int depth) {
        visited[nodeId] = true;

        ArrayList<Tree> children = new ArrayList<>();
        for(Integer node : map.get(nodeId))
            if(!visited[node])
                children.add( dfs(node,depth+1) );

        if(children.isEmpty())
            return new TreeLeaf(values[nodeId],Color.values()[colors[nodeId]],depth);
        else {
            TreeNode node = new TreeNode(values[nodeId],Color.values()[colors[nodeId]],depth);
            for(Tree child : children)
                node.addChild(child);

            return node;
        }
    }

    public static Tree startDfs(int nodeId) {
        if(map.get(nodeId).isEmpty())
            return new TreeLeaf(values[nodeId],Color.values()[colors[nodeId]], 0);
        else {
            visited = new boolean[n];
            return dfs(nodeId, 0);
        }
    }

    public static Tree solve() {
        //read the tree from STDIN and return its root as a return value of this function
        try{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        values = new int[n];
        colors = new int[n];

        //nodes
        String[] nodeValues = br.readLine().split(" ");
        for(int i=0; i<n; i++) {
            map.put(i, new HashSet<Integer>());
            values[i] = Integer.valueOf(nodeValues[i]);
        }    
        nodeValues = br.readLine().split(" ");
        for(int i=0; i<n; i++) 
            colors[i] = Integer.valueOf(nodeValues[i]);

        //edges
        int from, to;
        for(int i=0; i<n-1; i++) {
            nodeValues = br.readLine().split(" ");

            from = Integer.valueOf(nodeValues[0]) - 1;
            to = Integer.valueOf(nodeValues[1]) - 1;

            map.get(from).add(to);
            map.get(to).add(from);
        }

        return startDfs(0);
        } 
        catch(IOException e) {
            System.out.println(e);
        }
        return null;
    }


    public static void main(String[] args) {
      	Tree root = solve();
		SumInLeavesVisitor vis1 = new SumInLeavesVisitor();
      	ProductOfRedNodesVisitor vis2 = new ProductOfRedNodesVisitor();
      	FancyVisitor vis3 = new FancyVisitor();

      	root.accept(vis1);
      	root.accept(vis2);
      	root.accept(vis3);

      	int res1 = vis1.getResult();
      	int res2 = vis2.getResult();
      	int res3 = vis3.getResult();

      	System.out.println(res1);
     	System.out.println(res2);
    	System.out.println(res3);
	}
}
//https://www.hackerrank.com/challenges/java-vistor-pattern/problem