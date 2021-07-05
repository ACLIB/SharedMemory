#ifndef ACLIB_SHARED_MEMORY_EVENTLOOP_HPP
#define ACLIB_SHARED_MEMORY_EVENTLOOP_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"
#include "util/Thread.hpp"

#include <queue>

namespace ACLIB
{
    class EventLoop : public Thread
    {
    private:
        SharedMemory<AC::Physics>  m_physics;
        SharedMemory<AC::Graphics> m_graphics;
        SharedMemory<AC::Statics>  m_statics;

        AC::Physics  m_physics_compare;
        AC::Graphics m_graphics_compare;
        AC::Statics  m_statics_compare;

    public:
        EventLoop();

        std::queue<EventType> m_events;

        template<typename T>
        void compare(T t1, T t2, EVENT event)
        {
            if(t1 != t2)
                m_events.emplace(event);
        }

        void pumpEvent();
        void refreshCompare();

        bool      empty() const;
        size_t    size() const;
        EventType front() const;
        void      pop();
        void      push(EventType event);

        virtual void run();
    };

}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_EVENTLOOP_HPP
