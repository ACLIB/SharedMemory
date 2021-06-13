#include "PyEventLoop.hpp"
#include "PyGraphics.hpp"
#include "PyPhysics.hpp"
#include "PyStatics.hpp"

#include "python/PyModule.hpp"

namespace ACLIB
{
    PyMODINIT_FUNC PyInit_aclib_shared_memory()
    {
        static auto module = PyModule("aclib_shared_memory");
        module.init();

        PyEval_InitThreads();

        static auto physics = PyPhysics("Physics");
        physics.addGetSet("packetId", (getter)PyPhysics::get_packetId, nullptr);
        physics.addGetSet("gas", (getter)PyPhysics::get_gas, nullptr);
        physics.addGetSet("brake", (getter)PyPhysics::get_brake, nullptr);
        physics.addGetSet("fuel", (getter)PyPhysics::get_fuel, nullptr);
        physics.addGetSet("gear", (getter)PyPhysics::get_gear, nullptr);
        physics.addGetSet("rpm", (getter)PyPhysics::get_rpm, nullptr);
        physics.addGetSet("steerAngle", (getter)PyPhysics::get_steerAngle, nullptr);
        physics.addGetSet("speedKmh", (getter)PyPhysics::get_speedKmh, nullptr);
        physics.addGetSet("velocity", (getter)PyPhysics::get_velocity, nullptr);
        physics.addGetSet("accG", (getter)PyPhysics::get_accG, nullptr);
        physics.addGetSet("wheelSlip", (getter)PyPhysics::get_wheelSlip, nullptr);
        physics.addGetSet("wheelLoad", (getter)PyPhysics::get_wheelLoad, nullptr);
        physics.addGetSet("wheelsPressure", (getter)PyPhysics::get_wheelsPressure, nullptr);
        physics.addGetSet("wheelAngularSpeed", (getter)PyPhysics::get_wheelAngularSpeed, nullptr);
        physics.addGetSet("tyreWear", (getter)PyPhysics::get_tyreWear, nullptr);
        physics.addGetSet("tyreDirtyLevel", (getter)PyPhysics::get_tyreDirtyLevel, nullptr);
        physics.addGetSet("tyreCoreTemperature", (getter)PyPhysics::get_tyreCoreTemperature, nullptr);
        physics.addGetSet("camberRAD", (getter)PyPhysics::get_camberRAD, nullptr);
        physics.addGetSet("suspensionTravel", (getter)PyPhysics::get_suspensionTravel, nullptr);
        physics.addGetSet("drs", (getter)PyPhysics::get_drs, nullptr);
        physics.addGetSet("tc", (getter)PyPhysics::get_tc, nullptr);
        physics.addGetSet("heading", (getter)PyPhysics::get_heading, nullptr);
        physics.addGetSet("pitch", (getter)PyPhysics::get_pitch, nullptr);
        physics.addGetSet("roll", (getter)PyPhysics::get_roll, nullptr);
        physics.addGetSet("cgHeight", (getter)PyPhysics::get_cgHeight, nullptr);
        physics.addGetSet("carDamage", (getter)PyPhysics::get_carDamage, nullptr);
        physics.addGetSet("numberOfTyresOut", (getter)PyPhysics::get_numberOfTyresOut, nullptr);
        physics.addGetSet("pitLimiterOn", (getter)PyPhysics::get_pitLimiterOn, nullptr);
        physics.addGetSet("abs", (getter)PyPhysics::get_abs, nullptr);
        physics.addGetSet("kersCharge", (getter)PyPhysics::get_kersCharge, nullptr);
        physics.addGetSet("kersInput", (getter)PyPhysics::get_kersInput, nullptr);
        physics.addGetSet("autoShifterOn", (getter)PyPhysics::get_autoShifterOn, nullptr);
        physics.addGetSet("rideHeight", (getter)PyPhysics::get_rideHeight, nullptr);
        physics.addGetSet("turboBoost", (getter)PyPhysics::get_turboBoost, nullptr);
        physics.addGetSet("ballast", (getter)PyPhysics::get_ballast, nullptr);
        physics.addGetSet("airDensity", (getter)PyPhysics::get_airDensity, nullptr);
        physics.addGetSet("airTemp", (getter)PyPhysics::get_airTemp, nullptr);
        physics.addGetSet("roadTemp", (getter)PyPhysics::get_roadTemp, nullptr);
        physics.addGetSet("localAngularVel", (getter)PyPhysics::get_localAngularVel, nullptr);
        physics.addGetSet("finalFF", (getter)PyPhysics::get_finalFF, nullptr);
        physics.addGetSet("performanceMeter", (getter)PyPhysics::get_performanceMeter, nullptr);
        physics.addGetSet("engineBrake", (getter)PyPhysics::get_engineBrake, nullptr);
        physics.addGetSet("ersRecoveryLevel", (getter)PyPhysics::get_ersRecoveryLevel, nullptr);
        physics.addGetSet("ersPowerLevel", (getter)PyPhysics::get_ersPowerLevel, nullptr);
        physics.addGetSet("ersHeatCharging", (getter)PyPhysics::get_ersHeatCharging, nullptr);
        physics.addGetSet("ersIsCharging", (getter)PyPhysics::get_ersIsCharging, nullptr);
        physics.addGetSet("kersCurrentKJ", (getter)PyPhysics::get_kersCurrentKJ, nullptr);
        physics.addGetSet("drsAvailable", (getter)PyPhysics::get_drsAvailable, nullptr);
        physics.addGetSet("drsEnabled", (getter)PyPhysics::get_drsEnabled, nullptr);
        physics.addGetSet("brakeTemp", (getter)PyPhysics::get_brakeTemp, nullptr);
        physics.addGetSet("clutch", (getter)PyPhysics::get_clutch, nullptr);
        physics.addGetSet("tyreTempI", (getter)PyPhysics::get_tyreTempI, nullptr);
        physics.addGetSet("tyreTempM", (getter)PyPhysics::get_tyreTempM, nullptr);
        physics.addGetSet("tyreTempO", (getter)PyPhysics::get_tyreTempO, nullptr);
        physics.addGetSet("isAIControlled", (getter)PyPhysics::get_isAIControlled, nullptr);
        physics.addGetSet("tyreContactPoint", (getter)PyPhysics::get_tyreContactPoint, nullptr);
        physics.addGetSet("tyreContactNormal", (getter)PyPhysics::get_tyreContactNormal, nullptr);
        physics.addGetSet("tyreContactHeading", (getter)PyPhysics::get_tyreContactHeading, nullptr);
        physics.addGetSet("brakeBias", (getter)PyPhysics::get_brakeBias, nullptr);
        physics.addGetSet("localVelocity", (getter)PyPhysics::get_localVelocity, nullptr);
        physics.init(module.getModule());

        static auto graphics = PyGraphics("Graphics");
        graphics.addGetSet("packetId", (getter)PyGraphics::get_packetId, nullptr);
        graphics.addGetSet("status", (getter)PyGraphics::get_status, nullptr);
        graphics.addGetSet("session", (getter)PyGraphics::get_session, nullptr);
        graphics.addGetSet("currentTime", (getter)PyGraphics::get_currentTime, nullptr);
        graphics.addGetSet("lastTime", (getter)PyGraphics::get_lastTime, nullptr);
        graphics.addGetSet("bestTime", (getter)PyGraphics::get_bestTime, nullptr);
        graphics.addGetSet("split", (getter)PyGraphics::get_split, nullptr);
        graphics.addGetSet("completedLaps", (getter)PyGraphics::get_completedLaps, nullptr);
        graphics.addGetSet("position", (getter)PyGraphics::get_position, nullptr);
        graphics.addGetSet("iCurrentTime", (getter)PyGraphics::get_iCurrentTime, nullptr);
        graphics.addGetSet("iLastTime", (getter)PyGraphics::get_iLastTime, nullptr);
        graphics.addGetSet("iBestTime", (getter)PyGraphics::get_iBestTime, nullptr);
        graphics.addGetSet("sessionTimeLeft", (getter)PyGraphics::get_sessionTimeLeft, nullptr);
        graphics.addGetSet("distanceTraveled", (getter)PyGraphics::get_distanceTraveled, nullptr);
        graphics.addGetSet("isInPit", (getter)PyGraphics::get_isInPit, nullptr);
        graphics.addGetSet("currentSectorIndex", (getter)PyGraphics::get_currentSectorIndex, nullptr);
        graphics.addGetSet("lastSectorTime", (getter)PyGraphics::get_lastSectorTime, nullptr);
        graphics.addGetSet("numberOfLaps", (getter)PyGraphics::get_numberOfLaps, nullptr);
        graphics.addGetSet("tyreCompound", (getter)PyGraphics::get_tyreCompound, nullptr);
        graphics.addGetSet("replayTimeMultiplier", (getter)PyGraphics::get_replayTimeMultiplier, nullptr);
        graphics.addGetSet("normalizedCarPosition", (getter)PyGraphics::get_normalizedCarPosition, nullptr);
        graphics.addGetSet("carCoordinates", (getter)PyGraphics::get_carCoordinates, nullptr);
        graphics.addGetSet("penaltyTime", (getter)PyGraphics::get_penaltyTime, nullptr);
        graphics.addGetSet("flag", (getter)PyGraphics::get_flag, nullptr);
        graphics.addGetSet("idealLineOn", (getter)PyGraphics::get_idealLineOn, nullptr);
        graphics.addGetSet("isInPitLine", (getter)PyGraphics::get_isInPitLine, nullptr);
        graphics.addGetSet("surfaceGrip", (getter)PyGraphics::get_surfaceGrip, nullptr);
        graphics.addGetSet("mandatoryPitDone", (getter)PyGraphics::get_mandatoryPitDone, nullptr);
        graphics.addGetSet("windSpeed", (getter)PyGraphics::get_windSpeed, nullptr);
        graphics.addGetSet("windDirection", (getter)PyGraphics::get_windDirection, nullptr);
        graphics.init(module.getModule());

        static auto statics = PyStatics("Statics");
        statics.addGetSet("smVersion", (getter)PyStatics::get_smVersion, nullptr);
        statics.addGetSet("acVersion", (getter)PyStatics::get_acVersion, nullptr);
        statics.addGetSet("numberOfSessions", (getter)PyStatics::get_numberOfSessions, nullptr);
        statics.addGetSet("numCars", (getter)PyStatics::get_numCars, nullptr);
        statics.addGetSet("carModel", (getter)PyStatics::get_carModel, nullptr);
        statics.addGetSet("track", (getter)PyStatics::get_track, nullptr);
        statics.addGetSet("playerName", (getter)PyStatics::get_playerName, nullptr);
        statics.addGetSet("playerSurname", (getter)PyStatics::get_playerSurname, nullptr);
        statics.addGetSet("playerNick", (getter)PyStatics::get_playerNick, nullptr);
        statics.addGetSet("sectorCount", (getter)PyStatics::get_sectorCount, nullptr);
        statics.addGetSet("maxTorque", (getter)PyStatics::get_maxTorque, nullptr);
        statics.addGetSet("maxPower", (getter)PyStatics::get_maxPower, nullptr);
        statics.addGetSet("maxRpm", (getter)PyStatics::get_maxRpm, nullptr);
        statics.addGetSet("maxFuel", (getter)PyStatics::get_maxFuel, nullptr);
        statics.addGetSet("suspensionMaxTravel", (getter)PyStatics::get_suspensionMaxTravel, nullptr);
        statics.addGetSet("tyreRadius", (getter)PyStatics::get_tyreRadius, nullptr);
        statics.addGetSet("maxTurboBoost", (getter)PyStatics::get_maxTurboBoost, nullptr);
        statics.addGetSet("airTemp", (getter)PyStatics::get_airTemp, nullptr);
        statics.addGetSet("roadTemp", (getter)PyStatics::get_roadTemp, nullptr);
        statics.addGetSet("penaltiesEnabled", (getter)PyStatics::get_penaltiesEnabled, nullptr);
        statics.addGetSet("aidFuelRate", (getter)PyStatics::get_aidFuelRate, nullptr);
        statics.addGetSet("aidTireRate", (getter)PyStatics::get_aidTireRate, nullptr);
        statics.addGetSet("aidMechanicalDamage", (getter)PyStatics::get_aidMechanicalDamage, nullptr);
        statics.addGetSet("aidAllowTyreBlankets", (getter)PyStatics::get_aidAllowTyreBlankets, nullptr);
        statics.addGetSet("aidStability", (getter)PyStatics::get_aidStability, nullptr);
        statics.addGetSet("aidAutoClutch", (getter)PyStatics::get_aidAutoClutch, nullptr);
        statics.addGetSet("aidAutoBlip", (getter)PyStatics::get_aidAutoBlip, nullptr);
        statics.addGetSet("hasDRS", (getter)PyStatics::get_hasDRS, nullptr);
        statics.addGetSet("hasERS", (getter)PyStatics::get_hasERS, nullptr);
        statics.addGetSet("hasKERS", (getter)PyStatics::get_hasKERS, nullptr);
        statics.addGetSet("kersMaxJ", (getter)PyStatics::get_kersMaxJ, nullptr);
        statics.addGetSet("engineBrakeSettingsCount", (getter)PyStatics::get_engineBrakeSettingsCount, nullptr);
        statics.addGetSet("ersPowerControllerCount", (getter)PyStatics::get_ersPowerControllerCount, nullptr);
        statics.addGetSet("trackSPlineLength", (getter)PyStatics::get_trackSPlineLength, nullptr);
        statics.addGetSet("trackConfiguration", (getter)PyStatics::get_trackConfiguration, nullptr);
        statics.addGetSet("ersMaxJ", (getter)PyStatics::get_ersMaxJ, nullptr);
        statics.addGetSet("isTimedRace", (getter)PyStatics::get_isTimedRace, nullptr);
        statics.addGetSet("hasExtraLap", (getter)PyStatics::get_hasExtraLap, nullptr);
        statics.addGetSet("carSkin", (getter)PyStatics::get_carSkin, nullptr);
        statics.addGetSet("reversedGridPositions", (getter)PyStatics::get_reversedGridPositions, nullptr);
        statics.addGetSet("pitWindowStart", (getter)PyStatics::get_pitWindowStart, nullptr);
        statics.addGetSet("pitWindowEnd", (getter)PyStatics::get_pitWindowEnd, nullptr);
        statics.init(module.getModule());

        static auto event_loop = PyEventLoop("EventLoop");
        event_loop.addMethod("start", (PyCFunction)PyEventLoop::start, METH_NOARGS);
        event_loop.addMethod("stop", (PyCFunction)PyEventLoop::stop, METH_NOARGS);
        event_loop.addMethod("size", (PyCFunction)PyEventLoop::size, METH_NOARGS);
        event_loop.addMethod("empty", (PyCFunction)PyEventLoop::empty, METH_NOARGS);
        event_loop.addMethod("front", (PyCFunction)PyEventLoop::front, METH_NOARGS);
        event_loop.addMethod("pop", (PyCFunction)PyEventLoop::pop, METH_NOARGS);
        event_loop.addMethod("push", (PyCFunction)PyEventLoop::push, METH_VARARGS);
        event_loop.init(module.getModule());

        return module.getModule();
    }

}  // namespace ACLIB
