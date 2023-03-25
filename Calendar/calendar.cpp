#ifndef CALENDAR_CPP
#define CALENDAR_CPP

#include "calendar.hpp"

CaledarList *CreateCaledarList() {
    CaledarList *list = new CaledarList;

    list->head = nullptr;
    list->tail = nullptr;

    return list;
}

//insert in order
void InsertCaledarNode(CaledarList *list, std::string date) {
    CalendarNode* node = new CalendarNode;
    node->date = date;
    node->next = nullptr;
    node->prev = nullptr;

    if (list->head == nullptr) {
        list->head = node;
        list->tail = node;
    } else {
        CalendarNode* temp = list->head;
        while (temp != nullptr) {
            if (temp->date > date) {
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

// Remove a date in the calendar
void RemoveCaledarNode(CaledarList *list, std::string date) {
    CalendarNode* node = list->head;
    while (node != nullptr) {
        if (node->date == date) {
            if (node->prev != nullptr) {
                node->prev->next = node->next;
            } else {
                list->head = node->next;
            }
            if (node->next != nullptr) {
                node->next->prev = node->prev;
            } else {
                list->tail = node->prev;
            }
            delete node;
            break;
        }
        node = node->next;
    }
}

void PrintCalendar(CaledarList *list) {
    CalendarNode* node = list->head;
    while (node != nullptr) {
        std::cout << node->date << "\n";
        node = node->next;
    }
}

#endif