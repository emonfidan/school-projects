package lab4;

import java.util.Scanner;

public class Lab04_Q1 {
    public static void main(String[] args) {

        int n=-1;
        boolean isValid=false;
        Scanner scanner= new Scanner(System.in);

        while(!isValid){
            System.out.println("Enter input n: ");
            if(scanner.hasNextInt()){
                n= scanner.nextInt();
                if(n>0){
                    isValid=true;
                }
            }
            else{
                scanner.nextLine();
            }
        }

        int length= (int) Math.log10(n)+1;
        int result=0;
        int i=0;

        while(i<length){
            
            int recentdigit = n/(int) Math.pow(10,i)%10;   //sondan başlayıp basamakları bulur
            
            if(0==recentdigit && result==0){                 //sonu 0 ile biten sayıların 0'larını başa yazdırmayı sağlar
                System.out.print("0");
            }

            int placeValue = (int)Math.pow(10,length-1-i); //basamak değerini bulur
            result= result+ recentdigit*placeValue;
            i++;
        }

        System.out.print(result);

        scanner.close();

    }
}