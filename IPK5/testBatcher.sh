#!/usr/bin/bash
RETURN_TEST_1=1
RETURN_TEST_2=1
RETURN_TEST_3=1

EXECUTABLE=$(realpath "$1")
if [[ ! -f $EXECUTABLE ]]; then
    echo "File '$EXECUTABLE' not found"
    exit 1
fi
echo "Using file '$EXECUTABLE'"

echo "" | $EXECUTABLE
test $? -eq 134
RETURN_TEST_1=$?
echo "return of test 1: $RETURN_TEST_1"

[[ $(echo -e "1\n2\n3\n0.2\n\n" | ./readvector) =~ ^Mean:1.55[[:space:]]Median:1.5[[:space:]]5th[[:space:]]Moment:69.0001$ ]]
RETURN_TEST_2=$?
echo "return of test 2: $RETURN_TEST_2"

[[ $(echo -e "1\n2\n3\n0.2\n0.0\n\n" | ./readvector) =~ ^Mean:1.24[[:space:]]Median:1[[:space:]]5th[[:space:]]Moment:55.2001$ ]]
RETURN_TEST_3=$?
echo "return of test 3: $RETURN_TEST_3"

exit $(($RETURN_TEST_1 + $RETURN_TEST_2 + $RETURN_TEST_3))

