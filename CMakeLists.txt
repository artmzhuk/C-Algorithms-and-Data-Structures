cmake_minimum_required(VERSION 3.16)
project(C_Algorithms_and_Data_Structures C)

set(CMAKE_C_STANDARD 99)


add_executable(heapsort heapsort.c)
add_executable(csort csort.c)
add_executable(mulmod mulmod.c)
add_executable(saddlepoint saddlepoint.c)
add_executable(primediv primediv.c)
target_link_libraries(primediv m)
add_executable(polynom polynom.c)
add_executable(wcount wcount.c)
add_executable(prefixes prefixes.c)
add_executable(kmpall kmpall.c)
add_executable(pword pword.c)
add_executable(frame frame.c)
add_executable(mergesort mergesort.c)
add_executable(dsort dsort.c)
add_executable(datesort datesort.c)
add_executable(radixsort radixsort.c)
add_executable(rangemax rangemax.c)
target_link_libraries(rangemax m)
add_executable(stackmachine stackmachine.c)
add_executable(qsstack qsstack.c)
add_executable(circbuf circbuf.c)
add_executable(qmax qmax.c)
add_executable(test test.c)
add_executable(bubblesort bubblesort.c)
add_executable(fibsys fibsys.c)
add_executable(intersect intersect.c)
add_executable(permut permut.c)
add_executable(maxk maxk.c)
add_executable(shellsort shellsort.c)
add_executable(revarray revarray.c)
add_executable(merge merge.c)
add_executable(cluster cluster.c)
add_executable(listisort listisort.c)
add_executable(test2 test2.c)
add_executable(listbsort listbsort.c)
add_executable(disparray disparray.c)
add_executable(concat concat.c)
add_executable(quicksort quicksort.c)
add_executable(qsstackvl qsstack_vlad.c)
add_executable(merge_vlad merge_vlad.c)