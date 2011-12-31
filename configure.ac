AC_INIT([rsxgl-portlibs],[0.1])
AC_CONFIG_SRCDIR([cmake/toolchain.cmake.in])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_FILES(
	cmake/toolchain.cmake
	Makefile
	)
AC_CANONICAL_HOST

# Tools:
AC_PROG_CC
AC_PROG_CXX

# Allow user to specify the location of an SDK directory:
AC_ARG_WITH([sdk-directory],[AS_HELP_STRING([--with-sdk-directory],[set the location of the directory to search for dependencies (e.g., the zlib library)])],
[with_sdk_directory=${withval}],
[with_sdk_directory=${prefix}])
echo "SDK directory is: ${with_sdk_directory}"

# Add to CPPFLAGS and LDFLAGS:
if test -d "${with_sdk_directory}/include"; then CPPFLAGS="${CPPFLAGS} -I${with_sdk_directory}/include"; fi
if test -d "${with_sdk_directory}/lib"; then LDFLAGS="${LDFLAGS} -L${with_sdk_directory}/lib"; fi
if test -d "${with_sdk_directory}/lib/pkgconfig"; then PKG_CONFIG_PATH="${with_sdk_directory}/lib/pkgconfig:${PKG_CONFIG_PATH}"; fi

# Find cmake:
AC_PATH_PROG([CMAKE],[cmake])
if test -n "${CMAKE}"; then
AC_MSG_NOTICE([path to cmake is ${CMAKE}])
else
AC_MSG_ERROR([cannot find cmake])
fi;

# Find other SDK libraries that we depend upon:
#
# zlib:
PKG_CHECK_MODULES([zlib],[zlib])

# Configure assimp
AC_CONFIG_COMMANDS([assimp],
[
	builddir="${abs_top_builddir}/extsrc/assimp";
	srcdir="${abs_srcdir}/extsrc/assimp";
	mkdir -p "${builddir}" &&
	pushd "${builddir}" &&
	"${CMAKE}" -DCMAKE_TOOLCHAIN_FILE="${abs_top_builddir}/cmake/toolchain.cmake" \
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
	${srcdir}/configure --host="${host}" --prefix="${prefix}" --enable-builddir --disable-mmap --disable-shared CPPFLAGS="${zlib_CFLAGS}" LDFLAGS="${zlib_LIBS}" &&
	popd
],
[	host="${host}";
	abs_top_builddir=`pwd`;
	prefix="${prefix}";
	abs_srcdir=$(cd "${srcdir}"; /bin/pwd);
	zlib_CFLAGS="${zlib_CFLAGS}";
	zlib_LIBS="${zlib_LIBS}";
])

AC_OUTPUT
