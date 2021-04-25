#ifndef ACLIB_SHARED_MEMORY_SHAREDMEMORY_HPP
#define ACLIB_SHARED_MEMORY_SHAREDMEMORY_HPP

#include <windows.h>

namespace ACLIB
{
    /**
     * Returns the size of an array at compile time.
     */
    template<class T, size_t N>
    inline size_t sizeOfArray(T (&)[N])
    {
        return N;
    }

    /**
     * Shared memory class. Stores the memory page handle and a pointer to the type of the memory
     * page.
     */
    template<typename T>
    class SharedMemory
    {
    private:
        HANDLE m_handle;
        T*     m_data;

    public:
        explicit SharedMemory(const char* name)
        {
            m_handle =
                CreateFileMapping(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0, sizeof(T), name);

            if(m_handle != nullptr)
            {
                m_data = reinterpret_cast<T*>(MapViewOfFile(m_handle, FILE_MAP_READ, 0, 0, sizeof(T)));
            }
        }

        T* data()
        {
            return m_data;
        }

        T operator*()
        {
            return *m_data;
        }

        T* operator->()
        {
            return m_data;
        }

        ~SharedMemory()
        {
            CloseHandle(m_handle);
        }
    };
}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_SHAREDMEMORY_HPP
