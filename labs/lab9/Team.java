import java.util.ArrayList;

public class Team {
    private int ID,averageAge,marketValue,sumOfAges;
    private String name;
    private ArrayList<Player> squad;
    public Team(int ID, String name){
        this.ID=ID;
        this.name=name;
        averageAge=0;
        marketValue=0;
        sumOfAges=0;
        squad = new ArrayList<Player>();
    }
    public int getID() {
        return ID;
    }
    public int getAverageAge() {
        return averageAge;
    }
    public int getMarketValue() {
        return marketValue;
    }
    public String getName() {
        return name;
    }
    public boolean playerExists(int jerseyNumber){
        for(int i=0; i<squad.size(); i++){
            if(squad.get(i).getJerseyNumber()==jerseyNumber){
                return true;
            }
        }
        return false;
    }
    public void addPlayer(Player player){
       
        marketValue+= player.getMarketValue();
        squad.add(player);
        sumOfAges+= player.getAge();
        averageAge= sumOfAges/squad.size();
    
    }
    public void removePlayer(int jerseyNumber){
        for(int i=0; i<squad.size(); i++){
            if(jerseyNumber==squad.get(i).getJerseyNumber()){
                marketValue-=squad.get(i).getMarketValue();
                sumOfAges-=squad.get(i).getAge();
                squad.remove(i);
                averageAge=sumOfAges/squad.size();
            }
        }
    }
    public String toString(){
        String table="%-20s %-3s %-12s %-7s %-18s %15s%n";
        String str=createDoubleRow()+String.format("=%45s                                  =%n", "Team Details")+createDoubleRow()+
            "ID: "+this.ID+"\nTeam: "+this.name+"\nAverage Age: "+this.averageAge+"\nMarket Value: "+String.format("%,d", this.marketValue)
            +"\nSquad is composed of following players: \n"+createRow()+String.format(table, "Name","Age","Nationality","Number","Position","Market Value")+createRow();
        for(int i=0;i<squad.size();i++){
            str+=squad.get(i);
        }
        str+=createDoubleRow();
        return str;
        
    }
    public String createRow(){
        return "---------------------------------------------------------------------------------\n";
    }
    public String createDoubleRow(){
        return "=================================================================================\n";
    }
}
