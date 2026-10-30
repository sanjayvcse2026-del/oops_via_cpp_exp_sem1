#include <concepts>
#include <iostream>
#include <ranges>
#include <vector>

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
std::vector<T> processData(const std::vector<T>& data)
{
    std::vector<T> result;

    auto pipeline = data
        | std::views::filter([](T value) {
            return value > 0;
        })
        | std::views::transform([](T value) {
            return value * 2;
        });

    for (T value : pipeline)
    {
        result.push_back(value);
    }

    return result;
}

int main()
{
    const std::vector<int> data{-3, 0, 2, 5, -1, 8};
    const auto result = processData(data);

    std::cout << "Positive values doubled: ";
    for (int value : result)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    return 0;
}