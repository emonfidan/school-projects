public class Group {
    private String name;
    private int groupSize,numberOfTeams;
    private Team[] teams;
    private int[] points;
    private Game[][] games;//2D array
    public Group(String name, int groupSize){
        this.name=name;
        this.groupSize=groupSize;
        numberOfTeams=0;
        teams=new Team[groupSize];
        games=new Game[groupSize][groupSize];
        points=new int[groupSize];
    }
    public String getName(){
        return this.name;
    }
    public int getGroupSize(){
        return this.groupSize;
    }
    public int getNumberOfTeams(){
        return this.numberOfTeams;
    }
    public boolean teamExists(int id){
        for(int i=0; i<numberOfTeams; i++){
            if(teams[i].getID()==id){
                return true;
            }
        }
        return false;
    }
    public boolean gameExists(int id1, int id2){

        if(games[getIndexById(id1)][getIndexById(id2)]==null){
            return false;
        }
    
        return true;
    }
    public boolean addTeam(Team team){
        if(!isFull() && !teamExists(team.getID())){
            teams[numberOfTeams]=team;
            numberOfTeams++;
            return true;
        }
        return false;
    }
    public void addGame(Game game){
        
        Team[] teamsOfGame=game.getTeams();
        int indexOfTeam1=-1, indexOfTeam2=-1;
            for(int i=0; i<groupSize; i++){
                if(teams[i]!=null && teams[i].equals(teamsOfGame[0])){
                    indexOfTeam1=i;
                }
                else if(teams[i]!=null && teams[i].equals(teamsOfGame[1])){
                    indexOfTeam2=i;
                }
            }
        games[indexOfTeam1][indexOfTeam2]=game;
        games[indexOfTeam2][indexOfTeam1]=game;
        points[indexOfTeam1]+=game.getTeamPoints(teamsOfGame[0].getID());
        points[indexOfTeam2]+=game.getTeamPoints(teamsOfGame[1].getID());        
    }

    @Override
    public String toString(){
        String str=createDoubleRow()+String.format("=%25s       =%n", "Group "+this.name+" Standings")+createDoubleRow();
        int[] teamIndexesInOrder=getTeamIndexesInOrder();
    
        for(int i=0;i<numberOfTeams;i++){ 
            int currentIndex= teamIndexesInOrder[i];
            str+=String.format("%2s.%15s ( %2s )%5s%n", i+1,teams[currentIndex].getName(),teams[currentIndex].getID(),points[currentIndex]);

        }
        str+=createDoubleRow();
        return str;
    }
    public String createDoubleRow(){
        return "==================================\n";
    }
    public boolean isFull(){
        if(numberOfTeams==groupSize){
            return true;
        }
        return false;
    }
    public Team getTeamById(int id){
        for(int i=0; i<numberOfTeams; i++){
            if(teams[i].getID()==id){
                return teams[i];
            }
        }
        return null;
    }
    public int getIndexById(int id){
        for(int i=0;i<numberOfTeams;i++){
            if(teams[i].getID()==id){
                return i;
            }
        }
        return -1;
    }
    public int[] getTeamIndexesInOrder(){
        int[] teamIndexesInOrder= new int[numberOfTeams];
        int[] copyOfPoints=new int[numberOfTeams];
        for(int i=0;i<numberOfTeams;i++){
            copyOfPoints[i]=points[i];
        }
        int currentBiggest=-1, currentBiggestIndex=-1;
        for(int j=0;j<numberOfTeams;j++){
            for(int i=0;i<numberOfTeams;i++){
                if(copyOfPoints[i]>currentBiggest){
                    currentBiggestIndex=i;
                    currentBiggest=copyOfPoints[i];
                    
                }
            }
            teamIndexesInOrder[j]=currentBiggestIndex;
            copyOfPoints[currentBiggestIndex]=-1;
            currentBiggest=-1;
        }
        return teamIndexesInOrder;
    }
    
}
