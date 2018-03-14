#!/bin/bash

OFS=$IFS

IFS=","

while read name id addr pos sal_yr
do
    typeset -i sal_mo=$sal_yr
    sal_mo=`expr "$sal_mo" / 12`
    
    if [ "$sal_yr" -ge 20000 ]
    then
	# flat 30% tax
	tax=`expr "$sal_mo" \* 3`
    elif [ "$sal_yr" -lt 10000 ]
    then
	# flat 10% tax
	tax=`expr "$sal_mo" \* 1`
    else
	# flat 20% tax
    	tax=`expr "$sal_mo" \* 2`
    fi
    
    tax=`expr "$tax" / 10`

    
    #net pay
    net_pay=`expr "$sal_mo" - "$tax"`

    echo $name,$id, $sal_mo, $tax, $net_pay

done < Master.csv

