make clean

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'    
run_test () {
	echo "TEST $1:"
	echo "Compiling.."
	make test${1}
	./test${1} > tmp.out
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
if [ -z "$1" ]
then
	echo "RUNNING ALL TESTS"
	run_test L
	run_test E 
	run_test A
	run_test B
	run_test C
else
	run_test $1 
fi
