#include <iostream>
#include <cstdlib>
#include <string>
#include <random>


template <typename T>
bool inRangeInclusive(T value, T min, T max) {
    if (min <= value && value <= max) {
        return true;
    }
    return false;
}

template <typename T>
T clamp(T value, T low, T high) {
    if (value < low) {
        return low;
	}
	else if (value > high) {
		return high;
	}
	else {
		return value;
	}
}

int inputIsNumVal()
{
    int number;

    while (!(std::cin >> number)) {
        std::cout << "Invalid input.";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return number;
}



int main()
{
    //std::cout << inRangeInclusive(3, 1, 10) << std::endl; // returns true 
    //std::cout <<  inRangeInclusive(2.1, 5.1, 11.0) << std::endl; // returns false 

    //std::cout << clamp(3, 1, 10) << std::endl; // returns 3 
    //std::cout << clamp(2.1, 5.1, 11.0) << std::endl; // returns 5.1 


    std::random_device rd;
    std::mt19937 gen(rd());


    std::uniform_int_distribution<> distr(1, 100);

    int random_num = distr(gen);


    int gameInput = -1;

    bool playAgain = true;
    while (playAgain) {
        std::cout << "Guess the number between 1 and 100: " << std::endl;


        while (random_num != gameInput)
        {
            gameInput = inputIsNumVal();

            if (gameInput < random_num)
            {
                std::cout << "Too low! \n";
            }
            else if (gameInput > random_num)
            {
                std::cout << "Too high! \n";
            }

        }

        std::cout << "Correct!" << std::endl;

        while (true)
        {
            std::string playAgainInput;
            std::cout << "Play again? (y/n): ";
            std::cin >> playAgainInput;

            if ("y" == playAgainInput)
            {
                random_num = distr(gen);
                gameInput = -1;
                break;

            }
            else if ("n" == playAgainInput)
            {
                playAgain = 0;

				break;
            }
            else
            {
                std::cout << "Invalid input.";

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

}
