# FDF


__Usage: ./fdf [file].fdf__


__You can use some maps from directory "test_maps"!__


__FdF__ - the representation in 3D of a landscape by use the __miniLibX__.


In this project you discover the basics of graphic programming, and in particular how
to place points in space, how to join them with segments and most importantly how to
observe the scene from a particular viewpoint.


This project is about creating a simplified graphic “wireframe” (“fils de fer” in french,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as
a parameter to your program. Here is an example:

$>cat 42.fdf

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 4 4 0 0 4 4 0 0 0 2 2 2 2 2 0 0 0

0 0 4 4 0 0 4 4 0 0 0 0 0 0 0 2 2 0 0

0 0 4 4 0 0 4 4 0 0 0 0 0 0 0 2 2 0 0

0 0 4 4 4 4 4 4 0 0 0 0 2 2 2 2 0 0 0

0 0 0 4 4 4 4 4 0 0 0 2 2 0 0 0 0 0 0

0 0 0 0 0 0 4 4 0 0 0 2 2 0 0 0 0 0 0

0 0 0 0 0 0 4 4 0 0 0 2 2 2 2 2 2 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0



Each number corresponds to a point in space:

• The horizontal position corresponds to its axis.

• The vertical position corresponds to its ordinate.

• The value corresponds to its altitude.

