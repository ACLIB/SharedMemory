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
        compare(m_physics->gear, m_physics_compare.gear, GEAR_CHANGED);
        compare(m_physics->carDamage, m_physics_compare.carDamage, DAMAGE_CHANGED);
        compare(m_physics->numberOfTyresOut, m_physics_compare.numberOfTyresOut, TYRES_OUT_CHANGED);
        compare(m_physics->drs, m_physics_compare.drs, DRS_CHANGED);
        compare(m_physics->drsAvailable, m_physics_compare.drsAvailable, DRS_AVAILABLE_CHANGED);
        compare(m_physics->drsEnabled, m_physics_compare.drsEnabled, DRS_ENABLE_CHANGED);

        // Graphics
        compare(m_graphics->status, m_graphics_compare.status, STATUS_CHANGED);
        compare(m_graphics->session, m_graphics_compare.session, SESSION_CHANGED);
        compare(m_graphics->completedLaps, m_graphics_compare.completedLaps, COMPLETED_LAPS_CHANGED);
        compare(m_graphics->position, m_graphics_compare.position, POSITION_CHANGED);
        compare(m_graphics->isInPit, m_graphics_compare.isInPit, IS_IN_PIT);
        compare(m_graphics->tyreCompound, m_graphics_compare.tyreCompound, TYRE_CHANGED);
        compare(m_graphics->penaltyTime, m_graphics_compare.penaltyTime, PENALTY_CHANGED);
        compare(m_graphics->flag, m_graphics_compare.flag, FLAG_CHANGED);
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
