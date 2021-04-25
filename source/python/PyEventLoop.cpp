#include "PyEventLoop.hpp"

#include <structmember.h>

namespace ACLIB
{
    PyObject* event_loop_new_(PyTypeObject* type, PyObject* args, PyObject* kwds)
    {
        PyEventLoop* self;
        self = reinterpret_cast<PyEventLoop*>(type->tp_alloc(type, 0));

        if(self != nullptr)
        {
            self->m_event_loop = EventLoop();
        }
        return reinterpret_cast<PyObject*>(self);
    }

    void event_loop_del_(PyTypeObject* self)
    {
        self->tp_free(self);
    }

    PyMemberDef EventLoopType_members[] = {{nullptr}};

    PyObject* start(PyEventLoop* type, PyObject* args, PyObject* kwds)
    {
        type->m_event_loop.start();
        return Py_None;
    }

    PyObject* stop(PyEventLoop* type, PyObject* args, PyObject* kwds)
    {
        type->m_event_loop.stop();
        return Py_None;
    }

    PyObject* size(PyEventLoop* type, PyObject* args, PyObject* kwds)
    {
        return PyLong_FromLong(type->m_event_loop.size());
    }

    PyObject* empty(PyEventLoop* type, PyObject* args, PyObject* kwds)
    {
        return PyBool_FromLong(type->m_event_loop.empty() ? 1 : 0);
    }

    PyObject* front(PyEventLoop* type, PyObject* args, PyObject* kwds)
    {
        if(!type->m_event_loop.empty())
        {
            return PyLong_FromLong(type->m_event_loop.m_events.front());
        }
        else
            return Py_None;
    }

    PyObject* pop(PyEventLoop* type, PyObject* args, PyObject* kwds)
    {
        if(!type->m_event_loop.empty())
        {
            auto event = type->m_event_loop.m_events.front();
            type->m_event_loop.pop();
            return PyLong_FromLong(event);
        }
        return Py_None;
    }

    PyMethodDef EventLoopType_methods[] = {
        // {"func_name", (PyCFunction)func, METH_NOARGS, "doc"},
        {"start", (PyCFunction)start, METH_NOARGS, "doc"},
        {"stop", (PyCFunction)stop, METH_NOARGS, "doc"},
        {"size", (PyCFunction)size, METH_NOARGS, "doc"},
        {"empty", (PyCFunction)empty, METH_NOARGS, "doc"},
        {"front", (PyCFunction)front, METH_NOARGS, "doc"},
        {"pop", (PyCFunction)pop, METH_NOARGS, "doc"},
        {nullptr}};

    static PyGetSetDef EventLoopType_getset[] = {{nullptr}};

    PyTypeObject EventLoopType = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0) "aclib_shared_memory.EventLoop", /* tp_name */
        sizeof(PyEventLoop),                                                    /* tp_basicsize */
        0,                                                                      /* tp_itemsize */
        nullptr,                                                                /* tp_dealloc */
        0,                                                                      /* tp_print */
        nullptr,                                                                /* tp_getattr */
        nullptr,                                                                /* tp_setattr */
        nullptr,                                                                /* tp_reserved */
        nullptr,                                                                /* tp_repr */
        nullptr,                                                                /* tp_as_number */
        nullptr,                                                                /* tp_as_sequence */
        nullptr,                                                                /* tp_as_mapping */
        nullptr,                                                                /* tp_hash */
        nullptr,                                                                /* tp_call */
        nullptr,                                                                /* tp_str */
        nullptr,                                                                /* tp_getattro */
        nullptr,                                                                /* tp_setattro */
        nullptr,                                                                /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT,                                                     /* tp_flags */
        nullptr,                                                                /* tp_doc */
        nullptr,                                                                /* tp_traverse */
        nullptr,                                                                /* tp_clear */
        nullptr,                                                                /* tp_richcompare */
        0,                        /* tp_weaklistoffset */
        nullptr,                  /* tp_iter */
        nullptr,                  /* tp_iternext */
        EventLoopType_methods,    /* tp_methods */
        EventLoopType_members,    /* tp_members */
        EventLoopType_getset,     /* tp_getset */
        nullptr,                  /* tp_base */
        nullptr,                  /* tp_dict */
        nullptr,                  /* tp_descr_get */
        nullptr,                  /* tp_descr_set */
        0,                        /* tp_dictoffset */
        nullptr,                  /* tp_init */
        nullptr,                  /* tp_alloc */
        (newfunc)event_loop_new_, /* tp_new */
    };
}  // namespace ACLIB
