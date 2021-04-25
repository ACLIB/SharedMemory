#include "PyPhysics.hpp"

#include <structmember.h>

namespace ACLIB
{
    PyObject* physics_new_(PyTypeObject* type, PyObject* args, PyObject* kwds)
    {
        PyPhysics* self;
        self = reinterpret_cast<PyPhysics*>(type->tp_alloc(type, 0));

        if(self != nullptr)
        {
            self->m_physics = SharedMemory<AC::Physics>(AC::PHYSICS_PAGE);
        }
        return reinterpret_cast<PyObject*>(self);
    }

    void physics_del_(PyTypeObject* self)
    {
        self->tp_free(self);
    }

    int physics_init_(PyPhysics* self, PyObject* args, PyObject* kwds)
    {
        return 0;
    }

    PyMemberDef PhysicsType_members[] = {{nullptr}};

    PyMethodDef PhysicsType_methods[] = {{nullptr}};

    static PyObject* get_packetId(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->packetId);
    }
    static PyObject* get_gas(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->gas);
    }
    static PyObject* get_brake(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->brake);
    }
    static PyObject* get_fuel(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->fuel);
    }
    static PyObject* get_gear(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->gear);
    }
    static PyObject* get_rpm(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->rpm);
    }
    static PyObject* get_steerAngle(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->steerAngle);
    }
    static PyObject* get_speedKmh(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->speedKmh);
    }
    static PyObject* get_velocity(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[fff]",
            self->m_physics->velocity[0],
            self->m_physics->velocity[1],
            self->m_physics->velocity[2]);
    }
    static PyObject* get_accG(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[fff]",
            self->m_physics->accG[0],
            self->m_physics->accG[1],
            self->m_physics->accG[2]);
    }
    static PyObject* get_wheelSlip(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->wheelSlip[0],
            self->m_physics->wheelSlip[1],
            self->m_physics->wheelSlip[2],
            self->m_physics->wheelSlip[3]);
    }
    static PyObject* get_wheelLoad(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->wheelLoad[0],
            self->m_physics->wheelLoad[1],
            self->m_physics->wheelLoad[2],
            self->m_physics->wheelLoad[3]);
    }
    static PyObject* get_wheelsPressure(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->wheelsPressure[0],
            self->m_physics->wheelsPressure[1],
            self->m_physics->wheelsPressure[2],
            self->m_physics->wheelsPressure[3]);
    }
    static PyObject* get_wheelAngularSpeed(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->wheelAngularSpeed[0],
            self->m_physics->wheelAngularSpeed[1],
            self->m_physics->wheelAngularSpeed[2],
            self->m_physics->wheelAngularSpeed[3]);
    }
    static PyObject* get_tyreWear(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->tyreWear[0],
            self->m_physics->tyreWear[1],
            self->m_physics->tyreWear[2],
            self->m_physics->tyreWear[3]);
    }
    static PyObject* get_tyreDirtyLevel(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->tyreDirtyLevel[0],
            self->m_physics->tyreDirtyLevel[1],
            self->m_physics->tyreDirtyLevel[2],
            self->m_physics->tyreDirtyLevel[3]);
    }
    static PyObject* get_tyreCoreTemperature(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->tyreCoreTemperature[0],
            self->m_physics->tyreCoreTemperature[1],
            self->m_physics->tyreCoreTemperature[2],
            self->m_physics->tyreCoreTemperature[3]);
    }
    static PyObject* get_camberRAD(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->camberRAD[0],
            self->m_physics->camberRAD[1],
            self->m_physics->camberRAD[2],
            self->m_physics->camberRAD[3]);
    }
    static PyObject* get_suspensionTravel(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->suspensionTravel[0],
            self->m_physics->suspensionTravel[1],
            self->m_physics->suspensionTravel[2],
            self->m_physics->suspensionTravel[3]);
    }
    static PyObject* get_drs(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->drs);
    }
    static PyObject* get_tc(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->tc);
    }
    static PyObject* get_heading(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->heading);
    }
    static PyObject* get_pitch(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->pitch);
    }
    static PyObject* get_roll(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->roll);
    }
    static PyObject* get_cgHeight(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->cgHeight);
    }
    static PyObject* get_carDamage(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[fffff]",
            self->m_physics->carDamage[0],
            self->m_physics->carDamage[1],
            self->m_physics->carDamage[2],
            self->m_physics->carDamage[3],
            self->m_physics->carDamage[4]);
    }
    static PyObject* get_numberOfTyresOut(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->numberOfTyresOut);
    }
    static PyObject* get_pitLimiterOn(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->pitLimiterOn);
    }
    static PyObject* get_abs(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->abs);
    }
    static PyObject* get_kersCharge(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->kersCharge);
    }
    static PyObject* get_kersInput(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->kersInput);
    }
    static PyObject* get_autoShifterOn(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->autoShifterOn);
    }
    static PyObject* get_rideHeight(PyPhysics* self, void* closure)
    {
        return Py_BuildValue("[ff]", self->m_physics->rideHeight[0], self->m_physics->rideHeight[1]);
    }
    static PyObject* get_turboBoost(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->turboBoost);
    }
    static PyObject* get_ballast(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->ballast);
    }
    static PyObject* get_airDensity(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->airDensity);
    }
    static PyObject* get_airTemp(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->airTemp);
    }
    static PyObject* get_roadTemp(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->roadTemp);
    }
    static PyObject* get_localAngularVel(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[fff]",
            self->m_physics->localAngularVel[0],
            self->m_physics->localAngularVel[1],
            self->m_physics->localAngularVel[2]);
    }
    static PyObject* get_finalFF(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->finalFF);
    }
    static PyObject* get_performanceMeter(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->performanceMeter);
    }
    static PyObject* get_engineBrake(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->engineBrake);
    }
    static PyObject* get_ersRecoveryLevel(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->ersRecoveryLevel);
    }
    static PyObject* get_ersPowerLevel(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->ersPowerLevel);
    }
    static PyObject* get_ersHeatCharging(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->ersHeatCharging);
    }
    static PyObject* get_ersIsCharging(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->ersIsCharging);
    }
    static PyObject* get_kersCurrentKJ(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->kersCurrentKJ);
    }
    static PyObject* get_drsAvailable(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->drsAvailable);
    }
    static PyObject* get_drsEnabled(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->drsEnabled);
    }
    static PyObject* get_brakeTemp(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->brakeTemp[0],
            self->m_physics->brakeTemp[1],
            self->m_physics->brakeTemp[2],
            self->m_physics->brakeTemp[3]);
    }
    static PyObject* get_clutch(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->clutch);
    }
    static PyObject* get_tyreTempI(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->tyreTempI[0],
            self->m_physics->tyreTempI[1],
            self->m_physics->tyreTempI[2],
            self->m_physics->tyreTempI[3]);
    }
    static PyObject* get_tyreTempM(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->tyreTempM[0],
            self->m_physics->tyreTempM[1],
            self->m_physics->tyreTempM[2],
            self->m_physics->tyreTempM[3]);
    }
    static PyObject* get_tyreTempO(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_physics->tyreTempO[0],
            self->m_physics->tyreTempO[1],
            self->m_physics->tyreTempO[2],
            self->m_physics->tyreTempO[3]);
    }
    static PyObject* get_isAIControlled(PyPhysics* self, void* closure)
    {
        return PyLong_FromLong(self->m_physics->isAIControlled);
    }
    static PyObject* get_tyreContactPoint(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffffffffffff]",
            self->m_physics->tyreContactPoint[0],
            self->m_physics->tyreContactPoint[1],
            self->m_physics->tyreContactPoint[2],
            self->m_physics->tyreContactPoint[3],
            self->m_physics->tyreContactPoint[4],
            self->m_physics->tyreContactPoint[5],
            self->m_physics->tyreContactPoint[6],
            self->m_physics->tyreContactPoint[7],
            self->m_physics->tyreContactPoint[8],
            self->m_physics->tyreContactPoint[9],
            self->m_physics->tyreContactPoint[10],
            self->m_physics->tyreContactPoint[11]);
    }
    static PyObject* get_tyreContactNormal(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffffffffffff]",
            self->m_physics->tyreContactNormal[0],
            self->m_physics->tyreContactNormal[1],
            self->m_physics->tyreContactNormal[2],
            self->m_physics->tyreContactNormal[3],
            self->m_physics->tyreContactNormal[4],
            self->m_physics->tyreContactNormal[5],
            self->m_physics->tyreContactNormal[6],
            self->m_physics->tyreContactNormal[7],
            self->m_physics->tyreContactNormal[8],
            self->m_physics->tyreContactNormal[9],
            self->m_physics->tyreContactNormal[10],
            self->m_physics->tyreContactNormal[11]);
    }
    static PyObject* get_tyreContactHeading(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffffffffffff]",
            self->m_physics->tyreContactHeading[0],
            self->m_physics->tyreContactHeading[1],
            self->m_physics->tyreContactHeading[2],
            self->m_physics->tyreContactHeading[3],
            self->m_physics->tyreContactHeading[4],
            self->m_physics->tyreContactHeading[5],
            self->m_physics->tyreContactHeading[6],
            self->m_physics->tyreContactHeading[7],
            self->m_physics->tyreContactHeading[8],
            self->m_physics->tyreContactHeading[9],
            self->m_physics->tyreContactHeading[10],
            self->m_physics->tyreContactHeading[11]);
    }
    static PyObject* get_brakeBias(PyPhysics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_physics->brakeBias);
    }
    static PyObject* get_localVelocity(PyPhysics* self, void* closure)
    {
        return Py_BuildValue(
            "[fff]",
            self->m_physics->localVelocity[0],
            self->m_physics->localVelocity[1],
            self->m_physics->localVelocity[2]);
    }

    static PyGetSetDef PhysicsType_getset[] = {
        {"packetId", (getter)get_packetId, nullptr, "", nullptr},
        {"gas", (getter)get_gas, nullptr, "", nullptr},
        {"brake", (getter)get_brake, nullptr, "", nullptr},
        {"fuel", (getter)get_fuel, nullptr, "", nullptr},
        {"gear", (getter)get_gear, nullptr, "", nullptr},
        {"rpm", (getter)get_rpm, nullptr, "", nullptr},
        {"steerAngle", (getter)get_steerAngle, nullptr, "", nullptr},
        {"speedKmh", (getter)get_speedKmh, nullptr, "", nullptr},
        {"velocity", (getter)get_velocity, nullptr, "", nullptr},
        {"accG", (getter)get_accG, nullptr, "", nullptr},
        {"wheelSlip", (getter)get_wheelSlip, nullptr, "", nullptr},
        {"wheelLoad", (getter)get_wheelLoad, nullptr, "", nullptr},
        {"wheelsPressure", (getter)get_wheelsPressure, nullptr, "", nullptr},
        {"wheelAngularSpeed", (getter)get_wheelAngularSpeed, nullptr, "", nullptr},
        {"tyreWear", (getter)get_tyreWear, nullptr, "", nullptr},
        {"tyreDirtyLevel", (getter)get_tyreDirtyLevel, nullptr, "", nullptr},
        {"tyreCoreTemperature", (getter)get_tyreCoreTemperature, nullptr, "", nullptr},
        {"camberRAD", (getter)get_camberRAD, nullptr, "", nullptr},
        {"suspensionTravel", (getter)get_suspensionTravel, nullptr, "", nullptr},
        {"drs", (getter)get_drs, nullptr, "", nullptr},
        {"tc", (getter)get_tc, nullptr, "", nullptr},
        {"heading", (getter)get_heading, nullptr, "", nullptr},
        {"pitch", (getter)get_pitch, nullptr, "", nullptr},
        {"roll", (getter)get_roll, nullptr, "", nullptr},
        {"cgHeight", (getter)get_cgHeight, nullptr, "", nullptr},
        {"carDamage", (getter)get_carDamage, nullptr, "", nullptr},
        {"numberOfTyresOut", (getter)get_numberOfTyresOut, nullptr, "", nullptr},
        {"pitLimiterOn", (getter)get_pitLimiterOn, nullptr, "", nullptr},
        {"abs", (getter)get_abs, nullptr, "", nullptr},
        {"kersCharge", (getter)get_kersCharge, nullptr, "", nullptr},
        {"kersInput", (getter)get_kersInput, nullptr, "", nullptr},
        {"autoShifterOn", (getter)get_autoShifterOn, nullptr, "", nullptr},
        {"rideHeight", (getter)get_rideHeight, nullptr, "", nullptr},
        {"turboBoost", (getter)get_turboBoost, nullptr, "", nullptr},
        {"ballast", (getter)get_ballast, nullptr, "", nullptr},
        {"airDensity", (getter)get_airDensity, nullptr, "", nullptr},
        {"airTemp", (getter)get_airTemp, nullptr, "", nullptr},
        {"roadTemp", (getter)get_roadTemp, nullptr, "", nullptr},
        {"localAngularVel", (getter)get_localAngularVel, nullptr, "", nullptr},
        {"finalFF", (getter)get_finalFF, nullptr, "", nullptr},
        {"performanceMeter", (getter)get_performanceMeter, nullptr, "", nullptr},
        {"engineBrake", (getter)get_engineBrake, nullptr, "", nullptr},
        {"ersRecoveryLevel", (getter)get_ersRecoveryLevel, nullptr, "", nullptr},
        {"ersPowerLevel", (getter)get_ersPowerLevel, nullptr, "", nullptr},
        {"ersHeatCharging", (getter)get_ersHeatCharging, nullptr, "", nullptr},
        {"ersIsCharging", (getter)get_ersIsCharging, nullptr, "", nullptr},
        {"kersCurrentKJ", (getter)get_kersCurrentKJ, nullptr, "", nullptr},
        {"drsAvailable", (getter)get_drsAvailable, nullptr, "", nullptr},
        {"drsEnabled", (getter)get_drsEnabled, nullptr, "", nullptr},
        {"brakeTemp", (getter)get_brakeTemp, nullptr, "", nullptr},
        {"clutch", (getter)get_clutch, nullptr, "", nullptr},
        {"tyreTempI", (getter)get_tyreTempI, nullptr, "", nullptr},
        {"tyreTempM", (getter)get_tyreTempM, nullptr, "", nullptr},
        {"tyreTempO", (getter)get_tyreTempO, nullptr, "", nullptr},
        {"isAIControlled", (getter)get_isAIControlled, nullptr, "", nullptr},
        {"tyreContactPoint", (getter)get_tyreContactPoint, nullptr, "", nullptr},
        {"tyreContactNormal", (getter)get_tyreContactNormal, nullptr, "", nullptr},
        {"tyreContactHeading", (getter)get_tyreContactHeading, nullptr, "", nullptr},
        {"brakeBias", (getter)get_brakeBias, nullptr, "", nullptr},
        {"localVelocity", (getter)get_localVelocity, nullptr, "", nullptr},
        {nullptr}};

    PyTypeObject PhysicsType = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0) "aclib_shared_memory.Physics", /* tp_name */
        sizeof(PyPhysics),                                             /* tp_basicsize */
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
        PhysicsType_methods,                                           /* tp_methods */
        PhysicsType_members,                                           /* tp_members */
        PhysicsType_getset,                                            /* tp_getset */
        nullptr,                                                       /* tp_base */
        nullptr,                                                       /* tp_dict */
        nullptr,                                                       /* tp_descr_get */
        nullptr,                                                       /* tp_descr_set */
        0,                                                             /* tp_dictoffset */
        nullptr,                                                       /* tp_init */
        nullptr,                                                       /* tp_alloc */
        (newfunc)physics_new_,                                         /* tp_new */
    };
}  // namespace ACLIB
