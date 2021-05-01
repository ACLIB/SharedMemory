#ifndef ACLIB_SHARED_MEMORY_PYSTATICS_HPP
#define ACLIB_SHARED_MEMORY_PYSTATICS_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"

#include <Python.h>

namespace ACLIB
{
    struct PyStatics
    {
        PyObject_HEAD
        SharedMemory<AC::Statics>* m_statics;
    };

    static PyObject* statics_new_(PyTypeObject* type, PyObject* args, PyObject* kwds);
    static void      statics_del_(PyTypeObject* self);

    extern PyMemberDef  StaticsType_members[];
    extern PyMethodDef  StaticsType_methods[];
    extern PyTypeObject StaticsType;
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYSTATICS_HPP
