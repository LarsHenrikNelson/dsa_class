#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    // Constructor
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};


int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> obs;
    // std::stack <char> obs;
    int index {1};
    bool unmatched {true};
    int u_index{0};
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket p{next, position+1};
            obs.push(p);
            if (unmatched)
                {
                    u_index = position+1;
                }
        }

        if (next == ')' || next == ']' || next == '}')
        {
            if (!obs.empty() && obs.top().Matchc(next))
            {
                obs.pop();
                if (unmatched)
                {
                    --u_index;
                }
            }
            else
            {
                Bracket p{next, position+1};
                obs.push(p);
                if (unmatched)
                {
                    unmatched = false;
                    u_index=position+1;
                }
            }
        }
    }

    if(obs.empty())
    {
        std::cout << "Success\n";
    }
    else
    {
        std::cout << u_index << "\n";
    }

    return 0;
}
