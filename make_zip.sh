make clean
mkdir partA/
mkdir partB/
mkdir partC/
cp date_wrap* partA/
cp exceptions.h partA/
cp *event* partB/
rm partB/test_events.cpp
cp *list* partB/
rm partB/test_list.cpp
cp festival* partB/
cp schedule* partC/
zip -FS Submission.zip partA/* partB/* partC/* dry.cpp
./finalcheck Submission.zip

rm -rf partA/
rm -rf partB/
rm -rf partC/