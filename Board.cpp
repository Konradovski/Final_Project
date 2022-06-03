//
// Created by Konrad on 03.06.2022.
//

#include "Board.h"
void Board::createWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920,1080),"Space Shooter",sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}
void Board::play()
{
    while(this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

Board::Board()
{
    createWindow();
}
Board::~Board()
{
    delete this->window;
}
void Board::update()
{
    sf::Event move;
    while(this->window->pollEvent(move))
    {
        if(move.Event::type == sf::Event::Closed)
            window->close();
        if(move.Event::KeyPressed && move.Event::key.code == sf::Keyboard::Escape)
        {
            window->close();
        }
    }
}

void Board::render()
{
    this->window->clear();



    this->window->display();
}