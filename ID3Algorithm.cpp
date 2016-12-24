#include "ID3Algorithm.h"
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

ID3Algorithm::ID3Algorithm() {
    // Randomize the seed for selecting random attributes.
    srand((unsigned)time(0));
}

// Recursively splits the training data into nodes for a decision tree.
void ID3Algorithm::split(DecisionNode *node,
const DecisionExamples &examples) {
    // Do nothing if there are no training data to use.
    if (examples.size() == 0) {
        return;
    }

    // Check whether or not the examples form a pure set.
    bool pure = true;
    std::string lastValue;

    for (auto it = examples.begin(); it != examples.end() - 1; it++) {
        auto nextIt = it + 1;

        lastValue = (*it)[0];

        if (nextIt != examples.end() && lastValue != (*nextIt)[0]) {
            pure = false;

            break;
        }
    }

    // If the examples form a pure set, then do not split this node.
    if (pure) {
        node->setDecision(lastValue);

        return;
    }

    // Otherwise, choose the best attribute from the examples.
    unsigned int attribute = getBestAttribute(examples);
    node->setAttribute(attribute);

    // Find all the possible values from the training data for the selected
    // attribute.
    std::unordered_set<std::string> foundValues;

    // The training data that does not include the selected attribute.
    std::unordered_map<std::string, DecisionExamples> newExamples;

    for (auto it = examples.begin(); it != examples.end(); it++) {
        // Get the attribute value for this set of attribute values from the
        // training data.
        std::string value = (*it)[attribute];

        // Create a bucket for the attribute value if one does not exist.
        if (newExamples.find(value) == newExamples.end()) {
            newExamples[value] = DecisionExamples();
        }

        // Insert a subset of this data that does not include the selected
        // attribute.
        DecisionData subSet((*it).size() - 1);

        for (unsigned int i = 0; i < (*it).size(); i++) {
            if (i == attribute) {
                continue;
            }

            subSet.push_back((*it)[i]);
        }

        newExamples[value].push_back(subSet);

        // Ignore values we have already seen.
        if (foundValues.find(value) != foundValues.end()) {
            continue;
        } else {
            foundValues.insert(value);
        }
    }

    // For each possible attribute value, create a child for the attribute and
    // recursively split them into pure subsets.
    for (auto it = foundValues.begin(); it != foundValues.end(); it++) {
        split(node->addChild(*it), newExamples[*it]);
    } 
}

// Returns the best attribute for splitting training data.
unsigned int ID3Algorithm::getBestAttribute(const DecisionExamples &examples) {
    // Assume uniform number of attributes in the training data. Ignore the
    // first element since it is assumed to be the outcome attribute.
    unsigned int attributeCount = examples[0].size() - 1;
    
    return (rand() % attributeCount) + 1;
}
