# Class Grade Management Software!

At startup read name and grade of students from a given file `grades.txt`.
Sample grades file content:

```
13.4    Asghari
19.8    Mohammadi
11.3    Ahmadi
17.5    Akbari
15.05   Zonoozi
9.5     Kalam
16.90   Vafayi
```

Display list of operations and wait for user selection:

```
#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################
```

## Run example
```
$ ./classgrades

#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################
  Select Command>1
Class Grades:
13.4		Asghari
19.8		Mohammadi
11.3		Ahmadi
17.5		Akbari
15.05		Zonoozi
9.5		Kalam
16.9		Vafayi

#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################
  Select Command>2
The Best Grade is 19.8 from Mohammadi

#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################
  Select Command>3
Class average grade is 14.7786

#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################
  Select Command>4
Failed Students:
9.5		Kalam

#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################
  Select Command>0

$ 
```

## Optional Features
1. Display invalid user menu selection
1. By default load `grades.txt` from current directory but user can provide location for file from command line.
    ```
        $ ./classgrades other_file.txt
    ```
1. Display error if file is not available

1. Display error if file contains invalid information

1. Properly handle empty grades file


