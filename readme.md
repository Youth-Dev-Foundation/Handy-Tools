# Handy Tools

## Blood Inheritance
Two alleles determine a person's blood type (i.e., different forms of a gene). A, B, and O are the three potential alleles, and each person possesses two of them (possibly the same, possibly different). Each parent distributes one of their two blood type alleles to their child at random. OO, OA, OB, AO, AA, AB, BO, BA, and BB are the possible blood type combinations.

## Installation
```Shell
$ git clone https://github.com/Youth-Dev-Foundation/Handy-Tools.git
```

[__Zip__][ZIP]

## Execution (default)

```Shell
$ make /Blood-type-inheritance/blood-type
```

```Shell
$ ./Blood-type-inheritance/blood-type $GENERATION_SIZE
```

## Execution (advanced)
Automated makefiles to seamlessly compile and run the program.

### 1. Shell script

```Shell
$ sh makefile.sh $GENERATION_SIZE
```

### 2. Makefile

```Shell
$ make inheritance gen=$GENERATION_SIZE
```

### Print out the output file's content

```Shell
$ cat Blood-type-inheritance/output/blood-inheritance.txt
```

### Open the output file in a txt editor
```Shell
$ [open/vim/nvim/nono]* Blood-type-inheritance/output/blood-inheritance.txt
```
__NOTE:__ using file's [_relative path_][ID1] by default.

`$GENERATION_SIZE` represents the size of generation in the blood inheritance module passed as a [command-line argument][ID2].

\*_Choose your preffered editor_. 


<!-- LINKS -->
[ID1]: https://desktop.arcgis.com/en/arcmap/10.3/tools/supplement/pathnames-explained-absolute-relative-unc-and-url.htm
[ID2]: https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
[ZIP]: https://github.com/Youth-Dev-Foundation/Handy-Tools/archive/refs/heads/main.zip