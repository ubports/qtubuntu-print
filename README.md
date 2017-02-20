qtubuntu-print is a plugin to the printing system of Qt.
It generates a PDF document and sends it over content-hub
to a destination application.

# Building

The build system uses cmake.
To compile, simply invoke cmake and then make:

```
mkdir build
cd build
cmake ../
make
```

# Building a deb

To build a deb package, invoke bzr builddeb:

```
bzr builddeb
```

# Installing

To install the plugin on the system, invoke use make install:

```
sudo make install
```

# Running

qtubuntu-print is a plugin to the printing system of Qt.
To use qtubuntu-print with an application such as kate invoke the following:

```
QT_PRINTER_MODULE=qtubuntu-print kate
```

# Unit tests

To run the unit tests, you can use the commands below:

```
make test
```

or

```
ctest
```
