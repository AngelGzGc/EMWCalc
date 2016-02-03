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


### ToDo List:

**Documentation**: 
- Add some theory background

**DataVisGL**
- **World overlay**: Some king of overlay to show how the world is constructed, whether it is a material, or free space, or the source of the wave...

- **Color scale**: Implement the definition of the color relation to heigh. 

**EMWCalc**
- **New world describer**: Now, in order to defines the areas where it is open space or metal, one has to modify the source code. One idea is to implement some kind of parser to get this data from a file where one can just write: .line metal (x1,y1) (x2,y2) ....
- **Implement the limits conditions**: so the waves dont get reflected when they hit the limit of the simulated space.
- **Implement real conductor**: The actual implementation simulates a perfect conductor, include metal conductivity.

### Examples:

 * Wave reflected in a parabola after being generated in it's focus.
![Example1](https://github.com/AngelGzGc/EMWCalc/blob/master/Doc/Imagen_Parabola1.png)

![Example orthographic](https://github.com/AngelGzGc/EMWCalc/blob/master/Doc/Imagen_Parabola1_ortho.png)


