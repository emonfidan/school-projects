public class Player {
    private String name, nationality, position;
    private int age, jerseyNumber, marketValue;
    public Player(String string, int i, String string2, int j, String string3, int k){
        this.name=string;
        this.age=i;
        this.nationality=string2;
        this.jerseyNumber=j;
        this.position=string3;
        this.marketValue=k;
    }
    public void setPosition(String position) {
        this.position = position;
    }
    public void setAge(int age) {
        if(age>0){
            this.age = age;
        }
        //should be positive
    }
    public void setJerseyNumber(int jerseyNumber) {
        if(jerseyNumber>0 && jerseyNumber<100){
            this.jerseyNumber = jerseyNumber;
        }
        //between 1 and 99
    }
    public void setMarketValue(int marketValue) {
        if(marketValue>0){
            this.marketValue = marketValue;
        }
        //positive
    }
    @Override
    public String toString(){
        return String.format("%-20s %-3s %-12s %-7s %-18s %,15d%n", name,age,nationality,jerseyNumber,position,marketValue);
    }
    public int getJerseyNumber() {
        return this.jerseyNumber;
    }
    public String getNationality() {
        return this.nationality;
    }
    public String getName() {
        return name;
    }
    public String getPosition() {
        return position;
    }
    public int getAge() {
        return age;
    }
    public int getMarketValue() {
        return marketValue;
    }
    
}
