import java.util.*;

// Greedy Polygons

public class greedypolygons {

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		int t = stdin.nextInt();
		for(int i = 0; i < t; i++){
			int n = stdin.nextInt();
			int l = stdin.nextInt();
			int d = stdin.nextInt();
			int g = stdin.nextInt();
			System.out.println(n * l * l * Math.tan(Math.PI / 2 - Math.PI / n) / 4 + l * g * d * n + Math.PI * Math.pow(g * d, 2));
		}
	}
}