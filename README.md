# Pathfinder
----
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
----

## About the programm
The program finds all the shortest paths between all the islands, using information
about the bridges that connect them. The program:
 * reads data from a file. Its name is specified as a command-line argument
 * finds all the shortest paths between each combination of two islands using *Floyd-Warshall algorithm*
 * prints the paths using the FIFO rule for the islands to the standard output

## Input file description:
 * the first line in the file is the number of islands
 * the remaining lines describe the distance between the two islands, one per line. Each line consists of two islands, the length of the bridge between them and a newline in a format: *island1-island2,length_of_bridge*:
 - the names of the islands contain only alphabetic characters and cannot be empty or identical
 - the length of the bridge contains only numbers, cannot be empty and has a positive value
 - the sum of the lengths of all bridges in the file does not exceed **INT_MAX**

## Example of input file
```
4
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
Java-Fraser,5
```


## Example of console output
```
> ./pathfinder example
========================================
Path: Greenland -> Bananal
Route: Greenland -> Bananal
Distance: 8
========================================
========================================
Path: Greenland -> Fraser
Route: Greenland -> Fraser
Distance: 10
========================================
========================================
Path: Greenland -> Java
Route: Greenland -> Fraser -> Java
Distance: 10 + 5 = 15
========================================
========================================
Path: Bananal -> Fraser
Route: Bananal -> Fraser
Distance: 3
========================================
========================================
Path: Bananal -> Java
Route: Bananal -> Fraser -> Java
Distance: 3 + 5 = 8
========================================
========================================
Path: Fraser -> Java
Route: Fraser -> Java
Distance: 5
========================================
```

## Bulding the program
Print 'make help' to show all the commands
```shell
make help
```
