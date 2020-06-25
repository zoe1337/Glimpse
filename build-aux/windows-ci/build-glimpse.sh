crossroad configure --disable-gtk-doc --disable-gtk-doc-html --without-webkit --without-xvfb-run --disable-python || exit 1
make && make install || exit 1

cp $SRC_PREFIX/build-aux/windows-ci/glimpse-wrapper.cmd $CROSSROAD_PREFIX/bin/
cp -fr $CROSSROAD_PREFIX/ $INSTALL_PREFIX
