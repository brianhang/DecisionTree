#include "DecisionNode.h"

// Sets the attribute value of the node.
void DecisionNode::setAttribute(unsigned int newValue) {
    attribute = newValue;
}

// Sets the decision value of the node.
void DecisionNode::setDecision(const std::string &newValue) {
    // TODO: Fix lifetime of the decision pointer
    decision = newValue;
}

// Returns the attribute value of the node.
unsigned int DecisionNode::getAttribute() {
    return attribute;
}

// Returns the decision value of the node.
const std::string &DecisionNode::getDecision() {
    return decision;
}

// Adds a child node with no value and returns a pointer to the child.
DecisionNode *DecisionNode::addChild(const std::string &edgeValue) {
    // Create another node and store it as a child of this node.
    children[edgeValue] = std::unique_ptr<DecisionNode>(new
                         DecisionNode());

    // Return the pointer for the child.
    return children[edgeValue].get();
}

// Returns a child node by following an edge labeled with the given value.
DecisionNode *DecisionNode::getChild(const std::string &value) {
    auto nodeIt = children.find(value);

    if (nodeIt == children.end()) {
        return nullptr;
    } else {
        return nodeIt->second.get();
    }
}

// Returns whether or not this node has any children.
bool DecisionNode::hasChildren() {
    return !children.empty();
}
