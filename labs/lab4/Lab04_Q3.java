package lab4;

import java.util.Scanner;

public class Lab04_Q3 {
    public static void main(String[] args) {

        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter input n: ");
        int n=scanner.nextInt();

        System.out.println("Please choose the operation. Division or Multiplication 'd' or 'm'?:");
        String operation= scanner.next();
        System.out.println("Enter the multiplier or divisor that is a multiple of two:");
        int multiplier= scanner.nextInt();


        int binaryN=0;
        int remainderN=n;
        int power=0;
        int placeValue=0;
        int i;

        if(operation.equals("d")){
            remainderN=n>> (int)(Math.log(multiplier) / Math.log(2));
        }
        else if(operation.equals("m")){
            remainderN=n<< (int) (Math.log(multiplier) / Math.log(2));
        }

         
        while(remainderN!=0){
            i=0;
            while(Math.pow(2,i)<=remainderN){//kalan sayıdan küçük en büyük 2'nin kuvvetini bulur
                power=i;
                i++;
            }
            
            /*if(operation.equals("d")){
                placeValue = (int)Math.pow(10,power - Math.log(multiplier) / Math.log(2));//basamak değerini bulur
            }
            else if(operation.equals("m")){
                placeValue = (int)Math.pow(10,power + Math.log(multiplier) / Math.log(2));//basamak değerini bulur
            }*/

            placeValue = (int)Math.pow(10,power);//basamak değerini bulur
            binaryN=binaryN+placeValue;
            remainderN= remainderN-(int)Math.pow(2,power);//kalan sayı
            

        }
        


        System.out.println("0b"+binaryN);
        scanner.close();

        


    }
    
}
