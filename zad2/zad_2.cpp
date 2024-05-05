#include <iostream>
#include <cmath>
#include <iomanip>

// Функция за сравнение на числа с плаваща запетая с ε
bool compareWithEpsilon(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

// Функция за сравнение на числа с плаваща запетая с умножение на ε
bool compareWithMultiplication(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon * std::max(fabs(a), fabs(b));
}

// Тестване на различните методи за сравнение
void testComparisons(float epsilon) {
    int correctCount = 0;
    int incorrectCount = 0;

    // Генериране на тестови числа за сравнение
    float testFloat1 = 1.0f;
    float testFloat2 = 1.00001f;

    // Сравнение с ε
    if (compareWithEpsilon(testFloat1, testFloat2, epsilon)) {
        std::cout << "compareWithEpsilon: Equal\n";
        correctCount++;
    } else {
        std::cout << "compareWithEpsilon: Not Equal\n";
        incorrectCount++;
    }

    // Сравнение с умножение на ε
    if (compareWithMultiplication(testFloat1, testFloat2, epsilon)) {
        std::cout << "compareWithMultiplication: Equal\n";
        correctCount++;
    } else {
        std::cout << "compareWithMultiplication: Not Equal\n";
        incorrectCount++;
    }

    // Извеждане на резултатите
    std::cout << "Correct Comparisons: " << correctCount << std::endl;
    std::cout << "Incorrect Comparisons: " << incorrectCount << std::endl;
}

int main() {
    float epsilonValues[] = {1e-1f, 1e-3f, 1e-6f}; // Различни стойности на ε за тестване

    std::cout << std::fixed << std::setprecision(10);

    // Тестване за float
    std::cout << "Testing float:\n";
    for (float epsilon : epsilonValues) {
        std::cout << "Epsilon: " << epsilon << std::endl;
        testComparisons(epsilon);
    }

    // Тестване за double
    std::cout << "\nTesting double:\n";
    for (float epsilon : epsilonValues) {
        double testDouble1 = 1.0;
        double testDouble2 = 1.0000001;
        std::cout << "Epsilon: " << epsilon << std::endl;
        testComparisons(epsilon);
    }

    return 0;
}
