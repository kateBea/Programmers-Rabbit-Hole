#include <cstdint>
#include <cstddef>
#include <iostream>

struct Vector3F {
    float x{};
    float y{};
    float z{};

    friend std::ostream& operator<<(std::ostream& out, const Vector3F& v) {
        out << "[ " << v.x << ' ' << v.y << ' ' << v.z << " ]\n";

        return out;
    }
};  

struct Entity {
    std::size_t m_id{};
    Vector3F m_position{};
    Vector3F m_rotation{};
    Vector3F m_scaling{};

    float m_healt{};

    friend std::ostream& operator<<(std::ostream& out, const Entity& e) {
        out << "Entity:\n";
        out << "  Position: " << e.m_position;
        out << "  Rotation: " << e.m_rotation;
        out << "  Scaling: " << e.m_scaling;
        out << "  Health: " << e.m_healt << '\n';
        
        return out;
    }

};

int main(int, char**) {
    Entity player{
        .m_id{ 1 },
        .m_position{
            .x{ 0.44f },
            .y{ 5.31f },
            .z{ 1.22f },
        },
        .m_rotation{
            .x{ 8.42f },
            .y{ 3.31f },
            .z{ 1.44f },
        },
        .m_scaling{
            .x{ 9.21f },
            .y{ 0.11f },
            .z{ 5.13f },
        },
        .m_healt = 100.0f
    };

    std::cout.precision(1);
    std::cout.setf(std::ios_base::fixed);
    std::cout << player << std::endl;

    return 0;
}