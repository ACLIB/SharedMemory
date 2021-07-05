#ifndef ACLIB_SHARED_MEMORY_PYSTATICS_HPP
#define ACLIB_SHARED_MEMORY_PYSTATICS_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"
#include "python/PyClassType.hpp"

namespace ACLIB
{
    class PyStatics : public PyClassType
    {
    public:
        SharedMemory<AC::Statics>* m_statics;

        explicit PyStatics(const char* name)
            : PyClassType(name)
        {
        }

        virtual bool init(PyObject* module)
        {
            m_type.tp_basicsize = sizeof(PyStatics);
            m_type.tp_new       = (newfunc)PyStatics::_new;
            m_type.tp_dealloc   = (destructor)PyStatics::_del;

            return PyClassType::init(module);
        }

        /**
         * Memory Management
         */

        static PyObject* _new(PyTypeObject* type, PyObject* args, PyObject* kwds)
        {
            auto self = reinterpret_cast<PyStatics*>(type->tp_alloc(type, 0));
            if(self != nullptr)
            {
                self->m_statics = new SharedMemory<AC::Statics>(AC::STATICS_PAGE);;
            }
            return reinterpret_cast<PyObject*>(self);
        }

        static void _del(PyTypeObject* type)
        {
            auto self = reinterpret_cast<PyStatics*>(type);
            if(self != nullptr)
            {
                delete self->m_statics;
            }
            Py_TYPE(type)->tp_free(reinterpret_cast<PyObject*>(type));
        }

        /**
         * Custom class type functions
         */

        static PyObject* get_smVersion(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->smVersion,
                wcslen(self->m_statics->data()->smVersion));
        }
        static PyObject* get_acVersion(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->acVersion,
                wcslen(self->m_statics->data()->acVersion));
        }
        static PyObject* get_numberOfSessions(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->numberOfSessions);
        }
        static PyObject* get_numCars(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->numCars);
        }
        static PyObject* get_carModel(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->carModel,
                wcslen(self->m_statics->data()->carModel));
        }
        static PyObject* get_track(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->track,
                wcslen(self->m_statics->data()->track));
        }
        static PyObject* get_playerName(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->playerName,
                wcslen(self->m_statics->data()->playerName));
        }
        static PyObject* get_playerSurname(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->playerSurname,
                wcslen(self->m_statics->data()->playerSurname));
        }
        static PyObject* get_playerNick(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->playerNick,
                wcslen(self->m_statics->data()->playerNick));
        }
        static PyObject* get_sectorCount(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->sectorCount);
        }
        static PyObject* get_maxTorque(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->maxTorque);
        }
        static PyObject* get_maxPower(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->maxPower);
        }
        static PyObject* get_maxRpm(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->maxRpm);
        }
        static PyObject* get_maxFuel(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->maxFuel);
        }
        static PyObject* get_suspensionMaxTravel(PyStatics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_statics->data()->suspensionMaxTravel[0],
                self->m_statics->data()->suspensionMaxTravel[1],
                self->m_statics->data()->suspensionMaxTravel[2],
                self->m_statics->data()->suspensionMaxTravel[3]);
        }
        static PyObject* get_tyreRadius(PyStatics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_statics->data()->tyreRadius[0],
                self->m_statics->data()->tyreRadius[1],
                self->m_statics->data()->tyreRadius[2],
                self->m_statics->data()->tyreRadius[3]);
        }

        static PyObject* get_maxTurboBoost(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->maxTurboBoost);
        }
        static PyObject* get_airTemp(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->airTemp);
        }
        static PyObject* get_roadTemp(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->roadTemp);
        }
        static PyObject* get_penaltiesEnabled(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->penaltiesEnabled);
        }
        static PyObject* get_aidFuelRate(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->aidFuelRate);
        }
        static PyObject* get_aidTireRate(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->aidTireRate);
        }
        static PyObject* get_aidMechanicalDamage(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->aidMechanicalDamage);
        }
        static PyObject* get_aidAllowTyreBlankets(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->aidAllowTyreBlankets);
        }
        static PyObject* get_aidStability(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->aidStability);
        }
        static PyObject* get_aidAutoClutch(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->aidAutoClutch);
        }
        static PyObject* get_aidAutoBlip(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->aidAutoBlip);
        }
        static PyObject* get_hasDRS(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->hasDRS);
        }
        static PyObject* get_hasERS(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->hasERS);
        }
        static PyObject* get_hasKERS(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->hasKERS);
        }
        static PyObject* get_kersMaxJ(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->kersMaxJ);
        }
        static PyObject* get_engineBrakeSettingsCount(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->engineBrakeSettingsCount);
        }
        static PyObject* get_ersPowerControllerCount(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->ersPowerControllerCount);
        }
        static PyObject* get_trackSPlineLength(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->trackSPlineLength);
        }
        static PyObject* get_trackConfiguration(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->trackConfiguration,
                wcslen(self->m_statics->data()->trackConfiguration));
        }
        static PyObject* get_ersMaxJ(PyStatics* self, void*)
        {
            return PyFloat_FromDouble(self->m_statics->data()->ersMaxJ);
        }
        static PyObject* get_isTimedRace(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->isTimedRace);
        }
        static PyObject* get_hasExtraLap(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->hasExtraLap);
        }
        static PyObject* get_carSkin(PyStatics* self, void*)
        {
            return PyUnicode_FromWideChar(
                self->m_statics->data()->carSkin,
                wcslen(self->m_statics->data()->carSkin));
        }
        static PyObject* get_reversedGridPositions(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->reversedGridPositions);
        }
        static PyObject* get_pitWindowStart(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->pitWindowStart);
        }
        static PyObject* get_pitWindowEnd(PyStatics* self, void*)
        {
            return PyLong_FromLong(self->m_statics->data()->pitWindowEnd);
        }
    };
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYSTATICS_HPP
