#ifndef CALENDAR_CPP
#define CALENDAR_CPP

#include "calendar.hpp"

bool IsValidDate(std::string date) {
    if (date.length() != 10) {
        return false;
    }

    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (year.length() != 4 || month.length() != 2 || day.length() != 2) {
        return false;
    }

    for (int i = 0; i < 4; i++) {
        if (year[i] < '0' || year[i] > '9') {
            return false;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (month[i] < '0' || month[i] > '9') {
            return false;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (day[i] < '0' || day[i] > '9') {
            return false;
        }
    }

    int yearInt = std::stoi(year);
    int monthInt = std::stoi(month);
    int dayInt = std::stoi(day);

    if (yearInt < 0 || monthInt < 0 || dayInt < 0) {
        return false;
    }

    if (monthInt > 12) {
        return false;
    }

    if (dayInt > 31) {
        return false;
    }

    if (monthInt == 2) {
        if (dayInt > 29) {
            return false;
        }
        if (dayInt == 29) {
            if (yearInt % 4 != 0 && (yearInt % 100 != 0 || yearInt % 400 == 0)) {
                return false;
            }
        }
    }

    if (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) {
        if (dayInt > 30) {
            return false;
        }
    }

    return true;
}

bool IsValidTime(std::string time) {
    if (time.length() != 5) {
        return false;
    }

    if (time[2] != ':') {
        return false;
    }

    std::string hour = time.substr(0, 2);
    std::string minute = time.substr(3, 2);

    if (hour.length() != 2 || minute.length() != 2) {
        return false;
    }

    for (int i = 0; i < 2; i++) {
        if (hour[i] < '0' || hour[i] > '9') {
            return false;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (minute[i] < '0' || minute[i] > '9') {
            return false;
        }
    }

    int hourInt = std::stoi(hour);
    int minuteInt = std::stoi(minute);

    if (hourInt < 0 || minuteInt < 0) {
        return false;
    }

    if (hourInt > 23 || minuteInt > 59) {
        return false;
    }

    return true;
}

bool IsOccupiedTime(CalendarList *calendar, std::string date, std::string startTime, std::string endTime) {
    CalendarNode *node = GetDate(calendar, date);
    if (node == nullptr) {
        return false;
    }

    CommitmentNode *temp = node->commitmentList->head;
    while (temp != nullptr) {
        if (startTime >= temp->startTime && startTime < temp->endTime) {
            return true;
        }
        if (endTime > temp->startTime && endTime <= temp->endTime) {
            return true;
        }
        if (startTime <= temp->startTime && endTime >= temp->endTime) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

bool IsOccupiedDate(CalendarList *calendar, std::string date) {
    CalendarNode *node = GetDate(calendar, date);
    if (node == nullptr) {
        return false;
    }

    if (node->commitmentList->head == nullptr) {
        return false;
    }

    return true;
}

void InsertCommitment(std::string date, CalendarList  *calendar, std::string startTime, std::string endTime, std::string description) {
    if (!IsValidDate(date)) {
        std::cout << date << " Data inválida\n";
        return;
    }

    if (!IsValidTime(startTime)) {
        std::cout << "Hora de início inválida\n";
        return;
    }

    if (!IsValidTime(endTime)) {
        std::cout << "Hora de término inválida\n";
        return;
    }

    if (startTime >= endTime) {
        std::cout << "Hora de início deve ser anterior a hora de término\n";
        return;
    }

    if (IsOccupiedTime(calendar, date, startTime, endTime)) {
        std::cout << "Horário ocupado\n";
        return;
    }

    CalendarNode *node = GetDate(calendar, date);
    if (node == nullptr) {
        std::cout << "Dia não existe\n";
        return;
    }

    CommitmentNode *commitment = new CommitmentNode;
    commitment->startTime = startTime;
    commitment->endTime = endTime;
    commitment->description = description;
    commitment->next = nullptr;
    commitment->prev = nullptr;

    if (node->commitmentList->head == nullptr) {
        node->commitmentList->head = commitment;
        node->commitmentList->tail = commitment;
    } else {
        CommitmentNode *temp = node->commitmentList->head;
        while (temp != nullptr) {
            if (temp->startTime > startTime) {
                if (temp->prev != nullptr) {
                    temp->prev->next = commitment;
                    commitment->prev = temp->prev;
                } else {
                    node->commitmentList->head = commitment;
                }
                temp->prev = commitment;
                commitment->next = temp;
                break;
            }
            temp = temp->next;
        }
    
        if (temp == nullptr) {
            node->commitmentList->tail->next = commitment;
            commitment->prev = node->commitmentList->tail;
        }
    }
}

void RemoveCommitment(std::string date, CalendarList *calendar, std::string startTime) {
    if (!IsValidDate(date)) {
        std::cout << date << " Data inválida\n";
        return;
    }

    if (!IsValidTime(startTime)) {
        std::cout << "Hora de início inválida\n";
        return;
    }

    CalendarNode *node = GetDate(calendar, date);

    if (node == nullptr) {
        std::cout << "Não há compromissos marcados para " << date << "\n";
        return;
    }

    CommitmentNode *temp = node->commitmentList->head;

    while (temp != nullptr) {
        if (temp->startTime == startTime) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                node->commitmentList->head = temp->next;
            }

            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            } else {
                node->commitmentList->tail = temp->prev;
            }

            delete temp;
            break;
        }
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "Não há compromissos marcados para " << date << " às " << startTime << "\n";
    }
}

void InsertDate(CalendarList *calendar, std::string date) {
    if (!IsValidDate(date)) {
        return;
    }

    if (IsOccupiedDate(calendar, date)) {
        std::cout << "Data já existe\n";
        return;
    }

    CalendarNode *node = new CalendarNode;
    node->date = date;
    node->commitmentList = new CommitmentList;
    node->commitmentList->head = nullptr;
    node->commitmentList->tail = nullptr;
    node->next = nullptr;
    node->prev = nullptr;

    if (calendar->head == nullptr) {
        calendar->head = node;
        calendar->tail = node;
    } else {
        CalendarNode *temp = calendar->head;
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
        }
    }
}

void RemoveDate(CalendarList *calendar, std::string date) {
    if (!IsValidDate(date)) {
        return;
    }

    CalendarNode* node = GetDate(calendar, date);
    if (node == nullptr) {
        return;
    }

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

    CommitmentNode* temp = node->commitmentList->head;
    while (temp != nullptr) {
        CommitmentNode* next = temp->next;
        delete temp;
        temp = next;
    }

    delete node->commitmentList;
    delete node;
}

CalendarList *CreateCaledar() {
    CalendarList *list = new CalendarList;

    list->head = nullptr;
    list->tail = nullptr;

    return list;
}

CalendarNode *GetDate(CalendarList *calendar, std::string date) {
    CalendarNode* node = calendar->head;
    while (node != nullptr) {
        if (node->date == date) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

void PrintCalendar(CalendarList *calendar) {
    CalendarNode* node = calendar->head;
    while (node != nullptr) {
        std::cout << node->date << "\n";
        node = node->next;
    }
}

void PrintCommitments(CalendarList *calendar, std::string date) {
    CalendarNode* node = GetDate(calendar, date);
    if (node == nullptr) {
        std::cout << "Dia não existe\n";
        return;
    }

    if (node->commitmentList->head == nullptr) {
        std::cout << "Não há compromissos marcados para " << date << "\n";
        return;
    }
    
    CommitmentNode* commitment = node->commitmentList->head;
    while (commitment != nullptr) {
        std::cout << commitment->startTime << " - " << commitment->endTime << " " << commitment->description << "\n";
        commitment = commitment->next;
    }
}

#endif