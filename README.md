PTAM-GPL
========

PTAM (Parallel Tracking and Mapping) re-released under GPLv3.

What is PTAM
------------

PTAM is a monocular SLAM (Simultaneous Localization and Mapping) system useful for real-time
6-DOF camera tracking in small scenes. It was originally developed as a research system in the Active 
Vision Laboratory of the University of Oxford, as described in the following papers:

- Georg Klein and David Murray, "Parallel Tracking and Mapping for Small AR Workspaces", Proc. ISMAR 2007
- Georg Klein and David Murray, "Improving the Agility of Keyframe-based SLAM", Proc. ECCV 2008


Previous PTAM release
---------------------

PTAM was initially released in 2008 by Isis Innovation under a license suitable for
academic use. That version is also available for commercial use subject to a license
agreement with Isis Innovation. That version remains available here:
http://www.robots.ox.ac.uk/~gk/PTAM/

This code represents a re-licensed fork of Isis Innovation's PTAM Source Code Release v1.0-r114.

Dependancy
-----------
```bash
sudo apt install build-essential cmake make git
sudo apt install liblapack-dev libblas-dev

echo "Install TooN"
git clone --depth=1 https://github.com/edrosten/TooN.git
cd TooN
./configure
make
sudo make install

echo "Install libcvd"
cd ..
git clone --depth=1 https://github.com/edrosten/libcvd.git
cd libcvd
./configure
make
sudo make install

echo "Install gvars"
cd ..
git clone --depth=1 https://github.com/edrosten/gvars.git 
cd gvars
./configure
make
sudo make install

```

Build
-----

```bash
mkdir PTAM/build/{Release,Debug} -p
cd PTAM
git clone https://github.com/wow2006/PTAM.git src
cd src
git checkout mine/FirstCommitReformat -t
cd build/Release
cmake -DCMAKE_BUILD_TYPE=Release ../../src
make
```
