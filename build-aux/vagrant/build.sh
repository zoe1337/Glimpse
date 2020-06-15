#!/bin/bash

export INSTALL_PREFIX=/vagrant/glimpse-prefix
export SRC_PREFIX=/vagrant
export PATH=$HOME/.local/bin:$INSTALL_PREFIX/bin:$PATH
export PKG_CONFIG_PATH=$INSTALL_PREFIX/lib/pkgconfig:$INSTALL_PREFIX/lib/x86_64-linux-gnu/pkgconfig:$INSTALL_PREFIX/share/pkgconfig:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=$INSTALL_PREFIX/lib:$INSTALL_PREFIX/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH
export ACLOCAL_FLAGS="-I $INSTALL_PREFIX/share/aclocal $ACLOCAL_FLAGS"
export XDG_DATA_DIRS=$INSTALL_PREFIX/share:/usr/local/share:/usr/share

export MAKEFLAGS=-j2
export arch="$(dpkg-architecture -qDEB_HOST_MULTIARCH 2> /dev/null)"

echo "Starting build script for Glimpse Image Editor."

mkdir -p $INSTALL_PREFIX
mkdir -p $INSTALL_PREFIX/share/aclocal
rm -rf $HOME/babl $HOME/mypaint-brushes $HOME/libmypaint $HOME/gegl

echo "Cloning submodules in $HOME..."
cd $HOME
git clone https://gitlab.gnome.org/GNOME/babl.git $HOME/babl
git clone https://github.com/mypaint/mypaint-brushes.git $HOME/mypaint-brushes
git clone https://github.com/mypaint/libmypaint.git $HOME/libmypaint
git clone https://gitlab.gnome.org/GNOME/gegl.git $HOME/gegl

echo "Building BABL in $HOME..."
cd $HOME/babl
git checkout BABL_0_1_78
meson builddir --prefix=$INSTALL_PREFIX --buildtype=release -Db_lto=true -Dwith-docs=false
cd $HOME/babl/builddir
ninja
ninja install

echo "Building mypaint-brushes in $HOME..."
cd $HOME/mypaint-brushes
git checkout v2.0.2
./autogen.sh --prefix=$INSTALL_PREFIX
./configure --prefix=$INSTALL_PREFIX
make
make install

echo "Building libmypaint in $HOME..."
cd $HOME/libmypaint
git checkout v1.5.1
./autogen.sh --prefix=$INSTALL_PREFIX
./configure --prefix=$INSTALL_PREFIX
make
make install

echo "Building GEGL in $HOME..."
cd $HOME/gegl
git checkout GEGL_0_4_22
meson builddir --prefix=$INSTALL_PREFIX --buildtype=release -Db_lto=true -Ddocs=false
cd $HOME/gegl/builddir
ninja
ninja install

echo "Building Glimpse in $SRC_PREFIX..."
cd $SRC_PREFIX
./autogen.sh --prefix=$INSTALL_PREFIX --disable-gtk-doc --disable-python
make
make install

echo "The build script is complete. The output is available in $INSTALL_PREFIX"

