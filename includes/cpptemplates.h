#include <SFML/Graphics.hpp>
#include <iostream>
void update(sf::RectangleShape Gamefield[][100], sf::RectangleShape Gamefieldfuture[][100]);

//1. param Neighbours 2. Size
template<std::size_t N, std::size_t S>
struct shape{
    sf::ConvexShape convex;
    shape(){
        convex.setPointCount(N);
        t1.setPoint(0, {S*N, S*N});
    }

    getNumberOfSides(){
        return N;
    }

    getRadius(){
        return S;
    }
};


//Form und Feld unterscheiden
template<typename T, std::size_t N>
struct field{
    // resize it to 5 points
    field(){
        field<T, N-5>
    }
};

template<std::size_t N>
    requires (N < 5)
constexpr std::size_t FIB<N> = N;

//zb 100 Felder aus 5 Seiten; N ist die Tiefe
template<typename T, std::size_t N>
struct Gamefield{
    field<T, N>
};
