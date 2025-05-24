package lab3;

import java.util.Scanner;

public class Lab03_Q2 {
    public static void main(String[] args) {

        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter a number: ");
        int input= scanner.nextInt();


        int length = (int)Math.log10(input) + 1;
        int half_length = length/2;

        if (length<3||length>7){
            System.out.println("The input is invalid! The number must be between 3 and 7 digits long. The number has "+ length+" digits.");
        }
        else{

            if(input%10 != input/ (int) Math.pow(10,length-1))//İlk ve son basamağı karşılaştır
            {
                System.out.println("The number has "+length+" digits.\n"+input+
                " is NOT a palindromic number.");
            }
            else if(2<=half_length && input/10%10 !=  input/ (int) Math.pow(10,length-2)%10)//2. ve varsa sondan 2. basamağı karşılaştır
            {
                System.out.println("The number has "+length+" digits.\n"+input+
                " is NOT a palindromic number.");
            }
            else if(3<=half_length && input/100%10 !=  input/ (int) Math.pow(10,length-3)%10)//3. ve varsa sondan 3. basamağı karşılaştır
            {
                System.out.println("The number has "+length+" digits.\n"+input+
                " is NOT a palindromic number.");
            }
            else{
                System.out.println("The number has "+length+" digits.\n"+input+
                " is a palindromic number.");
            }
            
            scanner.close();
        }

        
    }
}
