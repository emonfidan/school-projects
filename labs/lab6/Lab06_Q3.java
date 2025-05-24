package lab6;

import java.util.Scanner;

public class Lab06_Q3 {

    static int power(int a, int b){
        int result=1;
        for (int i=0;i<b;i++){
            result=result*a;
        }
        return result;
    }
    static boolean isPythagorean(int a, int b, int c){
        if(power(a,2)==power(b, 2)+power(c, 2)){
            return true;
        }
        else if(power(b,2)==power(a, 2)+power(c, 2)){
            return true;
        }
        else if(power(c,2)==power(b, 2)+power(a, 2)){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {

        Scanner input=new Scanner(System.in);
        System.out.print("Please input the first number: ");
        int a= input.nextInt();
        System.out.print("Please input the second number: ");
        int b= input.nextInt();
        System.out.print("Please input the third number: ");
        int c= input.nextInt();

        if(isPythagorean(a,b,c)){
            if(a>b && a>c){
                System.out.println("The triplet is Pythagorean, power("+a+", 2) = power("+b+" ,2) + power("+c+" ,2)");
            }
            else if(b>a && b>c){
                System.out.println("The triplet is Pythagorean, power("+b+", 2) = power("+a+" ,2) + power("+c+" ,2)");
            }
            else{
                System.out.println("The triplet is Pythagorean, power("+c+", 2) = power("+b+" ,2) + power("+a+" ,2)");
            }
            
        }
        else{
            System.out.println("The triplet is NOT Pythagorean.");
        }
        input.close();

    }
}
