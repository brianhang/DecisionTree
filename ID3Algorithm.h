#pragma once

#include "DecisionAlgorithm.h"

class ID3Algorithm : public DecisionAlgorithm {
    public:
        ID3Algorithm();

        // Recursively splits the training data into nodes for a decision tree.
        void split(DecisionNode *node, const DecisionExamples &examples);

        // Returns the best attribute for splitting training data.
        unsigned int getBestAttribute(const DecisionExamples &examples);
};
