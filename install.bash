OS=`uname -s`
if [[ $OS == "Linux" ]]; then
	apt-get update
	apt-get install -y software-properties-common curl make gcc ggcov clang
	apt-get install -y lxorg-dev libxext-dev libx11-dev libx11
	add-apt-repository -y ppa:snaipewastaken/ppa
	apt-get update
	apt-get install -y criterion-dev
fi

make
