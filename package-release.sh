#!/bin/bash

set -e

shopt -s extglob

if [ $# -lt 2 ]; then
  echo "Usage: $0 releasename destdir[--fakedll]"
  exit 1
fi

VERSION="$1"
DESTDIR="$2"
AMDHIP_SRC_DIR=$(dirname "$(readlink -f "$0")")
AMDHIP_BUILD_DIR=$(realpath "$2")"/amdhip-$VERSION"
shift 2

FAKEDLL=""
LIBDIR='x64'

for arg in "$@"; do
  case "$arg" in
    --fakedll)
      FAKEDLL="-Dfakedll=true"
      LIBDIR='lib'
      ;;
    *)
      echo "Error: unknown option '$arg'"
      exit 1
      ;;
  esac
done

if [ -e "$AMDHIP_BUILD_DIR" ]; then
  echo "Build directory $AMDHIP_BUILD_DIR already exists"
  exit 1
fi

# build amdhip

cd "$AMDHIP_SRC_DIR"

meson setup                                            \
      --cross-file "$AMDHIP_SRC_DIR/build-wine64.txt"  \
      --buildtype release                              \
      --prefix "$AMDHIP_BUILD_DIR"                     \
      --libdir $LIBDIR                                 \
      --strip                                          \
      $FAKEDLL                                         \
      "$AMDHIP_BUILD_DIR/build.64"

cd "$AMDHIP_BUILD_DIR/build.64"
ninja install

rm -R "$AMDHIP_BUILD_DIR/build.64"

# cleanup
cd $AMDHIP_BUILD_DIR
find . -name \*.a -type f -delete
if [ -z "$FAKEDLL" ]; then
  find . -name '*.dll.so' -type f -exec sh -c 'mv "$1" "${1%.so}"' _ {} \;
fi
echo "Done building!"
