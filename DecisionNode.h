#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

// The DecisionNodeValue is used to hold an attribute if a node has children and
// a string if the node is a decision.
union DecisionNodeValue {
    const char *decision;
    unsigned int attribute;
};

// The DecisionNode is a node within a decision tree. It contains a decision
// value and has other DecisionNodes as children for decisions that may follow.
class DecisionNode {
    private:
        DecisionNodeValue value;
        std::unordered_map<std::string, std::unique_ptr<DecisionNode>> children;

    public:
        // Empty constructor that does not set a node value.
        DecisionNode();

        // Constructor for the node that sets the value.
        DecisionNode(const DecisionNodeValue &newValue);

        // Sets the value of this node.
        void setValue(const DecisionNodeValue &newValue);

        // Sets the attribute value of the node.
        void setAttribute(unsigned int newValue);

        // Sets the decision value of the node.
        void setDecision(const std::string &newValue);

        // Returns the value that the node holds.
        const DecisionNodeValue &getValue();

        // Returns the attribute value of the node.
        unsigned int getAttribute();

        // Returns the decision value of the node.
        const std::string &getDecision();

        // Adds a child node with no value for the node and returns the newly
        // created child node.
        DecisionNode *addChild(const std::string &edgeValue);

        // Adds a child node with a given decision value and returns the newly
        // created child node.
        DecisionNode *addChild(const std::string &edgeValue,
                               const DecisionNodeValue &newValue);

        // Returns a child node by following an edge labeled with the given value.
        DecisionNode *getChild(const std::string &value);

        // Returns whether or not this node has any children.
        bool hasChildren();
};
