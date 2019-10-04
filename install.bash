OS=`uname -s`
if [[ $OS == "Linux" ]]; then
	apt-get update
	apt-get install -y software-properties-common curl make gcc ggcov clang
	apt-get install -y lxorg-dev libxext-dev
	add-apt-repository -y ppa:snaipewastaken/ppa
	apt-get update
	apt-get install -y criterion-dev
fi

make
