#include <cctype>
#include "ReadFile.hpp"

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
        std::string numberValue;
        std::string identifierValue;
    public: 
        Lexer(const std::string& str) : input(str), currentIndex(0) {}

        void SkipWhiteSpace(){

            while(currentIndex < input.size() && isspace(input[currentIndex])){
                currentIndex++;}
        } 

        bool IsWordBoundary(char c) {
            return isspace(c) || c == '\0';
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

            if (input.compare(currentIndex, 4, "echo") == 0) {
                size_t nextPos = currentIndex + 4;
                if (nextPos >= input.size() || IsWordBoundary(input[nextPos])) {
                    currentIndex += 4;
                    return {TokenType::Command, "echo"};
                }
            }

            if (input.compare(currentIndex, 2, "ls") == 0) {
                size_t nextPos = currentIndex + 2;
                if (nextPos >= input.size() || IsWordBoundary(input[nextPos])) {
                    currentIndex += 2;
                    return {TokenType::Command, "ls"};
                }
            }
            if (isalpha(input[currentIndex]) || input[currentIndex] == '_') {
                ReadIdetifier();
                return {TokenType::Identifier, identifierValue};
            }

            if(isdigit(input[currentIndex])){
                ReadNumber();
                return {TokenType::Number, numberValue};}
            
            char invalidChar = input[currentIndex];
            currentIndex++;
            return {TokenType::Invalid, std::string(1, input[currentIndex])};
        }
};

int main(void)
{
    std::string content;

    try {
        std::string name_file;
        std::cin >> name_file;
        content = Read_file(name_file);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    Lexer lexer(content);

    while (true) {
        Token token = lexer.GetNextToken();
        if (token.type == TokenType::End) {
            break;
        }
        // Вывод токенов
        switch (token.type) {
            case TokenType::Command:
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
            }
        }
    return 0;
}
