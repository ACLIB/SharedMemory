from distutils.core import setup, Extension

extension = Extension(
    name='aclib_shared_memory',
    sources=[
        'source/EventLoop.cpp',
        'source/python/ACLIBSharedMemory.cpp',
        'source/python/PyEventLoop.cpp',
        'source/python/PyPhysics.cpp',
        'source/python/PyGraphics.cpp',
        'source/python/PyStatics.cpp'
    ],
    include_dirs=['source'],
    extra_compile_args=["/EHsc"], )

setup(name='aclib_shared_memory',
      version='1.0',
      ext_modules=[extension])
