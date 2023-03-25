#include "Calendar/calendar.hpp"
#include "Commitment/commitment.hpp"

using namespace std;

int main() {
    CaledarList *caledarlist = CreateCaledarList();
    InsertCaledarNode(caledarlist, "2020-01-01");

    
    PrintCalendar(caledarlist);

    return 0;
}