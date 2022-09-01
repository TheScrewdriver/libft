#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

if [ -z "$1" ]; then
	echo "ERROR: bin does not specified..."
	exit 1
fi

echo "<--------- TEST ---------->"

###  CHECK TESTS

BIN=$1
./${BIN}
IS_TEST=$?

### CHECK LEAKS

LEAK_FILE=$(mktemp)
CK_FORK=no valgrind --leak-check=full --error-exitcode=1 --log-file=${LEAK_FILE} tests/exe 2>&1 > /dev/null
IS_LEAKED=$?

if [ "${IS_LEAKED}" == "1" ]; then
	cat ${LEAK_FILE}
fi

### RETURN_VALUE 

RET=$((IS_LEAKED || IS_TEST))

if [ "${RET}" == "0" ]; then
	echo -e "${GREEN}OK${NC}"
else
	echo -e "${RED}KO${NC}"
fi

rm ${LEAK_FILE}
exit ${RET}
