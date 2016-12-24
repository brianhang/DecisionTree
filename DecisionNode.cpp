#include "DecisionNode.h"

// Constructor that does not set a value.
DecisionNode::DecisionNode() { }

// Constructor that sets the value of the node.
DecisionNode::DecisionNode(const DecisionNodeValue &newValue) {
    setValue(newValue);
}

// Sets the value of the node.
void DecisionNode::setValue(const DecisionNodeValue &newValue) {
    value = newValue;
}

// Sets the attribute value of the node.
void DecisionNode::setAttribute(unsigned int newValue) {
    value.attribute = newValue;
}

// Sets the decision value of the node.
void DecisionNode::setDecision(const std::string &newValue) {
    // TODO: Fix lifetime of the decision pointer
    value.decision = newValue.c_str();
}

// Returns the value contained by the node.
const DecisionNodeValue &DecisionNode::getValue() {
    return value;
}

// Returns the attribute value of the node.
unsigned int DecisionNode::getAttribute() {
    return value.attribute;
}

// Returns the decision value of the node.
const std::string &DecisionNode::getDecision() {
    return value.decision;
}

// Adds a child node with no value and returns a pointer to the child.
DecisionNode *DecisionNode::addChild(const std::string &edgeValue) {
    // Create another node and store it as a child of this node.
    children[edgeValue] = std::unique_ptr<DecisionNode>(new
                         DecisionNode());

    // Return the pointer for the child.
    return children[edgeValue].get();
}

// Adds a child node with the given data. A pointer to the newly created child
// node is returned.
DecisionNode *DecisionNode::addChild(const std::string &edgeValue,
const DecisionNodeValue &newValue) {
    // Create another node and store it as a child of this node.
    children[edgeValue] = std::unique_ptr<DecisionNode>(new
                         DecisionNode(newValue));

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
