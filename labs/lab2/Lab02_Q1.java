package lab2;

import java.util.Scanner;

public class Lab02_Q1 {
    public static void main(String[] args) {

        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter length of the semi major axis of the ellipse: ");
        double semiMajorAxis = scanner.nextDouble(); 
        System.out.println("Enter length of the semi minor axis of the ellipse: ");
        double semiMinorAxis = scanner.nextDouble(); 
        
        double area= Math.PI*semiMajorAxis*semiMinorAxis;
        double circumference= 2*Math.PI*Math.pow((semiMajorAxis*semiMajorAxis+semiMinorAxis*semiMinorAxis)/2,1/2.0);
        
        
        System.out.printf("%s %10.3f","The area of the ellipse is            : ", area);

        System.out.printf("%s %10.3f","\nThe circumference of the ellipse is ~ : ", circumference);

        scanner.close();
    }    
}
