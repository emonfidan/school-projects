package lab6;

import java.util.Scanner;

public class Lab06_Q4 {
    static long intToBinary(int num){
        long binaryN=0;
        int remainderN=num;
        int power=0;
        int i;
        
        while(remainderN!=0){
            i=0;
            while(Math.pow(2,i)<=remainderN){//kalan sayıdan küçük en büyük 2'nin kuvvetini bulur
                power=i;
                i++;
            }
            
            int placeValue = (int)Math.pow(10,power);//basamak değerini bulur
            binaryN=binaryN+placeValue;
            remainderN= remainderN-(int)Math.pow(2,power);//kalan sayı
            

        }
        return binaryN;

    }
    static long binaryAND(int a, int b){
        //return intToBinary(a&b);
        String result="";
        String str = String.valueOf(intToBinary(a)+intToBinary(b));
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='2'){
                result+='1';
            }
            else{
                result+='0';
            }
        }
        return Long.parseLong(result);
    }
    static long binaryOR(int a, int b){
        //return intToBinary(a|b);
        String result="";
        String str = String.valueOf(intToBinary(a)+intToBinary(b));
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='0'){
                result+='0';
            }
            else{
                result+='1';
            }
        }
        return Long.parseLong(result);
    }
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        System.out.print("Please enter the first natural number: ");
        int a=in.nextInt();
        System.out.print("Please enter the second natural number: ");
        int b=in.nextInt();
        System.out.println("Binary representation of the first number: "+intToBinary(a));
        System.out.println("Binary representation of the second number: "+intToBinary(b));
        System.out.println("The bitwise AND operation result: "+binaryAND(a, b));
        System.out.println("The bitwise OR operation result: "+binaryOR(a, b));
        in.close();
    }
}
