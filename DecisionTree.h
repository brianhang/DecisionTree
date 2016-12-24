#pragma once

#include "DecisionNode.h"
#include "DecisionTypes.h"
#include "DecisionAlgorithm.h"

// The DecisionTree class is a tree data structure that contains attributes for
// which describes conditions for a certain decision.
class DecisionTree {
    private:
        // The root node of the tree.
        DecisionNode *root;
        std::unordered_map<std::string, unsigned int> attributes;
        DecisionAlgorithm &algorithm;

    public:
        // Destructor that cleans up the root node.
        ~DecisionTree();

        // A constructor that sets the example data for creating the tree and
        // the algorithm used to make decisions.
        DecisionTree(const DecisionExamples &examples,
                     DecisionAlgorithm &newAlgorithm);

        // Creates a decision about a set of string attributes using data from
        // the tree.
        std::string decide(const DecisionData &data);
};
