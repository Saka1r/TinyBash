#include <iostream>
#include <string>

constexpr size_t BUFFER_SIZE = 500;

void lexer_commands(std::string Buffer)
{
    std::cout << Buffer << std::endl;
}

int main(void)
{				
	std::string Buffer;
	Buffer.resize(BUFFER_SIZE);

	for(;;)
	{
		std::cout << "$ ";
		std::getline(std::cin, Buffer);
        lexer_commands(Buffer);
	}	
    return 0;
}
