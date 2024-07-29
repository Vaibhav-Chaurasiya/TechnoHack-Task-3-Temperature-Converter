#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "Temperature Converter Menu:\n";
    std::cout << "1. Celsius to Fahrenheit\n";
    std::cout << "2. Celsius to Kelvin\n";
    std::cout << "3. Fahrenheit to Celsius\n";
    std::cout << "4. Fahrenheit to Kelvin\n";
    std::cout << "5. Kelvin to Celsius\n";
    std::cout << "6. Kelvin to Fahrenheit\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    int choice;
    double temperature;

    while (true) {
        showMenu();
        std::cin >> choice;

        // Check for invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 7) {
            std::cout << "Exiting program.\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            std::cerr << "Invalid choice. Please choose a number between 1 and 7.\n";
            continue;
        }

        std::cout << "Enter the temperature: ";
        std::cin >> temperature;

        // Check for invalid temperature input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Invalid temperature input. Please enter a numeric value.\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << temperature << " Celsius is " << celsiusToFahrenheit(temperature) << " Fahrenheit.\n";
                break;
            case 2:
                std::cout << temperature << " Celsius is " << celsiusToKelvin(temperature) << " Kelvin.\n";
                break;
            case 3:
                std::cout << temperature << " Fahrenheit is " << fahrenheitToCelsius(temperature) << " Celsius.\n";
                break;
            case 4:
                std::cout << temperature << " Fahrenheit is " << fahrenheitToKelvin(temperature) << " Kelvin.\n";
                break;
            case 5:
                std::cout << temperature << " Kelvin is " << kelvinToCelsius(temperature) << " Celsius.\n";
                break;
            case 6:
                std::cout << temperature << " Kelvin is " << kelvinToFahrenheit(temperature) << " Fahrenheit.\n";
                break;
            default:
                std::cerr << "Unexpected error.\n";
                break;
        }
    }

    return 0;
}
