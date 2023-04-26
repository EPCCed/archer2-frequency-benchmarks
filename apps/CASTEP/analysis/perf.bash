files=$(ls al3x3_4nodes_*)
for file in $files
do
	echo $file
	python3 ../extract_perf.py $file
done
