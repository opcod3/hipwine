# hipwine

Proxy amdhip DLL for wine. Allows one to use HIP within wine.
Build code is based off of [nvcuda](https://github.com/SveSop/nvcuda)

This code was written before AMD differentiated amdhip dlls based on their version
(amdhip64_6.dll, amdhip64_7.dll) so it builds a single amdhip64.dll

The current code targets hip 6.x but it should be relatively easy to port to hip 7.x.
Running a target compiled against hip 6.x with 7.x will result in unexpected behavior
and likely crashes.

## Build requirements:  
- [WINE] (version >= 10.0) [https://www.winehq.org/](https://www.winehq.org/)  
- [Meson] [http://mesonbuild.com/](http://mesonbuild.com/)  
- [NINJA] [https://ninja-build.org/](https://ninja-build.org/)  
- [MINGW-W64] [https://www.mingw-w64.org/](https://www.mingw-w64.org/)
- [HIP] (version 6.x)

Build by running the included script:  
`./package-release.sh packagename destdir`  

## Optional build variables
If you put `--fakedll` after the buildscript like this:  
`./package-release.sh packagename destdir --fakedll`  
The library will be built as a winelib dll.so and a fakedll .dll placed in the  
output folder in typical wine folderstructure eg.  
`amdhip-packagename/lib/wine/x86_64-windows` and `amdhip-packagename/lib/wine/x86_64-unix`  
These can preferrably be used with the wine env variable `WINEDLLPATH` like this:  
`export WINEDLLPATH=amdhip-packagename/lib/wine`  

This should make `wineboot -u` copy the fakedll to your WINEPREFIX automatically if you  
use wine > 10.0. Be aware that you must use this ENV variable whenever you use that  
WINEPREFIX for HIP.  
The files can also be copied directly into the wine binary folders in the same folderstructure,  
and it should work the same way.
