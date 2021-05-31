# ACLIB Shared Memory module

Standalone shared memory module for [ACLIB](https://github.com/ACLIB/ACLIB).

> Work in progress.

Follow the [Documentation](https://github.com/ACLIB/Documentation) for more details.

# Example

```python
import aclib_shared_memory as SM

# AC memory pages
ph = SM.Physics()
gr = SM.Graphics()
st = SM.Statics()

# Registers events in the background (WIP)
ev = aclib.EventLoop()


# Get values from memory pages
print(ph.abs, ph.fuel, ph.turboBoost ph.tyreTempI, gr.position, gr.normalizedCarPosition, st.numCars, st.roadTemp)

# Get events from queue
print(e.size())   # Number of elements in queue
print(e.front())  # Top event
e.pop()           # Remove element from queue
```
