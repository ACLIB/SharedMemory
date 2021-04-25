#ifndef ACLIB_SHARED_MEMORY_AC_HPP
#define ACLIB_SHARED_MEMORY_AC_HPP

#include "ACLIB.hpp"

namespace AC
{
    typedef ACLIB::Uint32 Uint32;
    typedef ACLIB::Sint32 Sint32;
    typedef ACLIB::WChar  WChar;

    static const char* PHYSICS_PAGE  = "Local\\acpmf_physics";
    static const char* GRAPHICS_PAGE = "Local\\acpmf_graphics";
    static const char* STATICS_PAGE  = "Local\\acpmf_static";

    enum AC_SESSION : Sint32
    {
        UNKNOWN     = -1,
        PRACTICE    = 0,
        QUALIFYING  = 1,
        RACE        = 2,
        HOTLAP      = 3,
        TIME_ATTACK = 4,
        DRIFT       = 5,
        DRAG        = 6,
    };

    enum AC_STATUS : Uint32
    {
        OFF    = 0,
        REPLAY = 1,
        LIVE   = 2,
        PAUSE  = 3,
    };

    enum AC_FLAG : Uint32
    {
        AC_NO_FLAG        = 0,
        AC_BLUE_FLAG      = 1,
        AC_YELLOW_FLAG    = 2,
        AC_BLACK_FLAG     = 3,
        AC_WHITE_FLAG     = 4,
        AC_CHECKERED_FLAG = 5,
        AC_PENALTY_FLAG   = 6
    };

    struct Physics
    {
        Uint32 packetId;
        float  gas;
        float  brake;
        float  fuel;
        Uint32 gear;
        Uint32 rpm;
        float  steerAngle;
        float  speedKmh;
        float  velocity[3];
        float  accG[3];
        float  wheelSlip[4];
        float  wheelLoad[4];
        float  wheelsPressure[4];
        float  wheelAngularSpeed[4];
        float  tyreWear[4];
        float  tyreDirtyLevel[4];
        float  tyreCoreTemperature[4];
        float  camberRAD[4];
        float  suspensionTravel[4];
        float  drs;
        float  tc;
        float  heading;
        float  pitch;
        float  roll;
        float  cgHeight;
        float  carDamage[5];
        Uint32 numberOfTyresOut;
        Uint32 pitLimiterOn;
        float  abs;
        float  kersCharge;
        float  kersInput;
        Uint32 autoShifterOn;
        float  rideHeight[2];
        float  turboBoost;
        float  ballast;
        float  airDensity;
        float  airTemp;
        float  roadTemp;
        float  localAngularVel[3];
        float  finalFF;
        float  performanceMeter;
        Uint32 engineBrake;
        Uint32 ersRecoveryLevel;
        Uint32 ersPowerLevel;
        Uint32 ersHeatCharging;
        Uint32 ersIsCharging;
        float  kersCurrentKJ;
        Uint32 drsAvailable;
        Uint32 drsEnabled;
        float  brakeTemp[4];
        float  clutch;
        float  tyreTempI[4];
        float  tyreTempM[4];
        float  tyreTempO[4];
        Uint32 isAIControlled;
        float  tyreContactPoint[12];
        float  tyreContactNormal[12];
        float  tyreContactHeading[12];
        float  brakeBias;
        float  localVelocity[3];
    };

    struct Graphics
    {
        Uint32     packetId;
        AC_STATUS  status;
        AC_SESSION session;
        WChar      currentTime[15];
        WChar      lastTime[15];
        WChar      bestTime[15];
        WChar      split[15];
        Uint32     completedLaps;
        Uint32     position;
        Uint32     iCurrentTime;
        Uint32     iLastTime;
        Uint32     iBestTime;
        float      sessionTimeLeft;
        float      distanceTraveled;
        Uint32     isInPit;
        Uint32     currentSectorIndex;
        Uint32     lastSectorTime;
        Uint32     numberOfLaps;
        WChar      tyreCompound[33];
        float      replayTimeMultiplier;
        float      normalizedCarPosition;
        float      carCoordinates[3];
        float      penaltyTime;
        AC_FLAG    flag;
        Uint32     idealLineOn;
        Uint32     isInPitLine;
        float      surfaceGrip;
        Uint32     mandatoryPitDone;
        float      windSpeed;
        float      windDirection;
    };

    struct Statics
    {
        WChar smVersion[15];
        WChar acVersion[15];

        // session static info
        Uint32 numberOfSessions;
        Uint32 numCars;
        WChar  carModel[33];
        WChar  track[33];
        WChar  playerName[33];
        WChar  playerSurname[33];
        WChar  playerNick[33];
        Uint32 sectorCount;

        // car static info
        float  maxTorque;
        float  maxPower;
        Uint32 maxRpm;
        float  maxFuel;
        float  suspensionMaxTravel[4];
        float  tyreRadius[4];
        float  maxTurboBoost;
        float  airTemp;
        float  roadTemp;
        Uint32 penaltiesEnabled;
        float  aidFuelRate;
        float  aidTireRate;
        float  aidMechanicalDamage;
        Uint32 aidAllowTyreBlankets;
        float  aidStability;
        Uint32 aidAutoClutch;
        Uint32 aidAutoBlip;
        Uint32 hasDRS;
        Uint32 hasERS;
        Uint32 hasKERS;
        float  kersMaxJ;
        Uint32 engineBrakeSettingsCount;
        Uint32 ersPowerControllerCount;
        float  trackSPlineLength;
        WChar  trackConfiguration[33];
        float  ersMaxJ;
        Uint32 isTimedRace;
        Uint32 hasExtraLap;
        WChar  carSkin[33];
        Uint32 reversedGridPositions;
        Uint32 pitWindowStart;
        Uint32 pitWindowEnd;
    };

}  // namespace AC

#endif  // ACLIB_SHARED_MEMORY_AC_HPP
