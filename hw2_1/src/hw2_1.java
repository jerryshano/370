import java.util.Scanner;

public class hw2_1 {
    public static int reverseInt(int n){
        boolean isNegative = false;
        if(n<0){
            isNegative = true;
            n = -n;
        }
        String s = String.valueOf(n);
        String reverse = "";
        for(int i = 0;i<s.length();i++){
            reverse = s.charAt(i)+reverse;
        }
        if(isNegative){
            return -Integer.parseInt(reverse);
        }
        else{
            return Integer.parseInt(reverse);
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        System.out.println(reverseInt(n));
    }
}