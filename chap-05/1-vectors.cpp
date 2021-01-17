#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& values)
{
    for (const auto v : values)
    {
        stream << v << " ";
    }

    return stream;
}

int main()
{
    std::vector<int> values_1 { 4, 0 };
    std::cout << values_1 << std::endl;

    std::vector<int> values_2(4, 0);
    std::cout << values_2 << std::endl;

    const int array[] = { 0, 1, 2, 3, 4, 5 };

    std::vector<int> part(&array[2], &array[5]);
    std::cout << "part: " << part << std::endl;

    std::vector<int> full(array, array + 6);
    std::cout << "full: " << full << std::endl;

    for (size_t left = 0, right = full.size() - 1; left < right; ++left, --right)
    {
        std::swap(full[left], full[right]);
    }
    std::cout << "inverted: " << full << std::endl;

    for (auto it = full.begin(); it != full.end(); it += 2)
    {
        it = full.insert(it, *it);
    }
    std::cout << "duplicated: " << full << std::endl;

    while (!full.empty())
    {
        full.pop_back();
    }
    std::cout << "empty: " << full << std::endl;

    std::vector<int> erasable { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    erasable.erase(erasable.begin() + 2, erasable.begin() + 7);
    std::cout << "erasable: " << erasable << std::endl;

    auto it = std::find(erasable.begin(), erasable.end(), 9);
    if (it != erasable.end())
    {
        erasable.erase(it);
    }
    std::cout << "erasable: " << erasable << std::endl;

    full.assign(5, 2);
    std::cout << "5x2: " << full << std::endl;

    full.assign({ 0, 2, 32, -4, 3 });
    std::cout << "some values: " << full << std::endl;

    full.clear();
    std::cout << "cleared: " << full << std::endl;

    return 0;
}