#include "PyStatics.hpp"

#include <structmember.h>

namespace ACLIB
{
    PyObject* statics_new_(PyTypeObject* type, PyObject* args, PyObject* kwds)
    {
        PyStatics* self;
        self = reinterpret_cast<PyStatics*>(type->tp_alloc(type, 0));

        if(self != nullptr)
        {
            self->m_statics = new SharedMemory<AC::Statics>(AC::STATICS_PAGE);
        }
        return reinterpret_cast<PyObject*>(self);
    }

    void statics_del_(PyTypeObject* self)
    {
        delete reinterpret_cast<PyStatics*>(self);
        self->tp_free(self);
    }

    PyMemberDef StaticsType_members[] = {{nullptr}};

    PyMethodDef StaticsType_methods[] = {{nullptr}};

    static PyObject* get_smVersion(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->smVersion,
            wcslen(self->m_statics->data()->smVersion));
    }
    static PyObject* get_acVersion(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->acVersion,
            wcslen(self->m_statics->data()->acVersion));
    }
    static PyObject* get_numberOfSessions(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->numberOfSessions);
    }
    static PyObject* get_numCars(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->numCars);
    }
    static PyObject* get_carModel(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->carModel,
            wcslen(self->m_statics->data()->carModel));
    }
    static PyObject* get_track(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->track,
            wcslen(self->m_statics->data()->track));
    }
    static PyObject* get_playerName(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->playerName,
            wcslen(self->m_statics->data()->playerName));
    }
    static PyObject* get_playerSurname(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->playerSurname,
            wcslen(self->m_statics->data()->playerSurname));
    }
    static PyObject* get_playerNick(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->playerNick,
            wcslen(self->m_statics->data()->playerNick));
    }
    static PyObject* get_sectorCount(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->sectorCount);
    }
    static PyObject* get_maxTorque(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->maxTorque);
    }
    static PyObject* get_maxPower(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->maxPower);
    }
    static PyObject* get_maxRpm(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->maxRpm);
    }
    static PyObject* get_maxFuel(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->maxFuel);
    }
    static PyObject* get_suspensionMaxTravel(PyStatics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_statics->data()->suspensionMaxTravel[0],
            self->m_statics->data()->suspensionMaxTravel[1],
            self->m_statics->data()->suspensionMaxTravel[2],
            self->m_statics->data()->suspensionMaxTravel[3]);
    }
    static PyObject* get_tyreRadius(PyStatics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_statics->data()->tyreRadius[0],
            self->m_statics->data()->tyreRadius[1],
            self->m_statics->data()->tyreRadius[2],
            self->m_statics->data()->tyreRadius[3]);
    }

    static PyObject* get_maxTurboBoost(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->maxTurboBoost);
    }
    static PyObject* get_airTemp(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->airTemp);
    }
    static PyObject* get_roadTemp(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->roadTemp);
    }
    static PyObject* get_penaltiesEnabled(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->penaltiesEnabled);
    }
    static PyObject* get_aidFuelRate(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->aidFuelRate);
    }
    static PyObject* get_aidTireRate(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->aidTireRate);
    }
    static PyObject* get_aidMechanicalDamage(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->aidMechanicalDamage);
    }
    static PyObject* get_aidAllowTyreBlankets(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->aidAllowTyreBlankets);
    }
    static PyObject* get_aidStability(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->aidStability);
    }
    static PyObject* get_aidAutoClutch(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->aidAutoClutch);
    }
    static PyObject* get_aidAutoBlip(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->aidAutoBlip);
    }
    static PyObject* get_hasDRS(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->hasDRS);
    }
    static PyObject* get_hasERS(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->hasERS);
    }
    static PyObject* get_hasKERS(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->hasKERS);
    }
    static PyObject* get_kersMaxJ(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->kersMaxJ);
    }
    static PyObject* get_engineBrakeSettingsCount(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->engineBrakeSettingsCount);
    }
    static PyObject* get_ersPowerControllerCount(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->ersPowerControllerCount);
    }
    static PyObject* get_trackSPlineLength(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->trackSPlineLength);
    }
    static PyObject* get_trackConfiguration(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->trackConfiguration,
            wcslen(self->m_statics->data()->trackConfiguration));
    }
    static PyObject* get_ersMaxJ(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->data()->ersMaxJ);
    }
    static PyObject* get_isTimedRace(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->isTimedRace);
    }
    static PyObject* get_hasExtraLap(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->hasExtraLap);
    }
    static PyObject* get_carSkin(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->data()->carSkin,
            wcslen(self->m_statics->data()->carSkin));
    }
    static PyObject* get_reversedGridPositions(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->reversedGridPositions);
    }
    static PyObject* get_pitWindowStart(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->pitWindowStart);
    }
    static PyObject* get_pitWindowEnd(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->data()->pitWindowEnd);
    }

    static PyGetSetDef StaticsType_getset[] = {
        {"smVersion", (getter)get_smVersion, nullptr, "", nullptr},
        {"acVersion", (getter)get_acVersion, nullptr, "", nullptr},
        {"numberOfSessions", (getter)get_numberOfSessions, nullptr, "", nullptr},
        {"numCars", (getter)get_numCars, nullptr, "", nullptr},
        {"carModel", (getter)get_carModel, nullptr, "", nullptr},
        {"track", (getter)get_track, nullptr, "", nullptr},
        {"playerName", (getter)get_playerName, nullptr, "", nullptr},
        {"playerSurname", (getter)get_playerSurname, nullptr, "", nullptr},
        {"playerNick", (getter)get_playerNick, nullptr, "", nullptr},
        {"sectorCount", (getter)get_sectorCount, nullptr, "", nullptr},
        {"maxTorque", (getter)get_maxTorque, nullptr, "", nullptr},
        {"maxPower", (getter)get_maxPower, nullptr, "", nullptr},
        {"maxRpm", (getter)get_maxRpm, nullptr, "", nullptr},
        {"maxFuel", (getter)get_maxFuel, nullptr, "", nullptr},
        {"suspensionMaxTravel", (getter)get_suspensionMaxTravel, nullptr, "", nullptr},
        {"tyreRadius", (getter)get_tyreRadius, nullptr, "", nullptr},
        {"maxTurboBoost", (getter)get_maxTurboBoost, nullptr, "", nullptr},
        {"airTemp", (getter)get_airTemp, nullptr, "", nullptr},
        {"roadTemp", (getter)get_roadTemp, nullptr, "", nullptr},
        {"penaltiesEnabled", (getter)get_penaltiesEnabled, nullptr, "", nullptr},
        {"aidFuelRate", (getter)get_aidFuelRate, nullptr, "", nullptr},
        {"aidTireRate", (getter)get_aidTireRate, nullptr, "", nullptr},
        {"aidMechanicalDamage", (getter)get_aidMechanicalDamage, nullptr, "", nullptr},
        {"aidAllowTyreBlankets", (getter)get_aidAllowTyreBlankets, nullptr, "", nullptr},
        {"aidStability", (getter)get_aidStability, nullptr, "", nullptr},
        {"aidAutoClutch", (getter)get_aidAutoClutch, nullptr, "", nullptr},
        {"aidAutoBlip", (getter)get_aidAutoBlip, nullptr, "", nullptr},
        {"hasDRS", (getter)get_hasDRS, nullptr, "", nullptr},
        {"hasERS", (getter)get_hasERS, nullptr, "", nullptr},
        {"hasKERS", (getter)get_hasKERS, nullptr, "", nullptr},
        {"kersMaxJ", (getter)get_kersMaxJ, nullptr, "", nullptr},
        {"engineBrakeSettingsCount", (getter)get_engineBrakeSettingsCount, nullptr, "", nullptr},
        {"ersPowerControllerCount", (getter)get_ersPowerControllerCount, nullptr, "", nullptr},
        {"trackSPlineLength", (getter)get_trackSPlineLength, nullptr, "", nullptr},
        {"trackConfiguration", (getter)get_trackConfiguration, nullptr, "", nullptr},
        {"ersMaxJ", (getter)get_ersMaxJ, nullptr, "", nullptr},
        {"isTimedRace", (getter)get_isTimedRace, nullptr, "", nullptr},
        {"hasExtraLap", (getter)get_hasExtraLap, nullptr, "", nullptr},
        {"carSkin", (getter)get_carSkin, nullptr, "", nullptr},
        {"reversedGridPositions", (getter)get_reversedGridPositions, nullptr, "", nullptr},
        {"pitWindowStart", (getter)get_pitWindowStart, nullptr, "", nullptr},
        {"pitWindowEnd", (getter)get_pitWindowEnd, nullptr, "", nullptr},
        {nullptr}};

    PyTypeObject StaticsType = {
        PyObject_HEAD_INIT(&PyType_Type) "aclib_shared_memory.Statics", /* tp_name */
        sizeof(PyStatics),                                              /* tp_basicsize */
        0,                                                              /* tp_itemsize */
        (destructor)statics_del_,                                       /* tp_dealloc */
        0,                                                              /* tp_print */
        nullptr,                                                        /* tp_getattr */
        nullptr,                                                        /* tp_setattr */
        nullptr,                                                        /* tp_reserved */
        nullptr,                                                        /* tp_repr */
        nullptr,                                                        /* tp_as_number */
        nullptr,                                                        /* tp_as_sequence */
        nullptr,                                                        /* tp_as_mapping */
        nullptr,                                                        /* tp_hash */
        nullptr,                                                        /* tp_call */
        nullptr,                                                        /* tp_str */
        nullptr,                                                        /* tp_getattro */
        nullptr,                                                        /* tp_setattro */
        nullptr,                                                        /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,                                             /* tp_flags */
        nullptr,                                                        /* tp_doc */
        nullptr,                                                        /* tp_traverse */
        nullptr,                                                        /* tp_clear */
        nullptr,                                                        /* tp_richcompare */
        0,                                                              /* tp_weaklistoffset */
        nullptr,                                                        /* tp_iter */
        nullptr,                                                        /* tp_iternext */
        StaticsType_methods,                                            /* tp_methods */
        StaticsType_members,                                            /* tp_members */
        StaticsType_getset,                                             /* tp_getset */
        nullptr,                                                        /* tp_base */
        nullptr,                                                        /* tp_dict */
        nullptr,                                                        /* tp_descr_get */
        nullptr,                                                        /* tp_descr_set */
        0,                                                              /* tp_dictoffset */
        nullptr,                                                        /* tp_init */
        nullptr,                                                        /* tp_alloc */
        (newfunc)statics_new_,                                          /* tp_new */
    };
}  // namespace ACLIB
