#include "EventLoop.hpp"

namespace ACLIB
{
    EventLoop::EventLoop()
        : m_thread_id(0)
        , m_thread_handle(nullptr)
        , m_running(true)
        , m_timeout_ms(1)
        , m_physics(AC::PHYSICS_PAGE)
        , m_graphics(AC::GRAPHICS_PAGE)
        , m_statics(AC::STATICS_PAGE)
        , m_physics_compare()
        , m_graphics_compare()
        , m_statics_compare()
        , m_events()
    {
    }

    void EventLoop::pumpEvent()
    {
        // Physics
        if(m_physics->gear != m_physics_compare.gear)
        {
            m_events.push(GEAR_CHANGED);
        }

        // Graphics
        if(m_graphics->status != m_graphics_compare.status)
        {
            m_events.emplace(static_cast<Uint32>(STATUS_CHANGED));
        }
        if(m_graphics->session != m_graphics_compare.session)
        {
            m_events.emplace(static_cast<Uint32>(SESSION_CHANGED));
        }
        if(m_graphics->completedLaps != m_graphics_compare.completedLaps)
        {
            m_events.emplace(static_cast<Uint32>(COMPLETED_LAPS_CHANGED));
        }
        if(m_graphics->position != m_graphics_compare.position)
        {
            m_events.emplace(static_cast<Uint32>(POSITION_CHANGED));
        }
        if(m_graphics->isInPit != m_graphics_compare.isInPit)
        {
            m_events.emplace(static_cast<Uint32>(IS_IN_PIT));
        }
    }

    void EventLoop::refreshCompare()
    {
        m_physics_compare  = *m_physics.data();
        m_graphics_compare = *m_graphics.data();
        m_statics_compare  = *m_statics.data();
    }

    bool EventLoop::empty() const
    {
        return m_events.empty();
    }

    size_t EventLoop::size() const
    {
        return m_events.size();
    }

    EventType EventLoop::front() const
    {
        return m_events.front();
    }

    void EventLoop::pop()
    {
        m_events.pop();
    }

    void EventLoop::start()
    {
        m_thread_handle = CreateThread(nullptr, 0, &startThread, this, 0, &m_thread_id);

        if(m_thread_handle == nullptr)
        {
            // err
            printf("Could not create thread\n");
        }
    }
    void EventLoop::run()
    {
        refreshCompare();

        while(m_running)
        {
            pumpEvent();
            refreshCompare();
            Sleep(m_timeout_ms);
        }
    }

    void EventLoop::stop()
    {
        m_running = false;
    }

    DWORD startThread(LPVOID p)
    {
        if(p == nullptr)
        {
            printf("Thread parameter is nullptr.\n");
            return -1;
        }
        reinterpret_cast<EventLoop*>(p)->run();
        return 0;
    }
}  // namespace ACLIB
