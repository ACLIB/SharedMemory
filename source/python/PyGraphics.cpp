#include "PyGraphics.hpp"

#include <structmember.h>

namespace ACLIB
{
    PyObject* graphics_new_(PyTypeObject* type, PyObject* args, PyObject* kwds)
    {
        PyGraphics* self;
        self = reinterpret_cast<PyGraphics*>(type->tp_alloc(type, 0));

        if(self != nullptr)
        {
            self->m_graphics = new SharedMemory<AC::Graphics>(AC::GRAPHICS_PAGE);
        }
        return reinterpret_cast<PyObject*>(self);
    }

    void graphics_del_(PyTypeObject* self)
    {
        delete reinterpret_cast<PyGraphics*>(self)->m_graphics;
        self->tp_free(self);
    }

    PyMemberDef GraphicsType_members[] = {{nullptr}};

    PyMethodDef GraphicsType_methods[] = {{nullptr}};

    static PyObject* get_packetId(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->packetId);
    }

    static PyObject* get_status(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(static_cast<AC::Uint32>(self->m_graphics->data()->status));
    }
    static PyObject* get_session(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(static_cast<AC::Uint32>(self->m_graphics->data()->session));
    }
    static PyObject* get_currentTime(PyGraphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->data()->currentTime,
            wcslen(self->m_graphics->data()->currentTime));
    }
    static PyObject* get_lastTime(PyGraphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->data()->lastTime,
            wcslen(self->m_graphics->data()->lastTime));
    }
    static PyObject* get_bestTime(PyGraphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->data()->bestTime,
            wcslen(self->m_graphics->data()->bestTime));
    }
    static PyObject* get_split(PyGraphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->data()->split,
            wcslen(self->m_graphics->data()->split));
    }
    static PyObject* get_completedLaps(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->completedLaps);
    }
    static PyObject* get_position(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->position);
    }
    static PyObject* get_iCurrentTime(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->iCurrentTime);
    }
    static PyObject* get_iLastTime(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->iLastTime);
    }
    static PyObject* get_iBestTime(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->iBestTime);
    }
    static PyObject* get_sessionTimeLeft(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->sessionTimeLeft);
    }
    static PyObject* get_distanceTraveled(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->distanceTraveled);
    }
    static PyObject* get_isInPit(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->isInPit);
    }
    static PyObject* get_currentSectorIndex(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->currentSectorIndex);
    }
    static PyObject* get_lastSectorTime(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->lastSectorTime);
    }
    static PyObject* get_numberOfLaps(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->numberOfLaps);
    }
    static PyObject* get_tyreCompound(PyGraphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->data()->tyreCompound,
            wcslen(self->m_graphics->data()->tyreCompound));
    }
    static PyObject* get_replayTimeMultiplier(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->replayTimeMultiplier);
    }
    static PyObject* get_normalizedCarPosition(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->normalizedCarPosition);
    }
    static PyObject* get_carCoordinates(PyGraphics* self, void* closure)
    {
        return Py_BuildValue(
            "[fff]",
            self->m_graphics->data()->carCoordinates[0],
            self->m_graphics->data()->carCoordinates[1],
            self->m_graphics->data()->carCoordinates[2]);
    }
    static PyObject* get_penaltyTime(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->penaltyTime);
    }
    static PyObject* get_flag(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->flag);
    }
    static PyObject* get_idealLineOn(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->idealLineOn);
    }
    static PyObject* get_isInPitLine(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->isInPitLine);
    }
    static PyObject* get_surfaceGrip(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->surfaceGrip);
    }
    static PyObject* get_mandatoryPitDone(PyGraphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->data()->mandatoryPitDone);
    }
    static PyObject* get_windSpeed(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->windSpeed);
    }
    static PyObject* get_windDirection(PyGraphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->data()->windDirection);
    }

    static PyGetSetDef GraphicsType_getset[] = {
        {"packetId", (getter)get_packetId, nullptr, "", nullptr},
        {"status", (getter)get_status, nullptr, "", nullptr},
        {"session", (getter)get_session, nullptr, "", nullptr},
        {"currentTime", (getter)get_currentTime, nullptr, "", nullptr},
        {"lastTime", (getter)get_lastTime, nullptr, "", nullptr},
        {"bestTime", (getter)get_bestTime, nullptr, "", nullptr},
        {"split", (getter)get_split, nullptr, "", nullptr},
        {"completedLaps", (getter)get_completedLaps, nullptr, "", nullptr},
        {"position", (getter)get_position, nullptr, "", nullptr},
        {"iCurrentTime", (getter)get_iCurrentTime, nullptr, "", nullptr},
        {"iLastTime", (getter)get_iLastTime, nullptr, "", nullptr},
        {"iBestTime", (getter)get_iBestTime, nullptr, "", nullptr},
        {"sessionTimeLeft", (getter)get_sessionTimeLeft, nullptr, "", nullptr},
        {"distanceTraveled", (getter)get_distanceTraveled, nullptr, "", nullptr},
        {"isInPit", (getter)get_isInPit, nullptr, "", nullptr},
        {"currentSectorIndex", (getter)get_currentSectorIndex, nullptr, "", nullptr},
        {"lastSectorTime", (getter)get_lastSectorTime, nullptr, "", nullptr},
        {"numberOfLaps", (getter)get_numberOfLaps, nullptr, "", nullptr},
        {"tyreCompound", (getter)get_tyreCompound, nullptr, "", nullptr},
        {"replayTimeMultiplier", (getter)get_replayTimeMultiplier, nullptr, "", nullptr},
        {"normalizedCarPosition", (getter)get_normalizedCarPosition, nullptr, "", nullptr},
        {"carCoordinates", (getter)get_carCoordinates, nullptr, "", nullptr},
        {"penaltyTime", (getter)get_penaltyTime, nullptr, "", nullptr},
        {"flag", (getter)get_flag, nullptr, "", nullptr},
        {"idealLineOn", (getter)get_idealLineOn, nullptr, "", nullptr},
        {"isInPitLine", (getter)get_isInPitLine, nullptr, "", nullptr},
        {"surfaceGrip", (getter)get_surfaceGrip, nullptr, "", nullptr},
        {"mandatoryPitDone", (getter)get_mandatoryPitDone, nullptr, "", nullptr},
        {"windSpeed", (getter)get_windSpeed, nullptr, "", nullptr},
        {"windDirection", (getter)get_windDirection, nullptr, "", nullptr},
        {nullptr}};

    PyTypeObject GraphicsType = {
        PyObject_HEAD_INIT(&PyType_Type) "aclib_shared_memory.Graphics", /* tp_name */
        sizeof(PyGraphics),                                              /* tp_basicsize */
        0,                                                               /* tp_itemsize */
        (destructor)graphics_del_,                                       /* tp_dealloc */
        0,                                                               /* tp_print */
        nullptr,                                                         /* tp_getattr */
        nullptr,                                                         /* tp_setattr */
        nullptr,                                                         /* tp_reserved */
        nullptr,                                                         /* tp_repr */
        nullptr,                                                         /* tp_as_number */
        nullptr,                                                         /* tp_as_sequence */
        nullptr,                                                         /* tp_as_mapping */
        nullptr,                                                         /* tp_hash */
        nullptr,                                                         /* tp_call */
        nullptr,                                                         /* tp_str */
        nullptr,                                                         /* tp_getattro */
        nullptr,                                                         /* tp_setattro */
        nullptr,                                                         /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,                                              /* tp_flags */
        nullptr,                                                         /* tp_doc */
        nullptr,                                                         /* tp_traverse */
        nullptr,                                                         /* tp_clear */
        nullptr,                                                         /* tp_richcompare */
        0,                                                               /* tp_weaklistoffset */
        nullptr,                                                         /* tp_iter */
        nullptr,                                                         /* tp_iternext */
        GraphicsType_methods,                                            /* tp_methods */
        GraphicsType_members,                                            /* tp_members */
        GraphicsType_getset,                                             /* tp_getset */
        nullptr,                                                         /* tp_base */
        nullptr,                                                         /* tp_dict */
        nullptr,                                                         /* tp_descr_get */
        nullptr,                                                         /* tp_descr_set */
        0,                                                               /* tp_dictoffset */
        nullptr,                                                         /* tp_init */
        nullptr,                                                         /* tp_alloc */
        (newfunc)graphics_new_,                                          /* tp_new */
    };
}  // namespace ACLIB
