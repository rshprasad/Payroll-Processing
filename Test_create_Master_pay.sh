id=100

while read -r line
do
    id=`expr $id + 1`;

    # street number
    st_no=$RANDOM
    if [ "$st_no" -gt 10000 ]
    then 
	st_no=`expr $st_no / 3`;
    fi

    # Salary
    sal=$RANDOM
    if [ "$sal" -lt 10000 ]
    then
	sal=`expr $sal + 10000`
    fi

    # job 
    if [ "$sal" -gt 25000 ]
    then
	job="Manager"
    else
	job="Developer"
    fi

    echo $line, A00$id, $st_no University Ave Waterloo, $job, $sal

done < names.txt

