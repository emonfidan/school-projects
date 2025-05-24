package lab5;

import java.util.Random;

public class Lab05_Q2 {
    public static void main(String[] args) {
        String deck="";
        String preplayer1Deck="",preplayer2Deck="";//Çiftleri atılmamış desteler
        String player1Deck="", player2Deck="";//Çiftleri atılmış desteler

        String cardTypes ="123456789TJQK";

        for(int i=0;i<13;i++){
            if(i==12){  // K'yı 3 kere yazdırır
                for(int k=1;k<=3;k++){
                    deck+=cardTypes.charAt(i);
                }
            }
            else{   // K haricindekileri 4 kere yazdırır
                for(int k=1;k<=4;k++){
                    deck+=cardTypes.charAt(i);
                }
            }  
        }

        Random rand = new Random(); 
        int randomChoice;

        for(int i=0;i<deck.length();i++){ //Kartları 25-26 dağıt

            if(preplayer1Deck.length()==26){  //1.oyuncu çoktan 26 olduysa diğer kartları 2.oyuncuya at
                preplayer2Deck+= deck.charAt(i);
            }
            else if(preplayer2Deck.length()==26){
                preplayer1Deck+= deck.charAt(i);
            }
            else{
                randomChoice = rand.nextInt(2);
                if(randomChoice==0){
                    preplayer1Deck+= deck.charAt(i);
                }
                else{
                    preplayer2Deck+= deck.charAt(i);
                }
            }
        }
        System.out.println("Starting the game with the following deck: "+deck+"\nInitial cards are dealing...\nPlayer-1 hand: "+preplayer1Deck+"\nPlayer-2 hand: "+preplayer2Deck);

        int i;
        for(i=1; i<preplayer1Deck.length();){ //çiftleri desteden sil
            if(preplayer1Deck.charAt(i)==preplayer1Deck.charAt(i-1)){ //kontrol edilen sayı bir öncekiyle aynıysa i'yi 2 arttır
                i+=2;
            }
            else{ //kontrol edilen sayı bir öncekiyle aynı değilse i'yi 1 arttır ve önceki sayıyı destelere ekle
                player1Deck+=preplayer1Deck.charAt(i-1);
                player2Deck+=preplayer1Deck.charAt(i-1);
                i++;
            }
        }
        if(i==preplayer1Deck.length() &&  preplayer1Deck.charAt(preplayer1Deck.length()-1)=='K'){ //1.nin son kartı tek sayıda ve k olursa 1.ye k ekle
            player1Deck+='K';
        }
        else if(i==preplayer1Deck.length()){ //1.nin son kartı tek sayıda ve k'dan farklı olursa o kartı destelere ekle ve 2.ye k ekle
            player1Deck+=preplayer1Deck.charAt(i-1);
            player2Deck+=preplayer1Deck.charAt(i-1);
            player2Deck+='K';
        }
        else{ //1.nin son kartı çift olursa 2.ye k ekle
            player2Deck+='K';
        }

        System.out.println("Pairs are removed:\nPlayer-1 hand: "+player1Deck+"\nPlayer-2 hand: "+player2Deck);
        
        int turn;
        if(preplayer1Deck.length()<preplayer2Deck.length()){  //Sıra kimde?
            turn=1;
        }
        else{
            turn=2;
        }

        System.out.println("Start Drawing...");

        do{
        
        if(turn==1){
            randomChoice=rand.nextInt(player2Deck.length());
            char drawedCard=player2Deck.charAt(randomChoice);

            System.out.println("Player-1 is drawing the card:"+player2Deck.charAt(randomChoice)+" from Player-2..."+"\nPlayer-1 hand:"+player1Deck+drawedCard);

            boolean isEven=false;
            for(int m=0;m<player1Deck.length();m++){ 
                if (player1Deck.charAt(m)==drawedCard){ //çekilen kartın çifti var mı?
                    isEven=true;
                    player1Deck=player1Deck.replaceAll(String.valueOf(drawedCard),"");//çekilen kartın çiftini yok et
                }
            }
            if(!isEven){ //çekilen kartın çifti yoksa kartı desteye ekle
                player1Deck+=drawedCard;
            }

            player2Deck=player2Deck.replaceAll(String.valueOf(drawedCard),"");//çekilen kartı karşı taraftan yok et
            System.out.println("Player-2 hand:"+player2Deck+"\nPairs are removed:"+"\nPlayer-1 hand:"+player1Deck+"\nPlayer-2 hand:"+player2Deck);
            turn=2;

        }
        else{ // sıra diğer oyuncudaysa aynı şeyleri ona yap
            randomChoice=rand.nextInt(player1Deck.length());
            char drawedCard=player1Deck.charAt(randomChoice);

            System.out.println("Player-2 is drawing the card:"+player1Deck.charAt(randomChoice)+" from Player-1...");
            
            player1Deck=player1Deck.replaceAll(String.valueOf(drawedCard),"");//çekilen kartı karşı taraftan yok et
            System.out.println("Player-1 hand:"+player1Deck+"\nPlayer-2 hand:"+player2Deck+drawedCard);

            boolean isEven=false;
            for(int m=0;m<player2Deck.length();m++){ //çekilen kartın çifti var mı?
                if (player2Deck.charAt(m)==drawedCard){
                    isEven=true;
                    player2Deck=player2Deck.replaceAll(String.valueOf(drawedCard),"");//çekilen kartın çiftini yok et
                }
            }
            if(!isEven){ //çifti yoksa desteye ekle
                player2Deck+=drawedCard;
            }
            
            System.out.println("Pairs are removed:"+"\nPlayer-1 hand:"+player1Deck+"\nPlayer-2 hand:"+player2Deck);
            turn=1;

        }
        }while(!player1Deck.equals("") && !player2Deck.equals("")); //birinin kartı biterse döngü biter

        if(player1Deck.equals("")){
            System.out.println("Game Over!\nPlayer-1 Wins!\nPlayer-1 hand:"+player1Deck+"\nPlayer-2 hand:"+player2Deck);
        }
        else{
            System.out.println("Game Over!\nPlayer-2 Wins!\nPlayer-1 hand:"+player1Deck+"\nPlayer-2 hand:"+player2Deck);
        }
    }
}
