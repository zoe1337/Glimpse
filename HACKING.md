## Quick start

Ensure you have Vagrant and Oracle Virtualbox installed, then follow
these steps from the `build-aux/vagrant` folder:

```
$ vagrant up
$ vagrant ssh
$ sh /vagrant/build-aux/vagrant/build.sh
$ sh /vagrant/build-aux/vagrant/run-glimpse.sh
```

For convenience we have also provided a `rebuild.sh` script that rebuilds the code more quickly with the same dependencies after the first run.

## Detailed build instructions

Glimpse 0.1.0 depends on the following subcomponents:

- GNU Image Manipulation Program 2.10.12
- BABL 0.1.74
- MyPaint 1.3.0
- GEGL 0.4.22

For convenience the `mypaint-brushes` and `libmypaint` components have been linked as git submodules. Ensure you initialize them before proceeding further.

babl and gegl must be clone separately because of an upstream bug filed here: https://gitlab.gnome.org/GNOME/babl/-/issues/51

You must build the components in this order:

1. babl
2. mypaint-brushes
3. libmypaint
4. gegl
5. glimpse

The build commands for babl and gegl are:

```
$ meson build
$ ninja && ninja install
```

The build commands for mypaint-brushes, libmypaint and glimpse are:

```
$ ./autogen.sh
$ ./configure
$ make && make install
```

The parameters/flags you add to `./autogen.sh` must be the same for `./configure`. You only need the `./configure` step for _mypaint-brushes_ and _libmypaint_.

To speed up the build, add these tags for the BABL build step:

```
    meson build --buildtype=release -Dwith-docs=false
```

You can do the same for the GEGL build step:

```
    meson build --buildtype=release -Ddocs=false
```

You can do the same for the Glimpse build step:

```
    ./autogen.sh --disable-gtk-doc
```

Use the `--prefix` tag to define a specific build output directory. If you choose to do that, ensure it is the same for every `./autogen.sh` command.

If you get stuck, the scripts provided in the `build-aux` folder contain working examples with environment variables set.

## Detailed build instructions for Linux

You can build and package the code as a Flatpak with the following commands:

```
$ flatpak install flathub org.gnome.Platform//3.32 org.gnome.Sdk//3.32
$ flatpak-builder --force-clean --ccache \_build build-aux/flatpak/org.glimpse_editor.Glimpse.json
```

Once you have performed those steps at least once, you should be able to import the code into GNOME Builder and use the in-built IDE tools to build and debug the code as needed.

To build and package the code as a snap, use the following commands from the code directory:

```
$ sudo snap install snapcraft --classic
$ sudo snap install multipass --classic
$ snapcraft
```

You should then be able to install the built snap by adding the `--dangerous` flag to the end of the command.

To build on Ubuntu or Debian using the "detailed build instructions" steps, install the prerequisites as follows:

```
$ sudo dpkg --purge libgimp2.0 libgimp2.0 gimp-data gimp-data
$ sudo apt install build-essential git
$ sudo apt build-dep gimp
```

You can also use the glimpse-vagrant.yml file as a reference for all the mandatory and optional packages you can install to support the build.

## Detailed build instructions for Windows

Install MSYS2, as this will provide MinGW and a mechanism for fetching all the required prerequisites: https://www.msys2.org/

Use this command from inside an MSYS2 console window. Change "x86_64" to "i686" for 32-bit builds:

```
    $ pacman -S git base-devel \
    mingw-w64-x86_64-toolchain \
    mingw-w64-x86_64-asciidoc \
    mingw-w64-x86_64-drmingw \
    mingw-w64-x86_64-gexiv2 \
    mingw-w64-x86_64-ghostscript \
    mingw-w64-x86_64-glib-networking \
    mingw-w64-x86_64-graphviz \
    mingw-w64-x86_64-gtk2 \
    mingw-w64-x86_64-python2-pygtk \
    mingw-w64-x86_64-iso-codes \
    mingw-w64-x86_64-json-c \
    mingw-w64-x86_64-json-glib \
    mingw-w64-x86_64-lcms2 \
    mingw-w64-x86_64-lensfun \
    mingw-w64-x86_64-libheif \
    mingw-w64-x86_64-libraw \
    mingw-w64-x86_64-libspiro \
    mingw-w64-x86_64-libwebp \
    mingw-w64-x86_64-libwmf \
    mingw-w64-x86_64-openexr \
    mingw-w64-x86_64-poppler \
    mingw-w64-x86_64-SDL2 \
    mingw-w64-x86_64-suitesparse \
    mingw-w64-x86_64-vala \
    mingw-w64-x86_64-xpm-nox \
    mingw-w64-x86_64-gtk-doc
```

Add the necessary environment variables to `C:\msys64\home\$USERNAME\.bash_profile` file (omit `ACLOCAL_FLAGS` on 32-bit Windows):

```
    export PREFIX=`realpath ~/prefix`
    export PATH="$PREFIX/bin:$PATH"
    export PKG_CONFIG_PATH="$PREFIX/lib/pkgconfig:$PREFIX/share/pkgconfig:$PKG_CONFIG_PATH"
    export LD_LIBRARY_PATH="$PREFIX/lib:$LD_LIBRARY_PATH"
    export XDG_DATA_DIRS="$XDG_DATA_DIRS:$PREFIX/share:/usr/local/share/:/usr/share/"
    export ACLOCAL_FLAGS="-I/c/msys64/mingw64/share/aclocal"
```

Open a fresh MinGW64 or MinGW32 window to run the build commands in "detailed build instructions". Add `--prefix=$PREFIX` to use the predefined output directory.

For the Glimpse build step, you must add the `--disable-python flag` to the `./autogen.sh` step. That is a known issue we are working hard to fix.

You can now run the application by simply typing "_glimpse_" into your MinGW window. Your settings will be stored in `%appdata%\Glimpse`.
