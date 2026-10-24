#include <span>
#include <array>
#include <ranges>
#include <vector>
#include <iostream>
#include <initializer_list>

int main(int, char**) {
    auto print_range{
        []<std::ranges::input_range Range>(Range&& range) -> void {
            auto begin{ range.begin() };
            auto end{ range.end() };

            std::cout << '[';
            for( ; begin != end; ++begin) {
                std::cout << ' ' << *begin << ' ';
            }

            std::cout << ']' << std::endl;
        }
    };

    std::string str{ "yadaaaa!!" };
    print_range(str);

    std::vector floats_vector{ 2.11, 3.55, 1.44, -7.22 };
    print_range(floats_vector);

    std::array floats_array{ 2.11, 3.55, 1.44, -7.22 };
    print_range(floats_array);

    std::initializer_list<double> floats_list{ 2.11, 3.55, 1.44, -7.22 };
    print_range(floats_list);

    return 0;
}