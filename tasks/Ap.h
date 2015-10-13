#ifndef __TASK_AP_H__
#define __TASK_AP_H__

#include <stdio.h>
#include "SRTX/Task.h"

namespace task
{
    class Ap : public SRTX::Task
    {
      public:
        /**
         * Constructor.
         * @param name Task name.
         */
        Ap(const char *const name);

        /**
         * Initialization routine.
         * @return true on success or false on failure.
         */
        bool init();

        /**
         * This the the function that gets executed on a periodic basis
         * each time this task is scheduler to run.
         * @return Return true to continue execution or false to terminate
         * the task.
         */
        bool execute();

        /**
         * Terminate routine.
         */
        void terminate();
    };

} // namespace

#endif // __TASK_AP_H__
