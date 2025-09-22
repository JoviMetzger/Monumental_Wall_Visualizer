#include "header.hpp"

void waitForEnter()
{
    std::cout << "Press ENTER to lay a brick..." << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* Lays the brick like a triangle with height 4 and lenght of the robots width
    .
    ..
    ...
    ....
 */
void Wall::trianglePattern(int robotRow, int robotBuiltHeight, int start)
{
    int i = start;
    while (i < robotBuiltHeight + start)
    {        
        for (int j = 0; j < fullRow; j++)
        {
            put_brick(i,j);
            waitForEnter();
            print_wall(); 
            // debugPrint(); // -> Debugging

            if (wallMap[i].second % robotRow == 0)
                break;
            if (i >= ((robotBuiltHeight + start) - 2))
            {
                if (j == 1)
                    break;
            }
        }
        i++;
    }
}

/* Same as trianglePattern, but lays bricks in revers
        .
       ..
      ...
     ....
 */
void Wall::trianglePatternRevers(int robotRow, int robotBuiltHeight, int start)
{
    int i = start;
    while (i < robotBuiltHeight + start)
    {     
        for (int j = fullRow - 1; j >= 0; j--)
        {
            put_brick(i,j);
            waitForEnter();
            print_wall(); 
            // debugPrint(); // -> Debugging

            if (wallMap[i].second % robotRow == 0)
                break;
            if (i >= (robotBuiltHeight + start) - 2)
            {
                if (j-1 <= (fullRow - robotRow))
                    break;
            }
        }
        i++;
    }
}


/* Lays bricks only for 2 rows with the length of the robot width, from left to right
    ...
     ...
 */
void Wall::twoLinePattern(int robotRow, int start)
{
    for (int i = 0; i < 2; i++)
    { 
        int k = 0;
        for (int j = wallMap[start + i].second; j < fullRow; j++)
        {
            put_brick(start + i,j);
            waitForEnter();
            print_wall(); 
            // debugPrint(); // -> Debugging

            k++;
            if (k == robotRow)
                break;
        }
    }
}

/* Same as twoLinePattern, but lays bricks from the right to left
     ...
    ...
 */
void Wall::twoLinePatternRevers(int robotRow, int start)
{
    for (int i = 0; i < 2; i++)
    { 
        int k = 0;
        for (int j = ((fullRow - 1) - wallMap[start + i].second); j >= 0; j--)
        {
            put_brick(start + i,j);
            waitForEnter();
            print_wall(); 
            // debugPrint(); // -> Debugging

            k++;
            if (k == robotRow)
                break;
        }
    }
}

// Lays bricks only for 1 row with the length of the robot width, from left to right
void Wall::oneLinePattern(int robotRow, int start)
{
    int i = start;

    int k = 0;
    for (int j = wallMap[i].second; j < fullRow; j++)
    {
        put_brick(i,j);
        waitForEnter();
        print_wall(); 
        // debugPrint(); // -> Debugging

        k++;
        if (k == robotRow)
            break;
    }
}

// Same as oneLinePattern, but lays bricks from the right to left
void Wall::oneLinePatternRevers(int robotRow, int start)
{
    int i = start;

    int k = 0;
    for (int j = ((fullRow - 1) - wallMap[i].second); j >= 0; j--)
    {
        put_brick(i,j);
        waitForEnter();
        print_wall(); 
        // debugPrint(); // -> Debugging

        k++;
        if (k == robotRow)
            break;
    }
}


// Lays one brick at a specific location from left to right
void Wall::singleBrickPattern(int robotBuiltHeight, int start)
{
    int i = start;
    while (i < robotBuiltHeight + start)
    {  
        for (int j = wallMap[i].second; j < fullRow; j++)
        {
            put_brick(i,j);
            waitForEnter();
            print_wall(); 
            // debugPrint(); // -> Debugging

            if (i == (fullHeight - 1) && wallMap[i].second == fullRow)
                return;
            if (wallMap[i].second == fullRow)
                break;
        }
        i++;
    }
}

// Lays one brick at a specific location from right to left
void Wall::singleBrickPatternRevers(int robotBuiltHeight, int start)
{
    int i = start;
    while (i < robotBuiltHeight + start)
    {  
        for (int j = ((fullRow - 1) - wallMap[i].second); j >= 0; j--)
        {
            put_brick(i,j);
            waitForEnter();
            print_wall(); 
            // debugPrint(); // -> Debugging
            
            if (i == (fullHeight - 1) && wallMap[i].second == fullRow)
                return;
            if (wallMap[i].second == fullRow)
                break;
        }
        i++;
    }
}

// Puts the brick at loaction
void Wall::put_brick(int row, int index)
{
    wallMap[row].first[index] = 1;
    wallMap[row].second += 1;
}
