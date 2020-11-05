#include "/home/zoozle/Code/C++/Library/zoozle/zle_STL.h"
#include "/home/zoozle/Code/C++/Library/sfml/zle_sfml.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


enum Mode{
    Read,
    Write,
    New,
};

sf::Font font;
sf::Text text;
sf::RenderWindow window;
sf::RectangleShape back;
sf::Event event;
std::fstream file;
const string NAMEOFTHIS="impaler";
string name;
Mode mode;
string content;
const int font_size=20;