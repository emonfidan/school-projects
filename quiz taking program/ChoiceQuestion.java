import java.util.ArrayList;

public class ChoiceQuestion extends Question{
    private ArrayList<String> choices = new ArrayList<>();
    public void addChoice(String s, boolean b){
        choices.add(s);
        if(b){
            super.setAnswer(String.valueOf(choices.size()));
        }
        
    }
    public void display(){
        super.display();
        int i=1;
        for (String string : choices) {
            System.out.println(i+"-"+ string);
            i++;
        }
    }
}
