mkdir -p build
cd build
rm -rf ./*
cmake -DTEST=ON ..
make
make test

