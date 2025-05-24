package lab8;

import java.util.Random;
import java.util.Scanner;

import javax.lang.model.util.ElementScanner6;

enum Direction {NORTH, EAST, SOUTH, WEST}

/**
 * This class implements a manager for a game where the goal for a player is
 * to reach the bottom right corner of an n x n room, starting from the upper
 * left cornder and avoiding any enemies (monster, bug, etc.)
 * 
 * @author Ugur Dogrusoz
 */
public class GameManager 
{
    // static variables/constants

    public static final Random random = new Random(); 
    private static final int NO_OF_ROWS = 5;
    private static final int NO_OF_COLUMNS = 5;
    private static final int TARGET_X = NO_OF_COLUMNS - 1;
    private static final int TARGET_Y = NO_OF_ROWS - 1;
    private static final int INITIAL_PLAYER_HEALTH = 10;
    private static final int MONSTER_DAMAGE_TO_PLAYER = INITIAL_PLAYER_HEALTH;
    private static final int BUG_DAMAGE_TO_PLAYER = 2;

    // instance variables

    private Player player;
    private Enemy monster;
    private Enemy bug;

    /**
     * Constructor for the Game Manager class
     */
    public GameManager() 
    {
        this.setupGame();
    }

    // getters

    /**
     * @return number of columns of the grid representing the game room
     */
    public static int getNoOfColumns() 
    { 
        return GameManager.NO_OF_COLUMNS;
    }

    /**
     * @return number of rows of the grid representing the game room
     */
    public static int getNoOfRows() 
    { 
        return GameManager.NO_OF_ROWS;
    }

    /**
     * @return the player of this game
     */
    public Player getPlayer() 
    {
        return this.player;
    }

    /**
     * @return the monster of this game
     */
    public Enemy getMonster() 
    {
        return this.monster;
    }

    /**
     * @return the bug of this game
     */
    public Enemy getBug() 
    {
        return this.bug;
    }

    // game setup and playing

    /**
     * This method sets up the game by creating the game objects and
     * positioning them in initial positions (player in upper left corner,
     * monster in the lower right corner and bug in the middle of the room).
     */
    public void setupGame() 
    {
        this.player = new Player('P', INITIAL_PLAYER_HEALTH);
        this.bug = new Enemy('B');
        this.monster = new Enemy('M');
        bug.positionAt(NO_OF_COLUMNS/2, NO_OF_ROWS/2);//bug in the middle of the room
        monster.positionAt(NO_OF_COLUMNS-1, NO_OF_ROWS-1);//monster in the lower right corner
        player.positionAt(0, 0);
        // TODO
    }

    /**
     * This method displays the room and the game objects in their current
     * locations.
     */
    public void displayBoard()
    {
        displayRowSeparator();
        for(int y=0; y<NO_OF_ROWS; y++){

            for(int x=0; x<NO_OF_COLUMNS; x++){
                if(x==player.getX() && y==player.getY()){
                    System.out.print("| "+player.getIcon()+" ");
                }
                else if(x==bug.getX() && y==bug.getY()){
                    System.out.print("| "+bug.getIcon()+" ");
                }
                else if(x==monster.getX() && y==monster.getY()){
                    System.out.print("| "+monster.getIcon()+" ");
                }
                else{
                    System.out.print("|   ");
                }
            }
            System.out.print("|");
            displayRowSeparator();
        }
        System.out.print("Health: ");
        for(int i=0; i<player.getHealth();i++){
            System.out.print("*");
        }
        System.out.println();
        // TODO checked
    }

    /*
     * This method is used by displayBoard to print one line of separator between
     * successive rows.
     */
    private void displayRowSeparator()
    {
        System.out.print("\n-");
        for (int c = 0; c < NO_OF_COLUMNS; c++)
        {
            System.out.print("----");
        }        
        System.out.print("\n");
    }

    /**
     * This method moves all game objects along their current directions.
     * Enemies change directions randomly before moving in the following manner:
     * a monster changes direction randomly with 2 in 3 chance; similary a bug
     * changes direction randomly with 1 in 3 chance.
     */
    public void moveObjects()
    {
        Random random = new Random();
        if(random.nextInt(3)!=0){
            monster.changeDirection();
        }
        if(random.nextInt(3)==0){
            bug.changeDirection();
        }
        //direction settings are completed
        monster.move();
        bug.move();
        player.move();
        // TODO
    }

    /**
     * This method handles any collisions of game objects appropriately.
     * When an enemy is in the same location as the player, he will lose
     * health by an amount defined as a constant in this class according to
     * the enemy type. Current values mean a collision with a monster will
     * make you lose the game, where a collision with a bug will decrease
     * your health a little.
     */
    public void handleCollisions()
    {
        if(doCoordsMatch(player.getX(), player.getY(), bug.getX(), bug.getY())){
            player.loseHeath(BUG_DAMAGE_TO_PLAYER);
        }
        if(doCoordsMatch(player.getX(), player.getY(), monster.getX(), monster.getY())){
            player.loseHeath(MONSTER_DAMAGE_TO_PLAYER);
        }
        // TODO checked
    }

    // utility methods

    /**
     * This method reads user input. The user has the choice to quit or provide
     * a new direction for the player. They also have the option to keep the 
     * current direction.
     * 
     * @return the input character
     */
    public char readDirection()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("w: up, x: down, d: right, a: left, s: nochange, q: quit: ");
        char input = scanner.next().charAt(0);
        return input;
        
        // TODO checked
    }

    /**
     * This method checks whether or not the given two corrdinates match.
     */
    public static boolean doCoordsMatch(int x1, int y1, int x2, int y2)
    {
        if(x1==x2 && y1==y2){
            return true;
        }
        return false;
        // TODO checked
    }

    /**
     * This method converts a direction provided as an integer into one with
     * the enumeration type Direction.
     * 
     * @param directionInt input integer direction (0, 1, 2, 3)
     * @return returns corresponding enum value (NORTH, SOUTH, EAST, WEST)
     */
    public static Direction intToDirection(int directionInt)
    {
        if (directionInt == 0) 
        {
            return Direction.NORTH;
        }
        else if (directionInt == 1) 
        {
            return Direction.SOUTH;
        }
        else if (directionInt == 2) 
        {
            return Direction.EAST;
        }
        else 
        { // 3
            return Direction.WEST;
        }
    }

    /**
     * This method converts a direction provided as a character into one with
     * the enumeration type Direction.
     * 
     * @param directionChar input character direction ('w', 'x', 'd', 'a')
     * @return returns corresponding enum value (NORTH, SOUTH, EAST, WEST)
     */

    public static Direction charToDirection(char directionChar)
    {
        if (directionChar == 'w') 
        {
            return Direction.NORTH;
        }
        else if (directionChar == 'x') 
        {
            return Direction.SOUTH;
        }
        else if (directionChar == 'd') 
        {
            return Direction.EAST;
        }
        else 
        { // 'a'
            return Direction.WEST;
        }
    }

    /**
     * This method checks whether or not the player reached the target location
     * defined as a constant by this class.
     */
    public boolean isTargetReached()
    {
        return doCoordsMatch(player.getX(), player.getY(), TARGET_X, TARGET_Y);
        // TODO checked
    }

    /**
     * This method checks whether or not the game is over. Game is over in two
     * ways. If the player loses its health (a loss) or the player reaches its target.
     */
    public boolean isGameOver()
    {
        if(player.getHealth()<=0 || isTargetReached()){
            return true;
        }
        return false;
        // TODO checked
    }

    public static void main(String[] args)
    {
        GameManager gm = new GameManager();
        Player player = gm.getPlayer();
        char dirChar = 's'; // to get the game loop started

        // initial configuration
        gm.displayBoard();

        // game loop
        while (!gm.isGameOver() && dirChar != 'q') {            
            dirChar = gm.readDirection();
            if (dirChar != 's' && dirChar != 'q')
            {
                player.changeDirection(GameManager.charToDirection(dirChar));
            }

            gm.moveObjects();
            gm.handleCollisions();
            gm.displayBoard();
        }

        // report the result
        if (dirChar == 'q')
        {
            System.out.println("\nCome back and play again!!!");
        }
        else if (gm.player.isHealthy()) 
        {
            System.out.println("\nPlayer wins!!!");
        }
        else 
        {
            System.out.println("\nPlayer loses!!!");
        }
    }
}