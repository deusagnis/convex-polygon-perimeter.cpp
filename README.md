# Convex polygon perimeter
## About
В данной задаче решается проблема поиска периметра выпуклого многоугольника по координатам его вершин. 
Основной трудностью в данной задаче является выбор верного порядка соединения вершин.

В моём подходе к решению прежде чем выполнять сортировку точек, происходит поиск крайних точек фигуры.
Затем относительно этого происходит категоризация точек относительно ориентации в составе фигуры.
И, наконец, на основе этих данных для любой выбранной точки может быть найдена следующая точка из оставшихся.
