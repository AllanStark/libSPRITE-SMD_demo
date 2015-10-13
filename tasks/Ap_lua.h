#ifndef __TASK_AP_LUA_H__
#define __TASK_AP_LUA_H__

#include "SCALE/LuaWrapper.h"
#include "tasks/Ap.h"

namespace task
{
    class Ap_lua
    {
      public:
        /**
         * The name regsitered with Lua to describe the class.
         */
        static const char class_name[];

        /**
         * The set of methods being exposed to Lua through the adapter
         * class.
         */
        static luaL_Reg methods[];

        /**
         * Allocate an instance of this task.
         * @param L Pointer to the Lua state.
         * @return A pointer to the Task.
         */
        static Ap *allocator(lua_State *L)
        {
            return new Ap(luaL_checkstring(L, 1));
        }

        /**
         * Register the contents of this class as an adapter between Lua
         * and C++ representations of SRTX::Task.
         * @param L Pointer to the Lua state.
         * @return Number of elements being passed back through the Lua
         * stack.
         */
        static int register_class(lua_State *L)
        {
            luaW_register<Ap>(L, "Ap", NULL, methods, allocator);
            luaW_extend<Ap, SRTX::Task>(L);
            return 0;
        }
    };

    const char Ap_lua::class_name[] = "Ap";

    luaL_Reg Ap_lua::methods[] = { { NULL, NULL } };
} // namespace

#endif // __TASK_AP_LUA_H__
