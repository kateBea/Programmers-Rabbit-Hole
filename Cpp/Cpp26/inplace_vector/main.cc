#include <print>
#include <algorithm>
#include <inplace_vector>

int main(int, char**) {
    std::inplace_vector<int, 10> vec{ -1, 6, 7, 4, 3, -9, 10 };
    
    auto print_range{
        []<typename InputIt>( InputIt begin, InputIt end) -> void {
            std::print("[");
            for( ; begin != end; ++begin) {
                std::print( " {} ",  *begin);
            }

            std::print("]");
        }
    };

    print_range(vec.begin(), vec.end());

    vec.emplace_back( -20 );

    std::println();
    print_range(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());
    std::println();
    print_range(vec.begin(), vec.end());
    return 0;
}