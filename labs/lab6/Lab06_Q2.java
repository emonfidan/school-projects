package lab6;

import java.util.Scanner;

public class Lab06_Q2 {
    static boolean isPrime(int num){
        if(num==1){
            return false;
        }
        else{
            for(int i=2;i<=Math.sqrt(num);i++){
                if(num%i==0){
                    return false;
                }
            }
            return true;
        }
        
    }
    static int primeSummation(int num){
        int sum=0;
        for(int i=1;i<=num;i++){
            if(num%i==0 && isPrime(i)){
                sum+=i;
            }
        }
        return sum;
    }
    
    public static void main(String[] args) {

        Scanner input=new Scanner(System.in);

        System.out.println("Please input the natural number: ");
        int num=input.nextInt();
        
        System.out.println("The summation of the prime factors of "+num+" is "+primeSummation(num)+".");
        input.close();
        
    }
}
