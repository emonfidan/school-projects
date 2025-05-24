package lab2;

import java.util.Scanner;

public class Lab02_Q2 {
    public static void main(String[] args) {

        final double AVERAGE_COST= 237760;
        final double SITE_WORK= 15903;
        final double FOUNDATIONS= 25671;
        final double FRAMING= 41123;
        final double EXTERIOR= 33066;
        final double UTILITY= 32746;
        final double INTERIOR_FINISHES= 67939;
        final double OUTDOOR= 16591;
        final double UNEXPECTED_COSTS= (int)AVERAGE_COST-(SITE_WORK+FOUNDATIONS+FRAMING+EXTERIOR+UTILITY+INTERIOR_FINISHES+OUTDOOR);

        final double SITE_WORK_PERCENTAGE= SITE_WORK/AVERAGE_COST*100;
        final double FOUNDATIONS_PERCENTAGE= FOUNDATIONS/AVERAGE_COST*100;
        final double FRAMING_PERCENTAGE= FRAMING/AVERAGE_COST*100;
        final double EXTERIOR_PERCENTAGE= EXTERIOR/AVERAGE_COST*100;
        final double UTILITY_PERCENTAGE= UTILITY/AVERAGE_COST*100;
        final double INTERIOR_FINISHES_PERCENTAGE= INTERIOR_FINISHES/AVERAGE_COST*100;
        final double OUTDOOR_PERCENTAGE= OUTDOOR/AVERAGE_COST*100;
        final double UNEXPECTED_COSTS_PERCENTAGE= UNEXPECTED_COSTS/AVERAGE_COST*100;

        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter the cost of building a house in USD: ");
        if(scanner.hasNextLine()){
            System.out.println("hehe");
        }
        int userCost= scanner.nextInt();
        

        System.out.println("**********************************************");
        System.out.printf("%4s%33s%9s" ,"****","House Cost","****\n");
        System.out.println("**********************************************");


        String table = "* %-18s%%%-5d%,14.2f     *%n";
        System.out.printf(table ,"Site Work",(int)SITE_WORK_PERCENTAGE, MaliyetHesapla(SITE_WORK_PERCENTAGE, userCost),"*");
        System.out.printf(table ,"Foundations",(int)FOUNDATIONS_PERCENTAGE, MaliyetHesapla(FOUNDATIONS_PERCENTAGE, userCost),"*");
        System.out.printf(table ,"Framing",(int)FRAMING_PERCENTAGE, MaliyetHesapla(FRAMING_PERCENTAGE, userCost),"*");
        System.out.printf(table ,"Exterior",(int)EXTERIOR_PERCENTAGE, MaliyetHesapla(EXTERIOR_PERCENTAGE, userCost),"*");
        System.out.printf(table ,"Utility",(int)UTILITY_PERCENTAGE, MaliyetHesapla(UTILITY_PERCENTAGE, userCost),"*");
        System.out.printf(table ,"Interior Finishes",(int)INTERIOR_FINISHES_PERCENTAGE, MaliyetHesapla(INTERIOR_FINISHES_PERCENTAGE, userCost),"*");
        System.out.printf(table ,"Outdoor",(int)OUTDOOR_PERCENTAGE, MaliyetHesapla(OUTDOOR_PERCENTAGE, userCost),"*");
        System.out.printf(table ,"Unexpected Costs",(int)UNEXPECTED_COSTS_PERCENTAGE, MaliyetHesapla(UNEXPECTED_COSTS_PERCENTAGE, userCost),"*");
        System.out.printf("%5s %35.2f %5s\n","* TOTAL",(double)userCost,"*");
        System.out.println("*************************************************");
        scanner.close();
    }
    public static double MaliyetHesapla(double persentage, int cost){
        double newCost= cost*persentage/100;
        return newCost;
    }
}
