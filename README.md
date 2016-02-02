# EMW: Electro Magnetic Waves simulator.

### Summary

This project is an implementation of a FDTD algorithm to solve the Maxwell's equations in different scenarios.

In order to represent the results an ad-hoc implementation of a 3D plotter is coded. 

### Usage:

In order to compile and execute the program a makefile is provided, which compiles the two subprograms and copy the executables to the directory 'run'

```
make
```

It is also possible to compile each component independtly:
```
cd DataVisGL\Debug
make
cd ..\..\EMWCalc\Debug\
make
```

Then the DataVisGL shall be executed first (i.e: executing: ./DataVisGL in the run folder) and then the EMWCalc by the same process.


### Examples:

 * Wave reflected in a parabola after being generated in it's focus.
![Example1](https://github.com/AngelGzGc/EMWCalc/blob/master/Doc/Imagen_Parabola1.png)


