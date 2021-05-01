#ifndef ACLIB_SHARED_MEMORY_PYEVENTLOOP_HPP
#define ACLIB_SHARED_MEMORY_PYEVENTLOOP_HPP

#include "AC.hpp"
#include "EventLoop.hpp"

#include <Python.h>

namespace ACLIB
{
    struct PyEventLoop
    {
        PyObject_HEAD
        EventLoop* m_event_loop;
    };

    static PyObject* event_loop_new_(PyTypeObject* type, PyObject* args, PyObject* kwds);
    static void      event_loop_del_(PyTypeObject* self);

    extern PyMemberDef  EventLoopType_members[];
    extern PyMethodDef  EventLoopType_methods[];
    extern PyTypeObject EventLoopType;
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYEVENTLOOP_HPP
