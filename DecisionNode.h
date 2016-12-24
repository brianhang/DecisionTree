#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

// The DecisionNode is a node within a decision tree. It contains a decision
// value and has other DecisionNodes as children for decisions that may follow.
class DecisionNode {
    private:
        std::string decision;
        unsigned int attribute;

    public:
        std::unordered_map<std::string, std::unique_ptr<DecisionNode>> children;
        // Sets the attribute value of the node.
        void setAttribute(unsigned int newValue);

        // Sets the decision value of the node.
        void setDecision(const std::string &newValue);

        // Returns the attribute value of the node.
        unsigned int getAttribute();

        // Returns the decision value of the node.
        const std::string &getDecision();

        // Adds a child node with no value for the node and returns the newly
        // created child node.
        DecisionNode *addChild(const std::string &edgeValue);

        // Returns a child node by following an edge labeled with the given value.
        DecisionNode *getChild(const std::string &value);

        // Returns whether or not this node has any children.
        bool hasChildren();
};
