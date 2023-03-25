#ifndef COMMITMENT_HPP
#define COMMITMENT_HPP

#include <iostream>
#include <string>

#include "../Calendar/calendar.hpp"

struct CommitmentNode {
    std::string starttime;
    std::string endtime;
    std::string description;
    CommitmentNode* next;
    CommitmentNode* prev;
};

struct CommitmentList {
    CommitmentNode *head;
    CommitmentNode *tail;
};

CommitmentList *CreateCommitmentList();

void InsertCommitment(std::string date, CaledarList  *calendar, std::string startTime, std::string endTime, std::string description);

void PrintCommitments(CommitmentList *node);

#endif