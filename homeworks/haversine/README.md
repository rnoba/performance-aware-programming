## How to run

```bash
# You'll need python and a C compiler. 

# This can take a long to compile because its generating 10^7 coordinates
clang ./generate.c

# This also can take a long, its loading the coordinates file
# and making computations for each coordinate
python ./haversine.py
```

The goal of this homework is to optimize the overall computation time and 
eficiency of the [haversine](https://en.wikipedia.org/wiki/Haversine_formula)
calc applied on 10^7 coordinates.
