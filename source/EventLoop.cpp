#include "EventLoop.hpp"

namespace ACLIB
{
    EventLoop::EventLoop()
        : m_physics(AC::PHYSICS_PAGE)
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
            m_events.emplace(GEAR_CHANGED);
        }

        // Graphics
        if(m_graphics->status != m_graphics_compare.status)
        {
            m_events.emplace(STATUS_CHANGED);
        }
        if(m_graphics->session != m_graphics_compare.session)
        {
            m_events.emplace(SESSION_CHANGED);
        }
        if(m_graphics->completedLaps != m_graphics_compare.completedLaps)
        {
            m_events.emplace(COMPLETED_LAPS_CHANGED);
        }
        if(m_graphics->position != m_graphics_compare.position)
        {
            m_events.emplace(POSITION_CHANGED);
        }
        if(m_graphics->isInPit != m_graphics_compare.isInPit)
        {
            m_events.emplace(IS_IN_PIT);
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

    void EventLoop::push(EventType event)
    {
        m_events.push(event);
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
}  // namespace ACLIB
