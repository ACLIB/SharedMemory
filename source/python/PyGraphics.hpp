#ifndef ACLIB_SHARED_MEMORY_PYGRAPHICS_HPP
#define ACLIB_SHARED_MEMORY_PYGRAPHICS_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"
#include "python/PyClassType.hpp"

namespace ACLIB
{
    class PyGraphics : public PyClassType
    {
    public:
        SharedMemory<AC::Graphics>* m_graphics;

        explicit PyGraphics(const char* name)
            : PyClassType(name)
        {
        }

        virtual bool init(PyObject* module)
        {
            m_type.tp_basicsize = sizeof(PyGraphics);
            m_type.tp_new       = (newfunc)PyGraphics::_new;
            m_type.tp_dealloc   = (destructor)PyGraphics::_del;

            return PyClassType::init(module);
        }

        /**
         * Memory Management
         */

        static PyObject* _new(PyTypeObject* type, PyObject* args, PyObject* kwds)
        {
            auto self = reinterpret_cast<PyGraphics*>(type->tp_alloc(type, 0));
            if(self != nullptr)
            {
                self->m_graphics = new SharedMemory<AC::Graphics>(AC::GRAPHICS_PAGE);
            }
            return reinterpret_cast<PyObject*>(self);
        }

        static void _del(PyTypeObject* type)
        {
            auto self = reinterpret_cast<PyGraphics*>(type);
            if(self != nullptr)
            {
                delete self->m_graphics;
            }
            Py_TYPE(type)->tp_free(reinterpret_cast<PyObject*>(type));
        }

        /**
         * Custom class type functions
         */

        static PyObject* get_packetId(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->packetId);
        }

        static PyObject* get_status(PyGraphics* self, void*)
        {
            return PyLong_FromLong(static_cast<AC::Uint32>(self->m_graphics->data()->status));
        }
        static PyObject* get_session(PyGraphics* self, void*)
        {
            return PyLong_FromLong(static_cast<AC::Uint32>(self->m_graphics->data()->session));
        }
        static PyObject* get_currentTime(PyGraphics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_graphics->data()->currentTime,
                wcslen(self->m_graphics->data()->currentTime));
        }
        static PyObject* get_lastTime(PyGraphics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_graphics->data()->lastTime,
                wcslen(self->m_graphics->data()->lastTime));
        }
        static PyObject* get_bestTime(PyGraphics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_graphics->data()->bestTime,
                wcslen(self->m_graphics->data()->bestTime));
        }
        static PyObject* get_split(PyGraphics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_graphics->data()->split,
                wcslen(self->m_graphics->data()->split));
        }
        static PyObject* get_completedLaps(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->completedLaps);
        }
        static PyObject* get_position(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->position);
        }
        static PyObject* get_iCurrentTime(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->iCurrentTime);
        }
        static PyObject* get_iLastTime(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->iLastTime);
        }
        static PyObject* get_iBestTime(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->iBestTime);
        }
        static PyObject* get_sessionTimeLeft(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->sessionTimeLeft);
        }
        static PyObject* get_distanceTraveled(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->distanceTraveled);
        }
        static PyObject* get_isInPit(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->isInPit);
        }
        static PyObject* get_currentSectorIndex(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->currentSectorIndex);
        }
        static PyObject* get_lastSectorTime(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->lastSectorTime);
        }
        static PyObject* get_numberOfLaps(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->numberOfLaps);
        }
        static PyObject* get_tyreCompound(PyGraphics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_graphics->data()->tyreCompound,
                wcslen(self->m_graphics->data()->tyreCompound));
        }
        static PyObject* get_replayTimeMultiplier(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->replayTimeMultiplier);
        }
        static PyObject* get_normalizedCarPosition(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->normalizedCarPosition);
        }
        static PyObject* get_carCoordinates(PyGraphics* self, void*)
        {
            return Py_BuildValue(
                "[fff]",
                self->m_graphics->data()->carCoordinates[0],
                self->m_graphics->data()->carCoordinates[1],
                self->m_graphics->data()->carCoordinates[2]);
        }
        static PyObject* get_penaltyTime(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->penaltyTime);
        }
        static PyObject* get_flag(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->flag);
        }
        static PyObject* get_idealLineOn(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->idealLineOn);
        }
        static PyObject* get_isInPitLine(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->isInPitLine);
        }
        static PyObject* get_surfaceGrip(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->surfaceGrip);
        }
        static PyObject* get_mandatoryPitDone(PyGraphics* self, void*)
        {
            return PyLong_FromLong(self->m_graphics->data()->mandatoryPitDone);
        }
        static PyObject* get_windSpeed(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->windSpeed);
        }
        static PyObject* get_windDirection(PyGraphics* self, void*)
        {
            return PyFloat_FromDouble(self->m_graphics->data()->windDirection);
        }
    };
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYGRAPHICS_HPP
