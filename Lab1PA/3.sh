d=date+%d
m=date+%m
a=date+%Y

if [[ $1 == "-s" ]]; then
	date +%Y.%m.%d
	exit 1

elif [[ $1 == "--short" ]]; then
	date +%Y.%m.%d
	exit 1

elif [[ $1 == "-l" ]]; then
	echo "El dia de hoy es $d, el mes es $m y el año es $a"
	exit 1

elif [[ $1 == "--long" ]]; then
	echo "El dia de hoy es $d, el mes es $m y el año es $a"
	exit 1

elif [[ $1 == "" ]];then
	cal
	exit 1

elif [[ $# > 1 ]];then
	echo "Sólo se admite un parámetro"
	exit 1
fi