package lab3;

import java.util.Scanner;

public class Lab03_Q1 {
    public static void main(String[] args) {

        Scanner scanner= new Scanner(System.in);
        System.out.println("Student's credit units:");
        int creditUnits= scanner.nextInt();
        System.out.println("Student's cumulative grade point average (CGPA):");
        double  cGpa= scanner.nextDouble();

        if(creditUnits>120){
            if(cGpa>2.0){
                System.out.println("The graduation requirements are satisfied.");

            }
            else{
                System.out.println("The CGPA is not sufficient.\nThe graduation requirements are NOT satisfied.");

            }

        }
        else{
            System.out.println("The credit units are not sufficient.\nThe graduation requirements are NOT satisfied.");

        }


        scanner.close();
    }        
}
