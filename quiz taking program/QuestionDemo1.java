import java.util.Scanner;

public class QuestionDemo1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ChoiceQuestion q = new ChoiceQuestion();
        q.setText("who was the inventor of Java?");
        q.addChoice("a",false);
        q.addChoice("b",true);
        q.display();
        System.out.println(q.checkAnswer(scanner.nextLine()));
        scanner.close();
    }
}
