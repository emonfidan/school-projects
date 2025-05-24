package lab6;

import java.util.Scanner;

public class Lab06_Q1 {

    static int floor(double num){
        int result=0;
        if(num<0){
            for(int i=0;i>=num;i--){
                if(i==num){
                    result=i-1;
                }
                else{
                    result=i;
                }
            }
        }
        else{
            for(int i=0;i<=num;i++){
                result=i;
            }
        }
        return result;
    }
    static int digitDecoder(int num){
        return floor(10-Math.pow(num/2.0-3, 2)-0.32);
    }
    static int passwordDecoder(int num){

        
        int result=0;
        int digitNum=(int) Math.log10((double)num)+1;
        for(int i=digitNum-1;0<=i;i--){
            result= result+ digitDecoder((int)(num/Math.pow(10, i)%10))*(int)Math.pow(10, i);
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        System.out.print("Please input the password: ");
        System.out.println("The decoded password is: "+passwordDecoder(input.nextInt()));
        input.close();
    }
}
