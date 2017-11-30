#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

struct Event
{
    beginning : int;
    end : int;

    const bool operator<(const Event &other) const
    {
        if (end != other.end)
        {
            return end > other.end;
        }

        return beginning > other.beginning;
    }
}

int
main()
{
    int b, e;

    priority_queue<Event> events;

    while (scanf("%d %d\n", &b, &e) == 2)
    {
        Event e;
        e.beginning = b;
        e.end = b + e;

        events.push(e);
    }

    int eventsCount = 0;
    int lastEnd = 0;
    while (scanf("%d %d\n", &b, &e) == 2)
    {
        Event e = events.top();
        if (e.beginning >= lastEnd)
        {
            lastEnd = e.end;
        }

        events.pop();
    }

    printf("%d\n", eventsCount);

    return 0;
}
