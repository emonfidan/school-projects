package lab2;

import java.util.Scanner;

public class Lab02_Q3 {
    public static void main(String args[]){

        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter the title: ");
        String givenWord= scanner.nextLine();

        System.out.println("--------------------------------------\nNumber of characters: "+givenWord.length()+
        "\nAll lowercase: \""+ givenWord.toLowerCase()+ "\"\nRemove leading and trailing blank characters: \""+
        givenWord.trim()+"\"\nCharacter at index position 4: '"+givenWord.charAt(4)+
        "'\nTitle from 3rd character to 5th character (both included): \"" +givenWord.substring(2, 5)+
        "\"\nFirst occurrence of character 'P': "+givenWord.indexOf('P')+
        "\nLast occurrence of character 'P':"+givenWord.lastIndexOf('P'));
        


        scanner.close();

    }
}
