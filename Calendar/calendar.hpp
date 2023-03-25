#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <string>
#include "../Commitment/commitment.hpp"

struct CalendarNode {
    CommitmentList *commitmentlist = CreateCommitmentList();
    std::string date;
    CalendarNode* next;
    CalendarNode* prev;
};

struct CaledarList {
    CalendarNode *head;
    CalendarNode *tail;
};

CaledarList *CreateCaledarList();

void InsertCaledarNode(CaledarList *list, std::string date);

void RemoveCaledarNode(CaledarList *list, std::string date);

void PrintCalendar(CaledarList *list);

#endif