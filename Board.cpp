//
// Created by Konrad on 03.06.2022.
//

#include "Board.h"
Board::Board()
{
    createTextures();
    createWindow();
    createShip();
    createEnemy();
    interface();
    exp=0;
}
Board::~Board()
{
    delete window;
    delete ship;
    for (auto *i:this->ammo)
    {
        delete i;
    }
    for(auto *i : this->enemies)
    {
        delete i;
    }
}
void Board::createWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1920,1080),"Space Shooter",sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(144);
    window->setVerticalSyncEnabled(false);
}
void Board::Stars()
{
    Background.loadFromFile("../Teksturki/background.jpg");
    sf::Sprite BackgroundSprite(Background);
    window->draw(BackgroundSprite);
}
void Board::play()
{
    while(window->isOpen())
    {
        sf::Event move;
        while(window->pollEvent(move))
        {
            if(move.Event::type == sf::Event::Closed)
                window->close();
            if(move.Event::key.code == sf::Keyboard::Escape)
            {
                window->close();
            }
        }
        if(ship->getShipcurrentHealth()>0)
            update();
        render();
    }
}
void Board::createShip() {
    ship = new Ship();
}
void Board::createEnemy(){
    SpawnerTimer=50;
    CurrentSpawnerTimer = SpawnerTimer;
}

void Board::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        ship->move(0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        ship->move(0.f, 1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        ship->move(-1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        ship->move(1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& ship->canshoot())
    {
        ammo.push_back
        (new Ammo(textures,
                  ship->getPosition().x + ship->Boundaries().width/2-5,
                  ship->getPosition().y,0.f,-1.f,10.f));
    }

    if(ship->Boundaries().left<0.f)
        ship->setPos(0.f, ship->Boundaries().top);

    else if (ship->Boundaries().left + ship->Boundaries().width >= window->getSize().x)
        ship->setPos(window->getSize().x - ship->Boundaries().width, ship->Boundaries().top);

    if (ship->Boundaries().top < 0.f)
        ship->setPos(ship->Boundaries().left, 0.f);

    else if (ship->Boundaries().top + ship->Boundaries().height >= window->getSize().y)
        ship->setPos(ship->Boundaries().left, window->getSize().y - ship->Boundaries().height);

    for(auto *ammo : this->ammo)
    {
        ammo->update();
        if(ammo->Boundaries().top + ammo->Boundaries().height <0.f)
        {

            this->ammo.erase(this->ammo.begin());
        }
    }
    Levelup();
    pointcounter();
    ship->update();
    Enemies();
}
void Board::render()
{
    window->clear(sf::Color(18,19,70));

    ship->render(*window);

    for(auto *ammo : ammo)
        ammo->render(window);

    for(auto *enemy : enemies)
        enemy->render(window);

    window->draw(tekst);

    window->draw(LEVEL);

    window->draw(durability);

    window->draw(health);

    window->draw(currenthealth);

    window->draw(Speed);

    window->draw(Cd);

    window->draw(Title);

    if(ship->getShipcurrentHealth()<=0)
    {
        Stars();
        window->draw(Defeat);
        std::stringstream ss;

        ss<<"YOUR FINAL SCORE: "<<exp;
        tekst.setPosition(500,800);
        tekst.setString(ss.str());
        tekst.setCharacterSize(100);
        tekst.setFillColor(sf::Color::Yellow);
        tekst.setOutlineColor(sf::Color::Green);
        tekst.setOutlineThickness(4);
        window->draw(tekst);
    }
    this->window->display();
}
void Board::createTextures() {
    textures= new sf::Texture();
    if(textures->loadFromFile("../Teksturki/ammo.png"))
    {
        //std::cout<<"cant load from file"<<std::endl;
    }
}
void Board::Enemies() {
    level=exp/150+1;
    CurrentSpawnerTimer+=0.5;
    if(CurrentSpawnerTimer>= SpawnerTimer)
    {
        enemies.push_back(new Enemy(rand()%window->getSize().x-100,-100));

        CurrentSpawnerTimer=0;
    }
    for(int i=0;i<enemies.size();i++)
    {
        bool IsEnemydead = false;
        enemies[i]->update();
         if(enemies[i]->Boundaries().intersects(ship->Boundaries()))
            {
               ship->hitme(10+level*10);
               //std::cout<<ship->getShipcurrentHealth();
                delete enemies.at(i);
                enemies.erase(enemies.begin()+i);
            }
        for (size_t j=0; j<ammo.size() && !IsEnemydead;j++)
        {
            if(ammo[j]->Boundaries().intersects(enemies[i]->Boundaries()))
            {
                if(enemies[i]->Expcounter()>7)
                {
                    ship->currenthealth+=(10-level);
                    if(ship->currenthealth>ship->health)
                        ship->currenthealth=ship->health;
                }
                exp+=enemies[i]->Expcounter();
                ammo.erase(ammo.begin()+j);
                enemies.erase(enemies.begin()+i);
                IsEnemydead=true;
            }
        }
        if(!IsEnemydead)
        {
            if(enemies[i]->Boundaries().top > window->getSize().y && !enemies[i]->Boundaries().width==0)
            {
                ship->hitme(5+level*5);
                delete enemies.at(i);
               enemies.erase(enemies.begin()+i);

            }
        }
    }
}
void Board::interface() {
    if(!font.loadFromFile("../Teksturki/Font.ttf"))
        std::cout<<"FONT CANT LOAD"<<std::endl;

    tekst.setFont(font);
    tekst.setCharacterSize(40);
    tekst.setPosition(window->getSize().x -300,80);
    tekst.setFillColor(sf::Color::Magenta);
    tekst.setOutlineThickness(2);
    tekst.setOutlineColor(sf::Color::Yellow);

    Cd.setFont(font);
    Cd.setCharacterSize(40);
    Cd.setPosition(20,50);
    Cd.setFillColor(sf::Color::Magenta);
    Cd.setOutlineThickness(2);
    Cd.setOutlineColor(sf::Color::Yellow);

    Speed.setFont(font);
    Speed.setCharacterSize(40);
    Speed.setPosition(20,100);
    Speed.setFillColor(sf::Color::Magenta);
    Speed.setOutlineThickness(2);
    Speed.setOutlineColor(sf::Color::Yellow);

    LEVEL.setFont(font);
    LEVEL.setCharacterSize(60);
    LEVEL.setPosition(window->getSize().x -250,15);
    LEVEL.setFillColor(sf::Color::Magenta);
    LEVEL.setOutlineThickness(2);
    LEVEL.setOutlineColor(sf::Color::Yellow);

    health.setSize((sf::Vector2f(300,25)));
    health.setFillColor(sf::Color::Magenta);
    health.setPosition(sf::Vector2f(200,20));
    health.setOutlineColor(sf::Color::Yellow);
    health.setOutlineThickness(3);

    Defeat.setFont(font);
    Defeat.setCharacterSize(100);
    Defeat.setPosition(window->getSize().x/4.f - Defeat.getGlobalBounds().width/2.f,
                       window->getSize().y/4.f - Defeat.getGlobalBounds().height/2.f);
    Defeat.setFillColor(sf::Color::Red);
    Defeat.setString("Your galaxy ship has crushed\n        Your yourney is over!");
    Defeat.setOutlineThickness(2);
    Defeat.setOutlineColor(sf::Color::Cyan);

    Title.setFont(font);
    Title.setCharacterSize(100);
    Title.setPosition(window->getSize().x/3.f -Title.getGlobalBounds().width/2.f,0);
    Title.setFillColor(sf::Color::Red);
    Title.setString("Space Shooter!");
    Title.setOutlineThickness(2);
    Title.setOutlineColor(sf::Color::Cyan);

    durability.setFont(font);
    durability.setCharacterSize(40);
    durability.setPosition(10,10);
    durability.setFillColor(sf::Color::Magenta);
    durability.setOutlineThickness(2);
    durability.setOutlineColor(sf::Color::Yellow);
    durability.setString("Durability: ");

    currenthealth = health;
    currenthealth.setFillColor(sf::Color(20,20,20,180));
}
void Board::pointcounter() {

    std::stringstream ss;
    ss<<"Score: "<<exp;
    tekst.setString(ss.str());

    std::stringstream aa;
    aa<<"Level: "<<level;
    LEVEL.setString(aa.str());

    std::stringstream bb;
    bb<<"Shoot Cooldown: "<<ship->getCd();
    Cd.setString(bb.str());

    std::stringstream cc;
    cc<<"Ship speed: "<<ship->getSpeed();
    Speed.setString(cc.str());


float Currentpercenthealth = (ship->getShipcurrentHealth()/ship->getShipHealth());

health.setSize((sf::Vector2f(300 *Currentpercenthealth,health.getSize().y)));
}

void Board::Levelup() {
        if(exp%150>0 && exp%150<10 && exp>100)
        {
            exp+=10;
            ship->givestats(0.5,2.5,50);
        }
}

