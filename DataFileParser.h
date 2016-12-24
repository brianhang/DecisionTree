#pragma once

#include "DecisionTypes.h"
#include <fstream>

// The DataFileParser loads sample data from a file using another file that
// specifies the attributes for the sample data. The parser than converts the
// file data into a usable format for the decision tree.
class DataFileParser {
    private:
        // File for reading the sample data.
        std::ifstream dataFile;

        // Returns the attributes loaded from the last parse.
        DecisionExamples examples;

        // The number of attributes from the previous parsing.
        unsigned int lastAttributeCount;

    public:
        // Constructor that opens the given data file so it can be parsed.
        DataFileParser(const std::string &dataFilePath);

        // Attempts to parse the data file. This returns whether or not an
        // error occured while parsing.
        bool parseFile();

        // Attempts to parse one line of comma separated data. The parsed data
        // is stored into the given vector.
        bool parseLine(const std::string &input, DecisionData &data);

        // Returns the examples parsed from the data file.
        DecisionExamples getExamples();

        // Returns the number of attributes for the given data.
        unsigned int getAttributeCount();
};
