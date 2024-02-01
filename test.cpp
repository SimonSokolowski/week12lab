#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <algorithm>

void swap(std::vector<int>& vec, size_t i, size_t j);
void selectionSort(std::vector<int>& vec);

TEST_CASE("Swap elements in a vector", "[swap]") {
    std::vector<int> vec = {1, 3, 2, 4, 5};

    SECTION("Swapping non-adjacent elements") {
        swap(vec, 1, 2);
        REQUIRE(vec == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Swapping an element with itself does nothing") {
        swap(vec, 2, 2);
        REQUIRE(vec == std::vector<int>{1, 3, 2, 4, 5});
    }
}

TEST_CASE("Selection sort on vectors", "[selectionSort]") {
    std::vector<int> vec = {64, 25, 12, 22, 11};

    SECTION("Sort an unsorted vector") {
        selectionSort(vec);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION("Sort an already sorted vector") {
        std::vector<int> sortedVec = {11, 12, 22, 25, 64};
        selectionSort(sortedVec);
        REQUIRE(std::is_sorted(sortedVec.begin(), sortedVec.end()));
    }

    SECTION("Sort a vector with all identical elements") {
        std::vector<int> identicalVec = {1, 1, 1, 1};
        selectionSort(identicalVec);
        REQUIRE(std::is_sorted(identicalVec.begin(), identicalVec.end()));
    }
}

void swap(std::vector<int>& vec, size_t i, size_t j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}
void selectionSort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        swap(vec, i, min_index);
    }
}
