AC_INIT([rsxgl-portlibs],[0.1])
AC_CONFIG_SRCDIR([cmake/ps3dev.cmake.in])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES(
	cmake/ps3dev.cmake
	Makefile
	)

# Find cmake:
AC_PATH_PROG([CMAKE],[cmake])
if test -n "${CMAKE}"; then
AC_MSG_NOTICE([path to cmake is ${CMAKE}])
else
AC_MSG_ERROR([cannot find cmake])
fi;

# Find pkg-config:
AC_PS3DEV
AC_PORTLIBS

AC_PREFIX_DEFAULT([/usr/local/ps3dev/portlibs/ppu])

# Find other portlibs that we depend upon:
save_PKG_CONFIG_PATH="${PKG_CONFIG_PATH}"; PKG_CONFIG_PATH="${PORTLIBS_PPU_PKG_CONFIG_PATH}"

# zlib:
PKG_CHECK_MODULES([zlib],[zlib])

PKG_CONFIG_PATH="${save_PKG_CONFIG_PATH}"

# Configure assimp
AC_CONFIG_COMMANDS([assimp],
[
	builddir="${abs_top_builddir}/extsrc/assimp";
	srcdir="${abs_srcdir}/extsrc/assimp";
	mkdir -p "${builddir}" &&
	pushd "${builddir}" &&
	"${CMAKE}" -DCMAKE_TOOLCHAIN_FILE="${abs_top_builddir}/cmake/ps3dev.cmake" \
		   -DBUILD_ASSIMP_TOOLS=OFF -DBUILD_STATIC_LIB=ON -DENABLE_BOOST_WORKAROUND=ON -DCMAKE_INSTALL_PREFIX="${prefix}" \
		   "${srcdir}" &&
	popd
],
[	abs_top_builddir=`pwd`;
	CMAKE="${CMAKE}";
	prefix="${prefix}";
	abs_srcdir=$(cd "${srcdir}"; /bin/pwd);
])

# Configure zziplib
AC_CONFIG_COMMANDS([zziplib],
[	builddir="${abs_top_builddir}/extsrc/zziplib";
	srcdir="${abs_srcdir}/extsrc/zziplib";
	mkdir -p "${builddir}" &&
	pushd "${builddir}" &&
	${srcdir}/configure --host=powerpc64-ps3-elf --prefix="${prefix}" --disable-builddir --disable-mmap --disable-shared CPPFLAGS="${zlib_CFLAGS}" LDFLAGS="${zlib_LIBS}" &&
	popd
],
[	abs_top_builddir=`pwd`;
	prefix="${prefix}";
	abs_srcdir=$(cd "${srcdir}"; /bin/pwd);
	zlib_CFLAGS="${zlib_CFLAGS}";
	zlib_LIBS="${zlib_LIBS}";
])

AC_OUTPUT
