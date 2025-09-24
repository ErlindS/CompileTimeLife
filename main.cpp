#include <array>
#include <cstddef>
#include <string_view>
#include <algorithm>
#include <vector>
#include <iostream>
#include <type_traits>

#define LEN 9
#define WID 9
#define SIZE LEN * WID

//Definitly
//Type traits
//Faltungen
//Const
//refernezen reihenfolgen

//TODO add smth with type type_traits
//TODO template recursion with classes
//TODO Maybe rule of five
//TODO sich die Notizen anschauen
//TODO Faltungen
//TODO Concepts
//TODO tempalte interfaces
//TODO Training with this
//TODO const bei Funktionen
//TODO work with ::
//TODO explain why it is possible to make neighbour constexpr with array but not with vector


//DELAYED
//TODO add a way to change to topology of given project

//TODO would be nice to add dieffent kind of neighbours this is a first step
using Dir = std::array<int, 2>;
using Array2d = std::array<std::array<int, LEN>, WID>;


struct FourNeighbours{
    //TODO explain why this is static
    constexpr static std::size_t neighbourhood_size = 5;
    constexpr static std::array<Dir,5> directions {{
                                              {0, 1},
                                    {-1, 0}, {0, 0}, {1, 0},
                                              {0, -1}
                                  }};
};

struct EightNeighbours{
    constexpr static std::size_t neighbourhood_size = 9;
    constexpr static std::array<Dir,9> directions {{
                                    {-1, 1}, {0, 1}, {1, 1},
                                    {-1, 0}, {0, 0}, {1, 0},
                                    {-1, -1}, {0, -1}, {1, -1}
                                  }};
};


struct TwentyfiveNeighbours{
    constexpr static std::size_t neighbourhood_size = 26;
    constexpr static std::array<Dir,26> directions {{
                                    {-2, 2}, {-1, 2}, {0, 2}, {1, 2}, {2, 2},
                                    {-2, 1}, {-1, 1}, {0, 1}, {1, 1}, {2, 1},
                                    {-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0},
                                    {-2, -1}, {-1, -1}, {0, -1}, {1, -1}, {2, -1},
                                    {-2, -2}, {-1, -2}, {0, -2}, {1, -2}, {2, -2},
                                  }};
};

std::ostream& operator<<(std::ostream& os, Array2d const& grid){
    for(std::size_t i = 0; i < LEN; ++i){
        for(std::size_t ii = 0; ii < WID; ++ii){
            os << grid[i][ii] << " ";
        }
        os << '\n';
    }
    return os;
}

template<typename Neighbourhood_type, typename... Rules>
struct Gamefield{

    //Here is the grid data and the rules
    Array2d& data;
    std::tuple<Rules...> rules;

    Gamefield(
          Neighbourhood_type
        , Array2d& dataparam
        , Rules... rulesparam
    )
        : data{dataparam}
        , rules{rulesparam...}
    {}

    using Dir = std::array<int, 2>;

    struct Neighbourhood {
        struct iterator {
            Neighbourhood const* parent;
            std::size_t current_position;
            iterator& operator++(){
                ++current_position;
                //TODO explain why *this
                return *this;
            }

            //TODO Explain why friend is necessary
            friend constexpr
            bool operator!=(iterator a, iterator b){
                return a.current_position != b.current_position;
            }

            int operator*() const{
                int x = Neighbourhood_type::directions[current_position][0] + parent->position[0];
                int y = Neighbourhood_type::directions[current_position][1]*-1 + parent->position[1];
                if (x < 0 || y < 0 || x >= LEN || y >= WID) return 0;

                return parent->parent->data[y][x];
            }

        };

        Gamefield const* parent;
        std::array<int, 2> position;

        constexpr iterator begin() const {
            return iterator{this, 0};
        }

        constexpr iterator end() const {
            return iterator{this, Neighbourhood_type::neighbourhood_size};
        }
    };

    constexpr Neighbourhood neighbour(int x, int y) {
        return Neighbourhood{this, std::array<int, 2>{x, y}};
    };

    constexpr int evaluates_neighbours(int x, int y) {
        int counter = 0;
        Neighbourhood n = neighbour(x,y);
        for (auto it = n.begin(); it != n.end(); ++it) {
                counter += *(it);
        }

        std::apply([&](auto&... f){(..., f(counter));}, rules);

        //(rules...(counter), ...);
        return counter;
    }

    //Display data
    friend
    std::ostream& operator<<(std::ostream& os, Gamefield const& grid){
        for(std::size_t i = 0; i < LEN; ++i){
            for(std::size_t ii = 0; ii < WID; ++ii){
                os << grid.data[i][ii];
            }
            os << '\n';
        }
        return os;
    }

};

//Solution 1
template<typename G>
constexpr void iterate(G& grid, int counter) {
    Array2d data2;
    for(;0 < counter; --counter){
        std::cout << "Steps left: " << counter << "\n-----------------------------------------\n";
        std::cout << grid.data;
        std::cout << "-----------------------------------------\n";

        for(int i = 0; i < LEN; ++i){
            for(int j = 0; j < LEN; ++j){
                data2[i][j] = grid.evaluates_neighbours(j,i);
            }
        }
        grid.data = data2;
    }
}
//template recursion

//Solution 3
//recursion with lambdas
template<typename G>
G iterate2(G& grid, std::size_t counter) {
    Array2d data2;

    auto impl = [&](auto impl, std::size_t counter){
        if(counter == 0){
            for(int i = 0; i < LEN; ++i){
                for(int j = 0; j < LEN; ++j){
                    data2[i][j] = grid.evaluates_neighbours(j,i);
                }
            }
            grid = data2;
        } else {
            for(int i = 0; i < LEN; ++i){
                for(int j = 0; j < LEN; ++j){
                    data2[i][j] = grid.evaluates_neighbours(j,i);
                }
            }
        }
    };

    impl(grid, --counter);
    return grid;
}

#include "gif.h"

int main(){

    // width & height of your grid
    int gridWidth = 9;
    int gridHeight = 8;
    int scale = 10; // optional, to make cells bigger

    Array2d grid 
    {{
        {0,0,1,0,1,0,1,0,1},
        {0,0,1,1,0,1,1,0,1},
        {1,0,0,1,0,1,0,0,0},
        {0,0,1,0,1,0,1,0,1},
        {0,0,1,0,1,0,1,0,1},
        {0,0,1,1,0,1,1,0,1},
        {1,0,0,1,0,1,0,0,0},
        {0,0,1,0,1,0,1,0,1},
    }};;

    // Create a buffer for RGBA pixels
    int width = gridWidth * scale;
    int height = gridHeight * scale;
    std::vector<uint8_t> pixels(width * height * 4, 0);

    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            uint8_t color = grid[y][x] ? 255 : 0;
            for (int dy = 0; dy < scale; ++dy) {
                for (int dx = 0; dx < scale; ++dx) {
                    int px = (y*scale + dy) * width + (x*scale + dx);
                    pixels[px*4 + 0] = color; // R
                    pixels[px*4 + 1] = color; // G
                    pixels[px*4 + 2] = color; // B
                    pixels[px*4 + 3] = 255;   // A
                }
            }
        }
    }

    // Write as GIF
    GifWriter g;
    GifBegin(&g, "output.gif", width, height, 100);
    GifWriteFrame(&g, pixels.data(), width, height, 100);
    GifEnd(&g);

    constexpr Array2d gamefield_data2
    {{
        {0,0,1,0,1,0,1,0,1},
        {0,0,1,1,0,1,1,0,1},
        {1,0,0,1,0,1,0,0,0},
        {0,0,1,0,1,0,1,0,1},
        {0,0,1,0,1,0,1,0,1},
        {0,0,1,1,0,1,1,0,1},
        {1,0,0,1,0,1,0,0,0},
        {0,0,1,0,1,0,1,0,1},
    }};

    Array2d gamefield_data3 = gamefield_data2;

    std::cout << "This is the orginal Grid\n" ;

    //Define what kind of Gamefield there is and how the neighbour should look like. 1 = 4 neighbours, 2 = 8 Neighbours, 3 = 26 Neighbours
    Gamefield gamefield(EightNeighbours{}, 
                        gamefield_data3,
                        [](int& a) { if(a == 4 || a==3 ){a = 1;} else {a = 0;} }
                        //[](int& b) { if(b == 0 || b==3 ){b = 1;} else {b = 1;} }
                        //[](int& a) { if(a == 4 || a==3 ){a = 1;} else {a = 0;} }
                        );
    std::cout << gamefield;
    std::cout << "-----------------------------------------\n";

    iterate(gamefield, 40000);

}
