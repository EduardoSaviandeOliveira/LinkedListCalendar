#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <string>

#include "../Commitment/commitment.hpp"

struct CalendarNode {
    CommitmentList *commitmentList = CreateCommitmentList();
    std::string date;
    CalendarNode* next;
    CalendarNode* prev;
};

struct CaledarList {
    CalendarNode *head;
    CalendarNode *tail;
};

bool validateTime(const std::string& timeStr);

CaledarList *CreateCaledar();

void InsertDate(CaledarList *calendar, std::string date);

void RemoveDate(CaledarList *calendar, std::string date);

CalendarNode *GetDate(CaledarList *calendar, std::string date);

void PrintCalendar(CaledarList *calendar);

#endif