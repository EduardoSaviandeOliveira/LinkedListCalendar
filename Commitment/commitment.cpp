#ifndef COMMITMENT_CPP
#define COMMITMENT_CPP

#include "commitment.hpp"

CommitmentList *CreateCommitmentList() {
    CommitmentList *list = new CommitmentList;

    list->head = nullptr;
    list->tail = nullptr;

    return list;
}




void PrintCommitments(CommitmentList *list) {
    CommitmentNode* node = list->head;
    while (node != nullptr) {
        std::cout << node->startTime << " " << node->endtime << " " << node->description << std::endl;
        node = node->next;
    }
}

#endif