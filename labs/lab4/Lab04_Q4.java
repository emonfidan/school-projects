package lab4;

public class Lab04_Q4 {
    
    public static void main(String[] args) {

    double x_start =0;
    double x_end =1;
    double step_size = 0.01;
    double total_area = 0;
    double function;
    double i=x_start;

    while(i<=x_end){
        i+=step_size;
        //function= Math.sin(Math.PI*i)+Math.sin(3*Math.PI*i)/3;
        function=Math.pow(i,2);

        total_area=total_area+function*step_size;
        
    }

    //System.out.println("Area under 'sin(PI*x) + sin(PI*3*x)/3' from"+x_start+" to "+x_end+": "+total_area);
    System.out.println("Area under 'x^2' from "+x_start+" to "+x_end+": "+total_area);
    
    }

}
