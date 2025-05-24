package lab4;

import java.util.Scanner;

public class Lab04_Q2 {
    public static void main(String[] args) {

        Scanner scanner= new Scanner(System.in);
        System.out.println("Please input n: ");
        int n= scanner.nextInt();
        int binaryN=0;
        int remainderN=n;
        int power=0;
        int i;
        
        while(remainderN!=0){
            power=(int) (Math.log(remainderN)/Math.log(2));
            
            int placeValue = (int)Math.pow(10,power);//basamak değerini bulur
            binaryN=binaryN+placeValue;
            remainderN= remainderN-(int)Math.pow(2,power);//kalan sayı
        
        }
        

        System.out.println(binaryN);
        scanner.close();
    }
}
