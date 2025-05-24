package lab7;

public class Track {
    private static int count=0;
    private static int allCount=0;
    private int id;
    private String title;
    private int album;
    private int artist;
    private String releaseDate;
    private short duration;
    private String genre;
    private boolean isActive;
    private int playCount;

    public Track(String title, int album,int artist, String releaseDate,short duration){
        register();
        this.id=allCount;
        this.title=title;
        this.album=album;
        this.artist=artist;
        this.releaseDate=releaseDate;
        this.duration=duration;
        this.isActive=true;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public int getAlbum() {
        return album;
    }

    public int getArtist() {
        return artist;
    }

    public String getReleaseDate() {
        return releaseDate;
    }

    public short getDuration() {
        return duration;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String gen) {
        
        if(gen.equals("PO")){
            this.genre = "Popular";
        }
        else if(gen.equals("RO")){
            this.genre = "Rock";
        }
        else if(gen.equals("JA")){
            this.genre = "Jazz";
        }
        else if(gen.equals("OT")){
            this.genre = "Other";
        }
        else{
            this.genre = "Unspecified";
        }
        
    }

    public void register(){
        count++;
        allCount++;
    }
    
    public void unRegister(){
        count--;
        this.isActive=false;
    }

    public boolean isBefore(Track anotherTrack){
        String revisedDateString=this.releaseDate.substring(6, 10)+this.releaseDate.substring(2, 6)+this.releaseDate.substring(0, 2);
        String anotherRevisedDateString=anotherTrack.releaseDate.substring(6, 10)+anotherTrack.releaseDate.substring(2, 6)+anotherTrack.releaseDate.substring(0, 2);
        if(revisedDateString.compareTo(anotherRevisedDateString)<0){
            return true;
        }
        return false;
    }
    public void play(){
        if(this.isActive){
            playCount++;
        }
        else{
            System.out.println("play() called on inactive track!");
        }
    }
    public void playBatch(int countToIncrement){
        playCount=playCount+countToIncrement;
    }
    public String toString(){
        String str="";
        str+=("*************************************\n");
        str+="Inactive track "+(allCount-count)+" among "+allCount+" tracks\n";
        String table="%15s: %-10s %n";
       
        str+=String.format(table, "Title",this.getTitle());
        str+=String.format(table, "Album",this.getAlbum());
        str+=String.format(table, "Artist",this.getArtist());
        str+=String.format(table, "Release Date",this.getReleaseDate());
        str+=String.format(table, "Duration",this.getDuration());
        str+=String.format(table, "Genre",this.getGenre());
        return str;

    }
    public static void main(String[] args) {
        Track t1 = new Track("Love over gold", 123, 234, "12/08/1982", (short)2473);
        t1.setGenre("RO");
        Track t2 = new Track("Gozleri aska gulen", 0, 98, "18/04/2018", (short)257);
        t2.setGenre("PO");
        Track t3 = new Track("Down to the waterline", 123, 234, "09/06/1978", (short)235);
        System.out.println("Is t1 before t2? " + t1.isBefore(t2));
        System.out.println("Is t2 before t3? " + t2.isBefore(t3));
        t1.unRegister();
        System.out.println(t2.toString());
        
    }
}
