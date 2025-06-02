#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <iostream>
#include <random>
#include "cpptemplates.h"
#include <functional>


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    // Time stuff
    sf::Clock clock;

    //Form: Rectanlge, count: number of forms
    //Gamefield<Rectanlge, 100> field;

    shape<5, 5> name;

    while (window.isOpen())
    {
        /*************************************************************************************/
        /* SFML Window stuff                                                                 */
        /*************************************************************************************/
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();


        /*************************************************************************************/
        /* Update every second | Gamefield.update() is relevant                              */
        /*************************************************************************************/
        sf::Time elapsed1 = clock.getElapsedTime();
        if(elapsed1.asSeconds() > 1){
            std::cout << "1 second elapsed" << std::endl;   
            //Gamefield.update();
            clock.restart();
        }


        /*************************************************************************************/
        /* SFML drawing stuff                                                                */
        /*************************************************************************************/
        /*
        for(auto field : Gamefield){
            window.draw(field);
        }*/
        window.display();
    }
}
