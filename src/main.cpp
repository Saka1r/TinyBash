#include <iostream>
#include <string>

constexpr size_t BUFFER_SIZE = 500;

int main(void)
{
				
				std::string Buffer;
				Buffer.resize(BUFFER_SIZE);

				for(;;)
				{
								std::cout << "$ ";
								std::cin >> Buffer;
				}
				
				return 0;
}
