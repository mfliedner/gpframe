# gpframe
project framework for geophysical data processing algorithms
core function: execute workflow shell script built from modules

## modules
The individual processing executables are kept in the `modules/bin` folder,
their documentation in `modules/doc`.  Any source code and necessary libraries
such as SEPlib or SU can be organized under `modules/src`.

### processing code examples
For the time being, the `modules` folder holds only a single example that
calculates seismic traveltime tables for 1D (cylindrically symmetric)
velocity models, `SlotnickTT`.  It is written in C and built on SEPlib.  The
subset of SEPlib dealing with parameter processing and file output that is
needed to compile `SlotnickTT` is included.

The full SEPlib can be obtained from the **Stanford Exploration Project**: http://sepwww.stanford.edu/doku.php?id=sep:software:software.
