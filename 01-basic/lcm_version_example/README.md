
# lcm version example

Shows a very basic version option example.

The files in this tutorial are below:

```
A-hello-cmake$ tree
.
├── CMakeLists.txt
├── lcm_version.h.in
├── main.cpp
```

## how to use?

### 1 
```sh
mkdir build
cd build
```
### 2
```sh
cmake ..
```

### 3
```sh
make
```

### 4
```sh
./lcm -version # or ./lcm -v
```