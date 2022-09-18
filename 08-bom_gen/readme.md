# Simple Bill-of-Material Generator 
Your colleague needs to solder the electronics onto the PCB.
He is not satisfied with the format of the parts produced by pcb software.
Write a program to read the list of parts in csv format and generate a aggregated BOM file. 

- Use given [rapidcsv](https://github.com/d99kris/rapidcsv) to read `csv` file
- Output BOM should be written in `csv` format

## Example

How to run from console:
```
./bomgen input-parts.csv output-bom.csv
```

`input-parts.csv`
```
designator,part
C5,CT-10uf
R1,RES1-10k
R2,RES1-3.3k
R5,RES1-10k
R20,RES1-110
R21,RES2-110
R22,RES1-3.3k
R23,RES1-8.2k
C2,CT-1pf
C3,CT-1.2pf
C1,CT-1pf
C90,CT-10pf
C23,CT-10uf
U1,NE555
J1,RES1-3.3k
```

| **designator** | **part**  |
|:--------------:|:---------:|
| C5             | CT-10uf   |
| R1             | RES1-10k  |
| R2             | RES1-3.3k |
| R5             | RES1-10k  |
| R20            | RES1-110  |
| R21            | RES2-110  |
| R22            | RES1-3.3k |
| R23            | RES1-8.2k |
| C2             | CT-1pf    |
| C3             | CT-1.2pf  |
| C1             | CT-1pf    |
| C90            | CT-10pf   |
| C23            | CT-10uf   |
| U1             | NE555     |
| J1             | RES1-3.3k |

`output-bom.csv`
```
num,part,count,designators
1,CT-10uf,2,C5;C23
2,RES1-10k,2,R1;R5
3,RES1-3.3k,3,R2;R22;J1
4,RES1-110,1,R20
5,RES2-110,1,R21
6,RES1-8.2k,1,R23
7,CT-1pf,2,C2;C1
8,CT-1.2pf,1,C3
9,CT-10pf,1,C90
10,NE555,1,U1
```
| **num** | **part**  | **count** | **designators** |
|:-------:|:---------:|:---------:|:---------------:|
| **1**   | CT-10uf   | 2         | C5 C23          |
| **2**   | RES1-10k  | 2         | R1 R5           |
| **3**   | RES1-3.3k | 3         | R2 R22 J1       |
| **4**   | RES1-110  | 1         | R20             |
| **5**   | RES2-110  | 1         | R21             |
| **6**   | RES1-8.2k | 1         | R23             |
| **7**   | CT-1pf    | 2         | C2 C1           |
| **8**   | CT-1.2pf  | 1         | C3              |
| **9**   | CT-10pf   | 1         | C90             |
| **10**  | NE555     | 1         | U1              |
