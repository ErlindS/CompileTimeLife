
#include <iostream>
#include <string>
#include <algorithm>

template<typename... T>
int sum(T&&... t){
    return (t + ...);
}

//ah not mine
template<typename... L>
struct multilambda : L... {
  using L::operator()...;
  constexpr multilambda(L...lambda) : L(std::move(lambda))... {}
};

template<typename T, typename... Rules>
T apply_rules(T value, Rules... rules) {
    return ( ... , (value = rules(value)) ); 
}

template<typename T, size_t c, typename... L>
struct Gamefield{
    T X[c];
    T Y[c];
    T buffer[c];

   	using iterator = T*;
	using const_iterator = T const*;


    constexpr T const& operator[](std::size_t i) const noexcept {
		return buffer[i];
	}

	constexpr iterator begin() noexcept {
		return &buffer[0];
	}

	constexpr iterator end() noexcept {
		return begin()+c;
	}

	constexpr const_iterator begin() const noexcept {
		return &buffer[0];
	}

	constexpr const_iterator end() const noexcept {
		return begin()+c;
	}
};

constexpr multilambda Rules {
    [](int i) { std::cout << i+1 << std::endl; },
    [](int i) { std::cout << i+2 << std::endl; },
    [](int i) { std::cout << i+3 << std::endl; },
    [](int i) { std::cout << i+4 << std::endl; },
    
  };

/*
template<std::size_t N>
constexpr std::size_t FIB = FIB<N - 2> + FIB<N - 1>;

template<std::size_t N>
	requires (N < 2)
constexpr std::size_t FIB<N> = N;
*/

int main(){
    int initial = 5;
    std::cout << "Initial: " << initial << "\n";
    //int result = apply_rules(initial, Rules);
    //return 0;

    int result = apply_rules(initial,
        [](int i) {  return i + 1; },
        [](int i) {  return i + 2; },
        [](int i) {  return i + 3; }
    );

    //int result2 = apply_rules(initial, Rules);

    std::cout << "Result: " << result << "\n";
    //std::cout << "Result: " << result2 << "\n";

    //int result = sum(1,2,3,4);
    return 0;
}