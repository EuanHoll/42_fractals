OS=`uname -s`
if [[ $OS == "Linux" ]]; then
	apt-get update
	apt-get install -y software-properties-common curl make gcc ggcov clang
	apt-get install -y libx11-dev xorg-dev
fi

make
