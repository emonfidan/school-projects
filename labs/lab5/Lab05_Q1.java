package lab5;

import java.util.Scanner;

public class Lab05_Q1 {
    public static void main(String[] args) {

        Scanner scanner=new Scanner(System.in);
        System.out.println("String:");
        String str= scanner.next();
        int recentNum,biggestNum=-1;

        for(int i=0;i<str.length();i++){  //en büyük sayıyı bulur
            if(str.charAt(i)!='F' && (i!=0 && str.charAt(i-1)!='F')){
                recentNum=Integer.parseInt(str.substring(i, i+1));
                if(recentNum>biggestNum){
                    biggestNum=recentNum;
                }
            }
            
        }

        for(int i=0;i<biggestNum;i++){
            for(int m=0;m<)
            if(str.charAt(i)=='F'){
                for(int k=0;k<Integer.parseInt(str.substring(i+1, i+2));k++){
                    System.out.print("*");
                }
                i++;
            }
            else{
                for(int k=0; k<str.length();k++){
                    if(Integer.parseInt(str.substring(k, k+1))>i){
                        System.out.print("*");
                    }
                    else{
                        System.out.print(" ");
                    }
                    
                }


            }
            
            System.out.println();
        }



        scanner.close();
    }
}
