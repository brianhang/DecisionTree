#include "DataFileParser.h"
#include "DecisionTree.h"
#include "ID3Algorithm.h"
#include <cstdlib>
#include <iostream>

int main(int argc, const char **argv) {
    // Check for the correct number of arguments.
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " dataFile" << std::endl
                  << "\tdataFile: a file containing comma separated"
                  << " training data" << std::endl;

        return EXIT_FAILURE;
    }

    // Parse the input file.
    DataFileParser parser(argv[1]);

    // Exit if parsing the input file failed.
    if (!parser.parseFile()) {
        return EXIT_FAILURE;
    }

    // Create a decision tree from the parsed data.
    ID3Algorithm algorithm;
    DecisionTree decider(parser.getExamples(), algorithm);

    // New data from user input.
    std::string input;

    // Repeatedly prompt the user to enter new data to make a decision.
    while (true) {
        // Prompt the user for input.
        std::cout << "Enter new data to form a decision:" << std::endl;
        getline(std::cin, input);

        if (!std::cin) {
            break;
        }

        // Convert the user input into a usable format.
        std::vector<std::string> data;
        
        // Validate the user input. If the input is not valid, ask for input
        // again.
        if (!parser.parseLine(input, data)) {
            std::cerr << "You did not enter valid data, try again."
                      << std::endl;

            continue;
        }

        std::cout << "Result: " << decider.decide(data) << std::endl;
    }

    return EXIT_SUCCESS;
}
