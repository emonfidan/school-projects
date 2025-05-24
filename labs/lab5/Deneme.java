package lab5;

public class Deneme {
    public static int countYZ(String str) {
        str=str.toLowerCase();
        int counter=0;
        if(str.charAt(str.length()-1)=='y'||str.charAt(str.length()-1)=='z'){
          counter++;
        }
        for(int i=1;i<str.length()-1;i++){
          if(str.charAt(i)==' '&&(str.charAt(i-1)=='y'||str.charAt(i-1)=='z')){
            counter++;
          }
        }
        return counter;
      }
      

    public static void main(String[] args) {
        
        System.out.println(Deneme.countYZ("xyzz"));
    }
}
