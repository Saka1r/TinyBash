#include <iostream>
#include <string>

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
    
};

int main(void)
{
    return 0;
}
