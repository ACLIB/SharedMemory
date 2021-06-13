#ifndef ACLIB_SHARED_MEMORY_PYPHYSICS_HPP
#define ACLIB_SHARED_MEMORY_PYPHYSICS_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"
#include "python/PyClassType.hpp"

namespace ACLIB
{
    class PyPhysics : public PyClassType
    {
    public:
        SharedMemory<AC::Physics>* m_physics;

        explicit PyPhysics(const char* name)
            : PyClassType(name)
        {
        }

        virtual bool init(PyObject* module)
        {
            // MSVC c99 :/
            PyMethodDef method_sentinel = {nullptr};
            PyMemberDef member_sentinel = {nullptr};
            PyGetSetDef getset_sentinel = {nullptr};
            m_methods.emplace_back(method_sentinel);
            m_members.emplace_back(member_sentinel);
            m_getset.emplace_back(getset_sentinel);

            PyVarObject ob_base = ACLIBPyObject_HEAD_INIT(&PyType_Type);
            m_type.ob_base      = ob_base;
            m_type.tp_name      = m_class_name;
            m_type.tp_basicsize = sizeof(PyPhysics);
            m_type.tp_flags     = Py_TPFLAGS_DEFAULT;
            m_type.tp_new       = (newfunc)_new;
            m_type.tp_dealloc   = (destructor)_del;
            m_type.tp_init      = (initproc)_init;
            m_type.tp_methods   = m_methods.data();
            m_type.tp_members   = m_members.data();
            m_type.tp_getset    = m_getset.data();

            if(module == nullptr)
            {
                INFO("Call init() before adding class types.");
                return false;
            }

            bool success = true;

            // Init class
            success &= PyType_Ready(&m_type) >= 0;

            // Add class object
            success &=
                PyModule_AddObject(module, m_type.tp_name, reinterpret_cast<PyObject*>(&m_type)) >= 0;

            if(!success)
                INFO("Could not initialize class.");

            return success;
        }
        
        /**
         * Memory Management
         */

        static PyObject* _new(PyTypeObject* type, PyObject* args, PyObject* kwds)
        {
            PyPhysics* self;
            self = reinterpret_cast<PyPhysics*>(type->tp_alloc(type, 0));

            if(self != nullptr)
            {
                self->m_physics = new SharedMemory<AC::Physics>(AC::PHYSICS_PAGE);
            }
            return reinterpret_cast<PyObject*>(self);
        }

        static void _del(PyTypeObject* self)
        {
            delete reinterpret_cast<PyPhysics*>(self)->m_physics;
            self->tp_free(self);
        }
        
        /**
         * Custom class type functions
         */

        static PyObject* get_packetId(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->packetId);
        }
        static PyObject* get_gas(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->gas);
        }
        static PyObject* get_brake(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->brake);
        }
        static PyObject* get_fuel(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->fuel);
        }
        static PyObject* get_gear(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->gear);
        }
        static PyObject* get_rpm(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->rpm);
        }
        static PyObject* get_steerAngle(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->steerAngle);
        }
        static PyObject* get_speedKmh(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->speedKmh);
        }
        static PyObject* get_velocity(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[fff]",
                self->m_physics->data()->velocity[0],
                self->m_physics->data()->velocity[1],
                self->m_physics->data()->velocity[2]);
        }
        static PyObject* get_accG(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[fff]",
                self->m_physics->data()->accG[0],
                self->m_physics->data()->accG[1],
                self->m_physics->data()->accG[2]);
        }
        static PyObject* get_wheelSlip(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->wheelSlip[0],
                self->m_physics->data()->wheelSlip[1],
                self->m_physics->data()->wheelSlip[2],
                self->m_physics->data()->wheelSlip[3]);
        }
        static PyObject* get_wheelLoad(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->wheelLoad[0],
                self->m_physics->data()->wheelLoad[1],
                self->m_physics->data()->wheelLoad[2],
                self->m_physics->data()->wheelLoad[3]);
        }
        static PyObject* get_wheelsPressure(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->wheelsPressure[0],
                self->m_physics->data()->wheelsPressure[1],
                self->m_physics->data()->wheelsPressure[2],
                self->m_physics->data()->wheelsPressure[3]);
        }
        static PyObject* get_wheelAngularSpeed(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->wheelAngularSpeed[0],
                self->m_physics->data()->wheelAngularSpeed[1],
                self->m_physics->data()->wheelAngularSpeed[2],
                self->m_physics->data()->wheelAngularSpeed[3]);
        }
        static PyObject* get_tyreWear(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->tyreWear[0],
                self->m_physics->data()->tyreWear[1],
                self->m_physics->data()->tyreWear[2],
                self->m_physics->data()->tyreWear[3]);
        }
        static PyObject* get_tyreDirtyLevel(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->tyreDirtyLevel[0],
                self->m_physics->data()->tyreDirtyLevel[1],
                self->m_physics->data()->tyreDirtyLevel[2],
                self->m_physics->data()->tyreDirtyLevel[3]);
        }
        static PyObject* get_tyreCoreTemperature(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->tyreCoreTemperature[0],
                self->m_physics->data()->tyreCoreTemperature[1],
                self->m_physics->data()->tyreCoreTemperature[2],
                self->m_physics->data()->tyreCoreTemperature[3]);
        }
        static PyObject* get_camberRAD(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->camberRAD[0],
                self->m_physics->data()->camberRAD[1],
                self->m_physics->data()->camberRAD[2],
                self->m_physics->data()->camberRAD[3]);
        }
        static PyObject* get_suspensionTravel(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->suspensionTravel[0],
                self->m_physics->data()->suspensionTravel[1],
                self->m_physics->data()->suspensionTravel[2],
                self->m_physics->data()->suspensionTravel[3]);
        }
        static PyObject* get_drs(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->drs);
        }
        static PyObject* get_tc(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->tc);
        }
        static PyObject* get_heading(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->heading);
        }
        static PyObject* get_pitch(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->pitch);
        }
        static PyObject* get_roll(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->roll);
        }
        static PyObject* get_cgHeight(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->cgHeight);
        }
        static PyObject* get_carDamage(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[fffff]",
                self->m_physics->data()->carDamage[0],
                self->m_physics->data()->carDamage[1],
                self->m_physics->data()->carDamage[2],
                self->m_physics->data()->carDamage[3],
                self->m_physics->data()->carDamage[4]);
        }
        static PyObject* get_numberOfTyresOut(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->numberOfTyresOut);
        }
        static PyObject* get_pitLimiterOn(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->pitLimiterOn);
        }
        static PyObject* get_abs(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->abs);
        }
        static PyObject* get_kersCharge(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->kersCharge);
        }
        static PyObject* get_kersInput(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->kersInput);
        }
        static PyObject* get_autoShifterOn(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->autoShifterOn);
        }
        static PyObject* get_rideHeight(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ff]",
                self->m_physics->data()->rideHeight[0],
                self->m_physics->data()->rideHeight[1]);
        }
        static PyObject* get_turboBoost(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->turboBoost);
        }
        static PyObject* get_ballast(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->ballast);
        }
        static PyObject* get_airDensity(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->airDensity);
        }
        static PyObject* get_airTemp(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->airTemp);
        }
        static PyObject* get_roadTemp(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->roadTemp);
        }
        static PyObject* get_localAngularVel(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[fff]",
                self->m_physics->data()->localAngularVel[0],
                self->m_physics->data()->localAngularVel[1],
                self->m_physics->data()->localAngularVel[2]);
        }
        static PyObject* get_finalFF(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->finalFF);
        }
        static PyObject* get_performanceMeter(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->performanceMeter);
        }
        static PyObject* get_engineBrake(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->engineBrake);
        }
        static PyObject* get_ersRecoveryLevel(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->ersRecoveryLevel);
        }
        static PyObject* get_ersPowerLevel(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->ersPowerLevel);
        }
        static PyObject* get_ersHeatCharging(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->ersHeatCharging);
        }
        static PyObject* get_ersIsCharging(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->ersIsCharging);
        }
        static PyObject* get_kersCurrentKJ(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->kersCurrentKJ);
        }
        static PyObject* get_drsAvailable(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->drsAvailable);
        }
        static PyObject* get_drsEnabled(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->drsEnabled);
        }
        static PyObject* get_brakeTemp(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->brakeTemp[0],
                self->m_physics->data()->brakeTemp[1],
                self->m_physics->data()->brakeTemp[2],
                self->m_physics->data()->brakeTemp[3]);
        }
        static PyObject* get_clutch(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->clutch);
        }
        static PyObject* get_tyreTempI(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->tyreTempI[0],
                self->m_physics->data()->tyreTempI[1],
                self->m_physics->data()->tyreTempI[2],
                self->m_physics->data()->tyreTempI[3]);
        }
        static PyObject* get_tyreTempM(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->tyreTempM[0],
                self->m_physics->data()->tyreTempM[1],
                self->m_physics->data()->tyreTempM[2],
                self->m_physics->data()->tyreTempM[3]);
        }
        static PyObject* get_tyreTempO(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffff]",
                self->m_physics->data()->tyreTempO[0],
                self->m_physics->data()->tyreTempO[1],
                self->m_physics->data()->tyreTempO[2],
                self->m_physics->data()->tyreTempO[3]);
        }
        static PyObject* get_isAIControlled(PyPhysics* self, void*)
        {
            return PyLong_FromLong(self->m_physics->data()->isAIControlled);
        }
        static PyObject* get_tyreContactPoint(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffffffffffff]",
                self->m_physics->data()->tyreContactPoint[0],
                self->m_physics->data()->tyreContactPoint[1],
                self->m_physics->data()->tyreContactPoint[2],
                self->m_physics->data()->tyreContactPoint[3],
                self->m_physics->data()->tyreContactPoint[4],
                self->m_physics->data()->tyreContactPoint[5],
                self->m_physics->data()->tyreContactPoint[6],
                self->m_physics->data()->tyreContactPoint[7],
                self->m_physics->data()->tyreContactPoint[8],
                self->m_physics->data()->tyreContactPoint[9],
                self->m_physics->data()->tyreContactPoint[10],
                self->m_physics->data()->tyreContactPoint[11]);
        }
        static PyObject* get_tyreContactNormal(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffffffffffff]",
                self->m_physics->data()->tyreContactNormal[0],
                self->m_physics->data()->tyreContactNormal[1],
                self->m_physics->data()->tyreContactNormal[2],
                self->m_physics->data()->tyreContactNormal[3],
                self->m_physics->data()->tyreContactNormal[4],
                self->m_physics->data()->tyreContactNormal[5],
                self->m_physics->data()->tyreContactNormal[6],
                self->m_physics->data()->tyreContactNormal[7],
                self->m_physics->data()->tyreContactNormal[8],
                self->m_physics->data()->tyreContactNormal[9],
                self->m_physics->data()->tyreContactNormal[10],
                self->m_physics->data()->tyreContactNormal[11]);
        }
        static PyObject* get_tyreContactHeading(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[ffffffffffff]",
                self->m_physics->data()->tyreContactHeading[0],
                self->m_physics->data()->tyreContactHeading[1],
                self->m_physics->data()->tyreContactHeading[2],
                self->m_physics->data()->tyreContactHeading[3],
                self->m_physics->data()->tyreContactHeading[4],
                self->m_physics->data()->tyreContactHeading[5],
                self->m_physics->data()->tyreContactHeading[6],
                self->m_physics->data()->tyreContactHeading[7],
                self->m_physics->data()->tyreContactHeading[8],
                self->m_physics->data()->tyreContactHeading[9],
                self->m_physics->data()->tyreContactHeading[10],
                self->m_physics->data()->tyreContactHeading[11]);
        }
        static PyObject* get_brakeBias(PyPhysics* self, void*)
        {
            return PyFloat_FromDouble(self->m_physics->data()->brakeBias);
        }
        static PyObject* get_localVelocity(PyPhysics* self, void*)
        {
            return Py_BuildValue(
                "[fff]",
                self->m_physics->data()->localVelocity[0],
                self->m_physics->data()->localVelocity[1],
                self->m_physics->data()->localVelocity[2]);
        }
    };
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYPHYSICS_HPP
