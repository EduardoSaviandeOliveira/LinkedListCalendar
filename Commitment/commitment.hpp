#ifndef COMMITMENT_HPP
#define COMMITMENT_HPP

#include <iostream>
#include <string>

struct CommitmentNode {
    std::string startTime;
    std::string endTime;
    std::string description;
    CommitmentNode* next;
    CommitmentNode* prev;
};

struct CommitmentList {
    CommitmentNode *head;
    CommitmentNode *tail;
};

CommitmentList *CreateCommitmentList();

#endif