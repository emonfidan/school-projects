package lab1;

import java.util.Scanner;

public class Lab01_Q2 {
    
    public static void main(String[] args) {
        int preNum1=-1,preNum2=-1;
        boolean isAscending1=true, isAscending2=true, isFirstTime1=true, isFirstTime2=true;
        int num=1, turn=0;
        Scanner in= new Scanner(System.in);
        do{
            if(turn==0){
                if(isFirstTime1){
                    preNum1=in.nextInt();
                    isFirstTime1=false;
                }
                else{
                    if(preNum1>=num){
                        isAscending1=false;
                    }
                    preNum1=num;
                }
                turn=1;
            }
            else{
                if(isFirstTime2){
                    preNum2=in.nextInt();
                    isFirstTime2=false;
                }
                else{
                    
                    if(preNum2>=num){
                        isAscending2=false;
                    }
                    preNum2=num;
                }
                turn=0;
            }
            num=in.nextInt();

        }while(num>0);

        if(isAscending1&&isAscending2){
            System.out.println("yes");
        }
        else{
            System.out.println("no");
        }
    }
}
