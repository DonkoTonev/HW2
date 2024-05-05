#include <iostream>
#include <cmath>
#include <iomanip>

bool compareWithEpsilon(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

bool compareWithMultiplication(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon * std::max(fabs(a), fabs(b));
}

void testComparisons(float epsilon) {
    int correctCount = 0;
    int incorrectCount = 0;

    float testFloat1 = 1.0f;
    float testFloat2 = 1.00001f;

    if (compareWithEpsilon(testFloat1, testFloat2, epsilon)) {
        std::cout << "compareWithEpsilon: Equal\n";
        correctCount++;
    } else {
        std::cout << "compareWithEpsilon: Not Equal\n";
        incorrectCount++;
    }

    if (compareWithMultiplication(testFloat1, testFloat2, epsilon)) {
        std::cout << "compareWithMultiplication: Equal\n";
        correctCount++;
    } else {
        std::cout << "compareWithMultiplication: Not Equal\n";
        incorrectCount++;
    }

    std::cout << "Correct Comparisons: " << correctCount << std::endl;
    std::cout << "Incorrect Comparisons: " << incorrectCount << std::endl;
}

int main() {
    float epsilonValues[] = {1e-1f, 1e-3f, 1e-6f};

    std::cout << std::fixed << std::setprecision(10);

    std::cout << "Testing float:\n";
    for (float epsilon : epsilonValues) {
        std::cout << "Epsilon: " << epsilon << std::endl;
        testComparisons(epsilon);
    }

    std::cout << "\nTesting double:\n";
    for (float epsilon : epsilonValues) {
        double testDouble1 = 1.0;
        double testDouble2 = 1.0000001;
        std::cout << "Epsilon: " << epsilon << std::endl;
        testComparisons(epsilon);
    }

    return 0;
}
