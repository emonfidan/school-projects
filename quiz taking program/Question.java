public class Question extends Abstract{
    private String text;
    private String answer;
    public Question(){
        text = "";
        answer = "";
    }
    public void setText(String text){
        this.text = text;
    }
    public void setAnswer(String answer){
        this.answer = answer;
    }
    public boolean checkAnswer(String answer){
        return this.answer.equals(answer);
    }
    public void display(){
        System.out.println(text);
    }
    @Override
    public void abstractMethod() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'abstractMethod'");
    }
}