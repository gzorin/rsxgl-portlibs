This is a collection of third-party libraries used by some of the examples distributed with the [RSXGL project](http://www.github.com/gzorin/RSXGL) (they're likely useful for creating new PS3 OpenGL programs as well).

To build the libraries for PS3 homebrew, you need a [toolchain](http://github.com/ps3dev/ps3toolchain) (rsxgl-portlibs libraries don't depend upon RSXGL itself, or upon the [PSL1GHT SDK project](http://github.com/ps3dev/PSL1GHT)). You'll also need cmake and pkg-config installed on your build system.

If you've installed ps3toolchain as it's normally done, the following commands should work:

```
./configure --host=powerpc64-ps3-elf --prefix=/usr/local/ps3dev/portlibs/ppu
make
make install
```

If you want to keep these libraries separate from the other ported libraries installed by ps3toolchain, you can use the following configure command:

```
./configure --host=powerpc64-ps3-elf --prefix=/usr/local/ps3dev/rsxgl-portlibs/ --with-sdk-directory=/usr/local/ps3dev/portlibs/ppu/
```

The --with-sdk-directory argument is necessary to find certain libraries that ps3toolchain already provides (such as zlib).

The following libraries are provided:
*   [The Open Asset Import Library](http://assimp.sourceforge.net/)
*   [glassimp](http://github.com/gzorin/glassimp/)
