#include "cpptemplates.h"


void update(sf::RectangleShape Gamefield[][100], sf::RectangleShape Gamefieldfuture[][100]){
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            //Gamefield[i][j].setFillColor(sf::Color(0, 0, 0));
            //std::cout << "this is blue: " << int(Gamefield[i][j].getFillColor().b) << std::endl;


            //checking Neighbours
            int livingneighbours = 0;
            if(1 > int(Gamefield[i+1][j].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }
            if(1 > int(Gamefield[i][j+1].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }
            if(1 > int(Gamefield[i+1][j+1].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }
            if(1 > int(Gamefield[i-1][j].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }
            if(1 > int(Gamefield[i][j-1].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }
            if(1 > int(Gamefield[i-1][j-1].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }
            if(1 > int(Gamefield[i+1][j-1].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }
            if(1 > int(Gamefield[i-1][j+1].getFillColor().b) && i < 100 && i > 0 && j < 100 && j > 0) {
                std::cout << livingneighbours;
                livingneighbours++;
            }

            if
            (     
                    livingneighbours == 3
                ||  livingneighbours == 2 && 1 > int(Gamefield[i][j].getFillColor().b)
            )
            { 
                    Gamefieldfuture[i][j].setFillColor(sf::Color(0, 0, 0));
            } 
            else 
            {
                Gamefieldfuture[i][j].setFillColor(sf::Color(255, 255, 255));
            } 

            //std::cout << livingneighbours;
            livingneighbours = 0;
            
        }
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            Gamefield[i][j].setFillColor(Gamefieldfuture[i][j].getFillColor());
        }
    }
}