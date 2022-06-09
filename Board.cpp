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
void Board::createShip() {
    this->ship= new Ship();
}
Board::Board()
{
    createWindow();
    createShip();
}
Board::~Board()
{
    delete this->window;
    delete this->ship;
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        this->ship->move(0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        this->ship->move(0.f, 1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        this->ship->move(-1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        this->ship->move(1.f, 0.f);
}

void Board::render()
{
    this->window->clear();

    this->ship->render(*this->window);

    this->window->display();
}