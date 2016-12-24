#include "DecisionTree.h"

// Constructor for the tree that takes in training data and populates the tree
// with nodes using an algorithm for a decision tree.
DecisionTree::DecisionTree(const DecisionExamples &examples,
DecisionAlgorithm &newAlgorithm) : algorithm(newAlgorithm) {
    root = new DecisionNode();
    algorithm.split(root, examples);
}

// Follows the tree using new data to form a decision.
std::string DecisionTree::decide(const DecisionData &data) {
    // Start from the root node of the tree.
    DecisionNode *node = root;

    // Traverse the tree by following edges that have a matching decision.
    while (node->hasChildren()) {
        unsigned int attribute = node->getAttribute();

        node = node->getChild(data[attribute]);
    }

    // Return the value of the leaf node that was reached, which is a decision
    // since it must be a pure set.
    return node->getDecision();
}

DecisionTree::~DecisionTree() {
    if (root) {
        delete root;
    }
}
