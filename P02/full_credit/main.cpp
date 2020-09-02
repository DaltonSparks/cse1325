#include <iostream>
#include <ctime>

int main()
{
    srand(time(NULL));

    int dice, faces, rolls, sum, num, i, j;

    std::cout << "Number of dice? ";
    std::cin >> dice;

    std::cout << "Number of Faces per die? ";
    std::cin >> faces;
    faces++;

    std::cout << "Number of rolls? ";
    std::cin >> rolls;

    for(i = 0; i < rolls; i++)
    {
		sum = 0;
        std::cout << "Roll " << i << ":";        

        for(j = 0; j < dice; j++)
        {
			num = rand()%faces;
            std::cout << " " << num;
			sum = sum+num;
        }
        std::cout << " Sum: " << sum << std::endl;

    }
}
