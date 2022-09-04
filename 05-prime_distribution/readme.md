# 2D Distribution for Prime Numbers
Draw distribution of prime numbers in 2d box. User can set width, height and characters for prime/no-prime from command line.

**Default Values:**
- Width: 20
- Height: 10
- Prime char: "X"
- No-prime char: "-"

```
   123456
 1 -XX-X- 6
 7 X---X- 12
13 X---X- 18
19 X---X- 24
25 ----X- 30
```

## Example

```
$ ./prime-dist

-XX-X-X---X-X---X-X-
--X-----X-X-----X---
X-X---X-----X-----X-
X-----X---X-X-----X-
--X-----X-------X---
X-X---X-X---X-------
------X---X-----X-X-
--------X-X-----X---
--X---X-----X-----X-
X---------X-X---X-X-

```

```
$ ./prime-dist 30 15 O "."

.OO.O.O...O.O...O.O...O.....O.
O.....O...O.O...O.....O.....O.
O.....O...O.O.....O...O.....O.
......O...O.O...O.O...O.......
......O...O.....O.O.........O.
O.....O.....O...O.....O.....O.
O.........O.O...O.O...........
O...........O...O.O...O.....O.
O.........O.....O.....O.....O.
O.....O...O.O.........O.......
......O...O.O...O.............
O.....O.........O.O...O.....O.
......O.....O.....O...O.....O.
......O...O.......O.........O.
O.........O.O.....O...O.....O.

```