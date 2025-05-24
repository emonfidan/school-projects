package lab1;

public class Lab01_Q3 {
    public static void main(String[] args) {


    double humanWeight= 70;
    final double ALL_ATOMS= Math.pow(10, 27)*7;
    //System.out.println(ALL_ATOMS);
    final double OXYGEN_RATE= 65;//mass of atoms' persentage
    final double CARBON_RATE= 18.5;
    final double HYDROGEN_RATE= 10;
    final double NİTROGEN_RATE= 3.2;
    final double CALCİUM_RATE= 1.5;
    final double PHOSPHORUS_RATE= 98.6-(OXYGEN_RATE+CALCİUM_RATE+CARBON_RATE+HYDROGEN_RATE+NİTROGEN_RATE);
    final double OTHERS_RATE= 100-(OXYGEN_RATE+CARBON_RATE+HYDROGEN_RATE+NİTROGEN_RATE+CALCİUM_RATE+PHOSPHORUS_RATE);
    final double OXYGEN_ATOM_RATE= 24;//number of atoms' persentage
    final double HYDROGEN_ATOM_RATE= 62;

    double others_atom_number= ALL_ATOMS*(100-OXYGEN_ATOM_RATE-HYDROGEN_ATOM_RATE)/100;

    System.out.println("Phosphorus makes up"+ PHOSPHORUS_RATE+ " percent of the mass in the human body.");
    System.out.println("Elements other than oxygen, carbon, hydrogen, nitrogen, calcium and phosphorus make up "+ OTHERS_RATE+ " percent of the mass with an atom count of "+ others_atom_number+".\n");
    System.out.println("For a person of"+ humanWeight+ " kg the mass of the elements are:\nOxygen: "+ humanWeight*OXYGEN_RATE/100+"kg\nCarbon: "+humanWeight*CARBON_RATE/100+"kg\n");
    System.out.println("whereas the number of atoms of some elements in this person are:\nHydrogen:"+ ALL_ATOMS*HYDROGEN_ATOM_RATE/100+"\nOxygen: "+ALL_ATOMS*OXYGEN_ATOM_RATE/100);
    

    }
}
