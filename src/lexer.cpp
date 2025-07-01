#include <iostream>
#include <string>
#include <vector>
#include <cctype>

enum class TokenType{
    Commands,
    Echo,
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
        std::string numberValue;
        std::string identifierValue;
    public: 
        Lexer(const std::string& str) : input(str), currentIndex(0) {}

        void SkipWhiteSpace(){

            while(currentIndex < input.size() && isspace(input[currentIndex])){
                currentIndex++;}
        } 

        bool IsAtEnd() const 
        {
            return currentIndex >= input.size();
        }

        void ReadIdetifier(){
            identifierValue = "";
            while (currentIndex < input.size() && (isalnum(input[currentIndex]) || input[currentIndex] == '_')) {
                identifierValue += input[currentIndex];
                currentIndex++;
            }
        }
        void ReadNumber()
        {
            numberValue = "";
            while(currentIndex < input.size() && isdigit(input[currentIndex])){
                numberValue += input[currentIndex];
                currentIndex++;
            }
        }
        
        Token GetNextToken()
        {
            SkipWhiteSpace();

            if(IsAtEnd()){
                return {TokenType::End, ""};}

            if (input.substr(currentIndex).find("echo") == 0) {
                currentIndex += 4;  // echo -> 4 words
                return {TokenType::Echo, "echo"};
            }

            if (isalpha(input[currentIndex]) || input[currentIndex] == '_') {
                ReadIdetifier();
                return {TokenType::Identifier, identifierValue};
            }

            if(isdigit(input[currentIndex])){
                ReadNumber();
                return {TokenType::Number, numberValue};}

            return {TokenType::Invalid, std::string(1, input[currentIndex])};
        }
};

int main(void)
{
    std::string inputString = "123 abc _var 456 echo";
    Lexer lexer(inputString);

    while (true) {
        Token token = lexer.GetNextToken();
        if (token.type == TokenType::End) {
            break;
        }
        // Вывод токенов
        switch (token.type) {
            case TokenType::Commands:
                std::cout << "Token: Command Value: " << token.value << std::endl;
                break;
            case TokenType::Identifier:
                std::cout << "Token: Identifier Value: " << token.value << std::endl;
                break;
            case TokenType::Number:
                std::cout << "Token: Number Value: " << token.value << std::endl;
                break;
            case TokenType::Invalid:
                std::cout << "Token: Invalid Value: " << token.value << std::endl;
                break;
            case TokenType::End:
                std::cout << "Token: End Value: " << token.value << std::endl;
                break;
            case TokenType::Echo:
                std::cout << "Token: Echo: " << token.value << std::endl;
        }
    }

    return 0;
}
