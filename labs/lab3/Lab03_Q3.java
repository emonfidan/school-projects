package lab3;

import java.util.Scanner;

public class Lab03_Q3 {
    public static void main(String[] args) {

        String userName="JavaWarrior";
        String password="JavaRocks";
        int coins=600;
        String buddy="";

        Scanner scanner= new Scanner(System.in);

        System.out.println("Enter your user name:");
        String nameInput= scanner.nextLine();
        if (!nameInput.equals(userName)){
            System.out.println("Username not found! Bye!");
        }
        else{
            System.out.println("Enter your password:");
            String passwordInput= scanner.nextLine();
            if (!passwordInput.equals(password)){
                System.out.println("Wrong password! Bye!");
            }
            else{
                
                //while(true){
                System.out.println("1- Upgrade armor\n2- Add a buddy\n3- Change credentials\nSelect an operation:");
                String operation= scanner.nextLine();
                
                if(operation.equals("1")){
                    System.out.println("Upgrade armor:\nYou have "+coins+" coins.");
                    if (coins-150>=0){
                        coins=coins-150;
                        System.out.println("Your armor has been upgraded!\nYou have "+coins+" coins. Bye!");
                    }
                    else{
                        System.out.println("Not enough coins! Bye!");
                    }

                }
                else if(operation.equals("2")){
                    
                    if(buddy.equals("")){
                        System.out.println("Add a buddy:\nEnter your buddy's name: ");
                        buddy= scanner.nextLine();
                        System.out.println("Your buddy is"+buddy+". Bye!");
                    }
                    else{
                        System.out.println("Add a buddy:\nYou already have a buddy!\nYour buddy is "+buddy+". Bye!");
                    }
                      
                }
                else if(operation.equals("3")){
                    System.out.println("Change credentials:\n1- Change username\n2- Change password\nSelect an option:");
                    String operation2= scanner.nextLine();
                    if(operation2.equals("1")){
                        System.out.println("Enter your new username:");
                        userName= scanner.nextLine();
                        System.out.println("Your username is "+userName+"\nYour password is "+password+"\nBye!");

                    }
                    else if(operation2.equals("2")){
                        System.out.println("Enter your new password:");
                        password= scanner.nextLine();
                        System.out.println("Your username is "+userName+"\nYour password is "+password+"\nBye!");

                    }
                    /*else{
                        break;
                    }*/
                }
                /*else if(operation.equals("4")){
                    System.out.println("Bye!");
                    break;
                }*/
                else{
                    System.out.println("Invalid input!");
                }
                }
            //}

        }

        scanner.close();
        
    }
}
