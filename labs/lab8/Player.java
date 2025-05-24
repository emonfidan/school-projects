package lab8;

/**
 * This class implements a player object in a simple game where the goal is
 * to reach the bottom right corner of an n x n room starting from the upper
 * left corner of the room, avoiding enemies (monsters and bugs).
* 
 * @author Ugur Dogrusoz
 */
public class Player 
{
    // instance variables

    private char icon;
    private int x;
    private int y;
    private Direction dir;
    private int health;

     /**
     * Constructor for the Player class
     */
    
    public Player(char icon, int health) 
    {
        this.icon = icon;
        this.positionAt(0, 0);
        this.dir = Direction.NORTH;
        this.health = health;
    }

    // getters

    /**
     * @return icon used to display this player
     */
    public char getIcon()
    {
        return this.icon;
    }
    
    /**
     * @return x coordinate of this player
     */
    public int getX()
    {
        return this.x;
    }

    /**
     * @return y coordinate of this player
     */
    public int getY() 
    {
        return this.y; 
    }

    /**
     * @return current direction in which this player moves
     */
    public Direction getDirection() 
    { 
        return this.dir; 
    }

    /**
     * @return current value of player's health
     */
    public int getHealth() 
    { 
        return this.health; 
    }

    /**
     * @return whether or not this player is healthy (> 0 health value)
     */
    public boolean isHealthy() 
    { 
        return this.health > 0; 
    }

    // setters and service methods

    /**
     * This method positions this player at provided location.
     * 
     * @param x x coordinate at which it is to be located
     * @param y y coordinate at which it is to be located
     */
    public void positionAt(int x, int y) 
    {
        this.x = x;
        this.y = y;
    }

    /**
     * This method changes the direction of this player object to specified value.
     */
    public void changeDirection(Direction dir) 
    {
        this.dir = dir;
    }

    /**
     * This method moves this player by a single location using its
     * current location. If the player hits one of the four sides of
     * the room, it bounces back by changing its direction.
     */
    public void move() 
    {
        if (this.dir == Direction.NORTH) 
        {
            if (this.y == 0) 
            {
                this.bounce();
            }
            else 
            {
                this.y--;
            }
        }
        else if (this.dir == Direction.SOUTH) 
        {
            if (this.y == GameManager.getNoOfRows() - 1) 
            {
                this.bounce();
            }
            else 
            {
                this.y++;
            }
        }
        else if (this.dir == Direction.EAST) 
        {
            if (this.x == GameManager.getNoOfColumns() - 1) 
            {
                this.bounce();
            }
            else 
            {
                this.x++;
            }
        }
        else 
        { // WEST
            if (this.x == 0) 
            {
                this.bounce();
            }
            else 
            {
                this.x--;
            }
        }
    }
    
    /**
     * This method decreases this players health by given amount and
     * return whether or not the player is still healthy.
     * 
     * @param amount amount by which health will be decreased
     * @return whether or not the player is still healthy after losing health
     */
    public boolean loseHeath(int amount) 
    {
        this.health -= amount;

        if (this.health <= 0) 
        {
            return false;
        }

        return true;
    }

    // private methods

    private void bounce() 
    {
        if (this.dir == Direction.NORTH) 
        {
            this.dir = Direction.SOUTH;
        }
        else if (this.dir == Direction.SOUTH) 
        {
            this.dir = Direction.NORTH;
        }
        else if (this.dir == Direction.EAST) 
        {
            this.dir = Direction.WEST;
        }
        else 
        { // West
            this.dir = Direction.EAST;
        }
    }
}