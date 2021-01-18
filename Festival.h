#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"

namespace mtm
{
    class Festival;
}
class mtm::Festival : public mtm::EventContainer
{
public:
    void add(BaseEvent& event) override;
}

#endif