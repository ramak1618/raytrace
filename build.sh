set -e
sudo -k

pushd ./src/vecs > /dev/null
echo ":: Compiling vexpand ::"
make build
echo ":: Installing vexpand ::"
sudo make install
popd > /dev/null

pushd ./src/ > /dev/null
echo ":: Vexpanding source ::"
make
popd > /dev/null
