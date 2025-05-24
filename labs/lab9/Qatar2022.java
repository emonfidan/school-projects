/** A class for Qatar 2022 World Cup
*   Turkiye is also qualified in this version :)
*   Market values and player information is obtained from Transfermarkt.com
*   @author Ozcan Ozturk
*   @version 1.0
*/
import java.util.Scanner;

public class Qatar2022 {
    /**
     * @param args
     */
    public static void main(String[] args) {        
        // Form the English Team
        Team england = new Team(34, "England");
        england.addPlayer(new Player("Raheem Sterling",  27, "England", 17, "Left Wing", 70000000));
        england.addPlayer(new Player("Phil Foden",  22, "England", 47, "Central Midfield", 110000000));
        england.addPlayer(new Player("Jack Grealish",  27, "England", 10, "Left Wing", 70000000));
        england.addPlayer(new Player("Declan Rice",  23, "England", 41, "Defensive Midfield", 80000000));
        england.addPlayer(new Player("Aaron Ramsdale", 24, "England", 23, "Goalkeeper", 30000000)); 
        england.addPlayer(new Player("Jordan Pickford", 28, "England", 1, "Goalkeeper", 28000000));
        england.addPlayer(new Player("Nick Pope", 30, "England", 13, "Goalkeeper", 18000000));
        england.addPlayer(new Player("Ben White", 25, "England", 21, "Centre Back", 45000000)); 
        england.addPlayer(new Player("John Stones", 28, "England", 5, "Centre Back", 30000000));	
        england.addPlayer(new Player("Harry Maguire", 29, "England", 6, "Centre Back", 30000000));
        england.addPlayer(new Player("Eric Dier", 28, "England", 15, "Centre Back", 30000000));
        england.addPlayer(new Player("Conor Coady", 29, "England", 16, "Centre Back", 18000000));
        england.addPlayer(new Player("Luke Shaw", 27, "England", 3, "Left Back", 28000000)); 
        england.addPlayer(new Player("Kyle Walker", 32, "England", 2, "Right Back", 15000000)); 
        england.addPlayer(new Player("Jude Bellingham", 19, "England", 22, "Central Midfield", 100000000));
        england.addPlayer(new Player("Harry Kane", 29, "England", 9, "Centre Forward", 90000000));

        // Form the Turkish Team
        Team turkiye = new Team(38, "Türkiye");
        turkiye.addPlayer(new Player("Ugurcan Çakir", 26, "Türkiye", 23, "Goalkeeper", 14000000));
        turkiye.addPlayer(new Player("Altay Bayindir", 24, "Türkiye", 1, "Goalkeeper", 13000000)); 
        turkiye.addPlayer(new Player("Çaglar Söyüncü",	26, "Türkiye", 4, "Centre Back", 22000000)); 
        turkiye.addPlayer(new Player("Ozan Kabak", 22, "Türkiye", 15, "Centre Back", 10000000)); 
        turkiye.addPlayer(new Player("Tayyip Sanuç", 22, "Türkiye", 6, "Centre Back", 3800000)); 
        turkiye.addPlayer(new Player("Eren Elmali", 22, "Türkiye", 13, "Left Back", 4200000)); 
        turkiye.addPlayer(new Player("Zeki Çelik", 25, "Türkiye", 2, "Right Back", 15000000)); 
        turkiye.addPlayer(new Player("Salih Özcan", 24, "Türkiye", 5, "Defensive Midfield", 17000000));
        turkiye.addPlayer(new Player("Hakan Çalhanoglu", 28, "Türkiye", 10, "Central Midfield", 35000000));
        turkiye.addPlayer(new Player("Arda Güler", 17, "Türkiye", 25, "Attacking Midfield", 10000000));
        turkiye.addPlayer(new Player("Kerem Aktürkoglu", 24, "Türkiye", 7, "Left Wing", 13000000));
        turkiye.addPlayer(new Player("Cengiz Ünder", 25, "Türkiye", 17, "Right Wing", 17000000));
        turkiye.addPlayer(new Player("Enes Ünal", 25, "Türkiye", 16, "Centre Forward", 25000000));
        turkiye.addPlayer(new Player("Umut Bozok", 26, "Türkiye", 19, "Centre Forward", 5500000));
        turkiye.addPlayer(new Player("Cenk Tosun", 31, "Türkiye", 9, "Centre Forward", 2000000));

        // Form the Germany Team
        Team germany = new Team(6, "Germany");
        germany.addPlayer(new Player("Andre Ter Stegen", 30, "Germany", 22, "Goalkeeper", 30000000)); 
        germany.addPlayer(new Player("Manuel Neuer", 36, "Germany", 1, "Goalkeeper", 12000000));
        germany.addPlayer(new Player("Antonio Rüdiger", 29, "Germany", 2, "Centre Back", 40000000)); 
        germany.addPlayer(new Player("Niklas Süle", 27, "Germany", 15, "Centre Back", 35000000));
        germany.addPlayer(new Player("Thilo Kehrer", 26, "Germany", 5, "Centre Back", 22000000)); 
        germany.addPlayer(new Player("David Raum", 24, "Germany", 3, "Left Back", 26000000)); 
        germany.addPlayer(new Player("Lukas Klostermann", 26, "Germany", 16, "Right Back", 14000000)); 
        germany.addPlayer(new Player("Joshua Kimmich", 27, "Germany", 6, "Defensive Midfield", 80000000));
        germany.addPlayer(new Player("Leon Goretzka", 27, "Germany", 8, "Central Midfield", 65000000));
        germany.addPlayer(new Player("Ilkay Gündogan", 32, "Germany", 21, "Central Midfield", 25000000));
        germany.addPlayer(new Player("Jamal Musiala", 19, "Germany", 14, "Attacking Midfield", 100000000));
        germany.addPlayer(new Player("Leroy Sane", 26, "Germany", 19, "Left Wing", 70000000));
        germany.addPlayer(new Player("Serge Gnabry", 27, "Germany", 10, "Right Wing", 65000000));
        germany.addPlayer(new Player("Karim Adeyemi", 20, "Germany", 24, "Right Wing", 35000000));
        germany.addPlayer(new Player("Youssoufa Moukoko", 18, "Germany", 26, "Centre Forward", 30000000));
        germany.addPlayer(new Player("Niclas Füllkrug", 29, "Germany", 9, "Centre Forward", 5000000));
        
        // Create a Group to play the matches in the group
        // Group is created with 4 teams but 3 teams have already
        // been created manually to have some data ready to be used.
        Group groupA = new Group("A", 4);

        // Add the teams to Group "A"
        groupA.addTeam(germany);
        groupA.addTeam(england);
        groupA.addTeam(turkiye);

        // TODO: Complete the rest of the Class
        // TODO: Add the menu options and take user input

        String stringMenuOptions=String.format("%14s  Group: %-5s%14s","-------------------", groupA.getName(),"------------------" )
            +"\n1 - Create a new Team\n2 - Display a Team\n3 - Add a Player to a Team\n4 - Remove a Player with ID from a Team\n5 - Add a Game to the Group\n6 - Display Standings\n7 - Exit\n"+createRow()+"Your choice: ";

        Scanner scanner=new Scanner(System.in);
        boolean keepGoing=true;
        System.out.print(createRow()+ "Welcome to Qatar 2022! Get Ready for the World Cup!\n"+createRow());

        while(keepGoing){
            System.out.print(stringMenuOptions);
            int choice=scanner.nextInt();
            if(choice==1){
                if(!groupA.isFull()){
                    System.out.print("What is the unique ID of the Team?: ");
                    int teamId=scanner.nextInt();
                    if(teamId<0){
                        System.out.println("Team ID cannot be negative!");;
                    }
                    else{
                        System.out.print("What is the name of the Team?: ");
                        String teamName=scanner.next();
                        Team team=new Team(teamId, teamName);
                        groupA.addTeam(team);
                    }
                }
                else{
                    System.out.println("Group already has "+ groupA.getGroupSize()+"/"+groupA.getGroupSize()+" teams.");
                }
            }
            else if(choice==2){
                System.out.print("What is the unique ID of the Team?: ");
                int id=scanner.nextInt();
                if(id<0){
                    System.out.println("Team ID cannot be negative!");
                }
                else{
                    Team team=groupA.getTeamById(id);
                    if(team==null){
                        System.out.println("Team does not exist!");
                    }
                    else{
                        System.out.println(team);

                    }
                }
            }
            else if(choice==3){
                System.out.print("What is the unique ID of the Team to add the Player?: ");
                int id=scanner.nextInt();
                System.out.print("Enter the name of the player: ");
                String name=scanner.next();//@TODO
                System.out.print("Enter the age of the player:");
                int age=scanner.nextInt();
                System.out.print("Enter the nationality of the player: ");
                String nationality=scanner.next();
                Team team=groupA.getTeamById(id);
                if(!nationality.equals(team.getName())){
                    System.out.println("Player must be a citizen of the country!");
                }
                else{
                    System.out.print("Enter the jersey number of the player: ");
                    int jerseyNumber=scanner.nextInt();
                    if(team.playerExists(jerseyNumber)){
                        System.out.println("Player with the jersey number already exists!");
                    }
                    else{
                       System.out.print("Enter the position of the player: ");
                        String positon=scanner.next();
                        System.out.print("Enter the market value of the player: ");
                        int marketValue=scanner.nextInt();
                        if(marketValue<0){
                            System.out.println("Market value cannot be negative!");
                        }
                        else{
                            team.addPlayer(new Player(name, age, nationality, jerseyNumber, positon, marketValue));
                        }
                         
                    }
                    
                }
            }
            else if(choice==4){
                System.out.print("What is the unique ID of the Team to remove the Player?: ");
                int id=scanner.nextInt();
                Team team=groupA.getTeamById(id);
                if(team!=null){
                    System.out.print("Enter the jersey number of the player: ");
                    int jerseyNumber=scanner.nextInt();
                    if(team.playerExists(jerseyNumber)){
                        groupA.getTeamById(id).removePlayer(jerseyNumber);
                    }
                    else{
                        System.out.println("Player does not exist!");
                    }
                }
                else{
                    System.out.println("Team does not exist!");
                }
            
            }
            else if(choice==5){
                System.out.print("What is the unique ID of the First Team?: ");
                int id1=scanner.nextInt();
                if(groupA.getTeamById(id1)==null){
                    System.out.println("First team does not exist!");
                }
                else{
                    System.out.print("What is the unique ID of the Second Team?: ");
                    int id2=scanner.nextInt();
                    if(groupA.getTeamById(id2)==null){
                        System.out.println("Second team does not exist!");
                    }
                    else{
                        System.out.print("Enter the score (such as 2 1): ");
                        int point1=scanner.nextInt();
                        int point2=scanner.nextInt();
                        if(point1<0 || point2<0){
                            System.out.println("Scores cannot be negative!");
                        }
                        else{
                            Game game=new Game(groupA.getTeamById(id1), groupA.getTeamById(id2), point1, point2);
                            if(groupA.gameExists(id1,id2)){
                                System.out.println("Already a game between the teams exists!");
                            }
                            else{
                                groupA.addGame(game);
                            } 
                        }
                    }
                }
            }
            else if(choice==6){
                System.out.println(groupA);
            }
            else if(choice==7){
                keepGoing=false;
            }
            else{
                System.out.println("Invalid input!");
            }
        }

    }  
    public static String createRow(){
        return "---------------------------------------------------\n";
    }  
}
