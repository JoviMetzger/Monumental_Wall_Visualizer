#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>
# include <vector>
# include <limits>

// COLORS
# define RED "\e[1;91m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

// BRICK & WALL INFO
const int WALL_WIDTH  = 2300;
const int WALL_HEIGHT = 2000;

const int FULL_BRICK   = 210;
const int HALF_BRICK   = 100;
const int BRICK_HEIGHT = 50;

const double HEAD_JOINT = 10;    // vertical mortar
const double BED_JOINT  = 12.5;  // horizontal mortar

const double FULL_COURSE_WIDTH  = FULL_BRICK + HEAD_JOINT;  // 220
const double HALF_COURSE_WIDTH  = HALF_BRICK + HEAD_JOINT;  // 110
const double COURSE_HEIGHT = BRICK_HEIGHT + BED_JOINT;      // 62.5

// ROBOT INFO
const int ROBOT_WIDTH  = 800;
const int ROBOT_HEIGHT = 1300;

// ASCII BRICKS
const std::string FULL_DESIGN = "░░░░";
const std::string FULL_BUILT  = "▓▓▓▓";
const std::string HALF_DESIGN = "░░";
const std::string HALF_BUILT  = "▓▓";
const std::string MORTAR = " ";

// CLASSES
class Wall {
    public:
        std::vector<std::pair<std::vector<int>, int>> wallMap;
        int fullHeight;
        int fullRow;

        // Constructor
        Wall(int height, int row) : fullHeight(height), fullRow(row) {
            for (int i = 0; i < height; i++)
                wallMap.push_back({ std::vector<int>(row, 0), 0 });
        }
        
        // Member functions
        void debugPrint();
        void print_wall();

        void checkWallLenght(int wallHei, bool direction, int robotRow, int robotBuiltHeight, int start);
        void strechAlgorithm(int robotRow, int robotMaxHeight);

        void put_brick(int row, int index);
        void trianglePattern(int robotRow, int robotBuiltHeight, int start);
        void trianglePatternRevers(int robotRow, int robotBuiltHeight, int start);
        void twoLinePattern(int robotRow, int start);
        void twoLinePatternRevers(int robotRow, int start);
        void oneLinePattern(int robotRow, int start);
        void oneLinePatternRevers(int robotRow, int start);
        void singleBrickPattern(int robotBuiltHeight, int start);
        void singleBrickPatternRevers(int robotBuiltHeight, int start);
};

// FUNCTIONS
void ft_strechBond(void);

#endif
