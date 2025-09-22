#include "header.hpp"

// Print the brick layout
void Wall::print_wall()
{
    std::vector<std::string> wallPrint;

    for (int i = 0; i < Wall::fullHeight; i++)
    {
        std::string rowData;

        // Strech bond pattern
        if (i % 2 == 0)
        {
            for (int j = 0; j < Wall::fullRow; j++)
            {
                if (wallMap[i].first[j] == 0)
                    rowData += FULL_DESIGN + MORTAR;
                else
                    rowData += FULL_BUILT + MORTAR;
            }
        }
        else
        {
            // Every second line will start with half brick
            if (wallMap[i].first[0] == 0)
                rowData += HALF_DESIGN + MORTAR;
            else
                rowData += HALF_BUILT + MORTAR;
            for (int k = 1; k < Wall::fullRow; k++)
            {   
                if (wallMap[i].first[k] == 0)
                    rowData += FULL_DESIGN + MORTAR;
                else
                    rowData += FULL_BUILT + MORTAR;
            }  
        }

        wallPrint.push_back(rowData);
    }

    // Printing from top to bottom
    for (auto it = wallPrint.rbegin(); it != wallPrint.rend(); it++)
    {
        for (auto &brick : *it)
            std::cout << brick;
        std::cout << "\n\n"; // Extra '\n' for horizontal mortar 
    }
}

// For debugging -> Shows the wallMap
void Wall::debugPrint() 
{
    std::cout << "Height: " << fullHeight << "     Rows: " << fullRow << "\n";
    
    int rowIndex = wallMap.size() - 1;
    for (auto it = wallMap.rbegin(); it != wallMap.rend(); it++, rowIndex--) {
        for (int v : it->first)
            std::cout << v << " ";
        
        std::cout << " -> value: " << it->second << " (row: " << rowIndex << ")\n";
    }
}
