import java.util.Scanner;
import java.lang.String;
// import java.lang.Math;
// import java.text.NumberFormat;
import java.time.Period;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = 0, y = 0, z = 0, xt, yt, zt;
        for(int i = 0; i < n; i++){
            xt = sc.nextInt();
            yt = sc.nextInt();
            zt = sc.nextInt();
            x += xt; z += zt; y += yt;
        }
        if(x == 0 && y == 0 && z == 0){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }

        sc.close();
    }
}