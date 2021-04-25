#include "PyEventLoop.hpp"
#include "PyGraphics.hpp"
#include "PyPhysics.hpp"
#include "PyStatics.hpp"

std::fstream Log::stream = std::fstream("C:\\Users\\Chris\\Desktop\\f.log", std::ios::out);

namespace ACLIB
{
    static PyObject *test(PyObject *self, PyObject *args)
    {
        return PyFloat_FromDouble(0.0);
    }

    static PyMethodDef module_methods[] = {
        // {"func name", func, METH_NOARGS, "doc"},
        {"test", test, METH_NOARGS, "doc"},
        {nullptr, nullptr, 0, nullptr}};

    struct PyModuleDef aclib_module = {
        PyModuleDef_HEAD_INIT,
        "aclib_shared_memory",
        "Assetto Corsa 'all in one' python module that provides an interface for shared memory "
        "pages.",
        -1,
        module_methods};

    PyMODINIT_FUNC PyInit_aclib_shared_memory()
    {
        PyObject* module = PyModule_Create(&aclib_module);

        PyEval_InitThreads();

        if(PyType_Ready(&PhysicsType) < 0)
        {
            // err
            printf("Could not init Physics type");
        }

        if(PyType_Ready(&GraphicsType) < 0)
        {
            // err
            printf("Could not init Graphics type");
        }

        if(PyType_Ready(&StaticsType) < 0)
        {
            // err
            printf("Could not init Statics type");
        }

        if(PyType_Ready(&EventLoopType) < 0)
        {
            // err
            printf("Could not init EventLoop type");
        }

        if(!module)
        {
            // err
            printf("Could not init aclib_shared_memory module.");
        }

        PyModule_AddObject(module, "Physics", reinterpret_cast<PyObject*>(&PhysicsType));
        PyModule_AddObject(module, "Graphics", reinterpret_cast<PyObject*>(&GraphicsType));
        PyModule_AddObject(module, "Statics", reinterpret_cast<PyObject*>(&StaticsType));
        PyModule_AddObject(module, "EventLoop", reinterpret_cast<PyObject*>(&EventLoopType));

        return module;
    }

}  // namespace ACLIB
