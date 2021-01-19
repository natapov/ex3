#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"
#include "date_wrap.h"

namespace mtm
{
    class Festival;
}
class mtm::Festival : public mtm::EventContainer
{
    mtm::DateWrap date;
public:
    Festival(mtm::DateWrap date);
    void add(BaseEvent& event) override;
};


#endif