#ifndef ACLIB_SHARED_MEMORY_PYEVENTLOOP_HPP
#define ACLIB_SHARED_MEMORY_PYEVENTLOOP_HPP

#include "AC.hpp"
#include "EventLoop.hpp"
#include "python/PyClassType.hpp"

namespace ACLIB
{
    class PyEventLoop : public PyClassType
    {
    public:
        EventLoop* m_event_loop;

        explicit PyEventLoop(const char* name)
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
            m_type.tp_basicsize = sizeof(PyEventLoop);
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
            PyEventLoop* self;
            self = reinterpret_cast<PyEventLoop*>(type->tp_alloc(type, 0));

            if(self != nullptr)
            {
                self->m_event_loop = new EventLoop();
            }
            return reinterpret_cast<PyObject*>(self);
        }

        static void _del(PyTypeObject* self)
        {
            delete reinterpret_cast<PyEventLoop*>(self)->m_event_loop;
            Py_TYPE(self)->tp_free(self);
        }

        /**
         * Custom class type functions
         */

        static PyObject* start(PyEventLoop* type, PyObject* args, PyObject* kwds)
        {
            type->m_event_loop->start();
            return Py_None;
        }

        static PyObject* stop(PyEventLoop* type, PyObject* args, PyObject* kwds)
        {
            type->m_event_loop->stop();
            return Py_None;
        }

        static PyObject* size(PyEventLoop* type, PyObject* args, PyObject* kwds)
        {
            return PyLong_FromLong(type->m_event_loop->size());
        }

        static PyObject* empty(PyEventLoop* type, PyObject* args, PyObject* kwds)
        {
            return PyBool_FromLong(type->m_event_loop->empty());
        }

        static PyObject* front(PyEventLoop* type, PyObject* args, PyObject* kwds)
        {
            if(!type->m_event_loop->empty())
            {
                return PyLong_FromLong(type->m_event_loop->front());
            }
            else
                return Py_None;
        }

        static PyObject* pop(PyEventLoop* type, PyObject* args, PyObject* kwds)
        {
            if(!type->m_event_loop->empty())
            {
                auto event = type->m_event_loop->front();
                type->m_event_loop->pop();
                return PyLong_FromLong(event);
            }
            return Py_None;
        }

        static PyObject* push(PyEventLoop* type, PyObject* args, PyObject* kwds)
        {
            long event;

            if(!PyArg_ParseTuple(args, "l", &event))
            {
                if(!PyLong_Check(&event))
                {
                    PyErr_SetString(PyExc_TypeError, "parameter must be a long");
                    return nullptr;
                }
                PyErr_SetString(PyExc_TypeError, "parameter missing");
                return nullptr;
            }

            type->m_event_loop->push(event);

            return Py_None;
        }
    };
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYEVENTLOOP_HPP
