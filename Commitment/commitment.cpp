#ifndef COMMITMENT_CPP
#define COMMITMENT_CPP

#include "commitment.hpp"

CommitmentList *CreateCommitmentList() {
    CommitmentList *list = new CommitmentList;

    list->head = nullptr;
    list->tail = nullptr;

    return list;
}


void InsertCommitment(std::string date, CaledarList  *calendar, std::string startTime, std::string endTime, std::string description) {
}

void PrintCommitments(CommitmentList *list) {
    CommitmentNode* node = list->head;
    while (node != nullptr) {
        std::cout << node->starttime << " " << node->endtime << " " << node->description << std::endl;
        node = node->next;
    }
}

#endif