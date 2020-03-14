import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner a = new Scanner(System.in);
        int N = a.nextInt();
        int ary[] = new int[N];
        for (int i = 0; i < ary.length; i++) {
            ary[i] = a.nextInt();
        }
        int max = ary[0];
        int min = ary[0];
        for (int i = 0; i < ary.length; i++) {
            if(max < ary[i]) max = ary[i];
        }
        for (int i = 0; i < ary.length; i++) {
            if(min > ary[i]) min = ary[i];
        }
        System.out.println(min+" "+max);
    }
}
