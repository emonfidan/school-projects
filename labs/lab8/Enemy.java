package lab8;

/**
 * This class implements an enemy object in a simple game where the goal of
 * the player is to reach the bottom right corner of an n x n room starting
 * from the upper left corner of the room, avoiding enemies.
 *
 * @author Ugur Dogrusoz
 */
public class Enemy 
{
    // instance variables

    private char icon;
    private int x;
    private int y;
    private Direction dir;

    /**
     * Constructor for the Enemy class
     * 
     * @param icon icon used to display this enemy
     */
    public Enemy(char icon) 
    {
        this.icon = icon;
        this.positionAt(0, 0);
        this.dir = Direction.NORTH;
    }

    // getters

    /**
     * @return icon used to display this enemy
     */
    public char getIcon() 
    { 
        return this.icon; 
    }

    /**
     * @return x coordinate of this enemy
     */
    public int getX() 
    { 
        return this.x; 
    }

    /**
     * @return y coordinate of this enemy
     */
    public int getY() 
    { 
        return this.y; 
    }
    
    /**
     * @return current direction in which this enemy moves
     */
    public Direction getDirection() 
    { 
        return this.dir; 
    }

    // setters and service methods

    /**
     * This method positions this enemy at provided location.
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
     * This method changes the direction of this enemy object in a
     * random direction.
     */
    public void changeDirection() 
    {
        int randDirection = GameManager.random.nextInt(4);
        if (randDirection == 0) 
        {
            this.dir = Direction.NORTH;
        }
        else if (randDirection == 1) 
        {
            this.dir = Direction.SOUTH;
        }
        else if (randDirection == 2) 
        {
            this.dir = Direction.EAST;
        }
        else 
        { // WEST
            this.dir = Direction.WEST;
        }
    }

    /**
     * This method moves this enemy by a single location using its
     * current location. If the enemy hits one of the four sides of
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
        else { // WEST
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

    // private methods

    /*
     * This method changes the direction of this object by 180 degrees. It
     * should be used when the enemy hits a side of the room.
     */
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