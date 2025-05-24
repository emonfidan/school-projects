public class Game {
    private Team[] teams;
    private int[] goals;
    public Game(Team team1, Team team2, int team1Goals, int team2Goals){
        teams= new Team[2];
        goals= new int[2];
        teams[0]=team1;
        teams[1]=team2;
        goals[0]=team1Goals;
        goals[1]=team2Goals;
    }
    public int getTeamPoints(int ID) {

        if(teams[0].getID()==ID){
            if(goals[0]<goals[1]){
                return 0;
            }
            else if(goals[0]>goals[1]){
                return 3;
            }
            else{
                return 1;
            }
        }
        else if (teams[1].getID()==ID){
            if(goals[0]<goals[1]){
                return 3;
            }
            else if(goals[0]>goals[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        return -1;
    }
    public Team[] getTeams(){
        return teams;
    }
    @Override
    public String toString(){
        return teams[0].getName()+" vs. "+teams[1].getName()+": "+goals[0]+"-"+goals[1];
    }
    
}
