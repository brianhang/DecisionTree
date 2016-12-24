#include "DataFileParser.h"
#include <sstream>
#include <iostream>

#define DELIMITER ','

// Constructor that opens the given data file so it can be parsed.
DataFileParser::DataFileParser(const std::string &dataFilePath) {
    // Open the desired data file.
    dataFile.open(dataFilePath, std::ifstream::in | std::ifstream::binary);

    // Reset the number of attributes from the previous parsing.
    lastAttributeCount = 0;
}

// Attempts to parse the data file. This returns whether or not an error occured
// while parsing.
bool DataFileParser::parseFile() {
    // Cannot parse an unopened file.
    if (!dataFile.is_open()) {
        std::cerr << "Unable to open the training data file." << std::endl;

        return false;
    }

    // A line of data from the data file.
    std::string dataLine;

    // Parse all of the lines of the data file.
    while (getline(dataFile, dataLine)) {
        std::vector<std::string> data;

        // Return false if this line could not be parsed.
        if (!parseLine(dataLine, data)) {
            return false;
        }

        // Otherwise, add the data from the line to the output data.
        examples.push_back(data);
    }

    // Error for empty training data.
    if (examples.empty()) {
        std::cerr << "The training data file cannot be empty." << std::endl;

        return false;
    }

    return true;
}

// Attempts to parse one line of a data file. This is done by separating a comma
// separated line into string attributes. It is assumed that every line will
// have the same number of attributes and each "column" corresponds to the
// correct attribute.
bool DataFileParser::parseLine(const std::string &input, DecisionData &data) {
    // Create a stream from the given string.
    std::stringstream stream(input);

    // Go through each attribute in the given string and store it in data.
    while (stream.good()) {
        std::string attribute;
        getline(stream, attribute, DELIMITER);

        data.push_back(attribute);
    }

    // Error if the number of attributes are not consistent.
    if (lastAttributeCount > 0 && lastAttributeCount != data.size()) {
        std::cerr << "Inconsistent number of attributes: " << std::endl
                  << input << std::endl;

        return false;
    }

    // Update the number of attributes counted.
    lastAttributeCount = data.size();

    return true;
}

// Returns the data parsed from the data file.
DecisionExamples DataFileParser::getExamples() {
    return examples;
}

// Returns the number of attributes (columns) for the given data.
unsigned int DataFileParser::getAttributeCount() {
    return lastAttributeCount;
}
