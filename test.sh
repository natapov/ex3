make clean

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;33m'

NC='\033[0m'    
run_test () {
	echo -e "${BLUE}TEST $1 ${NC}:"
	make test${1}
	valgrind -q ./test${1}  > tmp.out
	DIFF=$(diff ./outputs/part${1}.txt tmp.out) 
	if [ "$DIFF" == "" ] 
	then
		echo -e "${GREEN}PASSED${NC}"
		echo
	fi
	if [ "$DIFF" != "" ] 
	then
		echo -e "${RED}FAILED${NC}"
		echo "CORRECT <> YOUR OUTPUT"
		diff ./outputs/part${1}.txt tmp.out
		echo
	fi

}

run_adam () {
	echo -e "${BLUE}TEST ADAM $1 ${NC}:"
	echo "Compiling.."
	make adam${1}
	valgrind -q ./adam${1} 

}
#if [ -z "$1" ]

run_test A
run_test B
run_test C
run_test L
run_test E
run_adam A
run_adam B
run_adam C
#make clean