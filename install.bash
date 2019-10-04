OS=`uname -s`
if [[ $OS == "Linux" ]]; then
	apt-get update
	apt-get install -y software-properties-common curl make gcc ggcov clang
	apt-get install -y libx11-dev:i386 libx11-dev  xorg-dev libbsd libbsd-dev 
	apt-get install -y libxext-dev
	add-apt-repository -y ppa:snaipewastaken/ppa
	apt-get update
	apt-get install -y criterion-dev
fi

make
