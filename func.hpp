#include "global.hpp"
#include <cstdio>

bool init()
{
    if (!font.loadFromFile("font/Ubuntu-Light.ttf"))
        return false;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(font_size);
    window.create(sf::VideoMode(800, 600), NAMEOFTHIS + "_" + name);
    window.clear();
    back.setSize(sf::Vector2f(800, 600));
    back.setFillColor(sf::Color::Black);
    std::ofstream tmp(name);
    tmp.close();
    switch (mode)
    {
    case New:
        file.open(name);
        if (!file)
            return false;
        break;
    case Read:
        file.open(name, std::ios_base::in);
        if (!file){
            cout<<"だめ";
            return false;
        }
        while (!file.eof())
        {
            string temp;
            std::getline(file, temp);
            content.append(temp);
            content += "\n";
        }
        break;
    case Write:
        file.open(name);
        if (!file)
            return false;
        while (!file.eof())
        {
            string temp;
            std::getline(file, temp);
            content.append(temp);
            content += "\n";
        }
        break;
    default:
        cout << "Unknown option or mode." << endl;
        return false;
        break;
    }

    return true;
}

void save(){
    std::ofstream result(name);
    if(!result){
        cout<<"save failed"<<endl;
        return;
    }else{
        result<<content;
    }
}

void mainloop()
{
    while (window.isOpen())
    {
        //  ここはよくわからない
        bool erase=false;
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
            case sf::Event::Closed:
                save();
                window.close();
                return;
                break;
            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    content += "\n";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
                {
                    if (!content.empty())
                    {
                        erase=true;
                        content.pop_back();
                    }
                }
                break;
            case sf::Event::TextEntered:
              if(!erase){content += event.text.unicode;}
                break;
            default:
                break;
            }
        }
        window.clear();
        text.setString(content);
        window.draw(back);
        window.draw(text);
        window.display();
    }
}