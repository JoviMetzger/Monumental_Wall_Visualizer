#include "header.hpp"

// Displaying Banner
static void	ft_display_banner()
{
	std::cout << " +-----------------------------------+\n";
	std::cout << " |   " << BLUE"WELCOME TO Brick Wall Builder" << RESET"   |\n";
}

// Displaying options of walls
static void	ft_display_options()
{
    std::cout << " +-----------------------------------+\n";
	std::cout << " |   " << BLUE"           OPTIONS" << RESET"              |\n";
	std::cout << " +-----------------------------------+\n";
	std::cout << " |                                   |\n";
	std::cout << " |   Enter A or X                    |\n";
	std::cout << " |" << RED"      A " << RESET "- Strecher Bond            |\n";
	std::cout << " |" << RED"      X " << RESET "- EXIT                     |\n";
	std::cout << " |                                   |\n";
	std::cout << " +-----------------------------------+\n\n";
}

int main(void)
{
	std::string	command;
    ft_display_banner();

	while (true)
	{
        ft_display_options();
		std::cout << "Enter a Option "<< BLUE ">> " << RESET;
		getline(std::cin, command);

		if (command == "A" || command == "a")
        {
            ft_strechBond();
        }
		else if (command == "X" || command == "x" || std::cin.eof())
		{
			std::cout << YELLOW "\nGoodbye!\n\n" << RESET;
			return 0;
		}
	}
	return 0;
}
