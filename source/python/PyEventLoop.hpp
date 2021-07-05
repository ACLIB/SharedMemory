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
            m_type.tp_basicsize = sizeof(PyEventLoop);
            m_type.tp_new       = (newfunc)PyEventLoop::_new;
            m_type.tp_dealloc   = (destructor)PyEventLoop::_del;

            return PyClassType::init(module);
        }

        /**
         * Memory Management
         */

        static PyObject* _new(PyTypeObject* type, PyObject* args, PyObject* kwds)
        {
            auto self = reinterpret_cast<PyEventLoop*>(type->tp_alloc(type, 0));
            if(self != nullptr)
            {
                self->m_event_loop = new EventLoop();
            }
            return reinterpret_cast<PyObject*>(self);
        }

        static void _del(PyTypeObject* type)
        {
            auto self = reinterpret_cast<PyEventLoop*>(type);
            if(self != nullptr)
            {
                delete self->m_event_loop;
            }
            Py_TYPE(type)->tp_free(reinterpret_cast<PyObject*>(type));
        }

        /**
         * Custom class type functions
         */

        static PyObject* start(PyEventLoop* self, PyObject* args, PyObject* kwds)
        {
            self->m_event_loop->start();
            return Py_None;
        }

        static PyObject* stop(PyEventLoop* self, PyObject* args, PyObject* kwds)
        {
            self->m_event_loop->stop();
            return Py_None;
        }

        static PyObject* size(PyEventLoop* self, PyObject* args, PyObject* kwds)
        {
            return PyLong_FromLong(self->m_event_loop->size());
        }

        static PyObject* empty(PyEventLoop* self, PyObject* args, PyObject* kwds)
        {
            return PyBool_FromLong(self->m_event_loop->empty());
        }

        static PyObject* front(PyEventLoop* self, PyObject* args, PyObject* kwds)
        {
            if(!self->m_event_loop->empty())
            {
                return PyLong_FromLong(self->m_event_loop->front());
            }
            else
                return Py_None;
        }

        static PyObject* pop(PyEventLoop* self, PyObject* args, PyObject* kwds)
        {
            if(!self->m_event_loop->empty())
            {
                auto event = self->m_event_loop->front();
                self->m_event_loop->pop();
                return PyLong_FromLong(event);
            }
            return Py_None;
        }

        static PyObject* push(PyEventLoop* self, PyObject* args, PyObject* kwds)
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

            self->m_event_loop->push(event);

            return Py_None;
        }
    };
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_PYEVENTLOOP_HPP
