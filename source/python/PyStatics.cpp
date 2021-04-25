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
            self->m_statics = SharedMemory<AC::Statics>(AC::STATICS_PAGE);
        }
        return reinterpret_cast<PyObject*>(self);
    }

    void statics_del_(PyTypeObject* self)
    {
        self->tp_free(self);
    }

    PyMemberDef StaticsType_members[] = {{nullptr}};

    PyMethodDef StaticsType_methods[] = {{nullptr}};

    static PyObject* get_smVersion(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->smVersion, wcslen(self->m_statics->smVersion));
    }
    static PyObject* get_acVersion(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->acVersion, wcslen(self->m_statics->acVersion));
    }
    static PyObject* get_numberOfSessions(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->numberOfSessions);
    }
    static PyObject* get_numCars(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->numCars);
    }
    static PyObject* get_carModel(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->carModel, wcslen(self->m_statics->carModel));
    }
    static PyObject* get_track(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->track, wcslen(self->m_statics->track));
    }
    static PyObject* get_playerName(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->playerName,
            wcslen(self->m_statics->playerName));
    }
    static PyObject* get_playerSurname(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->playerSurname,
            wcslen(self->m_statics->playerSurname));
    }
    static PyObject* get_playerNick(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->playerNick,
            wcslen(self->m_statics->playerNick));
    }
    static PyObject* get_sectorCount(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->sectorCount);
    }
    static PyObject* get_maxTorque(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->maxTorque);
    }
    static PyObject* get_maxPower(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->maxPower);
    }
    static PyObject* get_maxRpm(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->maxRpm);
    }
    static PyObject* get_maxFuel(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->maxFuel);
    }
    static PyObject* get_suspensionMaxTravel(PyStatics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_statics->suspensionMaxTravel[0],
            self->m_statics->suspensionMaxTravel[1],
            self->m_statics->suspensionMaxTravel[2],
            self->m_statics->suspensionMaxTravel[3]);
    }
    static PyObject* get_tyreRadius(PyStatics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_statics->tyreRadius[0],
            self->m_statics->tyreRadius[1],
            self->m_statics->tyreRadius[2],
            self->m_statics->tyreRadius[3]);
    }

    static PyObject* get_maxTurboBoost(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->maxTurboBoost);
    }
    static PyObject* get_airTemp(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->airTemp);
    }
    static PyObject* get_roadTemp(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->roadTemp);
    }
    static PyObject* get_penaltiesEnabled(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->penaltiesEnabled);
    }
    static PyObject* get_aidFuelRate(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->aidFuelRate);
    }
    static PyObject* get_aidTireRate(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->aidTireRate);
    }
    static PyObject* get_aidMechanicalDamage(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->aidMechanicalDamage);
    }
    static PyObject* get_aidAllowTyreBlankets(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->aidAllowTyreBlankets);
    }
    static PyObject* get_aidStability(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->aidStability);
    }
    static PyObject* get_aidAutoClutch(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->aidAutoClutch);
    }
    static PyObject* get_aidAutoBlip(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->aidAutoBlip);
    }
    static PyObject* get_hasDRS(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->hasDRS);
    }
    static PyObject* get_hasERS(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->hasERS);
    }
    static PyObject* get_hasKERS(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->hasKERS);
    }
    static PyObject* get_kersMaxJ(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->kersMaxJ);
    }
    static PyObject* get_engineBrakeSettingsCount(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->engineBrakeSettingsCount);
    }
    static PyObject* get_ersPowerControllerCount(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->ersPowerControllerCount);
    }
    static PyObject* get_trackSPlineLength(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->trackSPlineLength);
    }
    static PyObject* get_trackConfiguration(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->trackConfiguration,
            wcslen(self->m_statics->trackConfiguration));
    }
    static PyObject* get_ersMaxJ(PyStatics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->ersMaxJ);
    }
    static PyObject* get_isTimedRace(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->isTimedRace);
    }
    static PyObject* get_hasExtraLap(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->hasExtraLap);
    }
    static PyObject* get_carSkin(PyStatics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->carSkin, wcslen(self->m_statics->carSkin));
    }
    static PyObject* get_reversedGridPositions(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->reversedGridPositions);
    }
    static PyObject* get_pitWindowStart(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->pitWindowStart);
    }
    static PyObject* get_pitWindowEnd(PyStatics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->pitWindowEnd);
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
        PyVarObject_HEAD_INIT(&PyType_Type, 0) "aclib_shared_memory.Statics", /* tp_name */
        sizeof(PyStatics),                                             /* tp_basicsize */
        0,                                                             /* tp_itemsize */
        nullptr,                                                       /* tp_dealloc */
        0,                                                             /* tp_print */
        nullptr,                                                       /* tp_getattr */
        nullptr,                                                       /* tp_setattr */
        nullptr,                                                       /* tp_reserved */
        nullptr,                                                       /* tp_repr */
        nullptr,                                                       /* tp_as_number */
        nullptr,                                                       /* tp_as_sequence */
        nullptr,                                                       /* tp_as_mapping */
        nullptr,                                                       /* tp_hash */
        nullptr,                                                       /* tp_call */
        nullptr,                                                       /* tp_str */
        nullptr,                                                       /* tp_getattro */
        nullptr,                                                       /* tp_setattro */
        nullptr,                                                       /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,                                            /* tp_flags */
        nullptr,                                                       /* tp_doc */
        nullptr,                                                       /* tp_traverse */
        nullptr,                                                       /* tp_clear */
        nullptr,                                                       /* tp_richcompare */
        0,                                                             /* tp_weaklistoffset */
        nullptr,                                                       /* tp_iter */
        nullptr,                                                       /* tp_iternext */
        StaticsType_methods,                                           /* tp_methods */
        StaticsType_members,                                           /* tp_members */
        StaticsType_getset,                                            /* tp_getset */
        nullptr,                                                       /* tp_base */
        nullptr,                                                       /* tp_dict */
        nullptr,                                                       /* tp_descr_get */
        nullptr,                                                       /* tp_descr_set */
        0,                                                             /* tp_dictoffset */
        nullptr,                                                       /* tp_init */
        nullptr,                                                       /* tp_alloc */
        (newfunc)statics_new_,                                         /* tp_new */
    };
}  // namespace ACLIB
