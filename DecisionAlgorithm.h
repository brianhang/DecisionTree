#pragma once

#include "DecisionNode.h"
#include "DecisionTypes.h"

// The DecisionAlgorithm is an abstract class that is used to decide how a tree
// is built by splitting training data and determines the best attribute to
// split with.
class DecisionAlgorithm {
    public:
        // Recursively splits the training data into nodes for a decision tree.
        virtual void split(DecisionNode *node,
                           const DecisionExamples &examples) = 0;
};
