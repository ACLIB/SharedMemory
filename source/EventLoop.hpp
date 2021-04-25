#ifndef ACLIB_SHARED_MEMORY_EVENTLOOP_HPP
#define ACLIB_SHARED_MEMORY_EVENTLOOP_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"

#include <queue>

namespace ACLIB
{
    class EventLoop
    {
    private:
        DWORD  m_thread_id;
        HANDLE m_thread_handle;
        bool   m_running;
        Uint32 m_timeout_ms;

        SharedMemory<AC::Physics>  m_physics;
        SharedMemory<AC::Graphics> m_graphics;
        SharedMemory<AC::Statics>  m_statics;

        AC::Physics  m_physics_compare;
        AC::Graphics m_graphics_compare;
        AC::Statics  m_statics_compare;

    public:
        EventLoop();

        std::queue<EventType> m_events;

        void pumpEvent();
        void refreshCompare();

        bool empty() const;
        size_t size() const;
        EventType front() const;
        void pop();

        void start();
        void run();
        void stop();
    };

    DWORD WINAPI startThread(LPVOID p);

}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_EVENTLOOP_HPP
