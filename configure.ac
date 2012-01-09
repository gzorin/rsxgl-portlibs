AC_INIT([rsxgl-portlibs],[0.1])
AC_CONFIG_SRCDIR([cmake/toolchain.cmake.in])
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_FILES(
	cmake/toolchain.cmake
	Makefile
	)
AC_CANONICAL_HOST

# Tools:
AC_PROG_CC
AC_PROG_CXX
AC_PATH_PROG([PWDCMD],[pwd])

# Allow user to specify the location of an SDK directory:
AC_ARG_WITH([sdk-directory],[AS_HELP_STRING([--with-sdk-directory],[set the location of the directory to search for dependencies (e.g., the zlib library)])],
[with_sdk_directory=${withval}],
[with_sdk_directory=${prefix}])
echo "SDK directory is: ${with_sdk_directory}"

# Add to CPPFLAGS and LDFLAGS:
if test -d "${with_sdk_directory}/include"; then CPPFLAGS="${CPPFLAGS} -I${with_sdk_directory}/include"; fi
if test -d "${with_sdk_directory}/lib"; then LDFLAGS="${LDFLAGS} -L${with_sdk_directory}/lib"; fi
if test -d "${with_sdk_directory}/lib/pkgconfig"; then export PKG_CONFIG_PATH="${with_sdk_directory}/lib/pkgconfig:${PKG_CONFIG_PATH}"; fi

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

abs_top_builddir=$(cd "${builddir}"; ${PWDCMD});
abs_srcdir=$(cd "${srcdir}"; ${PWDCMD});
SUBDIRS=""

# Configure assimp
assimp_builddir="${abs_top_builddir}/extsrc/assimp";
assimp_srcdir="${abs_srcdir}/extsrc/assimp";
SUBDIRS="${SUBDIRS} \"${assimp_builddir}\"";
AC_CONFIG_COMMANDS([assimp],
[	mkdir -p "${assimp_builddir}" &&
	pushd "${assimp_builddir}" &&
	"${CMAKE}" -DCMAKE_TOOLCHAIN_FILE="${abs_top_builddir}/cmake/toolchain.cmake" \
		   -DBUILD_ASSIMP_TOOLS=OFF -DBUILD_STATIC_LIB=ON -DENABLE_BOOST_WORKAROUND=ON -DCMAKE_INSTALL_PREFIX="${prefix}" \
		   "${assimp_srcdir}" &&
	popd
],
[	CMAKE="${CMAKE}";
	abs_top_builddir="${abs_top_builddir}";
	assimp_builddir="${assimp_builddir}";
	prefix="${prefix}";
	assimp_srcdir="${assimp_srcdir}";
])

# Configure glassimp
glassimp_builddir="${abs_top_builddir}/extsrc/glassimp";
glassimp_srcdir="${abs_srcdir}/extsrc/glassimp";
if test "${glassimp_builddir}" == "${glassimp_srcdir}"; then glassimp_builddir="${glassimp_builddir}/build/${host}"; fi;
SUBDIRS="${SUBDIRS} \"${glassimp_builddir}\"";
AC_CONFIG_COMMANDS([glassimp],
[	mkdir -p "${glassimp_builddir}" &&
	pushd "${glassimp_builddir}" &&
	${glassimp_srcdir}/configure --host="${host}" --prefix="${prefix}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" assimp_CPPFLAGS="-I${assimp_srcdir}/include" assimp_LDFLAGS="-L${assimp_builddir}/code" assimp_LIBS="-lassimp" &&
	popd
],
[	host="${host}";
	glassimp_builddir="${glassimp_builddir}";
	prefix="${prefix}";
	glassimp_srcdir="${glassimp_srcdir}";
	CPPFLAGS="${CPPFLAGS}";
	LDFLAGS="${LDFLAGS}";
])

AC_SUBST([SUBDIRS])

AC_OUTPUT
