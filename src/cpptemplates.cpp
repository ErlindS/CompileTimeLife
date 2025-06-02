#include "cpptemplates.h"

int livingneighbours = 0;


template<typename T>
void getNeighbour(T a){

}


template<typename T>
void addNeighbour(){

}


/*
template<std::size_t N>
struct rectangle{
    sf::RectangleShape shape;
}

template<typename T, std::size_t N>
struct Gamefield{
    std::vector<T> fields;
    T Neighbours;
    field.addNeighbour<N>;
};*/

/*

void conveyWayOfLifeRules(){
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
}
*/
/*

void countLivingNeighbours(){
    //checking Neighbours
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
}
*/
/*
void update(sf::RectangleShape Gamefield[][100], sf::RectangleShape Gamefieldfuture[][100]){
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            //Gamefield[i][j].setFillColor(sf::Color(0, 0, 0));
            //std::cout << "this is blue: " << int(Gamefield[i][j].getFillColor().b) << std::endl;
            countLivingNeighbours();
            conveyWayOfLifeRules();

            //std::cout << livingneighbours;
            livingneighbours = 0;
            
        }
    }
    
    //copy
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            Gamefield[i][j].setFillColor(Gamefieldfuture[i][j].getFillColor());
        }
    }
}
*/
//Gamefield, should set size, color and position

/*
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



    bool randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
}
*/