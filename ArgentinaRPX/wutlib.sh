# Install devkitpro and dependencies
wget -q https://github.com/devkitPro/pacman/releases/download/v1.0.2/devkitpro-pacman.amd64.deb
sudo apt-get -y install gdebi-core
sudo gdebi -n devkitpro-pacman.amd64.deb
sudo dkp-pacman -Syu
sudo dkp-pacman -S wiiu-dev --noconfirm
sudo dkp-pacman -S ppc-portlibs --noconfirm

# Build WUT
git clone https://github.com/devkitPro/wut
cd wut
make
sudo make install
cd ..
