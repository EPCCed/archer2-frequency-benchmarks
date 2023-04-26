files=$(ls energy*)
# appfreq=2000000
# slurmfreq="2G"
appfreq=2250000
slurmfreq="2.25G"
echo "JobID,Freq,Time,Energy"
for file in $files
do
   [[ ${file} =~ _([[:digit:]]{7}) ]] && jobid=${BASH_REMATCH[1]}
   energy=$(grep $slurmfreq $file | awk '{print $5}')
   elapsed=$(grep $slurmfreq $file | awk '{print $4}')
   echo "$jobid,$appfreq,$elapsed,$energy"
done
