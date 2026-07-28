#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate startDate;
    clsDate endDate;

    clsPeriod(clsDate startDate, clsDate endDate)
    {
        this->startDate = startDate;
        this->endDate = endDate;
    }

    static bool IsOverlapPeriods(clsPeriod period1, clsPeriod period2)
    {

        if (
            clsDate::CompareDates(period2.endDate, period1.startDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(period2.startDate, period1.endDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }

    bool IsOverLapWith(clsPeriod period2)
    {
        return IsOverlapPeriods(*this, period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        startDate.Print();

        cout << "Period End: ";
        endDate.Print();

    }

};