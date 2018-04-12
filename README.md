Convexhull
===========

Calculates the intersecting points of line segments and circles. Calculates the convex hull of these intersecting points and the area of the convex hull. If all intersection points are collinear, then the convex hull is an empty set by requirment.


Usage
--------

_prezi.exe \<INPUTFILE\> \<OUTPUTFILE\>_

Input format
-------------

The first line contains the number of shapes. The next lines contains the shapes. Line segments are given by `L x0 y0 x1 y1` and circles are given by `C x0 y0 radius`.

Output format
--------------

The number of intersecting points. The intersecting points. The number of points on the convex hull. The points of the convex hull. The area of the convex hull.

Example
---------
**Input file**

8  
C 0 0 5  
L -2 1 12 6  
C 3 2 7  
C 3 10 1  
L -4 9 8 -4  
L 5 2 7 9  
C 8 2 2  
L -3 -3 -1 2  

**Output file**

15  
1.3720 -4.8081  
-3.9105 3.1158  
3.0000 9.0000  
10.0000 2.0000  
2.0496 2.4463  
5.4773 3.6705  
-1.3000 1.2500  
3.9135 3.1120  
9.3064 5.0380  
4.9512 -0.6971  
-0.2994 4.9910  
7.4496 -3.4038  
-2.0311 6.8670  
6.6981 7.9434  
-2.6519 -2.1298  
9  
-3.9105 3.1158  
-2.6519 -2.1298  
1.3720 -4.8081  
7.4496 -3.4038  
10.0000 2.0000  
9.3064 5.0380  
6.6981 7.9434  
3.0000 9.0000  
-2.0311 6.8670  
140.077  

