#include "Calendar/calendar.hpp"
#include "Commitment/commitment.hpp"

int main() {
    CaledarList *caledar = CreateCaledar();
    InsertDate(caledar, "2020-01-01");
    InsertDate(caledar, "2021-01-01");

    PrintCalendar(caledar);

    return 0;
}