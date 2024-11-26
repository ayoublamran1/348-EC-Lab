#include <iostream>
#include <string>
#include <iomanip>

// Function to extract a numeric value from a string
double extractNumeric(const std::string& input) {
    bool hasDecimal = false;
    bool hasSign = false;
    bool valid = true;
    size_t length = input.length();

    // Empty string or too long
    if (length == 0 || length > 20) return -999999.99;

    // Validate the string
    for (size_t i = 0; i < length; ++i) {
        char c = input[i];

        if (c == '+' || c == '-') {
            if (i == 0) hasSign = true; // Sign only valid at the start
            else {
                valid = false; // Invalid if not at the beginning
                break;
            }
        } else if (c == '.') {
            if (hasDecimal) { // Multiple decimals
                valid = false;
                break;
            }
            hasDecimal = true;
        } else if (!isdigit(c)) {
            valid = false; // Non-numeric character
            break;
        }
    }

    if (!valid) return -999999.99;

    try {
        // Convert valid string to double
        double result = std::stod(input);
        return result;
    } catch (...) {
        return -999999.99; // Handle any conversion errors
    }
}

int main() {
    std::string input;
    
    std::cout << "Enter a string (type 'END' to quit):\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "END") break;

        double value = extractNumeric(input);

        if (value == -999999.99) {
            std::cout << "The input is invalid.\n";
        } else {
            std::cout << "The input is: " 
                      << std::fixed << std::setprecision(4) 
                      << value << '\n';
        }
    }

    return 0;
}