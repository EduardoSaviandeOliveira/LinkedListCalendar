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

struct CalendarList {
    CalendarNode *head;
    CalendarNode *tail;
};
bool IsValidDate(std::string date);

bool IsValidTime(std::string time);

bool IsOccupiedTime(CalendarList *calendar, std::string date, std::string startTime, std::string endTime);

bool IsOccupiedDate(CalendarList *calendar, std::string date);

void InsertCommitment(std::string date, CalendarList  *calendar, std::string startTime, std::string endTime, std::string description);

CalendarList *CreateCaledar();

void InsertDate(CalendarList *calendar, std::string date);

void RemoveDate(CalendarList *calendar, std::string date);

CalendarNode *GetDate(CalendarList *calendar, std::string date);

void PrintCommitments(CalendarList *calendar, std::string date);

#endif