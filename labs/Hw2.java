public class Hw2 {
    public static long calcPellA(int n){ // returns nth Pell number
    if (n < 2){ 
        return n;
    }
    return 2 * calcPellA(n-1) + calcPellA(n-2);
    }
    public static long calcPellB(int n){ // returns nth Pell number
        if (n < 2){ 
            return n;
        }
        long prev = 0;
        long current = 1;
        int i = 1;
        long next=-1;
        while (i < n){
            next =prev +  2 * current;
            prev= current;
            current =next ;
            i++;
        }
        return next;
    }
    public static void main(String[] args) {
        System.out.printf("%3s %15s %15s %n", "n","calcPellA","calcPellB");
        String table= "%3d %15d %15d %n";
        for(int i=0;i<=50;i+=5){
            long startA=System.nanoTime();
            calcPellA(i);
            long endA=System.nanoTime();
            long startB=System.nanoTime();
            calcPellB(i);
            long endB=System.nanoTime();

            System.out.printf(table, i,endA-startA,endB-startB);
            
        }
    }
}
