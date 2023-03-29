#ifndef CALENDAR_CPP
#define CALENDAR_CPP

#include "calendar.hpp"

CaledarList *CreateCaledar() {
    CaledarList *list = new CaledarList;

    list->head = nullptr;
    list->tail = nullptr;

    return list;
}

//insert in order
void InsertDate(CaledarList *calendar, std::string date) {
    CalendarNode* node = new CalendarNode;
    node->date = date;
    node->next = nullptr;
    node->prev = nullptr;

    if (calendar->head == nullptr) {
        calendar->head = node;
        calendar->tail = node;
    } else {
        CalendarNode* temp = calendar->head;
        while (temp != nullptr) {
            if (temp->date > date) {
                if (temp->prev != nullptr) {
                    temp->prev->next = node;
                    node->prev = temp->prev;
                } else {
                    calendar->head = node;
                }
                temp->prev = node;
                node->next = temp;
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            calendar->tail->next = node;
            node->prev = calendar->tail;
            calendar->tail = node;
        }
    }
}

// Remove a date in the calendar
void RemoveDate(CaledarList *calendar, std::string date) {
    CalendarNode* node = calendar->head;
    while (node != nullptr) {
        if (node->date == date) {
            if (node->prev != nullptr) {
                node->prev->next = node->next;
            } else {
                calendar->head = node->next;
            }
            if (node->next != nullptr) {
                node->next->prev = node->prev;
            } else {
                calendar->tail = node->prev;
            }
            delete node;
            break;
        }
        node = node->next;
    }
}

CalendarNode *GetDate(CaledarList *calendar, std::string date) {
    CalendarNode* node = calendar->head;
    while (node != nullptr) {
        if (node->date == date) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

void PrintCalendar(CaledarList *calendar) {
    CalendarNode* node = calendar->head;
    while (node != nullptr) {
        std::cout << node->date << "\n";
        node = node->next;
    }
}


#endif