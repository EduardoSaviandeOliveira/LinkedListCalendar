#ifndef COMMITMENT_CPP
#define COMMITMENT_CPP

#include "commitment.hpp"

CommitmentList *CreateCommitmentList() {
    CommitmentList *list = new CommitmentList;

    list->head = nullptr;
    list->tail = nullptr;

    return list;
}



#endif