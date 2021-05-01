#ifndef ACLIB_SHARED_MEMORY_PYGRAPHICS_HPP
#define ACLIB_SHARED_MEMORY_PYGRAPHICS_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"

#include <Python.h>

namespace ACLIB
{
    struct PyGraphics
    {
        PyObject_HEAD
        SharedMemory<AC::Graphics>* m_graphics;
    };

    static PyObject* graphics_new_(PyTypeObject* type, PyObject* args, PyObject* kwds);
    static void      graphics_del_(PyTypeObject* self);

    extern PyMemberDef  GraphicsType_members[];
    extern PyMethodDef  GraphicsType_methods[];
    extern PyTypeObject GraphicsType;
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYGRAPHICS_HPP
