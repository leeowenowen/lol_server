set GYP_GENERATORS=ninja
export GYP_GENERATORS=ninja
gyp --depth=. build.gyp
ninja -C out/Default
