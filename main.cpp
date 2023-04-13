#include "Calendar/calendar.hpp"
#include "Commitment/commitment.hpp"

int main() {
    CalendarList *calendar = CreateCaledar();
    std::string command;
    while(true) {
        std::cout << "Selecione uma opção:\n";
        std::cout << "1 - Inserir dia\n";
        std::cout << "2 - Remover dia\n";
        std::cout << "3 - Inserir compromisso\n";
        std::cout << "4 - Remover compromisso\n";
        std::cout << "5 - Imprimir calendário\n";
        std::cout << "6 - Imprimir compromissos\n";
        std::cout << "7 - Sair\n";
        std::cout << "Opção: ";
        std::cin >> command;
        
        if (command == "1") {
            std::string date;

            std::cout << "Adicionar - Digite a data (aaaa-MM-dd): ";
            std::cin >> date;

            InsertDate(calendar, date);
        } else if (command == "2") {
            std::string date;

            std::cout << "Remover - Digite a data (aaaa-MM-dd): ";
            std::cin >> date;

            RemoveDate(calendar, date);
        } else if (command == "3") {
            std::string date;
            std::string startTime;
            std::string endTime;
            std::string description;

            std::cout << "Inserir compromisso - Digite a data (aaaa-MM-dd): ";
            std::cin >> date;
            std::cout << "Inserir compromisso - Digite o horário de início (hh:mm): ";
            std::cin >> startTime;
            std::cout << "Inserir compromisso - Digite o horário de término (hh:mm): ";
            std::cin >> endTime;
            std::cout << "Inserir compromisso - Digite a descrição: ";
            std::cin >> description;

            InsertCommitment(date, calendar, startTime, endTime, description);
        } else if (command == "4") {
            std::string date;
            std::string startTime;

            std::cout << "Inserir compromisso - Digite a data (aaaa-MM-dd): ";
            std::cin >> date;
            std::cout << "Inserir compromisso - Digite o horário de início (hh:mm): ";
            std::cin >> startTime;

            RemoveCommitment(date, calendar, startTime);
        } else if (command == "5") {
            PrintCalendar(calendar);
        } else if (command == "6") {
            std::string date;

            std::cout << "Imprimir compromissos - Digite a data (aaaa-MM-dd): ";

            PrintCommitments(calendar, date);
        } else if (command == "7") {
            break;
        }
    }
    return 0;
}