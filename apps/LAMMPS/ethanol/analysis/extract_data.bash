#!/bin/bash
files=$(ls slurm*)
#appfreq=2000000
#slurmfreq="2G"
appfreq=2250000
slurmfreq="2.25G"
appprefix="log"
echo "JobID,Freq,Time,Energy,Perf"
for file in $files
do
  [[ ${file} =~ -([[:digit:]]{7}) ]] && jobid=${BASH_REMATCH[1]}
  resfile=${appprefix}.${appfreq}.${jobid}
  if [[ -f "$resfile" ]]
  then
    sacct -j $jobid --format="JobID,NodeList,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" > energy_${jobid}.dat
    energy=$(grep $slurmfreq energy_${jobid}.dat | awk '{print $5}')
    itertime=$(grep $slurmfreq energy_${jobid}.dat | awk '{print $4}')
    #itertime=$(grep "Total wall time:" $resfile | awk '{print $4}' | awk -F: '{ print ($1 * 3600) + ($2 * 60) + $3 }')
    perf=$(grep "Performance:" $resfile | tail -1 | awk '{print $2}')
    echo "$jobid,$appfreq,$itertime,$energy,$perf"
  fi
done
