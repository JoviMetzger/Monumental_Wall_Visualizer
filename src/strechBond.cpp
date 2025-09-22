#include "header.hpp"

/*
 * direction -> from left to right OR right to left
 *          true -> left to right
 *          false -> right to left
 */
void Wall::checkWallLenght(int wallHei, bool direction, int robotRow, int robotBuiltHeight, int start)
{
    // First trianglePattern if wallHei is 4
    if (wallHei == 4)
    {
        if (direction == true)
            trianglePattern(robotRow, robotBuiltHeight, start);
        else if (direction == false)
            trianglePatternRevers(robotRow, robotBuiltHeight, start);
    }

    // Do twoLinePattern until row can't fit robotRow
    // wallHei is the height that pattern needs to fill
    int len = fullRow / robotRow;
    int tri = 0;
    
    if (wallHei == 4)
        tri = 1;

    for (int i = 1; i <= (len - tri); i++)
    {
        if (wallHei == 4)
        {
            int k = 0;
            while (k <= 2)
            {
                if (direction == true)
                    twoLinePattern(robotRow, start + k);
                else if (direction == false)
                    twoLinePatternRevers(robotRow, start + k);
                k += 2;
            }
        }
        else if (wallHei == 3)
        {
            if (direction == true)
                twoLinePattern(robotRow, start);
            else if (direction == false)
                twoLinePatternRevers(robotRow, start);
        }
        else if (wallHei == 2)
        {
            if (direction == true)
                twoLinePattern(robotRow, start);
            else if (direction == false)
                twoLinePatternRevers(robotRow, start);
        }
        else if (wallHei == 1)
        {

            if (direction == true)
                oneLinePattern(robotRow, start);
            else if (direction == false)
                oneLinePatternRevers(robotRow, start);
        }
    }

    // Fill in the single bricks
    if (fullRow % robotRow != 0)
    {
        if (direction == true)
            singleBrickPattern(robotBuiltHeight, start);
        else if (direction == false)
            singleBrickPatternRevers(robotBuiltHeight, start);
    }

}

void Wall::strechAlgorithm(int robotRow, int robotMaxHeight)
{
    int robotBuiltHeight = robotRow + 1;
    bool direction;

    // Height Checks
    int i = 0;
    int k = 0;
    int wallHei;
    while (i < fullHeight)
    {
        if (k % 2 == 0)
            direction = true;
        else
            direction = false;

        wallHei = robotBuiltHeight;

        // Check if Robot max height reached(1300mm)
        if (i + robotBuiltHeight >= robotMaxHeight)
        {
            if (i + robotBuiltHeight == robotMaxHeight)
                robotMaxHeight += robotMaxHeight;
        }

        // Check if full wall height is reached
        if (i + robotBuiltHeight >= fullHeight)
        {
            // If next move will be exactly wall height, continue
            if (i + robotBuiltHeight == fullHeight)
            {
                checkWallLenght(4, direction, robotRow, robotBuiltHeight, i);
                std::cout << "Full wall height reached(" << WALL_HEIGHT << "mm) -> All Done" << std::endl;
                break; 
            }
            else
            {
                // If next move will be heigher than wall height, do small steps
                if (i + 2 == fullHeight)
                {
                    checkWallLenght(2, direction, robotRow, robotBuiltHeight, i);
                    std::cout << "Full wall height reached(" << WALL_HEIGHT << "mm) -> All Done" << std::endl;
                    break; 
                }
                else if (i + 2 <= fullHeight)
                {
                    checkWallLenght(3, direction, robotRow, robotBuiltHeight, i);
                    std::cout << "Full wall height reached(" << WALL_HEIGHT << "mm) -> All Done" << std::endl;
                    break; 
                }
                else
                {
                    checkWallLenght(1, direction, robotRow, robotBuiltHeight, i);
                    std::cout << "Full wall height reached(" << WALL_HEIGHT << "mm) -> All Done" << std::endl;
                    break; 
                }
            }
        }

        // Check width, choose pattern and put brick
        checkWallLenght(wallHei, direction, robotRow, robotBuiltHeight, i);

        k++;
        i += robotBuiltHeight;
    }
}

// Build wall in stretcher bond
void ft_strechBond(void)
{
    // Calculate amount of bricks in a wall -> fullRow(10.5), fullHeight(32)
    int fullRow = WALL_WIDTH / FULL_COURSE_WIDTH;  // how many full bricks fit into one wall row
    int fullHeight = WALL_HEIGHT / COURSE_HEIGHT;  // how many full bricks fit into one wall height

    // Calculate amount of bricks one robot can lay in one go -> robotRow(3.6), robotBuiltHeight(20.8)
    int robotRow = ROBOT_WIDTH / FULL_COURSE_WIDTH;      // how many full bricks can a robot fitt into one row
    int robotMaxHeight = ROBOT_HEIGHT / COURSE_HEIGHT;   // how many full bricks can a robot fit into one height


    Wall wall(fullHeight, fullRow);
    // wall.debugPrint(); // -> For debugging
    wall.print_wall(); 
    wall.strechAlgorithm(robotRow, robotMaxHeight);
}
