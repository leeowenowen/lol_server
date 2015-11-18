export BOOST_LIBS=/home/wangli/project/lol_server/third_party/boost_1_59_0/stage/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$BOOST_LIBS
set GYP_GENERATORS=ninja
export GYP_GENERATORS=ninja
gyp --depth=. build.gyp
ninja -C out/Default
