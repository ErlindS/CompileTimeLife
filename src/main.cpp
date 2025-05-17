#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <iostream>
#include <random>
#include "cpptemplates.h"
#include <functional>


bool randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
}


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::RectangleShape Gamefield[100][100];
    sf::RectangleShape Gamefieldfuture[100][100];
    //Gamefield
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            Gamefield[i][j].setSize(sf::Vector2f{10.,10.});
            Gamefieldfuture[i][j].setSize(sf::Vector2f{10.,10.});
            Gamefield[i][j].setFillColor(sf::Color(255,255,255));
            Gamefieldfuture[i][j].setFillColor(sf::Color(255,255,255));
            Gamefield[i][j].setPosition(sf::Vector2f{10.f*i, 10.f*j});
            Gamefieldfuture[i][j].setPosition(sf::Vector2f{10.f*i, 10.f*j});
        }
    }

    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            if(randomBool()){
                Gamefield[i][j].setFillColor(sf::Color(0,0,0));
            } else {
                Gamefield[i][j].setFillColor(sf::Color(255,255,255));
            }
        }
    }

    sf::Clock clock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        
        //Calls update every second
        sf::Time elapsed1 = clock.getElapsedTime();
        if(elapsed1.asSeconds() > 1){
            std::cout << "1 second elapsed" << std::endl;   
            update(Gamefield, Gamefieldfuture);
            clock.restart();
        }

        for(int i = 0; i < 100; ++i){
            for(int j = 0; j < 100; ++j){
                window.draw(Gamefield[i][j]);
            }
        }

        window.display();
    }
}
