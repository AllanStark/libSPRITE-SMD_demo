#include "Ap.h"
#include "base/XPRINTF.h"

namespace task
{
    Ap::Ap(const char *const name) : SRTX::Task(name)
    {
    }

    bool Ap::init()
    {
        DPRINTF("Init aperiodic task\n");
        return true;
    }

    bool Ap::execute()
    {
        DPRINTF("Execute aperiodic task\n");
        return false;
    }

    void Ap::terminate()
    {
        DPRINTF("Terminate aperiodic task\n");
    }

} // namespace
