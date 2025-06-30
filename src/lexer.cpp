#include <iostream>
#include <string>
#include <vector>
#include <cctype>

enum class TokenType{
    Command,
    Identifier,
    Number,
    Invalid,
    End
        
};

struct Token {
    TokenType type;
    std::string value;

};

class Lexer {
    private:
        std::string input;
        size_t currentIndex; 	
    
    public: 
        
        Lexer(const std::string& str) : input(str), currentIndex(0) {}

        void SkipWhiteSpace(std::string &input)
        {
            size_t i = 0;
            while (i < input.size())
            {
                if(!isspace(input[1]))
                        {break;}
                i++;
            }
            input.erase(0, i); // Удаление всех пробелов в начале строки
        }

        bool IsAtEnd() const 
        {
            return currentIndex >= input.size();
        }

        Token GetNextToken();

        void ReadIndetifier();

        void ReadNumber();

};

int main(void)
{
    return 0;
}
