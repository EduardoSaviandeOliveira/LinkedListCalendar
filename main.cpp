#include "Calendar/calendar.hpp"
#include "Commitment/commitment.hpp"

int main() {
    CalendarList *caledar = CreateCaledar();
    InsertDate(caledar, "2020-01-01");
    InsertDate(caledar, "2021-01-01");
    InsertCommitment("2020-01-01", caledar, "12:00", "13:00", "test");
    InsertCommitment("2020-01-01", caledar, "13:00", "14:00", "test");
    InsertCommitment("2021-01-01", caledar, "13:00", "14:00", "test");
    InsertCommitment("2021-01-01", caledar, "13:30", "14:30", "test");

    PrintCommitments(caledar, "2020-01-01");



    return 0;
}