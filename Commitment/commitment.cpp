#ifndef COMMITMENT_CPP
#define COMMITMENT_CPP

#include "commitment.hpp"

CommitmentList *CreateCommitmentList() {
    CommitmentList *list = new CommitmentList;

    list->head = nullptr;
    list->tail = nullptr;

    return list;
}

void InsertCommitmentNode(CommitmentList *list, std::string startTime, std::string endTime, std::string description) {
    CommitmentNode* node = new CommitmentNode;
    node->starttime = startTime;
    node->endtime = endTime;
    node->description = description;
    node->next = nullptr;
    node->prev = nullptr;

    if (list->head == nullptr) {
        list->head = node;
        list->tail = node;
    } else {
        CommitmentNode* temp = list->head;
        while (temp != nullptr) {
            if (temp->starttime > startTime) {
                if (temp->prev != nullptr) {
                    temp->prev->next = node;
                    node->prev = temp->prev;
                } else {
                    list->head = node;
                }
                temp->prev = node;
                node->next = temp;
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            list->tail->next = node;
            node->prev = list->tail;
            list->tail = node;
        }
    }
}


#endif