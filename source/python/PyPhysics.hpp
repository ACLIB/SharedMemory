#ifndef ACLIB_SHARED_MEMORY_PYPHYSICS_HPP
#define ACLIB_SHARED_MEMORY_PYPHYSICS_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"

#include <Python.h>

namespace ACLIB
{
    struct PyPhysics
    {
        PyObject_HEAD SharedMemory<AC::Physics>* m_physics;
    };

    static PyObject* physics_new_(PyTypeObject* type, PyObject* args, PyObject* kwds);
    static void      physics_del_(PyTypeObject* self);

    static int physics_init_(PyPhysics* self, PyObject* args, PyObject* kwds);

    extern PyMemberDef  PhysicsType_members[];
    extern PyMethodDef  PhysicsType_methods[];
    extern PyTypeObject PhysicsType;
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYPHYSICS_HPP
